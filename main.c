#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
#include <stdbool.h>

#include "INIT.h"
#include "interface_graphique.h"
#include "movement.h"
#include "solve.h"
#include "button.h"
#include "init_color.h"

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

    if(TTF_Init()==-1)
    {
        printf("erreur chargement du texte \n");
    }
    //audio
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT,2,2048);
    Rotation_Sound = Mix_LoadWAV("bruitage.wav");
    Solve_Sound = Mix_LoadWAV("mario.wav");
    Restart_Sound = Mix_LoadWAV("restart.wav");
    Tic_Sound = Mix_LoadWAV("tic.wav");
    Tic_Sound2 = Mix_LoadWAV("tic_pes2.wav");
    Tic_Sound3 = Mix_LoadWAV("tic_pes3.wav");

    isOpen=true;
    flag2=0;
    while(isOpen)
    {
        SDL_WaitEvent(&events);
        if(events.type==SDL_QUIT)
        {
            isOpen=false;
        }
        else if (events.type==SDL_KEYDOWN)
        {
            for(int i=0; i<200; i++)
            {
                tableau_next[i]=15;
            }
            switch(events.key.keysym.sym)
            {
            case SDLK_a:
                flag2=0;
                indice_next=0;
                indice_tableau_next=0;
                rotate_moove(F,renderer);
                break;
            case SDLK_b:
                flag2=0;
                indice_next=0;
                indice_tableau_next=0;
                rotate_moove(AF,renderer);
                break;
            case SDLK_c:
                flag2=0;
                indice_next=0;
                indice_tableau_next=0;
                rotate_moove(R,renderer);
                break;
            case SDLK_d:
                flag2=0;
                indice_next=0;
                indice_tableau_next=0;
                rotate_moove(AR,renderer);
                break;
            case SDLK_e:
                flag2=0;
                indice_next=0;
                indice_tableau_next=0;
                rotate_moove(U,renderer);
                break;
            case SDLK_f:
                flag2=0;
                indice_next=0;
                indice_tableau_next=0;
                rotate_moove(AU,renderer);
                break;
            case SDLK_g:
                flag2=0;
                indice_next=0;
                indice_tableau_next=0;
                rotate_moove(B,renderer);
                break;
            case SDLK_h:
                flag2=0;
                indice_next=0;
                indice_tableau_next=0;
                rotate_moove(AB,renderer);
                break;
            case SDLK_i:
                flag2=0;
                indice_next=0;
                indice_tableau_next=0;
                rotate_moove(L,renderer);
                break;
            case SDLK_j:
                flag2=0;
                indice_next=0;
                indice_tableau_next=0;
                rotate_moove(AL,renderer);
                break;
            case SDLK_k:
                flag2=0;
                indice_next=0;
                indice_tableau_next=0;
                rotate_moove(D,renderer);
                break;
            case SDLK_l:
                flag2=0;
                indice_next=0;
                indice_tableau_next=0;
                rotate_moove(AD,renderer);
                break;
            case SDLK_z:
                flag2=0;
                indice_next=0;
                indice_tableau_next=0;
                init_color("monfichier.txt");
                break;
            case SDLK_s:
                flag2=0;
                indice_next=0;
                indice_tableau_next=0;
                for(int i=0; i<200; i++)
                {
                    tableau_next[i]=15;
                }
                printf("--------------------------solve----------------------\n");
                nb_rotation=0;
                indice_tab_moove=0;
                step_1_do_white_cross();
                step_2_do_white_face();
                step_3_do_color_edges();
                step_4_yellow_cross();
                step_5_yellow_corner();
                step_6_yellow_corner_near_cubes();
                step_7_yellow_arretes();
                printf("\n Nombre de rotation : %d \n",nb_rotation);
                display_nb_roation();
                break;
            case SDLK_m:
                //flag2=0;
                indice_next=0;
                indice_tableau_next=0;
                shuffle_rubik();
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
                    remplissage_carre(renderer);
                }
                if( ((events.button.x >= r_solve.x) && (events.button.x <= (r_solve.x + r_solve.w))) && ((events.button.y >= r_solve.y) && (events.button.y <= (r_solve.y + r_solve.h))))
                {
                    for(int i=0; i<200; i++)
                    {
                        tableau_next[i]=15;
                    }
                    printf("--------------------------solve----------------------\n");
                    nb_rotation=0;
                    indice_tab_moove=0;
                    step_1_do_white_cross();
                    step_2_do_white_face();
                    step_3_do_color_edges();
                    step_4_yellow_cross();
                    step_5_yellow_corner();
                    step_6_yellow_corner_near_cubes();
                    step_7_yellow_arretes();
                    Mix_PlayChannel(-1,Solve_Sound,0);
                    Mix_VolumeChunk(Solve_Sound,15);
                    printf("\n Nombre de rotation : %d \n",nb_rotation);
                    display_nb_roation();
                    remplissage_carre(renderer);
                }
                if(((events.button.x >= r_step_1.x) && (events.button.x <= (r_step_1.x + r_step_1.w))) && ((events.button.y >= r_step_1.y) && (events.button.y <= (r_step_1.y + r_step_1.h))))
                    step_1_do_white_cross();
                if(((events.button.x >= r_step_2.x) && (events.button.x <= (r_step_2.x + r_step_2.w))) && ((events.button.y >= r_step_2.y) && (events.button.y <= (r_step_2.y + r_step_2.h))))
                    step_2_do_white_face();
                if(((events.button.x >= r_step_3.x) && (events.button.x <= (r_step_3.x + r_step_3.w))) && ((events.button.y >= r_step_3.y) && (events.button.y <= (r_step_3.y + r_step_3.h))))
                    step_3_do_color_edges();
                if(((events.button.x >= r_step_4.x) && (events.button.x <= (r_step_4.x + r_step_4.w))) && ((events.button.y >= r_step_4.y) && (events.button.y <= (r_step_4.y + r_step_4.h))))
                    step_4_yellow_cross();
                if(((events.button.x >= r_step_5.x) && (events.button.x <= (r_step_5.x + r_step_5.w))) && ((events.button.y >= r_step_5.y) && (events.button.y <= (r_step_5.y + r_step_5.h))))
                    step_5_yellow_corner();
                if(((events.button.x >= r_step_6.x) && (events.button.x <= (r_step_6.x + r_step_6.w))) && ((events.button.y >= r_step_6.y) && (events.button.y <= (r_step_6.y + r_step_6.h))))
                {
                    step_6_yellow_corner_near_cubes();
                    step_7_yellow_arretes();
                }
                if(((events.button.x >= r_next_move.x) && (events.button.x <= (r_next_move.x + r_next_move.w))) && ((events.button.y >= r_next_move.y) && (events.button.y <= (r_next_move.y + r_next_move.h))))
                {
                    fonction_next(renderer,window);
                }
                verify_increment_color(events.button.x, events.button.y);
            }
        }
        else if (events.type==SDL_MOUSEMOTION)
        {

            button_step(r_solve,"Solve_mouse.bmp","Solve.bmp",events,Tic_Sound);
            button_step(r_next_move,"next_move_mouse.bmp","next_move.bmp",events,Tic_Sound);
            button_step(r_restart,"Restart_mouse.bmp","Restart.bmp",events,Tic_Sound);
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
        if(flag==0)
        {
            flag=1;
            display_nb_roation();
            init_pic(renderer,window,"Up.bmp",r_u);
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
            init_pic(renderer,window,"Anti_Back.bmp",r_ab);

            init_pic(renderer,window,"STEP_1.bmp",r_step_1);
            init_pic(renderer,window,"STEP_2.bmp",r_step_2);
            init_pic(renderer,window,"STEP_3.bmp",r_step_3);
            init_pic(renderer,window,"STEP_4.bmp",r_step_4);
            init_pic(renderer,window,"STEP_5.bmp",r_step_5);
            init_pic(renderer,window,"STEP_6.bmp",r_step_6);
            init_pic(renderer,window,"Solve.bmp",r_solve);
            init_pic(renderer,window,"Restart.bmp",r_restart);
        }

    }
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    TTF_CloseFont(police);
    TTF_Quit();
    SDL_Quit();
    return 0;
}
