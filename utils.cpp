#include "setting.h"
#include "utils.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

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

void runGravity(std::vector<int> &stack){
    std::fill(std::remove(stack.begin(),stack.end(),0),stack.end(),0);

    for(int i = 1;i < stack.size();i++){
        if(stack[i] == stack[i-1]){
            stack[i-1]*=2;
            stack[i]=0;
        }
    }

    std::fill(std::remove(stack.begin(),stack.end(),0),stack.end(),0);
}
