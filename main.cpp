#include <iostream>
#include "utils.h"
#include "game.h"
using namespace std;

int main(){
    initSeed();
    /*State state;
    state.init();
    state.render();
    cout<<"\n";
    //for(int i =0 ;i<10;i++)
        state.moveLeft();
        state.render();
        state.moveUp();
        state.render();
        state.moveRight();
        
        state.render();
        state.moveDown();
        state.render();*/

    Game game;
    game.play();
}
