#include "ForestSpace.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <string>

using namespace std;
using namespace forestSpace;

int main(int argc, twoD argv)
{
        srand(time(0));

    //command line argument validation
    if(argc != 5){
        cerr << "Enter " << argc << " arguments in the following order: \n "
             << "< " << argv[0] << " > " << "<Rows> <Col> <Chance %> <Number of Map Pieces> ";
             exit(INVALID_ARGUMENTS);
    }//end of if else statement

    int intRows = stoi(argv[1]);
    int intCol = stoi(argv[2]);
    int intChance = stoi(argv[3]);
    int intMapPiece = stoi(argv[4]);

    //variables
    char chMovement = '0';
    bool blContinue = true;

    int intPRow = genRand(0, intRows);;
    int intPCol = intCol-2;
    int intCharge = 10;
    int intMapCount = 0;

    int arrMapRow[intMapPiece];
    int arrMapCol[intMapPiece];

    //initialize and Display default game
    twoD arrGame = arrInitialize(intRows,intCol);
    oneD arrMaps = new char [intMapPiece];

    //Populate game world
    arrPopulate(arrGame, arrMaps, intRows, intCol,intPRow);


        //Display Game
        arrDisplay(arrGame, intRows, intCol);

    do{

        cout << "A: West \t D: East \t W: North \t S: South" << endl;
        cout << "E: North East \t Q: North West \t Z: South West \t C: South East" << endl;
        cout << "L: Scan" << endl;
		cout << "Characters:" << endl;
		cout << "^: Tree" << endl;
		cout << "O: Drone" << endl;
		cout << "C: Charging tower" << endl;
		cout << "M: Treasure map" << endl;

        //keeps track of remaining charge
        cout << "Charge: " << intCharge << endl;

        //Handle Movements
        cin >> chMovement;
        arrMove(arrGame, intPRow, intPCol, intRows, intCol, intCharge, intChance, chMovement);

        //Displays the updated Game
        arrDisplay(arrGame, intRows, intCol);

       //Displays Game over and prompts user to return to menu
        if( intCharge <= 0 ){
            cout << "CHARGE DEPLETED... GAME OVER! \n";
            exit(GAME_OVER);

        }//end of if

    }//end of do while
    while(blContinue == true);

    for(int r = 0; r < intRows; r++){
        delete [] arrGame[r];
    }//end of for loop
    delete [] arrGame;

    return 0;
}

