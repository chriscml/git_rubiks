#include "movement.h"
#include "INIT.h"
#include <stdio.h>
void rotate_moove (moove_t moove,SDL_Renderer* renderer)
{
    carre_t temp;

    //affiche_fleche(moove);
    switch(moove)
    {
    case U:
        rotate_matrice_clockwise(UP);
        printf("rotate up\n");
        is_equal_to(&temp, &BACK[0]);
        is_equal_to(&BACK[0],&LEFT[0]);
        is_equal_to(&LEFT[0], &FRONT[0]);
        is_equal_to(&FRONT[0], &RIGHT[0]);
        is_equal_to(&RIGHT[0], &temp);

        is_equal_to(&temp, &BACK[1]);
        is_equal_to(&BACK[1], &LEFT[1]);
        is_equal_to(&LEFT[1], &FRONT[1]);
        is_equal_to(&FRONT[1], &RIGHT[1]);
        is_equal_to(&RIGHT[1], &temp);

        is_equal_to(&temp, &BACK[2]);
        is_equal_to(&BACK[2], &LEFT[2]);
        is_equal_to(&LEFT[2], &FRONT[2]);
        is_equal_to(&FRONT[2], &RIGHT[2]);
        is_equal_to(&RIGHT[2], &temp);
        break;
    case AU:
        rotate_matrice_anticlockwise(UP);
        printf("rotate up anticlockwise\n");
        is_equal_to(&temp, &BACK[0]);
        is_equal_to(&BACK[0], &RIGHT[0]);
        is_equal_to(&RIGHT[0], &FRONT[0]);
        is_equal_to(&FRONT[0], &LEFT[0]);
        is_equal_to(&LEFT[0], &temp);

        is_equal_to(&temp, &BACK[1]);
        is_equal_to(&BACK[1], &RIGHT[1]);
        is_equal_to(&RIGHT[1], &FRONT[1]);
        is_equal_to(&FRONT[1], &LEFT[1]);
        is_equal_to(&LEFT[1], &temp);

        is_equal_to(&temp, &BACK[2]);
        is_equal_to(&BACK[2], &RIGHT[2]);
        is_equal_to(&RIGHT[2], &FRONT[2]);
        is_equal_to(&FRONT[2], &LEFT[2]);
        is_equal_to(&LEFT[2], &temp);
        break;
    case D:
        rotate_matrice_clockwise(DOWN);
        printf("rotate down\n");
        is_equal_to(&temp, &BACK[6]);
        is_equal_to(&BACK[6], &RIGHT[6]);
        is_equal_to(&RIGHT[6], &FRONT[6]);
        is_equal_to(&FRONT[6], &LEFT[6]);
        is_equal_to(&LEFT[6], &temp);

        is_equal_to(&temp, &BACK[7]);
        is_equal_to(&BACK[7], &RIGHT[7]);
        is_equal_to(&RIGHT[7], &FRONT[7]);
        is_equal_to(&FRONT[7], &LEFT[7]);
        is_equal_to(&LEFT[7], &temp);

        is_equal_to(&temp, &BACK[8]);
        is_equal_to(&BACK[8], &RIGHT[8]);
        is_equal_to(&RIGHT[8], &FRONT[8]);
        is_equal_to(&FRONT[8], &LEFT[8]);
        is_equal_to(&LEFT[8], &temp);
        break;
    case AD:
        rotate_matrice_anticlockwise(DOWN);
        printf("rotate down anticlockwise\n");
        is_equal_to(&temp, &BACK[6]);
        is_equal_to(&BACK[6], &LEFT[6]);
        is_equal_to(&LEFT[6], &FRONT[6]);
        is_equal_to(&FRONT[6], &RIGHT[6]);
        is_equal_to(&RIGHT[6], &temp);

        is_equal_to(&temp, &BACK[7]);
        is_equal_to(&BACK[7], &LEFT[7]);
        is_equal_to(&LEFT[7], &FRONT[7]);
        is_equal_to(&FRONT[7], &RIGHT[7]);
        is_equal_to(&RIGHT[7], &temp);

        is_equal_to(&temp, &BACK[8]);
        is_equal_to(&BACK[8], &LEFT[8]);
        is_equal_to(&LEFT[8], &FRONT[8]);
        is_equal_to(&FRONT[8], &RIGHT[8]);
        is_equal_to(&RIGHT[8], &temp);
        break;
    case L:
        rotate_matrice_clockwise(LEFT);
        printf("rotate left\n");
        is_equal_to(&temp, &BACK[8]);
        is_equal_to(&BACK[8], &DOWN[0]);
        is_equal_to(&DOWN[0], &FRONT[0]);
        is_equal_to(&FRONT[0], &UP[0]);
        is_equal_to(&UP[0], &temp);

        is_equal_to(&temp, &BACK[5]);
        is_equal_to(&BACK[5], &DOWN[3]);
        is_equal_to(&DOWN[3], &FRONT[3]);
        is_equal_to(&FRONT[3], &UP[3]);
        is_equal_to(&UP[3], &temp);

        is_equal_to(&temp, &BACK[2]);
        is_equal_to(&BACK[2], &DOWN[6]);
        is_equal_to(&DOWN[6], &FRONT[6]);
        is_equal_to(&FRONT[6], &UP[6]);
        is_equal_to(&UP[6], &temp);
        break;
    case AL:
        rotate_matrice_anticlockwise(LEFT);
        printf("rotate left anticlockwise\n");
        is_equal_to(&temp, &BACK[2]);
        is_equal_to(&BACK[2], &UP[6]);
        is_equal_to(&UP[6], &FRONT[6]);
        is_equal_to(&FRONT[6], &DOWN[6]);
        is_equal_to(&DOWN[6], &temp);

        is_equal_to(&temp, &BACK[5]);
        is_equal_to(&BACK[5], &UP[3]);
        is_equal_to(&UP[3], &FRONT[3]);
        is_equal_to(&FRONT[3], &DOWN[3]);
        is_equal_to(&DOWN[3], &temp);

        is_equal_to(&temp, &BACK[8]);
        is_equal_to(&BACK[8], &UP[0]);
        is_equal_to(&UP[0], &FRONT[0]);
        is_equal_to(&FRONT[0], &DOWN[0]);
        is_equal_to(&DOWN[0], &temp);
        break;
    case R:
        rotate_matrice_clockwise(RIGHT);
        printf("rotate right\n");
        is_equal_to(&temp, &BACK[0]);
        is_equal_to(&BACK[0], &UP[8]);
        is_equal_to(&UP[8], &FRONT[8]);
        is_equal_to(&FRONT[8], &DOWN[8]);
        is_equal_to(&DOWN[8], &temp);

        is_equal_to(&temp, &BACK[3]);
        is_equal_to(&BACK[3], &UP[5]);
        is_equal_to(&UP[5], &FRONT[5]);
        is_equal_to(&FRONT[5], &DOWN[5]);
        is_equal_to(&DOWN[5], &temp);

        is_equal_to(&temp, &BACK[6]);
        is_equal_to(&BACK[6], &UP[2]);
        is_equal_to(&UP[2], &FRONT[2]);
        is_equal_to(&FRONT[2], &DOWN[2]);
        is_equal_to(&DOWN[2], &temp);

        break;
    case AR:
        rotate_matrice_anticlockwise(RIGHT);
        printf("rotate right anticlockwise\n");
        is_equal_to(&temp, &BACK[0]);
        is_equal_to(&BACK[0], &DOWN[8]);
        is_equal_to(&DOWN[8], &FRONT[8]);
        is_equal_to(&FRONT[8], &UP[8]);
        is_equal_to(&UP[8], &temp);

        is_equal_to(&temp, &BACK[3]);
        is_equal_to(&BACK[3], &DOWN[5]);
        is_equal_to(&DOWN[5], &FRONT[5]);
        is_equal_to(&FRONT[5], &UP[5]);
        is_equal_to(&UP[5], &temp);

        is_equal_to(&temp, &BACK[6]);
        is_equal_to(&BACK[6], &DOWN[2]);
        is_equal_to(&DOWN[2], &FRONT[2]);
        is_equal_to(&FRONT[2], &UP[2]);
        is_equal_to(&UP[2], &temp);
        break;
    case F:
        rotate_matrice_clockwise(FRONT);
        printf("rotate front\n");
        is_equal_to(&temp, &LEFT[8]);
        is_equal_to(&LEFT[8], &DOWN[2]);
        is_equal_to(&DOWN[2], &RIGHT[0]);
        is_equal_to(&RIGHT[0], &UP[6]);
        is_equal_to(&UP[6], &temp);

        is_equal_to(&temp, &LEFT[5]);
        is_equal_to(&LEFT[5], &DOWN[1]);
        is_equal_to(&DOWN[1], &RIGHT[3]);
        is_equal_to(&RIGHT[3], &UP[7]);
        is_equal_to(&UP[7], &temp);

        is_equal_to(&temp, &LEFT[2]);
        is_equal_to(&LEFT[2], &DOWN[0]);
        is_equal_to(&DOWN[0], &RIGHT[6]);
        is_equal_to(&RIGHT[6], &UP[8]);
        is_equal_to(&UP[8], &temp);
        break;
    case AF:
        rotate_matrice_anticlockwise(FRONT);
        printf("rotate front anticlockwise\n");
        is_equal_to(&temp, &LEFT[8]);
        is_equal_to(&LEFT[8], &UP[6]);
        is_equal_to(&UP[6], &RIGHT[0]);
        is_equal_to(&RIGHT[0], &DOWN[2]);
        is_equal_to(&DOWN[2], &temp);

        is_equal_to(&temp, &LEFT[5]);
        is_equal_to(&LEFT[5], &UP[7]);
        is_equal_to(&UP[7], &RIGHT[3]);
        is_equal_to(&RIGHT[3], &DOWN[1]);
        is_equal_to(&DOWN[1], &temp);

        is_equal_to(&temp, &LEFT[2]);
        is_equal_to(&LEFT[2], &UP[8]);
        is_equal_to(&UP[8], &RIGHT[6]);
        is_equal_to(&RIGHT[6], &DOWN[0]);
        is_equal_to(&DOWN[0], &temp);
        break;
    case B:
        rotate_matrice_clockwise(BACK);
        printf("rotate back\n");
        is_equal_to(&temp, &LEFT[6]);
        is_equal_to(&LEFT[6], &UP[0]);
        is_equal_to(&UP[0], &RIGHT[2]);
        is_equal_to(&RIGHT[2], &DOWN[8]);
        is_equal_to(&DOWN[8], &temp);

        is_equal_to(&temp, &LEFT[3]);
        is_equal_to(&LEFT[3], &UP[1]);
        is_equal_to(&UP[1], &RIGHT[5]);
        is_equal_to(&RIGHT[5], &DOWN[7]);
        is_equal_to(&DOWN[7], &temp);

        is_equal_to(&temp, &LEFT[0]);
        is_equal_to(&LEFT[0], &UP[2]);
        is_equal_to(&UP[2], &RIGHT[8]);
        is_equal_to(&RIGHT[8], &DOWN[6]);
        is_equal_to(&DOWN[6], &temp);

        break;
    case AB:
        rotate_matrice_anticlockwise(BACK);
        printf("rotate back anticlockwise\n");
        is_equal_to(&temp, &LEFT[6]);
        is_equal_to(&LEFT[6], &DOWN[8]);
        is_equal_to(&DOWN[8], &RIGHT[2]);
        is_equal_to(&RIGHT[2], &UP[0]);
        is_equal_to(&UP[0], &temp);

        is_equal_to(&temp, &LEFT[3]);
        is_equal_to(&LEFT[3], &DOWN[7]);
        is_equal_to(&DOWN[7], &RIGHT[5]);
        is_equal_to(&RIGHT[5], &UP[1]);
        is_equal_to(&UP[1], &temp);

        is_equal_to(&temp, &LEFT[0]);
        is_equal_to(&LEFT[0], &DOWN[6]);
        is_equal_to(&DOWN[6], &RIGHT[8]);
        is_equal_to(&RIGHT[8], &UP[2]);
        is_equal_to(&UP[2], &temp);
        break;
    default:
        break;
    }
    tableau_next[indice_tableau_next]=moove;

    if(indice_tableau_next>=200)
    {
        indice_tableau_next=0;
    }
    else
    {
        indice_tableau_next++;
    }
    remplissage_carre(renderer);
}
void rotate_matrice_clockwise(carre_t *Face) /*sens horaire*/
{
    carre_t temp;

    is_equal_to(&temp, &Face[0]);
    is_equal_to(&Face[0], &Face[6]);
    is_equal_to(&Face[6], &Face[8]);
    is_equal_to(&Face[8], &Face[2]);
    is_equal_to(&Face[2], &temp);

    is_equal_to(&temp, &Face[1]);
    is_equal_to(&Face[1], &Face[3]);
    is_equal_to(&Face[3], &Face[7]);
    is_equal_to(&Face[7], &Face[5]);
    is_equal_to(&Face[5], &temp);
}
void rotate_matrice_anticlockwise(carre_t *Face) /*sens horaire*/
{
    carre_t temp;

    is_equal_to(&temp, &Face[0]);
    is_equal_to(&Face[0], &Face[2]);
    is_equal_to(&Face[2], &Face[8]);
    is_equal_to(&Face[8], &Face[6]);
    is_equal_to(&Face[6], &temp);

    is_equal_to(&temp, &Face[1]);
    is_equal_to(&Face[1], &Face[5]);
    is_equal_to(&Face[5], &Face[7]);
    is_equal_to(&Face[7], &Face[3]);
    is_equal_to(&Face[3], &temp);
}
void is_equal_to(carre_t *carre1, carre_t *carre2)
{
    carre1->color=carre2->color;
    carre1->id=carre2->id;
}
