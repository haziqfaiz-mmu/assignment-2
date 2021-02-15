#ifndef MAP_H
#define MAP_H
#include <vector>
using namespace std;

class Map{
    private:
        vector<vector<char>> map;
        int dimX, dimY;

    public:
        Map(int dimx, int dimy);
        void resize(int dimx, int dimy, char ch);
        void display();
        void setObject(int x, int y, char ch);
        void getObject(int x, int y);
        bool isEmpty(int x, int y);
        bool isHill(int x, int y);
        bool isTrap(int x, int y);
        bool isInsideMap(int x, int y);
        int getDiimX();
        int getDimY();
};

#endif