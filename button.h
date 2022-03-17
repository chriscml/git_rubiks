#ifndef BUTTON_H
#define BUTTON_H

#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>
#include "interface_graphique.h"
#include "movement.h"
#include "solve.h"

Mix_Chunk *Rotation_Sound;
Mix_Chunk *Solve_Sound;
Mix_Chunk *Restart_Sound;
Mix_Chunk *Tic_Sound,*Tic_Sound2,*Tic_Sound3;
char flag;

SDL_Rect anc_rectangle;
SDL_Rect r_u;
SDL_Rect r_au;
SDL_Rect r_d;
SDL_Rect r_ad;
SDL_Rect r_l;
SDL_Rect r_al;
SDL_Rect r_r;
SDL_Rect r_ar;
SDL_Rect r_f;
SDL_Rect r_af;
SDL_Rect r_b;
SDL_Rect r_ab;

SDL_Rect r_solve;
SDL_Rect r_restart;

SDL_Rect r_step_1;
SDL_Rect r_step_2;
SDL_Rect r_step_3;
SDL_Rect r_step_4;
SDL_Rect r_step_5;
SDL_Rect r_step_6;
SDL_Rect r_step_7;

SDL_Rect r_next_move;
//declaration image et texture
SDL_Surface *pic_u, *pic_au;
SDL_Surface *pic_d, *pic_ad;
SDL_Surface *pic_l, *pic_al;
SDL_Surface *pic_r, *pic_ar;
SDL_Surface *pic_f, *pic_af;
SDL_Surface *pic_b, *pic_ab;

SDL_Texture *text_u,*text_au;
SDL_Texture *text_d,*text_ad;
SDL_Texture *text_l,*text_al;
SDL_Texture *text_r,*text_ar;
SDL_Texture *text_f,*text_af;
SDL_Texture *text_b,*text_ab;


void button_sound (Mix_Chunk *Sound, char *Sound_File);
void fill_button (SDL_Renderer* renderer);
void button_pos(void);
void init_pic (SDL_Renderer* renderer,SDL_Window* window,char *picture, SDL_Rect rectangle);
void button_press_moove (SDL_Rect rect,moove_t moove,SDL_Event events);
void button_step (SDL_Rect rect1,char *file_mouse,char *file,SDL_Event events,Mix_Chunk *Sound);
void shuffle_rubik(void);

#endif // SDL_H_INCLUDED
