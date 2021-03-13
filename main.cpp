/********************************************
Course : TCP1101 Programming Fundamentals
Session: Trimester 2, 2020/21
Assignment: 2
Lecture Section : TC1V
Tutorial Section: TT1V
Name of Student #1 : MUHAMMAD HAZIQ FAIZ BIN MOHD RIPIN
ID of Student #1: 1201302740
Email of Student #1:1201302740@student.mmu.edu.my
Phone of Student #1:0132061817
Name of Student #2 : KAVIILASAN A/L GANESAN
ID of Student #2: 1181103578
Email of Student #2:1181103578
Phone of Student #2:016-2632704
********************************************/
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