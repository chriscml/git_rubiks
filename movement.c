#include "movement.h"
#include "INIT.h"
#include <stdio.h>
void rotate_moove (moove_t moove )
{
    carre_t temp;
    switch(moove)
    {
    case U:
        rotate_matrice_clockwise(UP);
        printf("rotate up\n");
        temp = BACK[0];
        BACK[0]=LEFT[0];
        LEFT[0]=FRONT[0];
        FRONT[0]=RIGHT[0];
        RIGHT[0]=temp;

        temp = BACK[1];
        BACK[1]=LEFT[1];
        LEFT[1]=FRONT[1];
        FRONT[1]=RIGHT[1];
        RIGHT[1]=temp;

        temp = BACK[2];
        BACK[2]=LEFT[2];
        LEFT[2]=FRONT[2];
        FRONT[2]=RIGHT[2];
        RIGHT[2]=temp;
        break;
    case AU:
        rotate_matrice_anticlockwise(UP);
        printf("rotate up anticlockwise\n");
        temp = BACK[0];
        BACK[0]=RIGHT[0];
        RIGHT[0]=FRONT[0];
        FRONT[0]=LEFT[0];
        LEFT[0]=temp;

        temp = BACK[1];
        BACK[1]=RIGHT[1];
        RIGHT[1]=FRONT[1];
        FRONT[1]=LEFT[1];
        LEFT[1]=temp;

        temp = BACK[2];
        BACK[2]=RIGHT[2];
        RIGHT[2]=FRONT[2];
        FRONT[2]=LEFT[2];
        LEFT[2]=temp;
        break;
    case D:
        rotate_matrice_clockwise(DOWN);
        printf("rotate down\n");
        temp = BACK[6];
        BACK[6]=RIGHT[6];
        RIGHT[6]=FRONT[6];
        FRONT[6]=LEFT[6];
        LEFT[6]=temp;

        temp = BACK[7];
        BACK[7]=RIGHT[7];
        RIGHT[7]=FRONT[7];
        FRONT[7]=LEFT[7];
        LEFT[7]=temp;

        temp = BACK[8];
        BACK[8]=RIGHT[8];
        RIGHT[8]=FRONT[8];
        FRONT[8]=LEFT[8];
        LEFT[8]=temp;
        break;
    case AD:
        rotate_matrice_anticlockwise(DOWN);
        printf("rotate down anticlockwise\n");
        temp = BACK[6];
        BACK[6]=LEFT[6];
        LEFT[6]=FRONT[6];
        FRONT[6]=RIGHT[6];
        RIGHT[6]=temp;

        temp = BACK[7];
        BACK[7]=LEFT[7];
        LEFT[7]=FRONT[7];
        FRONT[7]=RIGHT[7];
        RIGHT[7]=temp;

        temp = BACK[8];
        BACK[8]=LEFT[8];
        LEFT[8]=FRONT[8];
        FRONT[8]=RIGHT[8];
        RIGHT[8]=temp;
        break;
    case L:
        rotate_matrice_clockwise(LEFT);
        printf("rotate left\n");
        temp = BACK[8];
        BACK[8]=DOWN[0];
        DOWN[0]=FRONT[0];
        FRONT[0]=UP[0];
        UP[0]=temp;

        temp = BACK[5];
        BACK[5]=DOWN[3];
        DOWN[3]=FRONT[3];
        FRONT[3]=UP[3];
        UP[3]=temp;

        temp = BACK[2];
        BACK[2]=DOWN[6];
        DOWN[6]=FRONT[6];
        FRONT[6]=UP[6];
        UP[6]=temp;
        break;
    case AL:
        rotate_matrice_anticlockwise(LEFT);
        printf("rotate left anticlockwise\n");
        temp = BACK[2];
        BACK[2]=UP[6];
        UP[6]=FRONT[6];
        FRONT[6]=DOWN[6];
        DOWN[6]=temp;

        temp = BACK[5];
        BACK[5]=UP[3];
        UP[3]=FRONT[3];
        FRONT[3]=DOWN[3];
        DOWN[3]=temp;

        temp = BACK[8];
        BACK[8]=UP[0];
        UP[0]=FRONT[0];
        FRONT[0]=DOWN[0];
        DOWN[0]=temp;
        break;
    case R:
        rotate_matrice_clockwise(RIGHT);
        printf("rotate right\n");
        temp = BACK[0];
        BACK[0]=UP[8];
        UP[8]=FRONT[8];
        FRONT[8]=DOWN[8];
        DOWN[8]=temp;

        temp = BACK[3];
        BACK[3]=UP[5];
        UP[5]=FRONT[5];
        FRONT[5]=DOWN[5];
        DOWN[5]=temp;

        temp = BACK[6];
        BACK[6]=UP[2];
        UP[2]=FRONT[2];
        FRONT[2]=DOWN[2];
        DOWN[2]=temp;

        break;
    case AR:
        rotate_matrice_anticlockwise(RIGHT);
        printf("rotate right anticlockwise\n");
        temp = BACK[0];
        BACK[0]=DOWN[8];
        DOWN[8]=FRONT[8];
        FRONT[8]=UP[8];
        UP[8]=temp;

        temp = BACK[3];
        BACK[3]=DOWN[5];
        DOWN[5]=FRONT[5];
        FRONT[5]=UP[5];
        UP[5]=temp;

        temp = BACK[6];
        BACK[6]=DOWN[2];
        DOWN[2]=FRONT[2];
        FRONT[2]=UP[2];
        UP[2]=temp;
        break;
    case F:
        rotate_matrice_clockwise(FRONT);
        printf("rotate front\n");
        temp = LEFT[8];
        LEFT[8]=DOWN[2];
        DOWN[2]=RIGHT[0];
        RIGHT[0]=UP[6];
        UP[6]=temp;

        temp = LEFT[5];
        LEFT[5]=DOWN[1];
        DOWN[1]=RIGHT[3];
        RIGHT[3]=UP[7];
        UP[7]=temp;

        temp = LEFT[2];
        LEFT[2]=DOWN[0];
        DOWN[0]=RIGHT[6];
        RIGHT[6]=UP[8];
        UP[8]=temp;
        break;
    case AF:
        rotate_matrice_anticlockwise(FRONT);
        printf("rotate front anticlockwise\n");
        temp = LEFT[8];
        LEFT[8]=UP[6];
        UP[6]=RIGHT[0];
        RIGHT[0]=DOWN[2];
        DOWN[2]=temp;

        temp = LEFT[5];
        LEFT[5]=UP[7];
        UP[7]=RIGHT[3];
        RIGHT[3]=DOWN[1];
        DOWN[1]=temp;

        temp = LEFT[2];
        LEFT[2]=UP[8];
        UP[8]=RIGHT[6];
        RIGHT[6]=DOWN[0];
        DOWN[0]=temp;
        break;
    case B:
        rotate_matrice_clockwise(BACK);
        printf("rotate back\n");
        temp = LEFT[6];
        LEFT[6]=UP[0];
        UP[0]=RIGHT[2];
        RIGHT[2]=DOWN[8];
        DOWN[8]=temp;

        temp = LEFT[3];
        LEFT[3]=UP[1];
        UP[1]=RIGHT[5];
        RIGHT[5]=DOWN[7];
        DOWN[7]=temp;

        temp = LEFT[0];
        LEFT[0]=UP[2];
        UP[2]=RIGHT[8];
        RIGHT[8]=DOWN[6];
        DOWN[6]=temp;

        break;
    case AB:
        rotate_matrice_anticlockwise(BACK);
        printf("rotate back anticlockwise\n");
        temp = LEFT[6];
        LEFT[6]=DOWN[8];
        DOWN[8]=RIGHT[2];
        RIGHT[2]=UP[0];
        UP[0]=temp;

        temp = LEFT[3];
        LEFT[3]=DOWN[7];
        DOWN[7]=RIGHT[5];
        RIGHT[5]=UP[1];
        UP[1]=temp;

        temp = LEFT[0];
        LEFT[0]=DOWN[6];
        DOWN[6]=RIGHT[8];
        RIGHT[8]=UP[2];
        UP[2]=temp;
        break;
    default:
        break;
    }
}
void rotate_matrice_clockwise(carre_t *Face) /*sens horaire*/
{   carre_t temp;

    temp=Face[0];
    Face[0]=Face[6];
    Face[6]=Face[8];
    Face[8]=Face[2];
    Face[2]=temp;

    temp=Face[1];
    Face[1]=Face[3];
    Face[3]=Face[7];
    Face[7]=Face[5];
    Face[5]=temp;
}
void rotate_matrice_anticlockwise(carre_t *Face) /*sens horaire*/
{   carre_t temp;

    temp=Face[0];
    Face[0]=Face[2];
    Face[2]=Face[8];
    Face[8]=Face[6];
    Face[6]=temp;

    temp=Face[1];
    Face[1]=Face[5];
    Face[5]=Face[7];
    Face[7]=Face[3];
    Face[3]=temp;
}
