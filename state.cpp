#include <iostream>
#include "state.h"
#include "setting.h"
State::State(){
    flat_values = (int *) values;
    std::fill(flat_values,flat_values+GRID_SIZE,0);
}
