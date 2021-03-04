#include "include.h"
#include "map.h"
#include "rover.h"

using namespace std;

int main(){

    Map Mars;
    Rover Curiosity(Mars);
    int i{0},j{0};

    Curiosity.land();
    
    while(Curiosity.getAvailableMoves() > 0){
        Curiosity.displayMapper();
        Curiosity.executeCommand();
    }
    
    

    return 0;
}