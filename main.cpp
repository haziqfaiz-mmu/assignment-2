#include<iostream>
#include<iomanip>
#include<cstdlib>
#include<string>
#include<vector>
#include<ctime>
#include<unistd.h>
#include "map.h"
#include "rover.h"

using namespace std;

int main(){

    Map Mars;
    Rover Curiosity(Mars);

   
    Mars.display();

    Curiosity.land(Mars);
    Mars.display();
    Curiosity.turnLeft(Mars);
    Mars.display();
    Curiosity.turnRight(Mars);
    Mars.display();

    return 0;
}