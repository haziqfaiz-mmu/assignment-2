#ifndef ROVER_H
#define ROVER_H
#include "map.h"

enum Direction{
    north = 0,
    east = 1,
    south =2,
    west = 3
};

class Rover{
    private:
        int x,y;
        Direction direction;
        char roverSymbol;
        char objectUnderRover;
        Map *p_mars;//points to the real map
        Map mapper;//map that we actually display
        int gold;
        int score;
        int numOfMoves;
        string command;
        int totalCommand, totalCommandSequence;


    public:
    Rover(Map &Mars);
    void land();//done
    void turnLeft();//done
    void turnRight();//done
    void move();//add check for hills
    void displayMapper();

    void executeCommand();
};


#endif