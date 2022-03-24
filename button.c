#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
#include <stdbool.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>
#include <time.h>

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

    r_next_move.x = 650;
    r_next_move.y = 500;
    r_next_move.w = 200;
    r_next_move.h = 100;
    /*-----------------------------------------*/
    r_fleche_u.x = 150;
    r_fleche_u.y = 0;
    r_fleche_u.w = 260;
    r_fleche_u.h = 150;

    r_fleche_au.x = 150;
    r_fleche_au.y = 0;
    r_fleche_au.w = 260;
    r_fleche_au.h = 150;

    r_fleche_l.x = 0;
    r_fleche_l.y = 150;
    r_fleche_l.w = 260;
    r_fleche_l.h = 150;

    r_fleche_al.x = 0;
    r_fleche_al.y = 150;
    r_fleche_al.w = 260;
    r_fleche_al.h = 150;

    r_fleche_f.x = 50;
    r_fleche_f.y = 150;
    r_fleche_f.w = 260;
    r_fleche_f.h = 150;

    r_fleche_af.x = 50;
    r_fleche_af.y = 150;
    r_fleche_af.w = 260;
    r_fleche_af.h = 150;

    r_fleche_r.x = 100;
    r_fleche_r.y = 150;
    r_fleche_r.w = 260;
    r_fleche_r.h = 150;

    r_fleche_ar.x = 100;
    r_fleche_ar.y = 150;
    r_fleche_ar.w = 260;
    r_fleche_ar.h = 150;

    r_fleche_b.x = 150;
    r_fleche_b.y = 150;
    r_fleche_b.w = 260;
    r_fleche_b.h = 150;

    r_fleche_ab.x = 150;
    r_fleche_ab.y = 150;
    r_fleche_ab.w = 260;
    r_fleche_ab.h = 150;

    r_fleche_d.x = 150;
    r_fleche_d.y = 300;
    r_fleche_d.w = 260;
    r_fleche_d.h = 150;

    r_fleche_ad.x = 150;
    r_fleche_ad.y = 300;
    r_fleche_ad.w = 260;
    r_fleche_ad.h = 150;



    r_fleche_u.x = UP[4].rect.x+((UP[4].rect.w - r_fleche_u.w)/2);
    r_fleche_au.x = UP[4].rect.x+((UP[4].rect.w - r_fleche_au.w)/2);

    r_fleche_l.x = LEFT[4].rect.x+((LEFT[4].rect.w - r_fleche_l.w)/2);
    r_fleche_al.x = LEFT[4].rect.x+((LEFT[4].rect.w - r_fleche_al.w)/2);

    r_fleche_f.x = FRONT[4].rect.x+((FRONT[4].rect.w - r_fleche_f.w)/2);
    r_fleche_af.x = FRONT[4].rect.x+((FRONT[4].rect.w - r_fleche_af.w)/2);

    r_fleche_r.x = RIGHT[4].rect.x+((RIGHT[4].rect.w - r_fleche_r.w)/2);
    r_fleche_ar.x = RIGHT[4].rect.x+((RIGHT[4].rect.w - r_fleche_af.w)/2);

    r_fleche_b.x = BACK[4].rect.x+((BACK[4].rect.w - r_fleche_b.w)/2);
    r_fleche_ab.x = BACK[4].rect.x+((BACK[4].rect.w - r_fleche_ab.w)/2);

    r_fleche_d.x = DOWN[4].rect.x+((DOWN[4].rect.w - r_fleche_d.w)/2);
    r_fleche_ad.x = DOWN[4].rect.x+((DOWN[4].rect.w - r_fleche_ad.w)/2);


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
    indice_tableau_next=0;
    if(events.button.button == SDL_BUTTON_LEFT)
    {
        if( ((events.button.x >= rect.x) && (events.button.x <= (rect.x + rect.w))) && ((events.button.y >= rect.y) && (events.button.y <= (rect.y + rect.h))))
        {
            rotate_moove(moove,renderer);
            Mix_PlayChannel(-1,Rotation_Sound,0);
            Mix_VolumeChunk(Rotation_Sound,40);
            flag2=0;

        }
    }
}

void button_step (SDL_Rect rect1,char *file_mouse,char *file,SDL_Event events,Mix_Chunk *Sound)
{
    if (events.type==SDL_MOUSEMOTION)
    {
        if( ((events.motion.x >= rect1.x) && (events.motion.x <= (rect1.x + rect1.w))) && ((events.motion.y >= rect1.y) && (events.motion.y <= (rect1.y + rect1.h))))
        {
            init_pic(renderer,window,file_mouse,rect1);
            if(Sound != NULL)
            {
                if((anc_rectangle.x != rect1.y) && (anc_rectangle.y != rect1.y))
                {
                    Mix_PlayChannel(-1,Sound,0);
                }
                if((anc_rectangle.x != rect1.x) && (anc_rectangle.y != rect1.x))
                {
                    Mix_PlayChannel(-1,Sound,0);
                    Mix_VolumeChunk(Sound,50);
                }
            }
            else
            {

            }
            anc_rectangle.x = rect1.x;
            anc_rectangle.y = rect1.y;
        }
        else
        {
            init_pic(renderer,window,file,rect1);
        }
    }
}

void shuffle_rubik(void)
{
    srand(time(NULL));
    moove_t face_rand;
    for(int i=0; i<100; i++)
    {
        face_rand = rand() % 12;
        rotate_moove(face_rand,renderer);
    }
}

void fonction_next (SDL_Renderer* renderer,SDL_Window* window)
{
    carre_t sauv_up[9];
    carre_t sauv_down[9];
    carre_t sauv_back[9];
    carre_t sauv_right[9];
    carre_t sauv_left[9];
    carre_t sauv_front[9];
    printf("next moove : \n");
    // printf("flag2 :%d", flag2);
    if(flag2==0)
    {
        for(int i=0; i<9; i++)
        {
            sauv_up[i]=UP[i];
        }
        for(int i=0; i<9; i++)
        {
            sauv_down[i]=DOWN[i];
        }
        for(int i=0; i<9; i++)
        {
            sauv_back[i]=BACK[i];
        }
        for(int i=0; i<9; i++)
        {
            sauv_right[i]=RIGHT[i];
        }
        for(int i=0; i<9; i++)
        {
            sauv_left[i]=LEFT[i];
        }
        for(int i=0; i<9; i++)
        {
            sauv_front[i]=FRONT[i];
        }
        step_1_do_white_cross();
        step_2_do_white_face();
        step_3_do_color_edges();
        step_4_yellow_cross();
        step_5_yellow_corner();
        step_6_yellow_corner_near_cubes();
        step_7_yellow_arretes();
        for(int i=0; i<9; i++)
        {
            UP[i]= sauv_up[i];
        }
        for(int i=0; i<9; i++)
        {
            DOWN[i]=sauv_down[i];
        }
        for(int i=0; i<9; i++)
        {
            BACK[i]=sauv_back[i];
        }
        for(int i=0; i<9; i++)
        {
            RIGHT[i]=sauv_right[i];
        }
        for(int i=0; i<9; i++)
        {
            LEFT[i]=sauv_left[i];
        }
        for(int i=0; i<9; i++)
        {
            FRONT[i] = sauv_front[i];
        }
        flag2=10;
    }
    rotate_moove(tableau_next[indice_next],renderer);
    if(indice_next>=200)
    {
        indice_next=0;
    }
    else
    {
        indice_next++;
    }
    affiche_fleche(tableau_next[indice_next]);

    //printf("indice next : %d\n",indice_next);

}

void affiche_fleche (moove_t moove)
{

    switch(moove)
    {
    case U:
        init_pic(renderer,window,"fleche.bmp",r_fleche_u);
        break;
    case AU:
        init_pic(renderer,window,"fleche_anti.bmp",r_fleche_au);
        break;
    case L:
        init_pic(renderer,window,"fleche.bmp",r_fleche_l);
        break;
    case AL:
        init_pic(renderer,window,"fleche_anti.bmp",r_fleche_al);
        break;
    case F:
        init_pic(renderer,window,"fleche.bmp",r_fleche_f);
        break;
    case AF:
        init_pic(renderer,window,"fleche_anti.bmp",r_fleche_af);
        break;
    case R:
        init_pic(renderer,window,"fleche.bmp",r_fleche_r);
        break;
    case AR:
        init_pic(renderer,window,"fleche_anti.bmp",r_fleche_ar);
        break;
    case B:
        init_pic(renderer,window,"fleche.bmp",r_fleche_b);
        break;
    case AB:
        init_pic(renderer,window,"fleche_anti.bmp",r_fleche_ab);
        break;
    case D:
        init_pic(renderer,window,"fleche.bmp",r_fleche_d);
        break;
    case AD:
        init_pic(renderer,window,"fleche_anti.bmp",r_fleche_ad);
        break;
    default:
        break;
    }
}


