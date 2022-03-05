#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
#include <stdbool.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>

#include"movement.h"
#include"INIT.h"
#include "interface_graphique.h"
#include "button.h"

void fill_button (SDL_Renderer* renderer)
{
    SDL_SetRenderDrawColor(renderer,44,120, 12, 255 );
    SDL_RenderFillRect(renderer, &r_u);
    SDL_SetRenderDrawColor(renderer,12, 200, 120, 255 );
    SDL_RenderFillRect(renderer, &r_au);

    SDL_SetRenderDrawColor(renderer,12, 200, 120, 255 );
    SDL_RenderFillRect(renderer, &r_d);
    SDL_SetRenderDrawColor(renderer,12, 200, 120, 255 );
    SDL_RenderFillRect(renderer, &r_ad);

    SDL_SetRenderDrawColor(renderer,12, 200, 120, 255 );
    SDL_RenderFillRect(renderer, &r_l);
    SDL_SetRenderDrawColor(renderer,12, 200, 120, 255 );
    SDL_RenderFillRect(renderer, &r_al);

    //

    SDL_SetRenderDrawColor(renderer,12,200, 120, 255 );
    SDL_RenderFillRect(renderer, &r_r);
    SDL_SetRenderDrawColor(renderer,12, 200, 120, 255 );
    SDL_RenderFillRect(renderer, &r_ar);

    SDL_SetRenderDrawColor(renderer,12, 200, 120, 255 );
    SDL_RenderFillRect(renderer, &r_f);
    SDL_SetRenderDrawColor(renderer,12,200, 120, 255 );
    SDL_RenderFillRect(renderer, &r_af);

    SDL_SetRenderDrawColor(renderer,12, 200, 120, 255 );
    SDL_RenderFillRect(renderer, &r_b);
    SDL_SetRenderDrawColor(renderer,12, 200, 120, 255 );
    SDL_RenderFillRect(renderer, &r_ab);

    SDL_RenderPresent(renderer);
}

void button_pos(void)
{
    //up
    r_u.x=200;
    r_u.y=500;
    r_u.w=50;
    r_u.h=50;
    //
    r_au.x=255;
    r_au.y=500;
    r_au.w=50;
    r_au.h=50;

    r_d.x=310;
    r_d.y=500;
    r_d.w=50;
    r_d.h=50;
    //
    r_ad.x=365;
    r_ad.y=500;
    r_ad.w=50;
    r_ad.h=50;

    //
    r_l.x=420;
    r_l.y=500;
    r_l.w=50;
    r_l.h=50;
    //
    r_al.x=475;
    r_al.y=500;
    r_al.w=50;
    r_al.h=50;

    /////////////
    r_r.x=200;
    r_r.y=555;
    r_r.w=50;
    r_r.h=50;
    //anti up
    r_ar.x=255;
    r_ar.y=555;
    r_ar.w=50;
    r_ar.h=50;

    //up
    r_f.x=310;
    r_f.y=555;
    r_f.w=50;
    r_f.h=50;
    //anti up
    r_af.x=365;
    r_af.y=555;
    r_af.w=50;
    r_af.h=50;

    //up
    r_b.x=420;
    r_b.y=555;
    r_b.w=50;
    r_b.h=50;
    //anti up
    r_ab.x=475;
    r_ab.y=555;
    r_ab.w=50;
    r_ab.h=50;

    r_solve.x=200;
    r_solve.y=630;
    r_solve.w=150;
    r_solve.h=50;

    r_restart.x=355;
    r_restart.y=630;
    r_restart.w=150;
    r_restart.h=50;

 //bouton etape
    r_step_1.x = 400;
    r_step_1.y = 325;
    r_step_1.w = 100;
    r_step_1.h = 50;

    r_step_2.x = 500;
    r_step_2.y = 325;
    r_step_2.w = 100;
    r_step_2.h = 50;

    r_step_4.x = 500;
    r_step_4.y = 375;
    r_step_4.w = 100;
    r_step_4.h = 50;

    r_step_3.x = 400;
    r_step_3.y = 375;
    r_step_3.w = 100;
    r_step_3.h = 50;

    r_step_5.x = 400;
    r_step_5.y = 425;
    r_step_5.w = 100;
    r_step_5.h = 50;

    r_step_6.x = 500;
    r_step_6.y = 425;
    r_step_6.w = 100;
    r_step_6.h = 50;
}

void init_pic (SDL_Renderer* renderer,SDL_Window* window,char *picture, SDL_Rect rectangle)
{
    pic_u = SDL_LoadBMP(picture);
    if(pic_u == NULL)
    {
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        printf("impossible de charger l'image \n");
    }
    text_u = SDL_CreateTextureFromSurface(renderer,pic_u);
    SDL_FreeSurface(pic_u);
    if(text_u == NULL)
    {
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        printf("impossible de charger la texture \n");
    }
    if(SDL_RenderCopy(renderer,text_u,NULL,&rectangle))
    {
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        printf("impossible de charger la texture \n");
    }
    SDL_RenderPresent(renderer);
}

void button_press_moove (SDL_Rect rect,moove_t moove,SDL_Event events)
{

    if(events.button.button == SDL_BUTTON_LEFT)
    {
        if( ((events.button.x >= rect.x) && (events.button.x <= (rect.x + rect.w))) && ((events.button.y >= rect.y) && (events.button.y <= (rect.y + rect.h))))
        {
            rotate_moove(moove);
            Mix_PlayChannel(-1,Rotation_Sound,0);
        }
    }
}

void button_step (SDL_Rect rect1,char *file_mouse,char *file,SDL_Event events)
{
     char flag=0;
    if (events.type==SDL_MOUSEMOTION)
    {
        if( ((events.motion.x >= rect1.x) && (events.motion.x <= (rect1.x + rect1.w))) && ((events.motion.y >= rect1.y) && (events.motion.y <= (rect1.y + rect1.h))))
        {
            init_pic(renderer,window,file_mouse,rect1);
            if(flag==0)
            {
                flag=1;
                Mix_PlayChannel(-1,Tic_Sound,0);
            }
            else
            {

            }
        }
        else
        {
            init_pic(renderer,window,file,rect1);
        }
    }
}




