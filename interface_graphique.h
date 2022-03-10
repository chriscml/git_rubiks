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
SDL_Rect rf1;
SDL_Rect rf2;
SDL_Rect rf3;
SDL_Rect rf4;
SDL_Rect rf5;
SDL_Rect rf6;
SDL_Rect rf7;
SDL_Rect rf8;
SDL_Rect rf9;

SDL_Rect rb1;
SDL_Rect rb2;
SDL_Rect rb3;
SDL_Rect rb4;
SDL_Rect rb5;
SDL_Rect rb6;
SDL_Rect rb7;
SDL_Rect rb8;
SDL_Rect rb9;

SDL_Rect rl1;
SDL_Rect rl2;
SDL_Rect rl3;
SDL_Rect rl4;
SDL_Rect rl5;
SDL_Rect rl6;
SDL_Rect rl7;
SDL_Rect rl8;
SDL_Rect rl9;

SDL_Rect rr1;
SDL_Rect rr2;
SDL_Rect rr3;
SDL_Rect rr4;
SDL_Rect rr5;
SDL_Rect rr6;
SDL_Rect rr7;
SDL_Rect rr8;
SDL_Rect rr9;

SDL_Rect ru1;
SDL_Rect ru2;
SDL_Rect ru3;
SDL_Rect ru4;
SDL_Rect ru5;
SDL_Rect ru6;
SDL_Rect ru7;
SDL_Rect ru8;
SDL_Rect ru9;

SDL_Rect rd1;
SDL_Rect rd2;
SDL_Rect rd3;
SDL_Rect rd4;
SDL_Rect rd5;
SDL_Rect rd6;
SDL_Rect rd7;
SDL_Rect rd8;
SDL_Rect rd9;

SDL_Surface *texte;
SDL_Texture *text_texte;
TTF_Font *police;
SDL_Color Color_white;
SDL_Rect Rect_text;
char nb_rotation_txt[20];

void init_sdl(void);
void init_sdl2(void);
void remplissage_carre(SDL_Renderer* renderer);
void carrre_init_pos(void);
uint8_t get_red(color_t color);
uint8_t get_green(color_t color);
uint8_t get_blue(color_t color);
void display_nb_roation(void);

#endif // INTERFACE_GRAPHIQUE_H_INCLUDED
