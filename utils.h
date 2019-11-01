#include <vector>
#pragma once
typedef enum {
    HORIZONTAL,
    VERTICAL
} Direction;

typedef enum {
    FORWARD,
    REVERSE
} Order;

int getRandomEmptyCell(int const *flat_values);
int get2or4(); 
void initSeed();
int runGravity(std::vector<int> &stack);
