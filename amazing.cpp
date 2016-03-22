
#include "game.h"

int main(){
    Game * thisGame = new Game();
    thisGame->init();
    thisGame->printAllTeams();
    thisGame->advanceTeams();
    thisGame->printAllTeams();
    return 0;
}
