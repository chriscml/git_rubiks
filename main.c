#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
#include <stdbool.h>
#include <SDL2/SDL_ttf.h>

#include "INIT.h"
#include "interface_graphique.h"
#include "movement.h"
#include "solve.h"
#include "button.h"

int main(int argc, char** argv)
{
    flag=0;
    global_init();
    nb_rotation=0;
    for(int i=0; i<9; i++)
    {
        printf("couleur:%d, id: %d\n", UP[i].color, UP[i].id);
    }

    init_sdl();

    init_color("melange.txt");
    carrre_init_pos();
    button_pos();
    remplissage_carre(renderer);

    /*//texte
    if(TTF_Init()==-1)
    {
        printf("erreur chargement du texte \n");
    }
    TTF_Font *police = TTF_OpenFont("arial.ttf",30);
    SDL_Color Color_white;
    Color_white.a=255;
    Color_white.r=255;
    Color_white.g=255;
    Color_white.b=255;

    SDL_Surface *texte = TTF_RenderText_Solid(police, "Salutdzdefefzvvr" ,Color_white);
    SDL_Texture *text_texte = SDL_CreateTextureFromSurface(renderer,texte);
    SDL_Rect textRect;
    textRect.y =0;
    textRect.x = textRect.y;
    SDL_QueryTexture(text_texte,NULL,NULL,&textRect.w,&textRect.h);*/

    //audio
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT,2,2048);
    Rotation_Sound = Mix_LoadWAV("bruitage.wav");
    Solve_Sound = Mix_LoadWAV("mario.wav");
    Restart_Sound = Mix_LoadWAV("restart.wav");
    Tic_Sound = Mix_LoadWAV("tic.wav");
    Tic_Sound2 = Mix_LoadWAV("tic_pes2.wav");
    Tic_Sound3 = Mix_LoadWAV("tic_pes3.wav");

    isOpen=true;
    while(isOpen)
    {
        SDL_WaitEvent(&events);
        if(events.type==SDL_QUIT)
        {
            isOpen=false;
        }
        else if (events.type==SDL_KEYDOWN)
        {
//          SDL_RenderCopy(renderer,text_texte, NULL,&textRect);
            switch(events.key.keysym.sym)
            {
            case SDLK_a:
                rotate_moove(F);
                break;
            case SDLK_b:
                rotate_moove(AF);
                break;
            case SDLK_c:
                rotate_moove(R);
                break;
            case SDLK_d:
                rotate_moove(AR);
                break;
            case SDLK_e:
                rotate_moove(U);
                break;
            case SDLK_f:
                rotate_moove(AU);
                break;
            case SDLK_g:
                rotate_moove(B);
                break;
            case SDLK_h:
                rotate_moove(AB);
                break;
            case SDLK_i:
                rotate_moove(L);
                break;
            case SDLK_j:
                rotate_moove(AL);
                break;
            case SDLK_k:
                rotate_moove(D);
                break;
            case SDLK_l:
                rotate_moove(AD);
                break;
            case SDLK_z:
                init_color("monfichier.txt");
                break;
            case SDLK_s:
                printf("--------------------------solve----------------------\n");
                nb_rotation=0;
                do_white_cross();
                do_white_face();
                step_3_do_color_edges();
                printf("\n Nombre de rotation : %d \n",nb_rotation);
                break;
            default:
                break;
            }
        }
        else if (events.type==SDL_MOUSEBUTTONDOWN)
        {
            button_press_moove(r_u,U,events);
            button_press_moove(r_au,AU,events);
            button_press_moove(r_d,D,events);
            button_press_moove(r_ad,AD,events);
            button_press_moove(r_l,L,events);
            button_press_moove(r_al,AL,events);
            //
            button_press_moove(r_r,R,events);
            button_press_moove(r_ar,AR,events);
            button_press_moove(r_f,F,events);
            button_press_moove(r_af,AF,events);
            button_press_moove(r_b,B,events);
            button_press_moove(r_ab,AB,events);


            if(events.button.button == SDL_BUTTON_LEFT)
            {
                if( ((events.button.x >= r_restart.x) && (events.button.x <= (r_restart.x + r_restart.w))) && ((events.button.y >= r_restart.y) && (events.button.y <= (r_restart.y + r_restart.h))))
                {
                    init_color("monfichier.txt");
                    Mix_PlayChannel(-1,Restart_Sound,2);
                    Mix_VolumeChunk(Restart_Sound,100);
                }
                if( ((events.button.x >= r_solve.x) && (events.button.x <= (r_solve.x + r_solve.w))) && ((events.button.y >= r_solve.y) && (events.button.y <= (r_solve.y + r_solve.h))))
                {
                    printf("--------------------------solve----------------------\n");
                    nb_rotation=0;
                    do_white_cross();
                    do_white_face();
                    step_3_do_color_edges();
                    Mix_PlayChannel(-1,Solve_Sound,0);
                    Mix_VolumeChunk(Solve_Sound,15);
                    printf("\n Nombre de rotation : %d \n",nb_rotation);
                }
            }
        }
        else if (events.type==SDL_MOUSEMOTION)
        {
            //mouvement
            button_step(r_u,"Up_MOUSE.bmp","Up.bmp",events,Tic_Sound);
            button_step(r_d,"Down_MOUSE.bmp","Down.bmp",events,Tic_Sound);
            button_step(r_l,"Left_MOUSE.bmp","Left.bmp",events,Tic_Sound);
            button_step(r_r,"Right_MOUSE.bmp","Right.bmp",events,Tic_Sound);
            button_step(r_f,"Front_MOUSE.bmp","Front.bmp",events,Tic_Sound);
            button_step(r_b,"Back_MOUSE.bmp","Back.bmp",events,Tic_Sound);

            button_step(r_au,"Anti_Up_MOUSE.bmp","Anti_Up.bmp",events,Tic_Sound);
            button_step(r_ad,"Anti_Down_MOUSE.bmp","Anti_Down.bmp",events,Tic_Sound);
            button_step(r_al,"Anti_Left_MOUSE.bmp","Anti_Left.bmp",events,Tic_Sound);
            button_step(r_ar,"Anti_Right_MOUSE.bmp","Anti_Right.bmp",events,Tic_Sound);
            button_step(r_af,"Anti_Front_MOUSE.bmp","Anti_Front.bmp",events,Tic_Sound);
            button_step(r_ab,"Anti_Back_MOUSE.bmp","Anti_Back.bmp",events,Tic_Sound);

            //etape
            button_step(r_step_1,"STEP_1_MOUSE.bmp","STEP_1.bmp",events,Tic_Sound);
            button_step(r_step_2,"STEP_2_MOUSE.bmp","STEP_2.bmp",events,Tic_Sound);
            button_step(r_step_3,"STEP_3_MOUSE.bmp","STEP_3.bmp",events,Tic_Sound);
            button_step(r_step_6,"STEP_6_MOUSE.bmp","STEP_6.bmp",events,Tic_Sound);
            button_step(r_step_5,"STEP_5_MOUSE.bmp","STEP_5.bmp",events,Tic_Sound);
            button_step(r_step_4,"STEP_4_MOUSE.bmp","STEP_4.bmp",events,Tic_Sound);

        }

        remplissage_carre(renderer);
        /*init_pic(renderer,window,"Up.bmp",r_u);
        init_pic(renderer,window,"Anti_Up.bmp",r_au);
        init_pic(renderer,window,"Down.bmp",r_d);
        init_pic(renderer,window,"Anti_Down.bmp",r_ad);
        init_pic(renderer,window,"Left.bmp",r_l);
        init_pic(renderer,window,"Anti_Left.bmp",r_al);
        init_pic(renderer,window,"Right.bmp",r_r);
        init_pic(renderer,window,"Anti_Right.bmp",r_ar);
        init_pic(renderer,window,"Front.bmp",r_f);
        init_pic(renderer,window,"Anti_Front.bmp",r_af);
        init_pic(renderer,window,"Back.bmp",r_b);
        init_pic(renderer,window,"Anti_Back.bmp",r_ab);*/

        init_pic(renderer,window,"Solve.bmp",r_solve);
        init_pic(renderer,window,"Restart.bmp",r_restart);

        //display();
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
//    TTF_CloseFont(police);
    TTF_Quit();
    TTF_Quit();
    SDL_Quit();
    return 0;
}
