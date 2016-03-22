#include "qnode.h"
#include "team.h"
#include "linked.h"
#include "queue.h"
#include <string>
#include <iostream>

using namespace std;

int main(){
    Linked<Team> * myLink = new Linked<Team>();
    Queue<Team> * myQ = new Queue<Team>();
    Team * team1 = new Team("Team 1");
    Team * team2 = new Team("Team 2");
    Team * team3 = new Team("Team 3");

    myQ->enqueue(team1);
    myQ->enqueue(team2);
    myQ->enqueue(team3);

    for (int x = 0; x < 3; x ++){
        Team * temp = myQ->dequeue();
        cout << temp->getName() << endl;
    }

    cout << myQ->getSize() << endl;

    myQ->enqueue(team1);
    cout << myQ->getSize() << endl;
    Team * temp = myQ->dequeue();
    cout << temp->getName() << endl;
    cout << myQ->getSize() <<endl;

    myLink->add(team1);
    myLink->add(team2);
    myLink->add(team3);
    myLink->remove();
    myLink->moveToTail();
    temp = myLink->get();
    cout << temp->getName() << endl;
    myLink->moveToHead();
    temp = myLink->get();
    cout << temp->getName() << endl;
    myLink->advance();
    cout << myLink->getSize() << endl;
    temp = myLink->get();
    cout << temp->getName() << endl;
    myLink->remove();
    temp = myLink->get();
    cout << temp->getName() << endl;
    myLink->advance();
    temp = myLink->get();
    cout << temp->getName() << endl;
    cout << myLink->getSize() << endl;

    temp->addTime();
    temp->addTime();
    temp->addTime();
    temp->print();
    cout << temp->getTotalTime() << endl;
/*
    QNode<string> thisNode;
    string testString = "test";
    string * ptr = &testString;
    thisNode.setData(&testString);
    cout << *(thisNode.getData()) << endl;*/
    return 0;
}
