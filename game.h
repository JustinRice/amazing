#ifndef GAME_H_
#define GAME_H_

#include "linked.h"
#include "queue.h"
#include "team.h"
#include <string>
#include <fstream>
#include <iostream>

class Game{
    public:
        Game();
        void init();
        void advanceTeams();
        void printResults();
        int teamsLeft();
        void deactivateTeam(Team);
        void sortTeams();
    private:
        Queue<Team> finished;
        Queue<Team> running;
        Linked<Team> teams;
        Linked<string> cities;
        int finishedCities;
};

Game::Game(){
    Queue<Team> finished;
    Queue<Team> running;
    Linked<string> finishedCities;
    Queue<string> cities;
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
            string * tmp = &nextCity;
            cities.add(tmp);
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
        }
        else
            done = true;
    }
    teamFile.close();
    cityFile.close();
}


#endif
