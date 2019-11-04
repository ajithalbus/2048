#include <iostream>
#include "game.h"
#include <ncurses.h>
Game::Game(){
    score = 0;
    state = NULL;
    initscr();
    noecho();
    keypad(stdscr, TRUE);
    cbreak();
}

int sendInput(int i){
    switch(i%4){
        case 0: return KEY_UP;
        case 1: return KEY_RIGHT;
        case 2: return KEY_DOWN;
        case 3: return KEY_LEFT;
    }
}
void Game::play(){
    if(state == NULL){
        state = new State;
        state->init();
    }

    printw("PRESS ANY KEY TO START");
    refresh();
    int i=0;
    while(!state->isWon() && !state->isJam()){
       int  c = 0;

        switch((c=sendInput(i))) {
        case KEY_UP:
            score += state->moveUp();
            break;
        case KEY_DOWN:
            score += state->moveDown();
            break;
        case KEY_LEFT:
            score += state->moveLeft();
            break;
        case KEY_RIGHT:
            score += state->moveRight();
            break;
        default:
            break;
        }
        clear();
        printw("SCORE : %5d\n",score);
        state->render();
        
        refresh();
        i++;
    }

    if(state->isWon())
        printw("YOU WON!!!\n");
    if(state->isJam())
        printw("YOU LOST!!!\n");
    refresh();

    delete state;
    state = NULL;
}
