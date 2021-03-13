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
    getTotalGoldInMap();
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
        if(p_mars->isGold(x,y)){
            gold = gold+1;
            totalGoldInMap = totalGoldInMap -1;
            }   
        //check for booster after the rover moved
        if(p_mars->isBooster(x,y))
            availableMoves = availableMoves+5;
        //check for trap after the rover moved
        if(p_mars->isTrap(x,y)){
            availableMoves = availableMoves - 10;
            trapFlag = true;
            break;}

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
        if(p_mars->isGold(x,y)){
            gold = gold+1;
            totalGoldInMap = totalGoldInMap -1;
            }   
        //check for booster after the rover moved
        if(p_mars->isBooster(x,y))
            availableMoves = availableMoves+5;
        //check for trap after the rover moved
        if(p_mars->isTrap(x,y)){
            availableMoves = availableMoves - 10;
            trapFlag = true;
            break;}

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
        if(p_mars->isGold(x,y)){
            gold = gold+1;
            totalGoldInMap = totalGoldInMap -1;
            }   
        //check for booster after the rover moved
        if(p_mars->isBooster(x,y))
            availableMoves = availableMoves+5;
        //check for trap after the rover moved
        if(p_mars->isTrap(x,y)){
            availableMoves = availableMoves - 10;
            trapFlag = true;
            break;}
            
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
        if(p_mars->isGold(x,y)){
            gold = gold+1;
            totalGoldInMap = totalGoldInMap -1;
            }   
        //check for booster after the rover moved
        if(p_mars->isBooster(x,y))
            availableMoves = availableMoves+5;
        //check for trap after the rover moved
        if(p_mars->isTrap(x,y)){
            availableMoves = availableMoves - 10;
            trapFlag = true;
            break;}

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

//display the player map contained in the mapper object
void Rover::displayMapper(){
    
    system("clear");

    for(int i=0; i<mapper.getDimY(); ++i){
    cout<<" ";
        for(int j=0;j<2*mapper.getDimX(); ++j){
            cout<<BOLDRED<<"+-"<<WHITE;
        }
        cout<<BOLDRED<<"+"<<WHITE<<endl;
        cout<<setw(2)<<(mapper.getDimY()-i);

        for(int j=0; j<mapper.getDimX();++j){
            if(mapper.getObjectArray(i,j) == 'I'){
                if(p_mars->getObjectArray(i,j) == '$'){
                    cout<<BOLDRED<<"| "<<BOLDYELLOW<<p_mars->getObjectArray(i,j)<<WHITE<<" ";
                }

                else if(p_mars->getObjectArray(i,j) == '@'){
                    cout<<BOLDRED<<"| "<<BOLDMAGENTA<<p_mars->getObjectArray(i,j)<<WHITE<<" ";
                }

                else if(p_mars->getObjectArray(i,j) == 'X'){
                    cout<<BOLDRED<<"| "<<BOLDGREEN<<p_mars->getObjectArray(i,j)<<WHITE<<" ";
                }

                else if(p_mars->getObjectArray(i,j) == '#'){
                    cout<<BOLDRED<<"| "<<RED<<p_mars->getObjectArray(i,j)<<WHITE<<" ";
                }

                else if(p_mars->getObjectArray(i,j) == '<'||p_mars->getObjectArray(i,j) == '^'||p_mars->getObjectArray(i,j) == '>'||p_mars->getObjectArray(i,j) == 'V'){
                    cout<<BOLDRED<<"| "<<BOLDBLUE<<p_mars->getObjectArray(i,j)<<WHITE<<" ";
                }

                else
                    cout<<BOLDRED<<"| "<<WHITE<<p_mars->getObjectArray(i,j)<<" ";
            }

            else
                cout<<BOLDRED<<"| "<<WHITE<<'?'<<WHITE<<" ";
        }
        cout<<BOLDRED<<"|"<<WHITE<<endl;
    }

    cout<<" ";
    for(int j=0;j<2*mapper.getDimX();++j){
        cout<<BOLDRED<<"+-"<<WHITE;
    }
    cout<<BOLDRED<<"+"<<WHITE<<endl;

    cout<<" ";
    for(int j=0; j<mapper.getDimX(); ++j){
        int digit = (j+1);
        cout<<" ";
        if(digit==0)
            cout<<" ";
        else
            cout<<setw(3)<<digit;
    }
    cout<<endl;

    cout<<endl<<endl;
}

//get the current score
int Rover::getScore(){
    return score;
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

//get command flag to know when to stop
bool Rover::getCommandFlag(){
    return commandFlag;
}

//get the total number of gold spawned in the map
int Rover::getTotalGoldInMap(){

    for(int i=0;i<mapper.getDimY();++i){
        for(int j=0;j<mapper.getDimX();++j){
            if(p_mars->getObjectArray(i,j) == '$')
                totalGoldInMap++;
        }
    }
    return totalGoldInMap;
}

//get remaining gold in the map
int Rover::getRemainingGold(){
    return totalGoldInMap;
}

//execute command after asking input from player
void Rover::executeCommand(){

    cout<<"Misssion: Get all the golds!! Remember traps will cost you 10 move points!!"<<endl;
    cout<<"L = Turn Left, R = Turn Right, M = Move, Q = Quit"<<endl;
    cout<<BOLDMAGENTA<<"@"<<WHITE<< " = Hill, "<<RED<<"#"<<WHITE<<" = Trap, "<<BOLDYELLOW<<"$"<<WHITE<<" = Gold, "<<"Booster ="<<BOLDGREEN<<" X"<<WHITE<<endl<<endl;

    cout<<"Total Command Sequences =  "<<BOLDBLUE<<totalCommandSequence<<WHITE<<" [S]\t\t\t";
    cout<<"Total Commands = "<<BOLDBLUE<<numOfMoves<<WHITE<<" [C]"<<endl;
    cout<<"Total Golds = "<<BOLDBLUE<<gold<<WHITE<<" [G]\t\t\t";
    cout<<"Total Score = [G] X 50 - [S] X 5 - [C] X 1 = "<<BOLDBLUE<<score<<WHITE<<endl;
    cout<<"Total Available Moves ="<<BOLDBLUE<<availableMoves<<WHITE<<endl<<endl;
    cout<<"Total Gold Left ="<<BOLDBLUE<<totalGoldInMap<<WHITE<<endl<<endl;
    
    cout<<"Example Sequence: LMMMLRLLMRMLRLRLMLRMLR"<<endl;

    if(hillFlag == true){
        cout<<RED<<"You can't go over a hill!!"<<WHITE<<endl;
        hillFlag = false;
    }

    if(trapFlag == true){
        cout<<RED<<"You hit a trap!! This will cost you 10 move points"<<WHITE<<endl;
        trapFlag = false;
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
        case 'Q':
            commandFlag = false;
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
