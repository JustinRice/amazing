/*Lisa Carter
  Justin Rice
  Section 1*/

#include <string>
#include <stdlib.h>
#include "linked.h"
#include "integer.h"
#include <sstream>
#include <iostream>
#include <iomanip>

#ifndef TEAM_H_
#define TEAM_H_

class Team{
    public:
        Team(string n);
        string getName();
        int addTime();
        int getStops();
        void print();
        static bool randSeeded;
        static int getRandomTime();
        string getTimeString();
        int getTotalTime();
    private:
        string name;
        Linked<Integer> raceTimes;
};

using namespace std;

bool Team::randSeeded = false;

Team::Team(string n){
    name = n;
    Linked<Integer> raceTimes;
    if (!randSeeded){
        srand(time(NULL));
        randSeeded = true;
    }
}

string Team::getName(){
    return name;
}  

int Team::addTime(){
    int time = getRandomTime();
    Integer * thistime = new Integer(time);
    raceTimes.add(thistime);
    return time;
}

int Team::getStops(){
    return raceTimes.getSize();
}

void Team::print(){
    char space = ' ';
    string temp = "";
    int nameWidth = 20;
    int timeWidth = 10;
    if (name.length() > 19){
        string shortName = name.substr(0, 16);
        shortName += "...";
        cout << left << setw(nameWidth) << setfill(space) << shortName;
    } else {
        cout << left << setw(nameWidth) << setfill(space) << name;
    }
    raceTimes.moveToHead();
    for (int i = 0; i < raceTimes.getSize(); i++){
        temp = getTimeString();
        raceTimes.advance();
        cout << left << setw(timeWidth) << setfill(space) << temp;
    }
    cout << endl;
}
        
        
int Team::getRandomTime(){
    int time = rand() % 1140 + 300;
    return time;
}

int Team::getTotalTime(){
    int total = 0;
    raceTimes.moveToHead();
    for (int i = 0; i < raceTimes.getSize(); i++){
        Integer * tmp = raceTimes.get();
        total += tmp->get();
        raceTimes.advance();
    }
    return total;
}

string Team::getTimeString(){
    //iterate through linked list and get time
    int time;
    string timestr;
    Integer * tmp = raceTimes.get();
    //cout << tmp->get() << endl;
    time = tmp->get();
    int hours = time/60;
    int min = time %60;
    stringstream ss;
    ss << hours << "h " << min << "m";
    timestr += ss.str();
 
    return timestr;
}



#endif
