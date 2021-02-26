#include "include.h"
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
    Curiosity.executeCommand();
    

    return 0;
}