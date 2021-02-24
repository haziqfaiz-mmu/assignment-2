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

    Curiosity.land();
    Curiosity.displayMapper();
    //Curiosity.move();
    Curiosity.executeCommand();
    Curiosity.displayMapper();
    

    return 0;
}