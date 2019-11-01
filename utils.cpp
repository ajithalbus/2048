#include "setting.h"
#include "utils.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

double rand_double() {
   return rand()/(double)RAND_MAX;
}

double rand_double2(double x, double y) {
   return (y - x)*rand_double() + x;
}

int rand_int(int a, int b) {
   return (int)((b - a + 1)*rand_double()) + a;
}

void initSeed(){
    srand((long)time(NULL));
}

int getEmptyCellCount(int const *flat_values){
    return std::count(flat_values,flat_values+GRID_SIZE,0);
}

int getRandomEmptyCell(int const *flat_values){
    int noOfEmptyCells = getEmptyCellCount(flat_values);
    int luckyNthEmptyCell = rand_int(0,noOfEmptyCells-1);
    
    for(int i = 0;i < GRID_SIZE;i++){
        if(flat_values[i] == 0){
            if(luckyNthEmptyCell == 0)
                return i;
            else
                luckyNthEmptyCell--;
        }
    }
    
    return -1;
}


int get2or4(){
    double toss = rand_double();
    if (toss < PROB2)
        return 2;
    return 4; 
}