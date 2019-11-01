#include <iostream>
#include <vector>
#include "state.h"
#include "setting.h"
#include "utils.h"

State::State(){
    flat_values = (int *) values;
    std::fill(flat_values,flat_values+GRID_SIZE,0);
}

void State::set(int position,int value){
    flat_values[position] = value;
}

void State::drop(){
    set(getRandomEmptyCell(flat_values),get2or4());
}

void State::init(){
    drop();
    drop();
}

bool State::isWon(){
    if(std::count(flat_values,flat_values+GRID_SIZE,GAME) != 0)
        return true;
    return false;
}

bool State::isJam(){
    if(std::count(flat_values,flat_values+GRID_SIZE,0) != 0)
        return true;
    return false;
}

void State::render(){
    for (int i = 0; i < BOARD_DIM; i++)
       for (int j = 0; j < BOARD_DIM; j++)
           std::cout << values[i][j] << " \n"[j == BOARD_DIM-1]; 
}

std::vector<int> State::getStack(int tab,Direction direction, Order order){
    std::vector<int> stack;
    return stack;
}

void State::putStack(std::vector<int> stack,int tab,Direction direction,Order order){
}


int State::moveLeft(){
    
    for(int i = 0 ;i < BOARD_DIM;i++){
        std::vector<int> stack = getStack(i,HORIZONTAL,FORWARD);
        runGravity(stack);
        putStack(stack,i,HORIZONTAL,FORWARD);
    }
    return 0;
}


