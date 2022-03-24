#include <stdio.h>
#include <stdlib.h>
#include<conio.h>

#include"init_color.h"
#include"INIT.h"

void init_color(char *FileName)
{
    FILE* f=NULL;
    f=fopen(FileName, "r"); //C'est en lecture seule
    if(f!=NULL) {
        for(char i=0; i<9; i++)
        {
            fscanf(f,"%d",&UP[i].color);//lit le fichier
        }
        for(char i=0; i<9; i++)
        {
            fscanf(f,"%d",&LEFT[i].color);//lit le fichier
        }
        for(char i=0; i<9; i++)
        {
            fscanf(f,"%d",&FRONT[i].color);//lit le fichier
        }
        for(char i=0; i<9; i++)
        {
            fscanf(f,"%d",&RIGHT[i].color);//lit le fichier
        }
        for(char i=0; i<9; i++)
        {
            fscanf(f,"%d",&BACK[i].color);//lit le fichier
        }
        for(char i=0; i<9; i++)
        {
            fscanf(f,"%d",&DOWN[i].color);//lit le fichier
        }
        fclose(f);  //ne pas oublier oublier de fermer le flux
    }
    else
    {
        exit(1);
    }
}
/*
void entry_color(char *FileName)
{
    FILE* f=NULL;
    f=fopen(FileName, "w"); C'est en ecriture seule
    if(f!=NULL) {
        for(char i=0; i<9; i++)
        {
            fprintf(f,"%d\n",RED);
        }
        for(char i=0; i<9; i++)
        {
             fprintf(f,"%d\n",ORANGE);
        }
        for(char i=0; i<9; i++)
        {
             fprintf(f,"%d\n",BLUE);
        }
        for(char i=0; i<9; i++)
        {
             fprintf(f,"%d\n",GREEN);
        }
        for(char i=0; i<9; i++)
        {
             fprintf(f,"%d\n",YELLOW);
        }
        for(char i=0; i<9; i++)
        {
             fprintf(f,"%d\n",WHITE);
        }
    }
    else
    {
        exit(1);
    }
}*/

void display(void) {

    printf("\t%d%d%d\n\t%d%d%d\n\t%d%d%d\n",UP[0].color,UP[1].color,UP[2].color,UP[3].color,UP[4].color,UP[5].color,UP[6].color,UP[7].color,UP[8].color);
    printf("       ----- \n  ");
    for(char i=0; i<3; i++)
    {
        printf("%d",LEFT[i].color);
        if(i==2)
        {
            printf(" | ");
        }
    }
    for(char i=0; i<3; i++)
    {
        printf("%d",FRONT[i].color);
        if(i==2)
        {
            printf(" | ");
        }

    }
    for(char i=0; i<3; i++)
    {
        printf("%d",RIGHT[i].color);
        if(i==2)
        {
            printf(" | ");
        }
    }
    for(char i=0; i<3; i++)
    {
        printf("%d",BACK[i].color);
        if(i==2)
        {
            printf(" | ");
        }
    }

    printf("\n  ");
    /*--------------------------------------------------------------------*/
    for(char i=3; i<6; i++)
    {
        printf("%d",LEFT[i].color);
        if(i==5)
        {
            printf(" | ");
        }
    }
    for(char i=3; i<6; i++)
    {
        printf("%d",FRONT[i].color);
        if(i==5)
        {
            printf(" | ");
        }

    }
    for(char i=3; i<6; i++)
    {
        printf("%d",RIGHT[i].color);
        if(i==5)
        {
            printf(" | ");
        }
    }
    for(char i=3; i<6; i++)
    {
        printf("%d",BACK[i].color);
        if(i==5)
        {
            printf(" | ");
        }
    }
    printf("\n  ");
     /*--------------------------------------------------------------------*/
    for(char i=6; i<9; i++)
    {
        printf("%d",LEFT[i].color);
        if(i==8)
        {
            printf(" | ");
        }
    }
    for(char i=6; i<9; i++)
    {
        printf("%d",FRONT[i].color);
        if(i==8)
        {
            printf(" | ");
        }

    }
    for(char i=6; i<9; i++)
    {
        printf("%d",RIGHT[i].color);
        if(i==8)
        {
            printf(" | ");
        }
    }
    for(char i=6; i<9; i++)
    {
        printf("%d",BACK[i].color);
        if(i==8)
        {
            printf(" | ");
        }
    }
    printf("\n");
    printf("       ----- \n  ");
    printf("\t%d%d%d\n\t%d%d%d\n\t%d%d%d\n",DOWN[0].color,DOWN[1].color,DOWN[2].color,DOWN[3].color,DOWN[4].color,DOWN[5].color,DOWN[6].color,DOWN[7].color,DOWN[8].color);

    printf("\n\n\n-----------------------------------------------------------------------\n\n\n");
}

