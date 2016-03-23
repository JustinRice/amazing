
#include "game.h"

int main(){
    Game * thisGame = new Game();
    thisGame->init();
    for (int i = 0; i < thisGame->getCityCount(); i++){
        thisGame->advanceTeams();
    }
    thisGame->printResults();

    return 0;
}
