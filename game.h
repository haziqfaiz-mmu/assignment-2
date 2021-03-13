#include "include.h"
#include "map.h"
using namespace std;

class Game{
    public:
        void WelcomeLights();
        void alien();
        void startsequence();
        void EndingLights(int x);
        void gameOver();
        void gameOverSequence(int x);
        void displayRealMap();
        Game(Map &mars);
    private:
        Map *p_mars;

};

