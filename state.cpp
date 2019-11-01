#include <ncurses.h>
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
           printw("%4i%c",values[i][j]," \n"[j == BOARD_DIM-1]); 
}

std::vector<int> State::getStack(int tab,Direction direction, Order order){
    std::vector<int> stack;
    if(direction == HORIZONTAL){
        stack.insert(stack.begin(),values[tab],values[tab]+BOARD_DIM);
    }
    else{
        for(int i = 0;i < BOARD_DIM;i++){
            stack.push_back(values[i][tab]);
        }
    }
        
    if(order == REVERSE){
        std::reverse(stack.begin(),stack.end());
    }
        
    return stack;
}

void State::putStack(std::vector<int> stack,int tab,Direction direction,Order order){

    if(order == REVERSE){
        std::reverse(stack.begin(),stack.end());
    }
    if(direction == HORIZONTAL){
        for(int i = 0;i < BOARD_DIM;i++){
            values[tab][i]=stack[i];
        }
    }
    else{
        for(int i = 0;i < BOARD_DIM;i++){
            values[i][tab]=stack[i];
        }
    }
        
        
}

int State::moveUp(){

    int score = 0;
    
    for(int i = 0 ;i < BOARD_DIM;i++){
        std::vector<int> stack = getStack(i,VERTICAL,FORWARD);
        score += runGravity(stack);
        putStack(stack,i,VERTICAL,FORWARD);
    }
    drop();
    return score;
}
int State::moveDown(){

    int score = 0;
    
    for(int i = 0 ;i < BOARD_DIM;i++){
        std::vector<int> stack = getStack(i,VERTICAL,REVERSE);
        score += runGravity(stack);
        putStack(stack,i,VERTICAL,REVERSE);
    }
    drop();
    return score;
}

int State::moveRight(){

    int score = 0;
    
    for(int i = 0 ;i < BOARD_DIM;i++){
        std::vector<int> stack = getStack(i,HORIZONTAL,REVERSE);
        score += runGravity(stack);
        putStack(stack,i,HORIZONTAL,REVERSE);
    }
    drop();
    return score;
}
int State::moveLeft(){

    int score = 0;
    
    for(int i = 0 ;i < BOARD_DIM;i++){
        std::vector<int> stack = getStack(i,HORIZONTAL,FORWARD);
        score += runGravity(stack);
        putStack(stack,i,HORIZONTAL,FORWARD);
    }
    drop();
    return score;
}


