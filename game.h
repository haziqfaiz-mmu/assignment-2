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
Email of Student #2:1181103578@student.mmu.edu.my
Phone of Student #2:016-2632704
********************************************/
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
        void success();
        void successSequence(int x);
        void displayRealMap();
        Game(Map &mars);
    private:
        Map *p_mars;

};

