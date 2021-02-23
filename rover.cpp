#include<iostream>
#include<iomanip>
#include<cstdlib>
#include<string>
#include<vector>
#include<ctime>
#include<unistd.h>
#include "rover.h"

using namespace std;

Rover::Rover(Map &Mars){

    p_mars = &Mars;
}

void Rover::land(Map &Mars){

    x = rand() %Mars.getDimX()+1;
    y = rand() % Mars.getDimY()+1;
    int directionValue = rand()%4;

    if(directionValue == 0){

        direction = north;
        roverSymbol = '^';
        }
    else if(directionValue ==1){
        direction = east;
        roverSymbol = '>';
        }
    else if(directionValue == 2){
        direction = south;
        roverSymbol = 'V';
        }
    else {
        direction = west;
        roverSymbol = '<';
        }
    p_mars->setObject(x,y,roverSymbol);
}

//turn left
void Rover::turnLeft(Map &Mars){

     switch (roverSymbol)
    {
    case '^':
        roverSymbol = '<';
        break;
    case '<':
        roverSymbol ='V';
        break;
    case 'V':
        roverSymbol = '>';
        break;
    case '>':
        roverSymbol = '^';
        break;
    }
    Mars.setObject(x,y,roverSymbol);
}
void Rover::turnRight(Map &Mars){

    switch (roverSymbol)
    {
    case '^':
        roverSymbol = '>';
        break;
    case '>':
        roverSymbol ='V';
        break;
    case 'V':
        roverSymbol = '<';
        break;
    case '<':
        roverSymbol = '^';
        break;
    }
    Mars.setObject(x,y,roverSymbol);
}
bool Rover::move(){return true;}
void Rover::displayMapper(){}
bool Rover::executeCommand(){return true;}