#ifndef SOLVE_H_INCLUDED
#define SOLVE_H_INCLUDED
#include "INIT.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
typedef enum {
    EDGE =1, CENTER=2, CORNER=3
}type_cube_t;


carre_t *nb_rotation_sauvegarde[3];
int indice_tab_moove;
unsigned char nb_rotation;
FILE* file_solution;



/////////////////////////////////////////////////////////////////////
/////////////////////// FONCTIONS ANNEXES///////////////////////////
////////////////////////////////////////////////////////////////////


carre_t *get_carre_on_the_same_cube(carre_t *face,  signed char position, type_cube_t type);
signed char get_position(carre_t *face, color_t color23, type_cube_t type, signed char id0_excluded, signed char id1_excluded, signed char id2_excluded);
carre_t *get_face_from_color(color_t color);
bool isinthetableau(carre_t *carre, carre_t *addressecarre);
carre_t *get_face_from_carre(carre_t *carre);
void rotate_face(carre_t *face, signed char clockwise);
void affich_id(void);



/////////////////////////////////////////////////////////////////////
/////////////////// FONCTIONS DE RESOLUTION/////////////////////////
////////////////////////////////////////////////////////////////////

////////////////////////ETAPE 1///////////////////////////////////
void step_1_do_white_cross(void);//FONCTION PRINCIPALE
void step_1_get_carre_blanc_on_the_white_face(carre_t *face);
void step_1_get_edges_from_otherfaces_to_white_cross(carre_t *face);
void step_1_verify_white_cross(void);



//////////////////////ETAPE 2//////////////////////////////////////
void step_2_do_white_face(void);//FONCTION PRINCIPALE
void step_2_get_corner_on_the_white_face(carre_t *face);
void step_2_treat_this_white_corner(signed char id);
void step_2_verify_white_face(void);



//////////////////////ETAPE 3///////////////////////////////////////
void step_3_do_color_edges(void);//FONCTION PRINCIPALE
void get_colored_edges_on_this_face(carre_t *face);
void step_3_get_this_edge_in_the_right_place(carre_t * carre, signed char cote);
carre_t *step_3_get_face_on_the_left(carre_t *face);
carre_t *step_3_get_face_on_the_right(carre_t *face);
signed char step_3_get_id_from_searched_cube(color_t color1, color_t color2);



///////////////////////ETAPE 4///////////////////////////////////////
void step_4_yellow_cross(void);//FONCTION PRINCIPALE
unsigned char step_4_get_configuration_yellow_cross(void);
void step_4_treat_this_yellow_cross_configuration(unsigned char config);



////////////////////////ETAPE 5///////////////////////////////////////
void step_5_yellow_corner(void);//FONCTION PIRNCIPALE
unsigned char step_5_get_configuration_yellow_corner(void);


//////////////////////////ETAPE 6//////////////////////////////////////
void step_6_yellow_corner_near_cubes(void);//FONCTION PRINCIPALE
signed char step_6_get_config(void);


//////////////////////////ETAPE 7//////////////////////////////////////
void step_7_yellow_arretes(void);//FONCTION PRINCIPALE
signed char step_7_get_config(void);

#endif // SOLVE_H_INCLUDED
