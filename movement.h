#ifndef MOVEMENT_H_INCLUDED
#define MOVEMENT_H_INCLUDED
#include "INIT.h"
typedef enum
{
    U,AU,D,AD,L,AL,R,AR,F,AF,B,AB
} moove_t;
void rotate_moove (moove_t moove );
void rotate_matrice_clockwise(carre_t *Face);
void rotate_matrice_anticlockwise(carre_t *Face);
void is_equal_to(carre_t *carre1, carre_t *carre2);


moove_t tableau_next[200];

int indice_tableau_next;

#endif // MOVEMENT_H_INCLUDED
