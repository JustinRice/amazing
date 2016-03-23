/*Lisa Carter
  Justin Rice
  Section 1*/

#include <string>

#ifndef CITY_H_
#define CITY_H_

class City{
    public:
        City(string n);
        string getName();
    private:
        string name;
};

using namespace std;


City::City(string n){
    name = n;
}

string City::getName(){
    return name;
}  

#endif
