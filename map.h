/********************************************
Course : TCP1101 Programming Fundamentals
Session: Trimester 2, 2020/21
Assignment: 2
Lecture Section : TC1V
Tutorial Section: TT1V
Name of Student #1 : MUHAMMAD HAZIQ FAIZ BIN MOHD RIPIN
ID of Student #1: 1201302740
Email of Student #1:1201302740@student.mmu.edu.my
Phone of Student #1:0132061817
Name of Student #2 : KAVIILASAN A/L GANESAN
ID of Student #2: 1181103578
Email of Student #2:1181103578
Phone of Student #2:016-2632704
********************************************/
#ifndef MAP_H
#define MAP_H
#include <vector>
using namespace std;

class Map{
    private:
        vector<vector<char>> map;
        int dimX, dimY;

    public:
        Map(){
            init();
        }
        void init();//done
        void resize(int new_dimx, int new_dimy, char ch);
        void emptyMap();//empty the map, used for the mapper
        void display();//done but need improvement
        void setObject(int x, int y, char ch);//done
        char getObject(int x, int y);//done
        char getObjectArray(int x, int y);//return char in map but not confusing
        bool isEmpty(int x, int y);//done
        bool isGold(int x, int y);//done
        bool isHill(int x, int y);//done
        bool isTrap(int x, int y);//done
        bool isBooster(int x, int y);
        bool isInsideMap(int x, int y);//done but I want to replace it with something else
        int getDimX();//done
        int getDimY();//done
};

#endif