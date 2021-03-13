#include "include.h"
#include "map.h"
#include "rover.h"
#include "game.h"

using namespace std;

int main(){

    Map Mars;
    Rover Curiosity(Mars);
    Game game(Mars);
    char decision;

    Curiosity.land();
    game.startsequence();
    
    while(Curiosity.getAvailableMoves() > 0 && Curiosity.getCommandFlag() && Curiosity.getRemainingGold()!=0){
        Curiosity.displayMapper();
        Curiosity.executeCommand();
    }

    if(Curiosity.getRemainingGold() == 0)
        game.successSequence(Curiosity.getScore());
    else
        game.gameOverSequence(Curiosity.getScore());

    game.displayRealMap();
    
    return 0;
}