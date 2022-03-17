#ifndef INTERFACE_GRAPHIQUE_H_INCLUDED
#define INTERFACE_GRAPHIQUE_H_INCLUDED

#include <stdbool.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "INIT.h"
#include"solve.h"

#define WINDOW_WIDTH 900
#define WINDOW_LENGHT 700

SDL_Renderer* renderer;
SDL_Window* window;

bool isOpen2,isOpen;
SDL_Event events;
SDL_Surface *texte;
SDL_Texture *text_texte;
TTF_Font *police;
SDL_Color Color_white;
SDL_Rect Rect_text;
char nb_rotation_txt[30];

void init_sdl(void);
void init_sdl2(void);
void remplissage_carre(SDL_Renderer* renderer);
void carrre_init_pos(void);
uint8_t get_red(color_t color);
uint8_t get_green(color_t color);
uint8_t get_blue(color_t color);
void display_nb_roation(void);
void verify_increment_color(int x, int y);
void color_inc(color_t *color);

#endif // INTERFACE_GRAPHIQUE_H_INCLUDED
