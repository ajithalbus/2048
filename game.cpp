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

void Game::play(){
    if(state == NULL){
        state = new State;
        state->init();
    }

    while(state->isWon() || state->isJam()){
       int  c = 0;

        switch((c=getch())) {
        case KEY_UP:
            state->moveUp();
            break;
        case KEY_DOWN:
            state->moveDown();
            break;
        case KEY_LEFT:
            state->moveLeft();
            break;
        case KEY_RIGHT:
            state->moveRight();
            break;
        default:
            break;
        }
        clear();
        state->render();
        refresh();
    }

    delete state;
    state = NULL;
}
