#include <iostream>
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

void State::init(){
    set(getRandomEmptyCell(flat_values),get2or4());
    set(getRandomEmptyCell(flat_values),get2or4());    }

void State::render(){
    for (int i = 0; i < BOARD_DIM; i++)
       for (int j = 0; j < BOARD_DIM; j++)

          std::cout << values[i][j] << " \n"[j == BOARD_DIM-1]; 
}
