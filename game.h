#ifndef GAME_H_
#define GAME_H_

#include "linked.h"
#include "queue.h"
#include "team.h"
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <iomanip>
#include "city.h"

class Game{
    public:
        Game();
        void init();
        void advanceTeams();
        void printResults();
        void deactivateTeam(Team *);
        void sortTeams();
        void printAllTeams();
        int getCityCount();
    private:
        Queue<Team> finished;
        Queue<Team> running;
        Linked<Team> teams;
        Queue<City> cities;
        int finishedCities;
};

Game::Game(){
    Queue<Team> finished;
    Queue<Team> running;
    Linked<Team> teams;
    Queue<City> cities;
    finishedCities = 0;
}

void Game::init(){
    cout << "##################################" << endl;
    cout << "## WELCOME TO THE AMAZING RACE! ##" << endl;
    cout << "##################################" << endl;

    string teamFileName, cityFileName;
    ifstream teamFile, cityFile;
    while (!teamFile.is_open()){
        cout << "Enter team list file name: ";
        getline(cin, teamFileName);
        teamFile.open(teamFileName.c_str());
        if (!teamFile.is_open())
            cout << "Invalid file name." << endl;
    }
    while(!cityFile.is_open()){
        cout << endl << "Enter city list file name: ";
        getline(cin, cityFileName);
        cityFile.open(cityFileName.c_str());
        if (!cityFile.is_open())
            cout << "Invalid file name." << endl;
    }
    bool done = false;
    while (!done){
        string nextCity;
        if (getline(cityFile, nextCity)){
            City * temp = new City(nextCity);
            cities.enqueue(temp);
        }
        else
            done = true;
    }
    done = false;
    while (!done){
        string nextTeam;
        if (getline(teamFile, nextTeam)){
            Team * newTeam = new Team(nextTeam);
            running.enqueue(newTeam);
            teams.add(newTeam);
            nextTeam = "";
        }
        else
            done = true;
    }
    teamFile.close();
    cityFile.close();
    cout << endl;
}

void Game::printAllTeams(){
    Linked<Team> * teamList = new Linked<Team>();
    while (!running.isEmpty()){
        Team * tmp = running.dequeue();
        teamList->add(tmp);
    }
    teamList->moveToHead();
    char space = ' ';
    int teamWidth = 20;
    int roundWidth = 10;
    string roundStr;
    cout << left << setw(teamWidth) << setfill(space) << "Teams";
    for (int i = 1; i <= cities.getSize(); i++){
        stringstream ss;
        ss << "Round " << i;
        roundStr = ss.str();
        cout << left << setw(roundWidth) << setfill(space) << roundStr;
    }
    cout << endl << endl;

    for (int x = 0; x < teamList->getSize(); x++){
        Team * tmp = teamList->get();
        tmp->print();
        running.enqueue(tmp);
        teamList->advance();
    }
    cout << endl;
    delete teamList;
}

void Game::advanceTeams(){
    Linked<Team> * teamList = new Linked<Team>();
    while (!running.isEmpty()){
        Team * thisTeam = running.dequeue();
        thisTeam->addTime();
        teamList->add(thisTeam);
    }
    for (int x = 0; x < teamList->getSize(); x++){
        Team * thisTeam = teamList->get();
        running.enqueue(teamList->get());
        teamList->advance();
    }
    delete teamList;
    finishedCities++;
    sortTeams();
}

void Game::sortTeams(){
    Linked<Team> * teamList = new Linked<Team>();
    Team * hold;
    while (!running.isEmpty()){
        hold = running.dequeue();
        teamList->add(hold);
    }
    int numOfTeams = teamList->getSize();
    for(int i = 1; i <= numOfTeams; i++){
        if (i == numOfTeams){
            City * cPtr = cities.dequeue();
            cout << "The " << teamList->get()->getName() << " were the last team to reach " << cPtr->getName() << "." << endl << endl;
            cities.enqueue(cPtr);
            if (finishedCities < cities.getSize()){
                deactivateTeam(teamList->get());
                teamList->remove();
            } else {
                running.enqueue(teamList->remove());
            }
        }
        else{
            teamList->moveToHead();
            Team * smallest;
            int least = 999999;
            int saveMoves = 0;
            for (int x = 0; x < teamList->getSize(); x++){
                if (teamList->get()->getTotalTime() < least){
                    smallest = teamList->get();
                    least = smallest->getTotalTime();
                    saveMoves = x;
                }
                teamList->advance();
            }     

            teamList->moveToHead();
            for (int x = 0; x < saveMoves; x++)
                teamList->advance();
            teamList->remove();
            running.enqueue(smallest);
        }
    }
    delete teamList;
}

void Game::printResults(){
    Queue<Team> finalists;
    /*teams.moveToHead();
      for (int i = 0; i < teams.getSize(); i++){
      Team * tmp = teams.get();
      Linked<Integer> times = tmp->get*/
    int finalistCount = running.getSize();
    for (int x = 0; x < finalistCount; x++){
        if (finalists.isEmpty())
            finalists.enqueue(running.dequeue());
        else{
            Queue<Team> * tmp = new Queue<Team>();
            while (!finalists.isEmpty())
                tmp->enqueue(finalists.dequeue());
            finalists.enqueue(running.dequeue());
            while (!tmp->isEmpty())
                finalists.enqueue(tmp->dequeue());
            delete tmp;
        }
    }


    stringstream ss;
    Team * winner;

    ss << "The final " << finalistCount << " teams are: ";
    for (int x = 0; x < finalistCount; x++){
        Team * temp = finalists.dequeue();
        if (x == (finalistCount - 1)){
            ss << "and the " << temp->getName() << " . . . and the winner of the million dollars is the ";
            winner = temp;
        } else {
            ss << "the " << temp->getName() << ", ";
        }
        deactivateTeam(temp);
    } 

    ss << winner->getName() << "!!!";
    string winStr = ss.str();
    cout << winStr << endl << endl;

    char space = ' ';
    int teamWidth = 20;
    int roundWidth = 10;
    string roundStr;
    cout << left << setw(teamWidth) << setfill(space) << "Teams";
    for (int i = 1; i <= cities.getSize(); i++){
        stringstream ss;
        ss << "Round " << i;
        roundStr = ss.str();
        cout << left << setw(roundWidth) << setfill(space) << roundStr;
    }
    cout << endl << endl;

    while(!finished.isEmpty())
        finished.dequeue()->print();
    cout << endl << endl;

    cout << "##################################" << endl;
    cout << "##     THANKS FOR PLAYING!      ##" << endl;
    cout << "##################################" << endl << endl;

}

int Game::getCityCount(){
    return cities.getSize();
}

void Game::deactivateTeam(Team * t){
    if (finished.isEmpty())
        finished.enqueue(t);
    else{
        Queue<Team> * tmp = new Queue<Team>();
        tmp->enqueue(t);
        while(!finished.isEmpty())
            tmp->enqueue(finished.dequeue());
        while(!tmp->isEmpty())
            finished.enqueue(tmp->dequeue());
        delete tmp;

    }

}
#endif
