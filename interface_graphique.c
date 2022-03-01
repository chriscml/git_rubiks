#include "interface_graphique.h"
#include "INIT.h"
#include <stdio.h>
#include <SDL2/SDL.h>

void init_sdl(void)
{
   if(SDL_Init(SDL_INIT_VIDEO)!=0)
    {
        printf("Initialisation SDL \n");
    }
    if(SDL_CreateWindowAndRenderer(WINDOW_WIDTH,WINDOW_LENGHT,0,&window,&renderer)!=0)
    {
        printf("Impossible d'ouvrir la fenetre et de creer le rendu\n");
    }
    else
    {
        printf("creation fenetre et rendu reussi \n");
    }
    SDL_SetRenderDrawColor(renderer, 0,0,0,255);
    SDL_RenderClear(renderer);
}

void remplissage_carre(SDL_Renderer* renderer)
{
    // FACE FRONT -------------------------------------------------------------
    SDL_SetRenderDrawColor(renderer,get_red(FRONT[0].color), get_green(FRONT[0].color), get_blue(FRONT[0].color), 255 );
    SDL_RenderFillRect(renderer, &rf1);

    SDL_SetRenderDrawColor(renderer,get_red(FRONT[1].color), get_green(FRONT[1].color), get_blue(FRONT[1].color), 255 );
    SDL_RenderFillRect(renderer, &rf2);

    SDL_SetRenderDrawColor(renderer,get_red(FRONT[2].color), get_green(FRONT[2].color), get_blue(FRONT[2].color), 255 );
    SDL_RenderFillRect(renderer, &rf3);

    SDL_SetRenderDrawColor(renderer,get_red(FRONT[3].color), get_green(FRONT[3].color), get_blue(FRONT[3].color), 255 );
    SDL_RenderFillRect(renderer, &rf4);

    SDL_SetRenderDrawColor(renderer,get_red(FRONT[4].color), get_green(FRONT[4].color), get_blue(FRONT[4].color), 255 );
    SDL_RenderFillRect(renderer, &rf5);

    SDL_SetRenderDrawColor(renderer,get_red(FRONT[5].color), get_green(FRONT[5].color), get_blue(FRONT[5].color), 255 );
    SDL_RenderFillRect(renderer, &rf6);

    SDL_SetRenderDrawColor(renderer,get_red(FRONT[6].color), get_green(FRONT[6].color), get_blue(FRONT[6].color), 255 );
    SDL_RenderFillRect(renderer, &rf7);

    SDL_SetRenderDrawColor(renderer,get_red(FRONT[7].color), get_green(FRONT[7].color), get_blue(FRONT[7].color), 255 );
    SDL_RenderFillRect(renderer, &rf8);

    SDL_SetRenderDrawColor(renderer,get_red(FRONT[8].color), get_green(FRONT[8].color), get_blue(FRONT[8].color), 255 );
    SDL_RenderFillRect(renderer, &rf9);

    // FACE BACK -----------------------------------------------------------------------------------
    SDL_SetRenderDrawColor(renderer,get_red(BACK[0].color), get_green(BACK[0].color), get_blue(BACK[0].color), 255 );
    SDL_RenderFillRect(renderer, &rb1);

    SDL_SetRenderDrawColor(renderer,get_red(BACK[1].color), get_green(BACK[1].color), get_blue(BACK[1].color), 255 );
    SDL_RenderFillRect(renderer, &rb2);

    SDL_SetRenderDrawColor(renderer,get_red(BACK[2].color), get_green(BACK[2].color), get_blue(BACK[2].color), 255 );
    SDL_RenderFillRect(renderer, &rb3);

    SDL_SetRenderDrawColor(renderer,get_red(BACK[3].color), get_green(BACK[3].color), get_blue(BACK[3].color), 255 );
    SDL_RenderFillRect(renderer, &rb4);

    SDL_SetRenderDrawColor(renderer,get_red(BACK[4].color), get_green(BACK[4].color), get_blue(BACK[4].color), 255 );
    SDL_RenderFillRect(renderer, &rb5);

    SDL_SetRenderDrawColor(renderer,get_red(BACK[5].color), get_green(BACK[5].color), get_blue(BACK[5].color), 255 );
    SDL_RenderFillRect(renderer, &rb6);

    SDL_SetRenderDrawColor(renderer,get_red(BACK[6].color), get_green(BACK[6].color), get_blue(BACK[6].color), 255 );
    SDL_RenderFillRect(renderer, &rb7);

    SDL_SetRenderDrawColor(renderer,get_red(BACK[7].color), get_green(BACK[7].color), get_blue(BACK[7].color), 255 );
    SDL_RenderFillRect(renderer, &rb8);

    SDL_SetRenderDrawColor(renderer,get_red(BACK[8].color), get_green(BACK[8].color), get_blue(BACK[8].color), 255 );
    SDL_RenderFillRect(renderer, &rb9);

    //FACE LEFT -------------------------------------

    SDL_SetRenderDrawColor(renderer,get_red(LEFT[0].color), get_green(LEFT[0].color), get_blue(LEFT[0].color), 255 );
    SDL_RenderFillRect(renderer, &rl1);

    SDL_SetRenderDrawColor(renderer,get_red(LEFT[1].color), get_green(LEFT[1].color), get_blue(LEFT[1].color), 255 );
    SDL_RenderFillRect(renderer, &rl2);

    SDL_SetRenderDrawColor(renderer,get_red(LEFT[2].color), get_green(LEFT[2].color), get_blue(LEFT[2].color), 255 );
    SDL_RenderFillRect(renderer, &rl3);

    SDL_SetRenderDrawColor(renderer,get_red(LEFT[3].color), get_green(LEFT[3].color), get_blue(LEFT[3].color), 255 );
    SDL_RenderFillRect(renderer, &rl4);

    SDL_SetRenderDrawColor(renderer,get_red(LEFT[4].color), get_green(LEFT[4].color), get_blue(LEFT[4].color), 255 );
    SDL_RenderFillRect(renderer, &rl5);

    SDL_SetRenderDrawColor(renderer,get_red(LEFT[5].color), get_green(LEFT[5].color), get_blue(LEFT[5].color), 255 );
    SDL_RenderFillRect(renderer, &rl6);

    SDL_SetRenderDrawColor(renderer,get_red(LEFT[6].color), get_green(LEFT[6].color), get_blue(LEFT[6].color), 255 );
    SDL_RenderFillRect(renderer, &rl7);

    SDL_SetRenderDrawColor(renderer,get_red(LEFT[7].color), get_green(LEFT[7].color), get_blue(LEFT[7].color), 255 );
    SDL_RenderFillRect(renderer, &rl8);

    SDL_SetRenderDrawColor(renderer,get_red(LEFT[8].color), get_green(LEFT[8].color), get_blue(LEFT[8].color), 255 );
    SDL_RenderFillRect(renderer, &rl9);

    //FACE RIGHT ------------------------------------------------------------

    SDL_SetRenderDrawColor(renderer,get_red(RIGHT[0].color), get_green(RIGHT[0].color), get_blue(RIGHT[0].color), 255 );
    SDL_RenderFillRect(renderer, &rr1);

    SDL_SetRenderDrawColor(renderer,get_red(RIGHT[1].color), get_green(RIGHT[1].color), get_blue(RIGHT[1].color), 255 );
    SDL_RenderFillRect(renderer, &rr2);

    SDL_SetRenderDrawColor(renderer,get_red(RIGHT[2].color), get_green(RIGHT[2].color), get_blue(RIGHT[2].color), 255 );
    SDL_RenderFillRect(renderer, &rr3);

    SDL_SetRenderDrawColor(renderer,get_red(RIGHT[3].color), get_green(RIGHT[3].color), get_blue(RIGHT[3].color), 255 );
    SDL_RenderFillRect(renderer, &rr4);

    SDL_SetRenderDrawColor(renderer,get_red(RIGHT[4].color), get_green(RIGHT[4].color), get_blue(RIGHT[4].color), 255 );
    SDL_RenderFillRect(renderer, &rr5);

    SDL_SetRenderDrawColor(renderer,get_red(RIGHT[5].color), get_green(RIGHT[5].color), get_blue(RIGHT[5].color), 255 );
    SDL_RenderFillRect(renderer, &rr6);

    SDL_SetRenderDrawColor(renderer,get_red(RIGHT[6].color), get_green(RIGHT[6].color), get_blue(RIGHT[6].color), 255 );
    SDL_RenderFillRect(renderer, &rr7);

    SDL_SetRenderDrawColor(renderer,get_red(RIGHT[7].color), get_green(RIGHT[7].color), get_blue(RIGHT[7].color), 255 );
    SDL_RenderFillRect(renderer, &rr8);

    SDL_SetRenderDrawColor(renderer,get_red(RIGHT[8].color), get_green(RIGHT[8].color), get_blue(RIGHT[8].color), 255 );
    SDL_RenderFillRect(renderer, &rr9);

    // FACE UP -----------------------------------------------------------------------

    SDL_SetRenderDrawColor(renderer,get_red(UP[0].color), get_green(UP[0].color), get_blue(UP[0].color), 255 );
    SDL_RenderFillRect(renderer, &ru1);

    SDL_SetRenderDrawColor(renderer,get_red(UP[1].color), get_green(UP[1].color), get_blue(UP[1].color), 255 );
    SDL_RenderFillRect(renderer, &ru2);

    SDL_SetRenderDrawColor(renderer,get_red(UP[2].color), get_green(UP[2].color), get_blue(UP[2].color), 255 );
    SDL_RenderFillRect(renderer, &ru3);

    SDL_SetRenderDrawColor(renderer,get_red(UP[3].color), get_green(UP[3].color), get_blue(UP[3].color), 255 );
    SDL_RenderFillRect(renderer, &ru4);

    SDL_SetRenderDrawColor(renderer,get_red(UP[4].color), get_green(UP[4].color), get_blue(UP[4].color), 255 );
    SDL_RenderFillRect(renderer, &ru5);

    SDL_SetRenderDrawColor(renderer,get_red(UP[5].color), get_green(UP[5].color), get_blue(UP[5].color), 255 );
    SDL_RenderFillRect(renderer, &ru6);

    SDL_SetRenderDrawColor(renderer,get_red(UP[6].color), get_green(UP[6].color), get_blue(UP[6].color), 255 );
    SDL_RenderFillRect(renderer, &ru7);

    SDL_SetRenderDrawColor(renderer,get_red(UP[7].color), get_green(UP[7].color), get_blue(UP[7].color), 255 );
    SDL_RenderFillRect(renderer, &ru8);

    SDL_SetRenderDrawColor(renderer,get_red(UP[8].color), get_green(UP[8].color), get_blue(UP[8].color), 255 );
    SDL_RenderFillRect(renderer, &ru9);

    // FACE DOWN --------------------------------------------------------------------------

    SDL_SetRenderDrawColor(renderer,get_red(DOWN[0].color), get_green(DOWN[0].color), get_blue(DOWN[0].color), 255 );
    SDL_RenderFillRect(renderer, &rd1);

    SDL_SetRenderDrawColor(renderer,get_red(DOWN[1].color), get_green(DOWN[1].color), get_blue(DOWN[1].color), 255 );
    SDL_RenderFillRect(renderer, &rd2);

    SDL_SetRenderDrawColor(renderer,get_red(DOWN[2].color), get_green(DOWN[2].color), get_blue(DOWN[2].color), 255 );
    SDL_RenderFillRect(renderer, &rd3);

    SDL_SetRenderDrawColor(renderer,get_red(DOWN[3].color), get_green(DOWN[3].color), get_blue(DOWN[3].color), 255 );
    SDL_RenderFillRect(renderer, &rd4);

    SDL_SetRenderDrawColor(renderer,get_red(DOWN[4].color), get_green(DOWN[4].color), get_blue(DOWN[4].color), 255 );
    SDL_RenderFillRect(renderer, &rd5);

    SDL_SetRenderDrawColor(renderer,get_red(DOWN[5].color), get_green(DOWN[5].color), get_blue(DOWN[5].color), 255 );
    SDL_RenderFillRect(renderer, &rd6);

    SDL_SetRenderDrawColor(renderer,get_red(DOWN[6].color), get_green(DOWN[6].color), get_blue(DOWN[6].color), 255 );
    SDL_RenderFillRect(renderer, &rd7);

    SDL_SetRenderDrawColor(renderer,get_red(DOWN[7].color), get_green(DOWN[7].color), get_blue(DOWN[7].color), 255 );
    SDL_RenderFillRect(renderer, &rd8);

    SDL_SetRenderDrawColor(renderer,get_red(DOWN[8].color), get_green(DOWN[8].color), get_blue(DOWN[8].color), 255 );
    SDL_RenderFillRect(renderer, &rd9);

    // Dessin des lignes -------------------------------------------------------------
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderDrawLine(renderer, 50, 0, 50, 480);
    SDL_RenderDrawLine(renderer, 100, 0, 100, 480);
    SDL_RenderDrawLine(renderer, 150, 0, 150, 480);
    SDL_RenderDrawLine(renderer, 200, 0, 200, 480);
    SDL_RenderDrawLine(renderer, 250, 0, 250, 480);
    SDL_RenderDrawLine(renderer, 300, 0, 300, 480);
    SDL_RenderDrawLine(renderer, 350, 0, 350, 480);
    SDL_RenderDrawLine(renderer, 400, 0, 400, 480);
    SDL_RenderDrawLine(renderer, 450, 0, 450, 480);
    SDL_RenderDrawLine(renderer, 500, 0, 500, 480);
    SDL_RenderDrawLine(renderer, 550, 0, 550, 480);

    SDL_RenderDrawLine(renderer, 0, 50, 640, 50);
    SDL_RenderDrawLine(renderer, 0, 100, 640, 100);
    SDL_RenderDrawLine(renderer, 0, 150, 640, 150);
    SDL_RenderDrawLine(renderer, 0, 200, 640, 200);
    SDL_RenderDrawLine(renderer, 0, 250, 640, 250);
    SDL_RenderDrawLine(renderer, 0, 300, 640, 300);
    SDL_RenderDrawLine(renderer, 0, 350, 640, 350);
    SDL_RenderDrawLine(renderer, 0, 400, 640, 400);
    SDL_RenderDrawLine(renderer, 0, 450, 640, 450);


    SDL_RenderPresent(renderer);


}
uint8_t get_red(color_t color)
{
    switch(color)
    {
    case 1: //1:rouge 2: bleu 3:blanc 4: vert 5: jaune 6:orange
        return 255;
        break;

    case 2:
        return 0;
        break;
    case 3:
        return 255;
        break;
    case 4:
        return 0;
        break;
    case 5:
        return 255;
        break;
    case 6:
        return 255;
        break;
    default:
        return 1;
        break;
    }
}

uint8_t get_green(color_t color)
{
    switch(color)
    {
    case 1: //1:rouge 2: bleu 3:blanc 4: vert 5: jaune 6:orange
        return 0;
        break;

    case 2:
        return 0;
        break;
    case 3:
        return 255;
        break;
    case 4:
        return 255;
        break;
    case 5:
        return 255;
        break;
    case 6:
        return 127;
        break;
    default:
        return 1;
        break;
    }
}

uint8_t get_blue(color_t color)
{
    switch(color)
    {
    case 1: //1:rouge 2: bleu 3:blanc 4: vert 5: jaune 6:orange
        return 0;
        break;

    case 2:
        return 139;
        break;
    case 3:
        return 255;
        break;
    case 4:
        return 0;
        break;
    case 5:
        return 0;
        break;
    case 6:
        return 0;
        break;
    default:
        return 1;
        break;
    }
}

void carrre_init_pos(void){
    //-FACE 1 FRONT ----------------------------
    rf1.x=150;
    rf1.y=150;
    rf1.w=50;
    rf1.h=50;

    rf2.x=200;
    rf2.y=150;
    rf2.w=50;
    rf2.h=50;

    rf3.x=250;
    rf3.y=150;
    rf3.w=50;
    rf3.h=50;

    rf4.x=150;
    rf4.y=200;
    rf4.w=50;
    rf4.h=50;

    rf5.x=200;
    rf5.y=200;
    rf5.w=50;
    rf5.h=50;

    rf6.x=250;
    rf6.y=200;
    rf6.w=50;
    rf6.h=50;

    rf7.x=150;
    rf7.y=250;
    rf7.w=50;
    rf7.h=50;

    rf8.x=200;
    rf8.y=250;
    rf8.w=50;
    rf8.h=50;

    rf9.x=250;
    rf9.y=250;
    rf9.w=50;
    rf9.h=50;

    // FACE 2  BACK -----------------------

    rb1.x=450;
    rb1.y=150;
    rb1.w=50;
    rb1.h=50;

    rb2.x=500;
    rb2.y=150;
    rb2.w=50;
    rb2.h=50;

    rb3.x=550;
    rb3.y=150;
    rb3.w=50;
    rb3.h=50;

    rb4.x=450;
    rb4.y=200;
    rb4.w=50;
    rb4.h=50;

    rb5.x=500;
    rb5.y=200;
    rb5.w=50;
    rb5.h=50;

    rb6.x=550;
    rb6.y=200;
    rb6.w=50;
    rb6.h=50;

    rb7.x=450;
    rb7.y=250;
    rb7.w=50;
    rb7.h=50;

    rb8.x=500;
    rb8.y=250;
    rb8.w=50;
    rb8.h=50;

    rb9.x=550;
    rb9.y=250;
    rb9.w=50;
    rb9.h=50;

    // FACE 3 LEFT -----------------------------------------

    rl1.x=0;
    rl1.y=150;
    rl1.w=50;
    rl1.h=50;

    rl2.x=50;
    rl2.y=150;
    rl2.w=50;
    rl2.h=50;

    rl3.x=100;
    rl3.y=150;
    rl3.w=50;
    rl3.h=50;

    rl4.x=0;
    rl4.y=200;
    rl4.w=50;
    rl4.h=50;

    rl5.x=50;
    rl5.y=200;
    rl5.w=50;
    rl5.h=50;

    rl6.x=100;
    rl6.y=200;
    rl6.w=50;
    rl6.h=50;

    rl7.x=0;
    rl7.y=250;
    rl7.w=50;
    rl7.h=50;

    rl8.x=50;
    rl8.y=250;
    rl8.w=50;
    rl8.h=50;

    rl9.x=100;
    rl9.y=250;
    rl9.w=50;
    rl9.h=50;

    // FACE 4 RIGHT ---------------------------------

    rr1.x=300;
    rr1.y=150;
    rr1.w=50;
    rr1.h=50;

    rr2.x=350;
    rr2.y=150;
    rr2.w=50;
    rr2.h=50;

    rr3.x=400;
    rr3.y=150;
    rr3.w=50;
    rr3.h=50;

    rr4.x=300;
    rr4.y=200;
    rr4.w=50;
    rr4.h=50;

    rr5.x=350;
    rr5.y=200;
    rr5.w=50;
    rr5.h=50;

    rr6.x=400;
    rr6.y=200;
    rr6.w=50;
    rr6.h=50;

    rr7.x=300;
    rr7.y=250;
    rr7.w=50;
    rr7.h=50;

    rr8.x=350;
    rr8.y=250;
    rr8.w=50;
    rr8.h=50;

    rr9.x=400;
    rr9.y=250;
    rr9.w=50;
    rr9.h=50;

    //Face 5 UP ----------------------------------------

    ru1.x=150;
    ru1.y=0;
    ru1.w=50;
    ru1.h=50;

    ru2.x=200;
    ru2.y=0;
    ru2.w=50;
    ru2.h=50;

    ru3.x=250;
    ru3.y=0;
    ru3.w=50;
    ru3.h=50;

    ru4.x=150;
    ru4.y=50;
    ru4.w=50;
    ru4.h=50;

    ru5.x=200;
    ru5.y=50;
    ru5.w=50;
    ru5.h=50;

    ru6.x=250;
    ru6.y=50;
    ru6.w=50;
    ru6.h=50;

    ru7.x=150;
    ru7.y=100;
    ru7.w=50;
    ru7.h=50;

    ru8.x=200;
    ru8.y=100;
    ru8.w=50;
    ru8.h=50;

    ru9.x=250;
    ru9.y=100;
    ru9.w=50;
    ru9.h=50;

    //FACE 6 DOWN -----------------------------------------
    rd1.x=150;
    rd1.y=300;
    rd1.w=50;
    rd1.h=50;

    rd2.x=200;
    rd2.y=300;
    rd2.w=50;
    rd2.h=50;

    rd3.x=250;
    rd3.y=300;
    rd3.w=50;
    rd3.h=50;

    rd4.x=150;
    rd4.y=350;
    rd4.w=50;
    rd4.h=50;

    rd5.x=200;
    rd5.y=350;
    rd5.w=50;
    rd5.h=50;

    rd6.x=250;
    rd6.y=350;
    rd6.w=50;
    rd6.h=50;

    rd7.x=150;
    rd7.y=400;
    rd7.w=50;
    rd7.h=50;

    rd8.x=200;
    rd8.y=400;
    rd8.w=50;
    rd8.h=50;

    rd9.x=250;
    rd9.y=400;
    rd9.w=50;
    rd9.h=50;
}
