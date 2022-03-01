#ifndef MOVEMENT_H_INCLUDED
#define MOVEMENT_H_INCLUDED
#include "INIT.h"
typedef enum{
U,AU,D,AD,L,AL,R,AR,F,AF,B,AB
}moove_t;
void rotate_moove (moove_t moove );
void rotate_matrice_clockwise(carre_t *Face);
void rotate_matrice_anticlockwise(carre_t *Face);


#endif // MOVEMENT_H_INCLUDED
