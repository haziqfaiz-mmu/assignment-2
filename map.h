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
        void resize(int new_dimx, int new_dimy, char ch);//not sure what this supposed to do
        void display();//done but need improvement
        void setObject(int x, int y, char ch);//done
        char getObject(int x, int y);//done
        bool isEmpty(int x, int y);//done
        bool isHill(int x, int y);//done
        bool isTrap(int x, int y);//done
        bool isInsideMap(int x, int y);//done but I want to replace it with something else
        int getDimX();
        int getDimY();
};

#endif