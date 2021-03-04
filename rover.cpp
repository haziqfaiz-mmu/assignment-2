#include "rover.h"
#include "include.h"

using namespace std;

Rover::Rover(Map &Mars){

    p_mars = &Mars;
    gold = 0;
    score = 0;
    availableMoves = 50;
    numOfMoves = 0;
    totalCommandSequence = 0;
    mapper.emptyMap();
}

void Rover::land(){

    x = rand() %p_mars->getDimX()+1;
    y = rand() % p_mars->getDimY()+1;
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
    //set rover on the real map
    p_mars->setObject(x,y,roverSymbol);
    //mark the player's map
    markMap(x,y);
}

//mark the mapper with 'I' after visited by rover
void Rover::markMap(int x, int y){
    mapper.setObject(x,y,'I');
    mapper.setObject(x+1,y,'I');
    mapper.setObject(x-1,y,'I');
    mapper.setObject(x,y+1,'I');
    mapper.setObject(x,y-1,'I');
}

//turn left
void Rover::turnLeft(){

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
    numOfMoves = numOfMoves +1;
    p_mars->setObject(x,y,roverSymbol);
}
void Rover::turnRight(){

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
    numOfMoves = numOfMoves +1;
    p_mars->setObject(x,y,roverSymbol);
}

void Rover::move(){

    int tempx, tempy;

    tempx=x;
    tempy=y;

    switch (roverSymbol)
    {
    case '^':
        //check for hills
        if(p_mars->isHill(x, (y+1)%10)){
        hillFlag = true;
        break;
        }
        //check if inside map before moving
        if(p_mars->isInsideMap(x,y+1))
            y = y+1;
        else
            y = 1;
        //increment number of moves
        numOfMoves = numOfMoves +1;
        //decrease number of moves avaiable
        availableMoves  = availableMoves -1;
        //check for gold after the rover moved
        if(p_mars->isGold(x,y))
            gold = gold+1;
        //check for booster after the rover moved
        if(p_mars->isBooster(x,y))
            availableMoves = availableMoves+5;
        //check for trap after the rover moved
        if(p_mars->isTrap(x,y))
            availableMoves = availableMoves - 10;
        break;
    case '>':
        //check for hills before moving
        if(p_mars->isHill(x+1, y)){
        hillFlag = true;
        break;
        }
        //check if inside map before moving
        if(p_mars->isInsideMap(x+1,y))
        x =x+1;
        else
        x = 1;
        //increment number of moves
        numOfMoves = numOfMoves +1;
        //decrease number of moves avaiable
        availableMoves  = availableMoves -1;
        //check for gold after the rover moved
        if(p_mars->isGold(x,y))
            gold = gold+1;
        //check for booster after the rover moved
        if(p_mars->isBooster(x,y))
            availableMoves = availableMoves+5;
        //check for trap after the rover moved
        if(p_mars->isTrap(x,y))
            availableMoves = availableMoves - 10;
        break;
    case 'V':
        //check for hills
        if(p_mars->isHill(x, y-1)){
        hillFlag = true;
        break;
        }
        //check if inside map before moving
        if(p_mars->isInsideMap(x,y-1))
        y=y-1;
        else
        y = 10;
        //increment number of moves
        numOfMoves = numOfMoves +1;
        //decrease number of moves avaiable
        availableMoves  = availableMoves -1;
        //check for gold after the rover moved
        if(p_mars->isGold(x,y))
            gold = gold+1;
        //check for booster after the rover moved
        if(p_mars->isBooster(x,y))
            availableMoves = availableMoves+5;
        //check for trap after the rover moved
        if(p_mars->isTrap(x,y))
            availableMoves = availableMoves - 10;
        break;
    case '<':
        //check for hills
        if(p_mars->isHill(x-1, y)){
        hillFlag = true;
        break;
        }
        //check if inside map before moving
        if(p_mars->isInsideMap(x-1,y))
        x=x-1;
        else
        x = 15;
        //increment number of moves
        numOfMoves = numOfMoves +1;
        //decrease number of moves avaiable
        availableMoves  = availableMoves -1;
        //check for gold after the rover moved
        if(p_mars->isGold(x,y))
            gold = gold+1;
        //check for booster after the rover moved
        if(p_mars->isBooster(x,y))
            availableMoves = availableMoves+5;
        //check for trap after the rover moved
        if(p_mars->isTrap(x,y))
            availableMoves = availableMoves - 10;

        break;
    }


    p_mars->setObject(tempx,tempy,' ');
    p_mars->setObject(x,y,roverSymbol);
    //mark the player's map
    markMap(x,y);
}
//display the real hidden map
void Rover::displayRealMap(){

    p_mars->display();
}

//display the player map containedd in the mapper object
void Rover::displayMapper(){
    mapper.display();
}

//get the number of available moves
int Rover::getAvailableMoves(){
    return availableMoves;
}

//calculate current score
int Rover::calcScore(int gold, int totalCommandSequence, int moves){

    int score = gold * 50 - totalCommandSequence * 5 - moves;
    return score;
}


void Rover::executeCommand(){

    cout<<"Misssion: Get all the golds!! Do not get trapped!!"<<endl;
    cout<<"L = Turn Left, R = Turn Right, M = Move, Q = Quit"<<endl;
    cout<<"@ = Hill, # = Trap, * = Gold"<<endl<<endl;

    cout<<"Total Command Sequences =  "<<totalCommandSequence<<" [S]"<<endl;
    cout<<"Total Commands = "<<numOfMoves<<" [C]"<<endl;
    cout<<"Total Golds = "<<gold<<" [G]"<<endl;
    cout<<"Total Score = [G] X 50 - [S] X 5 - [C] X 1 = "<<score<<endl;
    cout<<"Total Available Moves ="<<availableMoves<<endl<<endl;
    
    cout<<"Example Sequence: LMMLMLMLMLMLMLMLMLMLMLMML"<<endl;

    if(hillFlag == true){
        cout<<"You can't go over a hill!!"<<endl;
        hillFlag = false;
    }

    cout<<"Enter command sequence: ";
    cin>>command;

    char *ch = &command[0];
    
    while(*ch!='\0'){

        switch (*ch)
        {
        case 'M':
            move();
            break;
        case 'L':
            turnLeft();
            break;
        case 'R':
            turnRight();
            break;
        default:
            break;
        }

        ch++;
    }

    totalCommandSequence = totalCommandSequence +1;

    //update score
    score = calcScore(gold, totalCommandSequence, numOfMoves);

    }
