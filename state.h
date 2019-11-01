#include <vector>
#include "setting.h"
#include "utils.h"
#pragma once
class State{

    int values[BOARD_DIM][BOARD_DIM];
    public : 
    int *flat_values;
    void set(int position,int value);
    void drop();
    std::vector<int> getStack(int tab,Direction direction, Order order);
    void putStack(std::vector<int> stack,int tab,Direction direction,Order order);
    
    public :
        State();

        void init();
        bool isWon();
        bool isJam();

        int moveUp();
        int moveDown();
        int moveRight();
        int moveLeft();

        void render();


        
};
