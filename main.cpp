#include <iostream>
#include "setting.h"
#include "state.h"
#include "utils.h"
using namespace std;

int main(){
    State state;
    cout<<"hello";
    initSeed();
    for(int i =0 ;i<10;i++)
        cout<<get2or4();
}
