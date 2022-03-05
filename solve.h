#ifndef SOLVE_H_INCLUDED
#define SOLVE_H_INCLUDED
#include "INIT.h"
#include <stdbool.h>
typedef enum {
    EDGE =1, CENTER=2, CORNER=3
}type_cube_t;

char nb_rotation;

carre_t *get_carre_from_id(unsigned char id);
carre_t *get_carre_on_the_same_cube(carre_t *face,  signed char position, type_cube_t type);
signed char get_position(carre_t *face, color_t color23, type_cube_t type, signed char id0_excluded, signed char id1_excluded, signed char id2_excluded);
void do_white_cross(void);
carre_t *get_face_from_color(color_t color);
bool isinthetableau(carre_t *carre, carre_t *addressecarre);
carre_t *get_face_from_carre(carre_t *carre);
void rotate_face(carre_t *face, signed char clockwise);
void get_carre_blanc_on_the_white_face(carre_t *face);
void get_edges_from_otherfaces_to_white_cross(carre_t *face);
void verify_white_cross(void);
void get_corner_on_the_white_face(carre_t *face);
void treat_this_white_corner(signed char id);
void do_white_face(void);
void verify_white_face(void);
void step_3_do_color_edges(void);
void get_colored_edges_on_this_face(carre_t *face);
void get_this_edge_in_the_right_place(carre_t * carre, signed char cote);
carre_t *get_face_on_the_left(carre_t *face);
carre_t *get_face_on_the_right(carre_t *face);
signed char get_id_from_searched_cube(color_t color1, color_t color2);
void affich_id(void);
#endif // SOLVE_H_INCLUDED
