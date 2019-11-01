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
int getRandomEmptyCell(int const *flat_values);

int get2or4(){
    double toss = rand_double();
    if (toss < PROB2)
        return 2;
    return 4; 
}
