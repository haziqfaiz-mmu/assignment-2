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


    public:
    Rover();
    void land(Map &Mars);
    void turnLeft(Map &Mars);
    void turnRight(Map &Mars);
    bool move();
    void displayMapper();
    bool executeCommand();
};


#endif