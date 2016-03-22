/*Lisa Carter
  Justin Rice
  Section 1*/

#include <string>
#include <stdlib.h>
#include "linked.h"
#include "integer.h"
#include <sstream>
#include <iostream>

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
    cout << "Calling racetimes add" << endl;
    raceTimes.add(thistime);
    return time;
}

int Team::getStops(){
    return raceTimes.getSize();
}

void Team::print(){
    string temp = name + "        " + getTimeString();
    cout << temp << endl;
}
        
        
int Team::getRandomTime(){
    int time = rand() % 1140 + 300;
    return time;
}

string Team::getTimeString(){
    //iterate through linked list and get time
    int time;
    string timestr;
    cout << "First here." << endl;
    cout << "Size: " << raceTimes.getSize() << endl;
    cout << "Then here." << endl;
    for (int i = 0; i < raceTimes.getSize(); i++){
        Integer * tmp = raceTimes.get();
        cout << tmp->get() << endl;
        time = tmp->get();
        int hours = time/60;
        int min = time %60;
        stringstream ss;
        ss << hours << "hrs " << min << "min     ";
        timestr += ss.str();
        raceTimes.advance();
    }
    
    return timestr;
}

 

#endif
