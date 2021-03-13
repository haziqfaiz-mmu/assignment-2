#ifndef ROVER_H
#define ROVER_H
#include "map.h"
#include "include.h"

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
        int availableMoves;
        string command;
        int totalCommandSequence;
        bool hillFlag;
        bool trapFlag;
        bool commandFlag{true};


    public:
    Rover(Map &Mars);//constructor that accept reference to the map
    void land();//done
    void markMap(int x, int y);//mark the mapper with 'I' after visited by rover
    void turnLeft();//done
    void turnRight();//done
    void move();//done
    void displayRealMap();//done
    void displayMapper();
    int calcScore(int gold, int totalCommandSequence, int moves);//done
    int getScore();
    int getAvailableMoves();
    bool getCommandFlag();

    void executeCommand();
};


#endif