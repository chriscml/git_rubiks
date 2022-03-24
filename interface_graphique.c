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
    SDL_SetRenderDrawColor(renderer, 55,55,125,255);
    SDL_RenderClear(renderer);
}

void remplissage_carre(SDL_Renderer* renderer)
{
    // FACE FRONT -------------------------------------------------------------
    for(int i=0; i<9; i++)
    {
        SDL_SetRenderDrawColor(renderer, get_red(FRONT[i].color), get_green(FRONT[i].color), get_blue(FRONT[i].color), 255);
        SDL_RenderFillRect(renderer, &FRONT[i].rect);
    }

    // FACE BACK -----------------------------------------------------------------------------------
    for(int i=0; i<9; i++)
    {
        SDL_SetRenderDrawColor(renderer, get_red(BACK[i].color), get_green(BACK[i].color), get_blue(BACK[i].color), 255);
        SDL_RenderFillRect(renderer, &BACK[i].rect);
    }

    //FACE LEFT -------------------------------------

    for(int i=0; i<9; i++)
    {
        SDL_SetRenderDrawColor(renderer, get_red(LEFT[i].color), get_green(LEFT[i].color), get_blue(LEFT[i].color), 255);
        SDL_RenderFillRect(renderer, &LEFT[i].rect);
    }

    //FACE RIGHT ------------------------------------------------------------

    for(int i=0; i<9; i++)
    {
        SDL_SetRenderDrawColor(renderer, get_red(RIGHT[i].color), get_green(RIGHT[i].color), get_blue(RIGHT[i].color), 255);
        SDL_RenderFillRect(renderer, &RIGHT[i].rect);
    }

    // FACE UP -----------------------------------------------------------------------

    for(int i=0; i<9; i++)
    {
        SDL_SetRenderDrawColor(renderer, get_red(UP[i].color), get_green(UP[i].color), get_blue(UP[i].color), 255);
        SDL_RenderFillRect(renderer, &UP[i].rect);
    }

    // FACE DOWN --------------------------------------------------------------------------

    for(int i=0; i<9; i++)
    {
        SDL_SetRenderDrawColor(renderer, get_red(DOWN[i].color), get_green(DOWN[i].color), get_blue(DOWN[i].color), 255);
        SDL_RenderFillRect(renderer, &DOWN[i].rect);
    }

    // Dessin des lignes -------------------------------------------------------------

    //verticale
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderDrawLine(renderer, 150, 0, 300, 0);
    SDL_RenderDrawLine(renderer, 150, 50, 300, 50);
    SDL_RenderDrawLine(renderer, 150, 100, 300, 100);
    SDL_RenderDrawLine(renderer, 0, 150, 600, 150);
    SDL_RenderDrawLine(renderer, 0, 200, 600, 200);
    SDL_RenderDrawLine(renderer, 0, 250, 600, 250);
    SDL_RenderDrawLine(renderer, 0, 300, 600, 300);
    SDL_RenderDrawLine(renderer, 150, 350, 300, 350);
    SDL_RenderDrawLine(renderer, 150, 400, 300, 400);
    SDL_RenderDrawLine(renderer, 150, 450, 300, 450);

    //horizontale
    SDL_RenderDrawLine(renderer, 0, 150, 0, 300);
    SDL_RenderDrawLine(renderer, 50, 150, 50, 300);
    SDL_RenderDrawLine(renderer, 100, 150, 100, 300);
    SDL_RenderDrawLine(renderer, 150, 0, 150, 450);
    SDL_RenderDrawLine(renderer, 200, 0, 200, 450);
    SDL_RenderDrawLine(renderer, 250, 0, 250, 450);
    SDL_RenderDrawLine(renderer, 300, 0, 300, 450);
    SDL_RenderDrawLine(renderer, 350, 150, 350, 300);
    SDL_RenderDrawLine(renderer, 400, 150, 400, 300);
    SDL_RenderDrawLine(renderer, 450, 150, 450, 300);
    SDL_RenderDrawLine(renderer, 500, 150, 500, 300);
    SDL_RenderDrawLine(renderer, 550, 150, 550, 300);
    SDL_RenderDrawLine(renderer, 600, 150, 600, 300);


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

void carrre_init_pos(void)
{
    //-FACE 1 FRONT ----------------------------
    FRONT[0].rect.x=150;
    FRONT[0].rect.y=150;
    FRONT[0].rect.w=50;
    FRONT[0].rect.h=50;

    FRONT[1].rect.x=200;
    FRONT[1].rect.y=150;
    FRONT[1].rect.w=50;
    FRONT[1].rect.h=50;

    FRONT[2].rect.x=250;
    FRONT[2].rect.y=150;
    FRONT[2].rect.w=50;
    FRONT[2].rect.h=50;

    FRONT[3].rect.x=150;
    FRONT[3].rect.y=200;
    FRONT[3].rect.w=50;
    FRONT[3].rect.h=50;

    FRONT[4].rect.x=200;
    FRONT[4].rect.y=200;
    FRONT[4].rect.w=50;
    FRONT[4].rect.h=50;

    FRONT[5].rect.x=250;
    FRONT[5].rect.y=200;
    FRONT[5].rect.w=50;
    FRONT[5].rect.h=50;

    FRONT[6].rect.x=150;
    FRONT[6].rect.y=250;
    FRONT[6].rect.w=50;
    FRONT[6].rect.h=50;

    FRONT[7].rect.x=200;
    FRONT[7].rect.y=250;
    FRONT[7].rect.w=50;
    FRONT[7].rect.h=50;

    FRONT[8].rect.x=250;
    FRONT[8].rect.y=250;
    FRONT[8].rect.w=50;
    FRONT[8].rect.h=50;

    // FACE 2  BACK -----------------------

    BACK[0].rect.x=450;
    BACK[0].rect.y=150;
    BACK[0].rect.w=50;
    BACK[0].rect.h=50;

    BACK[1].rect.x=500;
    BACK[1].rect.y=150;
    BACK[1].rect.w=50;
    BACK[1].rect.h=50;

    BACK[2].rect.x=550;
    BACK[2].rect.y=150;
    BACK[2].rect.w=50;
    BACK[2].rect.h=50;

    BACK[3].rect.x=450;
    BACK[3].rect.y=200;
    BACK[3].rect.w=50;
    BACK[3].rect.h=50;

    BACK[4].rect.x=500;
    BACK[4].rect.y=200;
    BACK[4].rect.w=50;
    BACK[4].rect.h=50;

    BACK[5].rect.x=550;
    BACK[5].rect.y=200;
    BACK[5].rect.w=50;
    BACK[5].rect.h=50;

    BACK[6].rect.x=450;
    BACK[6].rect.y=250;
    BACK[6].rect.w=50;
    BACK[6].rect.h=50;

    BACK[7].rect.x=500;
    BACK[7].rect.y=250;
    BACK[7].rect.w=50;
    BACK[7].rect.h=50;

    BACK[8].rect.x=550;
    BACK[8].rect.y=250;
    BACK[8].rect.w=50;
    BACK[8].rect.h=50;

    // FACE 3 LEFT -----------------------------------------

    LEFT[0].rect.x=0;
    LEFT[0].rect.y=150;
    LEFT[0].rect.w=50;
    LEFT[0].rect.h=50;

    LEFT[1].rect.x=50;
    LEFT[1].rect.y=150;
    LEFT[1].rect.w=50;
    LEFT[1].rect.h=50;

    LEFT[2].rect.x=100;
    LEFT[2].rect.y=150;
    LEFT[2].rect.w=50;
    LEFT[2].rect.h=50;

    LEFT[3].rect.x=0;
    LEFT[3].rect.y=200;
    LEFT[3].rect.w=50;
    LEFT[3].rect.h=50;

    LEFT[4].rect.x=50;
    LEFT[4].rect.y=200;
    LEFT[4].rect.w=50;
    LEFT[4].rect.h=50;

    LEFT[5].rect.x=100;
    LEFT[5].rect.y=200;
    LEFT[5].rect.w=50;
    LEFT[5].rect.h=50;

    LEFT[6].rect.x=0;
    LEFT[6].rect.y=250;
    LEFT[6].rect.w=50;
    LEFT[6].rect.h=50;

    LEFT[7].rect.x=50;
    LEFT[7].rect.y=250;
    LEFT[7].rect.w=50;
    LEFT[7].rect.h=50;

    LEFT[8].rect.x=100;
    LEFT[8].rect.y=250;
    LEFT[8].rect.w=50;
    LEFT[8].rect.h=50;

    // FACE 4 RIGHT ---------------------------------

    RIGHT[0].rect.x=300;
    RIGHT[0].rect.y=150;
    RIGHT[0].rect.w=50;
    RIGHT[0].rect.h=50;

    RIGHT[1].rect.x=350;
    RIGHT[1].rect.y=150;
    RIGHT[1].rect.w=50;
    RIGHT[1].rect.h=50;

    RIGHT[2].rect.x=400;
    RIGHT[2].rect.y=150;
    RIGHT[2].rect.w=50;
    RIGHT[2].rect.h=50;

    RIGHT[3].rect.x=300;
    RIGHT[3].rect.y=200;
    RIGHT[3].rect.w=50;
    RIGHT[3].rect.h=50;

    RIGHT[4].rect.x=350;
    RIGHT[4].rect.y=200;
    RIGHT[4].rect.w=50;
    RIGHT[4].rect.h=50;

    RIGHT[5].rect.x=400;
    RIGHT[5].rect.y=200;
    RIGHT[5].rect.w=50;
    RIGHT[5].rect.h=50;

    RIGHT[6].rect.x=300;
    RIGHT[6].rect.y=250;
    RIGHT[6].rect.w=50;
    RIGHT[6].rect.h=50;

    RIGHT[7].rect.x=350;
    RIGHT[7].rect.y=250;
    RIGHT[7].rect.w=50;
    RIGHT[7].rect.h=50;

    RIGHT[8].rect.x=400;
    RIGHT[8].rect.y=250;
    RIGHT[8].rect.w=50;
    RIGHT[8].rect.h=50;

    //Face 5 UP ----------------------------------------

    UP[0].rect.x=150;
    UP[0].rect.y=0;
    UP[0].rect.w=50;
    UP[0].rect.h=50;

    UP[1].rect.x=200;
    UP[1].rect.y=0;
    UP[1].rect.w=50;
    UP[1].rect.h=50;

    UP[2].rect.x=250;
    UP[2].rect.y=0;
    UP[2].rect.w=50;
    UP[2].rect.h=50;

    UP[3].rect.x=150;
    UP[3].rect.y=50;
    UP[3].rect.w=50;
    UP[3].rect.h=50;

    UP[4].rect.x=200;
    UP[4].rect.y=50;
    UP[4].rect.w=50;
    UP[4].rect.h=50;

    UP[5].rect.x=250;
    UP[5].rect.y=50;
    UP[5].rect.w=50;
    UP[5].rect.h=50;

    UP[6].rect.x=150;
    UP[6].rect.y=100;
    UP[6].rect.w=50;
    UP[6].rect.h=50;

    UP[7].rect.x=200;
    UP[7].rect.y=100;
    UP[7].rect.w=50;
    UP[7].rect.h=50;

    UP[8].rect.x=250;
    UP[8].rect.y=100;
    UP[8].rect.w=50;
    UP[8].rect.h=50;

    //FACE 6 DOWN -----------------------------------------
    DOWN[0].rect.x=150;
    DOWN[0].rect.y=300;
    DOWN[0].rect.w=50;
    DOWN[0].rect.h=50;

    DOWN[1].rect.x=200;
    DOWN[1].rect.y=300;
    DOWN[1].rect.w=50;
    DOWN[1].rect.h=50;

    DOWN[2].rect.x=250;
    DOWN[2].rect.y=300;
    DOWN[2].rect.w=50;
    DOWN[2].rect.h=50;

    DOWN[3].rect.x=150;
    DOWN[3].rect.y=350;
    DOWN[3].rect.w=50;
    DOWN[3].rect.h=50;

    DOWN[4].rect.x=200;
    DOWN[4].rect.y=350;
    DOWN[4].rect.w=50;
    DOWN[4].rect.h=50;

    DOWN[5].rect.x=250;
    DOWN[5].rect.y=350;
    DOWN[5].rect.w=50;
    DOWN[5].rect.h=50;

    DOWN[6].rect.x=150;
    DOWN[6].rect.y=400;
    DOWN[6].rect.w=50;
    DOWN[6].rect.h=50;

    DOWN[7].rect.x=200;
    DOWN[7].rect.y=400;
    DOWN[7].rect.w=50;
    DOWN[7].rect.h=50;

    DOWN[8].rect.x=250;
    DOWN[8].rect.y=400;
    DOWN[8].rect.w=50;
    DOWN[8].rect.h=50;
}

void display_nb_roation(void)
{

    sprintf(nb_rotation_txt, "rotations:%d",nb_rotation);

    police = TTF_OpenFont("arial.ttf",30);
    Color_white.a=255;
    Color_white.r=255;
    Color_white.g=255;
    Color_white.b=255;
    Rect_text.y  =635;
    Rect_text.x  =525;

    SDL_SetRenderDrawColor(renderer,55,55,125,255);
    SDL_RenderFillRect(renderer, &Rect_text);


    texte=TTF_RenderText_Solid(police, nb_rotation_txt,Color_white);
    text_texte = SDL_CreateTextureFromSurface(renderer,texte);

    SDL_QueryTexture(text_texte,NULL,NULL,&Rect_text.w,&Rect_text.h);
    SDL_RenderCopy(renderer,text_texte, NULL,&Rect_text);
    SDL_FreeSurface(texte);
}
void verify_increment_color(int x, int y)
{
    for(int i=0; i<9; i++)
    {
        if((x>=FRONT[i].rect.x)&&(x<=FRONT[i].rect.x+FRONT[i].rect.w)&&(y>=FRONT[i].rect.y)&&(y<=FRONT[i].rect.y+FRONT[i].rect.h))
        {
            remplissage_carre(renderer);
            color_inc(&FRONT[i].color);
            SDL_SetRenderDrawColor(renderer,get_red(FRONT[i].color), get_green(FRONT[i].color), get_blue(FRONT[i].color), 255 );
            SDL_RenderFillRect(renderer, &FRONT[i].rect);
            return;
        }
    }
    for(int i=0; i<9; i++)
    {
        if((x>=UP[i].rect.x)&&(x<=UP[i].rect.x+UP[i].rect.w)&&(y>=UP[i].rect.y)&&(y<=UP[i].rect.y+UP[i].rect.h))
        {
            remplissage_carre(renderer);
            color_inc(&UP[i].color);
            SDL_SetRenderDrawColor(renderer,get_red(UP[i].color), get_green(UP[i].color), get_blue(UP[i].color), 255 );
            SDL_RenderFillRect(renderer, &UP[i].rect);
            return;
        }
    }

    for(int i=0; i<9; i++)
    {
        if((x>=LEFT[i].rect.x)&&(x<=LEFT[i].rect.x+LEFT[i].rect.w)&&(y>=LEFT[i].rect.y)&&(y<=LEFT[i].rect.y+LEFT[i].rect.h))
        {
            remplissage_carre(renderer);
            color_inc(&LEFT[i].color);
            SDL_SetRenderDrawColor(renderer,get_red(LEFT[i].color), get_green(LEFT[i].color), get_blue(LEFT[i].color), 255 );
            SDL_RenderFillRect(renderer, &LEFT[i].rect);
            return;
        }
    }

    for(int i=0; i<9; i++)
    {
        if((x>=RIGHT[i].rect.x)&&(x<=RIGHT[i].rect.x+RIGHT[i].rect.w)&&(y>=RIGHT[i].rect.y)&&(y<=RIGHT[i].rect.y+RIGHT[i].rect.h))
        {
            remplissage_carre(renderer);
            color_inc(&RIGHT[i].color);
            SDL_SetRenderDrawColor(renderer,get_red(RIGHT[i].color), get_green(RIGHT[i].color), get_blue(RIGHT[i].color), 255 );
            SDL_RenderFillRect(renderer, &RIGHT[i].rect);
            return;
        }
    }

    for(int i=0; i<9; i++)
    {
        if((x>=BACK[i].rect.x)&&(x<=BACK[i].rect.x+BACK[i].rect.w)&&(y>=BACK[i].rect.y)&&(y<=BACK[i].rect.y+BACK[i].rect.h))
        {
            remplissage_carre(renderer);
            color_inc(&BACK[i].color);
            SDL_SetRenderDrawColor(renderer,get_red(BACK[i].color), get_green(BACK[i].color), get_blue(BACK[i].color), 255 );
            SDL_RenderFillRect(renderer, &BACK[i].rect);
            return;
        }
    }

    for(int i=0; i<9; i++)
    {
        if((x>=DOWN[i].rect.x)&&(x<=DOWN[i].rect.x+DOWN[i].rect.w)&&(y>=DOWN[i].rect.y)&&(y<=DOWN[i].rect.y+DOWN[i].rect.h))
        {
            remplissage_carre(renderer);
            color_inc(&DOWN[i].color);
            SDL_SetRenderDrawColor(renderer,get_red(DOWN[i].color), get_green(DOWN[i].color), get_blue(DOWN[i].color), 255 );
            SDL_RenderFillRect(renderer, &DOWN[i].rect);
            return;
        }
    }
}

void color_inc(color_t *color)
{
    if(*color==6)
    {
        *color=1;
    }
    else
    {
        (*color)++;
    }
}


