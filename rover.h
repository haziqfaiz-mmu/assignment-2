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
        Direction heading;
        char objectUnderRover;
        Map *p_mars;
        Map mapper;

    public:
    Rover();
    void land(Map &Mars);
    bool turnLeft();
    bool turnRight();
    bool move();
    void displayMapper();
    bool executeCommand();
};


#endif