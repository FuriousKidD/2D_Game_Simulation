#ifndef FORESTSPACE_H_INCLUDED
#define FORESTSPACE_H_INCLUDED

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <string>
#include <cctype>

using namespace std;


namespace forestSpace{

    typedef char** twoD;
    typedef char* oneD;
    typedef int* oneMD;

    //Game Obstacles
    const char DEFAULT = 'U'; //
    const char TREES = '^'; //Trees representation
    const char DRONE = 'O'; // Drone representation
    const char TOWER = 'C'; // Charging Tower representation
    const char T_MAP = 'M'; // Treasure map representation
    const char REMOVE = ' '; //removes the trees in search of map pieces

    const int SCAN_CHARGE = 3;
    const int MOVE_CHARGE = 1;
    const int COLLECTION_CHARGE = 2;

    //
    const int INVALID_ARGUMENTS = -1;
    const int GAME_OVER = -2;

    void clearScreen();
    int genRand(int intMin, int intMax);

    //Initializes Game world and populate with empty values
    twoD arrInitialize(int intRows, int intCol);

    //Map pieces
    void arrMaps(twoD arrGame, oneMD intMapRow, oneMD intMapCol, int intRows, int intCol, int intNumMap);

    //Populate Game world
    void arrPopulate(twoD arrGame, oneD arrMaps, int intRows, int intCol, int& intRandPRow);

    //Display Game World
    void arrDisplay(twoD arrGame, int intRows, int intCol);

    //Handle Movements
    void arrMove(twoD arrGame, int& intPRow, int& intPCol,int& intRows,
                  int& intCol, int& intCharge, int intChance, char chMovement);

    //Recharge Drone when on top of Tower
    bool droneRecharge (twoD arrGame, int intPRow, int intPCol, int intCharge);

    //Scan
    void arrScan(twoD arrGame, int& intPRow, int& intPCol);

    //Recharge
    void arrRecharge(twoD arrGame, int& intPRow, int& intPCol, int& intCharge);

}//end of ForestSpace namespace

#endif // FORESTSPACE_H_INCLUDED
