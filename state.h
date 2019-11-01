#include "setting.h"
class State{

    int values[BOARD_DIM][BOARD_DIM];
    public : 
    int *flat_values;
    void set(int position,int value);

    public :
        State();

        void init();
        bool isWon();
        bool isJam();

        int moveUp();
        int moveDown();
        int moveRight();
        int moveLeft();

        void render();


        
};
