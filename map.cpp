#include<iostream>
#include<iomanip>
#include<cstdlib>
#include<string>
#include<vector>
#include<ctime>
#include<unistd.h>
#include "map.h"
using namespace std;

//Function that is called by the constructor
void Map::init(){

    srand(time(0));
    char objects[] ={' ',' ',' ',' ',' ',' ',
                    'X','#','@','$'};
    
    int noOfObjects = 10;

    dimX = 15;
    dimY = 10;

    //create dynamic 2D array using vector
    map.resize(dimY); //create rows
    for (int i=0;i<dimY;i++){
        map[i].resize(dimX);//resize each row
    }

    //put random chars into the vector array
    for(int i=0;i<dimY; ++i){
        for(int j=0; j<dimX; ++j){
            int objNo = rand() % noOfObjects;
            map[i][j] = objects[objNo];
        }
    }
}
void Map::resize(int new_dimX, int new_dimY, char ch){

    dimX = new_dimX;
    dimY = new_dimY;
}

//display the map
void Map::display(){

    //system("cls");
    cout<<setw(15)<<" "<<"--__--__--__--__--__--__--__--_"<<endl;
    cout<<setw(15)<<" "<<"= Curiosity, welcome to Mars! ="<<endl;
    cout<<setw(15)<<" "<<"--__--__--__--__--__--__--__--_"<<endl<<endl;
    for(int i=0; i<dimY; ++i){
    cout<<" ";
        for(int j=0;j<2*dimX; ++j){
            cout<<"+-";
        }
        cout<<"+"<<endl;
        cout<<setw(2)<<(dimY-i);

        for(int j=0; j<dimX;++j){
            cout<<"| "<<map[i][j]<<" ";
        }
        cout<<"|"<<endl;
    }

    cout<<" ";
    for(int j=0;j<2*dimX;++j){
        cout<<"+-";
    }
    cout<<"+"<<endl;

    cout<<" ";
    for(int j=0; j<dimX; ++j){
        int digit = (j+1);
        cout<<" ";
        if(digit==0)
            cout<<" ";
        else
            cout<<setw(3)<<digit;
    }
    cout<<endl;

    cout<<endl<<endl;

    cout<<"Misssion: Get all the golds!! Do not get trapped!!"<<endl;
    cout<<"L = Turn Left, R = Turn Right, M = Move, Q = Quit"<<endl;
    cout<<"@ = Hill, # = Trap, * = Gold"<<endl<<endl;

    cout<<"Total Command Sequences = 0 [S]"<<endl;
    cout<<"Total Commands = 0 [C]"<<endl;
    cout<<"Total Golds = 0 [G]"<<endl;
    cout<<"Total Score = [G] X 50 - [S] X 5 - [C] X 1 = 0"<<endl<<endl;
    
    cout<<"Example Sequence: LMMLMLMLMLMLMLMLMLMLMLMML"<<endl;
    cout<<"Enter command sequence: "<<endl;
}

//set the object at coordinate x,y
void Map::setObject(int x, int y, char ch){

    map[(dimY-y)][x-1] = ch;
}

//get the object in coordinate x,y
char Map::getObject(int x, int y){

    char obj =map[dimY-y][x-1];
        return obj;
}

//check whether the cell is empty
bool Map::isEmpty(int x, int y){

    if (map[dimY-y][x-1] ==' ')
        return true;
    
    else
        return false;
}

//check for hill
bool Map::isHill(int x, int y){

    if (map[dimY-y][x-1] =='@')
        return true;
    
    else
        return false;
}

//check for trap
bool Map::isTrap(int x, int y){

    if (map[dimY-y][x-1] =='#')
        return true;
    
    else
        return false;
}

//check to see if the rover is inside the map
//doesn't make any sense, I wan to change it
bool Map::isInsideMap(int x, int y){

    if((x>=1 && x<=dimX) && (y>=1 && y<=dimY))
        return true;

    else
        return false;
}
int Map::getDimX(){

    return dimX;
}
int Map::getDimY(){

    return dimY;
}