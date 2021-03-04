#include "include.h"
#include "map.h"
#include "rover.h"

using namespace std;

int main(){

    Map Mars;
    Rover Curiosity(Mars);
    int i{0};

    Curiosity.land();
    Curiosity.displayMapper();
    while(i<100){
    Curiosity.move();++i;}
    Curiosity.displayMapper();
    Curiosity.executeCommand();
    
    
    

    return 0;
}