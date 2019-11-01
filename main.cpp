#include <iostream>
#include "setting.h"
#include "state.h"
#include "utils.h"
using namespace std;

int main(){
    State state;
    initSeed();
    state.init();
    state.render();
    cout<<"\n";
    //for(int i =0 ;i<10;i++)
        state.moveLeft();
        state.render();
}
