#include "INIT.h"
void global_init(void){
    init_carre(UP);
    init_carre(DOWN);
    init_carre(LEFT);
    init_carre(RIGHT);
    init_carre(FRONT);
    init_carre(BACK);
}
void init_carre(carre_t *carre)
{
    int i;
    if(carre==UP){
        i=0;
        for(int j=0; j<9; j++)
        {
            (carre+j)->color=WHITE;
            //(carre+j)->face=face_up;
        }
    }
    else if(carre==DOWN){
        i=9;
        for(int j=0; j<9; j++)
        {
            (carre+j)->color=BLUE;
            //(carre+j)->face=face_down;
        }
    }
    else if(carre==LEFT){
        i=18;
        for(int j=0; j<9; j++)
        {
            (carre+j)->color=ORANGE;
            //(carre+j)->face=face_left;
        }
    }
    else if(carre==RIGHT){
        i=27;
        for(int j=0; j<9; j++)
        {
            (carre+j)->color=YELLOW;
            //(carre+j)->face=face_right;
        }
    }
    else if(carre==FRONT){
        i=36;
        for(int j=0; j<9; j++)
        {
            (carre+j)->color=GREEN;
            //(carre+j)->face=face_front;
        }
    }
    else if(carre==BACK){
        i=45;
        for(int j=0; j<9; j++)
        {
            (carre+j)->color=RED;
            //(carre+j)->face=face_back;
        }
    }


    for(int j=0; j<9; j++)
    {
        carre[j].id=j+i;
    }
}
