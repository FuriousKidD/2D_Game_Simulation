#include "ForestSpace.h"


namespace forestSpace{

    void clearScreen(){
        #if _WIN32
            system("cls");
        #else
            system("clear");
        #endif // _WIN32

    }//end of clear screen

    int genRand(int intMin, int intMax){
        int getRand = (rand()% intMax) + intMin;
        return getRand;
    }//end of GenRand

    //Initializes dynamic array and populate with empty values
    twoD arrInitialize(int intRows, int intCol){
        twoD arrGame = new oneD [intRows];

        for(int r = 0; r < intRows; r++){
            arrGame[r] = new char[intCol];

            //populates arrGame with initial values
            for(int c = 0; c < intCol; c++){
                arrGame[r][c] = DEFAULT;
            }//end of inner for loop
        }//end of outter for loop

        return arrGame;
    }//end of arrInitialize


    //Map pieces
    void arrMaps(twoD arrGame, oneMD intMapRow, oneMD intMapCol, int intRows, int intCol, int intNumMap){

        for(int i = 0; i < intNumMap; i++){
            bool blUnique = false;

            while(blUnique == false){
                int mapRow = genRand(0,intRows);
                int mapCol = genRand(0, intCol);

                if(arrGame[mapRow][mapCol] != TOWER){

                    intMapRow[i] = genRand(0,intRows);
                    intMapCol[i] = genRand(0,intCol);
                    blUnique = true;
                }//end of if

            }


        }//end of for loop

    }//end of arrMaps

    //Populate Game world
    void arrPopulate(twoD arrGame, oneD arrMaps, int intRows, int intCol, int& intRandPRow){

        for(int r = 0; r <intRows; r++){

            //random coloumn for Tower to be placed and must not be at the same position as the starting position for drone
            int intTPlace = genRand(0, intCol);
            if(intRandPRow == intTPlace){
                intTPlace = genRand(0, intCol);
            }//end of if

            for(int c = 0; c < intCol; c++){

                //Drone placement
                if( (r == intRandPRow) && (c == intCol - 2) ){
                    arrGame[r][c] = DRONE;
                }//end of if

                //Tower placement
                else if( (c == intTPlace) ){
                    arrGame[r][c] = TOWER;
                }//end of else if

                //Tree placement
                else {
                    arrGame[r][c] = TREES;
                }//end of else

            }//end of inner for loop
        }//end pf outter for loop
    }//end of arrpopulate

    //Display Game World
    void arrDisplay(twoD arrGame, int intRows, int intCol){

        //clears screen to display current game world
        clearScreen();

        for(int r = 0; r < intRows; r++){
            for(int c = 0; c <intCol; c++){

                cout << arrGame[r][c] << " ";

            }//end of inner for loop
            cout << endl;
        }//end of outter for loop
    }//end of arrDisplay

    void arrScan(twoD arrGame, int& intPRow, int& intPCol){

        arrGame[intPRow+1][intPCol] = REMOVE;//checks South
        arrGame[intPRow-1][intPCol] = REMOVE;//checks North

        arrGame[intPRow][intPCol+1] = REMOVE;//checks East
        arrGame[intPRow][intPCol-1] = REMOVE;//checks West

        arrGame[intPRow+1][intPCol+1] = REMOVE;//checks South East
        arrGame[intPRow+1][intPCol-1] = REMOVE;//checks South West

        arrGame[intPRow-1][intPCol+1] = REMOVE;//checks North East
        arrGame[intPRow-1][intPCol-1] = REMOVE;//checks North West

    }//end of arrScan

    //Recharges the drone when it is on top of a Tower
    void arrRecharge(twoD arrGame, int& intPRow, int& intPCol, int& intCharge){

        //Drone Recharges if on top of tower
        if(arrGame[intPRow][intPCol] == TOWER){
            intCharge = 10;
        }//end of recharge

    }//end of arrRecharge

    //Handle Movements
    void arrMove(twoD arrGame, int& intPRow, int& intPCol, int& intRows,
                int& intCol, int& intCharge, int intChance, char chMovement){


        //remove player from current position
        arrGame[intPRow][intPCol] = TREES;



        switch(chMovement){
            case 'a':
            case 'A':{
                if(intPCol > 0){

                    intPCol--;

                    //charge decreases by 1
                    intCharge -= MOVE_CHARGE;

                    //Drone Recharges if on top of tower
                    arrRecharge(arrGame, intPRow, intPCol, intCharge);

                }//end of if
                break;
            }//end of case A

            case 'w':
            case 'W':{
                if(intPRow > 0){

                    intPRow--;

                    //charge decreases by 1
                   intCharge -= MOVE_CHARGE;

                    //Drone Recharges if on top of tower
                    arrRecharge(arrGame, intPRow, intPCol, intCharge);

                }//end of if
                break;
            }//end of case W

            case 'd':
            case 'D':{
                if(intPCol < intCol-1){

                    intPCol++;

                    //charge decreases by 1
                    intCharge -= MOVE_CHARGE;

                    //Drone Recharges if on top of tower
                    arrRecharge(arrGame, intPRow, intPCol, intCharge);

                }//end of if
                break;
            }//end of case D

            case 's':
            case 'S':{
                if(intPRow < intRows -1){

                    intPRow++;

                    //charge decreases by 1
                    intCharge -= MOVE_CHARGE;

                    //Drone Recharges if on top of tower
                    arrRecharge(arrGame, intPRow, intPCol, intCharge);

                }//end of if
                break;
            }//end of case S

            case 'q':
            case 'Q':{
                if(intPRow > 0 && intPCol > 0){

                    intPRow--;
                    intPCol--;

                    //charge decreases by 1
                    intCharge -= MOVE_CHARGE;

                    //Drone Recharges if on top of tower
                    arrRecharge(arrGame, intPRow, intPCol, intCharge);

                }//end of if
                break;
            }//end of case Q

            case 'e':
            case 'E':{
                if(intPRow > 0 && intPCol < intCol - 1){

                    intPRow--;
                    intPCol++;

                    //charge decreases by 1
                    intCharge -= MOVE_CHARGE;

                    //Drone Recharges if on top of tower
                    arrRecharge(arrGame, intPRow, intPCol, intCharge);

                }//end of if
                break;
            }//end of case E

            case 'z':
            case 'Z':{
                if(intPRow < intRows - 1 && intPCol > 0){

                    intPRow++;
                    intPCol--;

                    //charge decreases by 1
                    intCharge -= MOVE_CHARGE;

                    //Drone Recharges if on top of tower
                    arrRecharge(arrGame, intPRow, intPCol, intCharge);

                }//end of if
                break;
            }//end of case Z

            case 'c':
            case 'C':{
                if(intPRow < intRows - 1 && intPCol < intCol - 1){

                    intPRow++;
                    intPCol++;

                    //charge decreases by 1
                    intCharge -= MOVE_CHARGE;

                    //Drone Recharges if on top of tower
                    arrRecharge(arrGame, intPRow, intPCol, intCharge);

                }//end of if
                break;
            }//end of case C

            //when user decides to scan the area
            case 'l':
            case 'L':{

                //Uses 3 units of charge to scan and prevents user from scanning when charge less than 3
                if(intCharge >= 3){
                    intCharge -= SCAN_CHARGE;
                    arrScan(arrGame, intPRow, intPCol);//scans for map pieces
                }//end of if

                //make a function that will put the trees back

                break;
            }//end of case L

        }//end of switch

        arrGame[intPRow][intPCol] = DRONE;

        //The chances of towers getting destroyed
        for(int r = 0; r < intRows; r++){
            for(int c = 0; c < intCol; c++){

                if(arrGame[r][c] == TOWER && (genRand(1, 100) <= intChance)){
                arrGame[r][c] = TREES;

            }//end of if

            }//end of inner for loop
        }//end of outter for loop

    }//end of arrMove

}//end of ForestSpace namespace
