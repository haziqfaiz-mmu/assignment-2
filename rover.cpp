#include "rover.h"
#include "include.h"

using namespace std;

Rover::Rover(Map &Mars){

    p_mars = &Mars;
    gold = 0;
    score = 0;
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
    p_mars->setObject(x,y,roverSymbol);
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
        if(p_mars->isInsideMap(x,y+1))
        y = y+1;
        else
        y = 1;
        break;
    case '>':
        //check for hills
        if(p_mars->isHill(x+1, y)){
        hillFlag = true;
        break;
        }
        if(p_mars->isInsideMap(x+1,y))
        x =x+1;
        else
        x = 1;
        break;
    case 'V':
        //check for hills
        if(p_mars->isHill(x, y-1)){
        hillFlag = true;
        break;
        }
        if(p_mars->isInsideMap(x,y-1))
        y=y-1;
        else
        y = 10;
        break;
    case '<':
        //check for hills
        if(p_mars->isHill(x-1, y)){
        hillFlag = true;
        break;
        }
        if(p_mars->isInsideMap(x-1,y))
        x=x-1;
        else
        x = 15;
        break;
    }


    p_mars->setObject(tempx,tempy,' ');
    p_mars->setObject(x,y,roverSymbol);
}
void Rover::displayMapper(){

    p_mars->display();
}


void Rover::executeCommand(){

    cout<<"Misssion: Get all the golds!! Do not get trapped!!"<<endl;
    cout<<"L = Turn Left, R = Turn Right, M = Move, Q = Quit"<<endl;
    cout<<"@ = Hill, # = Trap, * = Gold"<<endl<<endl;

    cout<<"Total Command Sequences =  "<<totalCommandSequence<<" [S]"<<endl;
    cout<<"Total Commands = "<<totalCommand<<" [C]"<<endl;
    cout<<"Total Golds = "<<gold<<" [G]"<<endl;
    cout<<"Total Score = [G] X 50 - [S] X 5 - [C] X 1 = "<<score<<endl<<endl;
    
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

        

        
    

    }
