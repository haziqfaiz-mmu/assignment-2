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