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

    printw("PRESS ANY KEY TO START");
    refresh();

    while(!state->isWon() && !state->isJam()){
       int  c = 0;

        switch((c=getch())) {
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
    }

    if(state->isWon()){
        printw("YOU WON!!!\n");
    }
    else
        printw("YOU LOST!!!\n");
    refresh();

    delete state;
    state = NULL;
}
