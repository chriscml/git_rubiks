#include "solve.h"
#include "INIT.h"
#include <stdio.h>
#include <stdbool.h>
#include "movement.h"
#include "interface_graphique.h"

carre_t *get_carre_from_id(unsigned char id)
{
    carre_t *retour;
    for(int i=0; i<9; i++)
    {
        if(UP[i].id==id)
        {
            retour= &UP[i];
            break;
        }

        if(DOWN[i].id==id)
        {
            retour= &DOWN[i];
            break;
        }


        if(LEFT[i].id==id)
        {
            retour= &LEFT[i];
            break;
        }

        if(RIGHT[i].id==id)
        {
            retour= &RIGHT[i];
            break;
        }

        if(FRONT[i].id==id)
        {
            retour= &FRONT[i];
            break;
        }

        if(BACK[i].id==id)
        {
            retour= &BACK[i];
            break;
        }
    }

    return retour;
}

signed char get_position_from_id(signed char id)
{
    signed char retour;
    for(int i=0; i<9; i++)
    {
        if(UP[i].id==id)
        {
            retour= i;
            break;
        }

        if(DOWN[i].id==id)
        {
            retour= i;
            break;
        }


        if(LEFT[i].id==id)
        {
            retour= i;
            break;
        }

        if(RIGHT[i].id==id)
        {
            retour= i;
            break;
        }

        if(FRONT[i].id==id)
        {
            retour= i;
            break;
        }

        if(BACK[i].id==id)
        {
            retour= i;
            break;
        }
    }
    return retour;

}


void do_white_cross(void)
{
    get_carre_blanc_on_the_white_face(UP);
    get_carre_blanc_on_the_white_face(DOWN);
    get_carre_blanc_on_the_white_face(LEFT);
    get_carre_blanc_on_the_white_face(RIGHT);
    get_carre_blanc_on_the_white_face(FRONT);
    get_carre_blanc_on_the_white_face(BACK);
    verify_white_cross();
    verify_white_cross();
    verify_white_cross();
    verify_white_cross();

}

void do_white_face(void)
{
    get_corner_on_the_white_face(DOWN);//faire down en premier: important
    get_corner_on_the_white_face(UP);
    get_corner_on_the_white_face(LEFT);
    get_corner_on_the_white_face(RIGHT);
    get_corner_on_the_white_face(FRONT);
    get_corner_on_the_white_face(BACK);
    verify_white_face();
    verify_white_face();

}

signed char get_position(carre_t *face, color_t color23, type_cube_t type, signed char id0_excluded, signed char id1_excluded, signed char id2_excluded)
{
    signed char retour=-1;
    switch(type)
    {
    case EDGE:
        for(unsigned char i=0; i<9; i++)
        {
            if((face[i].id==id0_excluded)||(face[i].id==id1_excluded)||(face[i].id==id2_excluded))
                continue;
            if(i%2==1)
            {
                if(face[i].color==color23)
                {
                    retour= i;
                }
            }

        }
        break;

    case CENTER:
        if(face[4].color==color23)
            retour= 4;
        break;

    case CORNER:
        if(face[0].color==color23)
            retour= 0;
        else if(face[2].color==color23)
            retour= 2;
        else if(face[6].color==color23)
            retour= 6;
        else if(face[8].color==color23)
            retour= 8;
        else retour=-1;
        break;

    default:
        retour= -2;
    }
    return retour;
}

carre_t *get_carre_on_the_same_cube(carre_t *face,  signed char position, type_cube_t type)
{
    carre_t *returned_carre;
    switch(type)
    {
    case EDGE:
        if(face==UP)
        {
            switch(position)
            {
            case 1:
                returned_carre=&BACK[1];
                break;
            case 3:
                returned_carre=&LEFT[1];
                break;
            case 5:
                returned_carre=&RIGHT[1];
                break;
            case 7:
                returned_carre=&FRONT[1];
                break;
            }
        }
        else if(face == DOWN)
        {
            switch(position)
            {
            case 1:
                returned_carre=&FRONT[7];
                break;
            case 3:
                returned_carre=&LEFT[7];
                break;
            case 5:
                returned_carre=&RIGHT[7];
                break;
            case 7:
                returned_carre=&BACK[7];
                break;
            }
        }
        else if (face ==FRONT)
        {
            switch(position)
            {
            case 1:
                returned_carre=&UP[7];
                break;
            case 3:
                returned_carre=&LEFT[5];
                break;
            case 5:
                returned_carre=&RIGHT[3];
                break;
            case 7:
                returned_carre=&DOWN[1];
                break;
            }
        }
        else if (face==BACK)
        {
            switch(position)
            {
            case 1:
                returned_carre=&UP[1];
                break;
            case 3:
                returned_carre=&RIGHT[5];
                break;
            case 5:
                returned_carre=&LEFT[3];
                break;
            case 7:
                returned_carre=&DOWN[7];
                break;
            }
        }
        else if (face==LEFT)
        {
            switch(position)
            {
            case 1:
                returned_carre=&UP[3];
                break;
            case 3:
                returned_carre=&BACK[5];
                break;
            case 5:
                returned_carre=&FRONT[3];
                break;
            case 7:
                returned_carre=&DOWN[3];
                break;
            }
        }
        else if (face==RIGHT)
        {
            switch(position)
            {
            case 1:
                returned_carre=&UP[5];
                break;
            case 3:
                returned_carre=&FRONT[5];
                break;
            case 5:
                returned_carre=&BACK[3];
                break;
            case 7:
                returned_carre=&DOWN[5];
                break;
            }
        }
    case CORNER:

        if (face ==FRONT)
        {
            switch(position)
            {
            case 0:
                returned_carre=&LEFT[2];
                break;
            case 2:
                returned_carre=&RIGHT[0];
                break;
            case 6:
                returned_carre=&LEFT[8];
                break;
            case 8:
                returned_carre=&RIGHT[6];
                break;
            }
        }
        else if (face==BACK)
        {
            switch(position)
            {
            case 0:
                returned_carre=&RIGHT[2];
                break;
            case 2:
                returned_carre=&LEFT[0];
                break;
            case 6:
                returned_carre=&RIGHT[8];
                break;
            case 8:
                returned_carre=&LEFT[6];
                break;
            }
        }
        else if (face==LEFT)
        {
            switch(position)
            {
            case 0:
                returned_carre=&BACK[2];
                break;
            case 2:
                returned_carre=&FRONT[0];
                break;
            case 6:
                returned_carre=&BACK[8];
                break;
            case 8:
                returned_carre=&FRONT[6];
                break;
            }
        }
        else if (face==RIGHT)
        {
            switch(position)
            {
            case 0:
                returned_carre=&FRONT[2];
                break;
            case 2:
                returned_carre=&BACK[0];
                break;
            case 6:
                returned_carre=&FRONT[8];
                break;
            case 8:
                returned_carre=&BACK[6];
                break;
            }
        }

    }
    return returned_carre;
}

carre_t *get_face_from_color(color_t color)
{
    carre_t *face_returned;
    switch(color)
    {
    case 1:
        face_returned=&BACK[0];
        break;
    case 2:
        face_returned=&DOWN[0];
        break;
    case 3:
        face_returned=&UP[0];
        break;
    case 4:
        face_returned=&FRONT[0];
        break;
    case 5:
        face_returned=&RIGHT[0];
        break;
    case 6:
        face_returned=&LEFT[0];
        break;
    }
    return face_returned;


}

bool isinthetableau(carre_t *carre, carre_t *addressecarre)
{
    //printf("adresse carre: %d, adresse basse: %d, adresse haute: %d\n", carre, addressecarre, &addressecarre[8]);
    if((carre>=addressecarre)&&(carre<=&addressecarre[8]))
    {
        return true;
    }
    else
    {
        return false;
    }
}

carre_t *get_face_from_carre(carre_t *carre)
{
    carre_t *retour=0;
    if(isinthetableau(carre, UP))
        retour=UP;
    else if(isinthetableau(carre, DOWN))
        retour=DOWN;
    else if(isinthetableau(carre, LEFT))
        retour=LEFT;
    else if(isinthetableau(carre, RIGHT))
        retour=RIGHT;
    else if(isinthetableau(carre, FRONT))
        retour=FRONT;
    else if(isinthetableau(carre, BACK))
        retour=BACK;
    return retour;
}

void rotate_face(carre_t *face, signed char clockwise)
{
    switch(clockwise)
    {
    case 1:
        if(face==UP)
            rotate_moove(U);
        else if(face==DOWN)
            rotate_moove(D);
        else if(face==LEFT)
            rotate_moove(L);
        else if(face==RIGHT)
            rotate_moove(R);
        else if(face==FRONT)
            rotate_moove(F);
        else if(face==BACK)
            rotate_moove(B);
        break;
    case 0:
        if(face==UP)
            rotate_moove(AU);
        else if(face==DOWN)
            rotate_moove(AD);
        else if(face==LEFT)
            rotate_moove(AL);
        else if(face==RIGHT)
            rotate_moove(AR);
        else if(face==FRONT)
            rotate_moove(AF);
        else if(face==BACK)
            rotate_moove(AB);
        break;
    default:
        printf("erreur");
        break;
    }

}

void get_carre_blanc_on_the_white_face(carre_t *face)
{
    if(get_position(face, WHITE, EDGE, -1, -1, -1)!=-1) // gestion du cas ou 1, 2, 3, ou 4 carr�s se trouvent d�j� sur la face *face: partie fonctionnelle
    {
        //printf("position carre: %d\n", get_position(face, WHITE, EDGE, -1, -1, -1));
        unsigned char id_saved0_carre_blanc=face[get_position(face, WHITE, EDGE, -1, -1, -1)].id;
        carre_t *near_cube=get_carre_on_the_same_cube(face, get_position(face, WHITE, EDGE, -1, -1, -1),EDGE);
        unsigned char id_saved0_near_cube=near_cube->id;
        carre_t *face_from_color= get_face_from_color(near_cube->color);
        carre_t *actual_face = get_face_from_carre(near_cube);
        if((face!=UP)&&(face!=DOWN))
            get_edges_from_otherfaces_to_white_cross(face);
        if((face==UP)||(face==DOWN))
        {
            while(actual_face!=face_from_color)
            {
                rotate_face(face, 1);
                // printf("actual_face : %d", actual_face);
                actual_face =get_face_from_carre(get_carre_from_id(id_saved0_near_cube)) ;
            }
        }
        if(face==DOWN)
        {
            rotate_face(face_from_color, 1);
            rotate_face(face_from_color, 1);
        }
        if(get_position(face, WHITE, EDGE, id_saved0_carre_blanc, -1, -1)!=-1)
        {
            //printf("il y a un autre carr� blanc\n");
            //printf("position carre: %d\n", get_position(face, WHITE, EDGE, id_saved0_carre_blanc, -1, -1));
            unsigned char id_saved1_carre_blanc = face[get_position(face, WHITE, EDGE, id_saved0_carre_blanc, -1, -1)].id;
            near_cube= get_carre_on_the_same_cube(face, get_position(face, WHITE, EDGE, id_saved0_carre_blanc, -1, -1), EDGE);
            unsigned char id_saved1_near_cube=near_cube->id;
            carre_t *face_saved = get_face_from_carre(near_cube);
            face_from_color=get_face_from_color(near_cube->color);
            if((face!=UP)&&(face!=DOWN))
                get_edges_from_otherfaces_to_white_cross(face);
            if(face_saved!=face_from_color)
            {
                if(face==UP)//modifi�
                {
                    rotate_face(face_saved,1);
                    rotate_face(face_saved,1);
                }
                actual_face=get_face_from_carre(get_carre_from_id(id_saved1_near_cube));
                if((face==UP)||(face==DOWN))
                {
                    while(actual_face!=face_from_color)
                    {
                        rotate_face(DOWN,1);
                        //printf("actual_face2: %d", actual_face);
                        actual_face=get_face_from_carre(get_carre_from_id(id_saved1_near_cube));
                    }
                    rotate_face(face_from_color,1);
                    rotate_face(face_from_color,1);
                }
            }
            if(get_position(face, WHITE, EDGE, id_saved0_carre_blanc, id_saved1_carre_blanc, -1)!=-1)
            {
                //printf("il y a encore un autre carr� blanc\n");
                //printf("position carre: %d\n", get_position(face, WHITE, EDGE, id_saved0_carre_blanc, id_saved1_carre_blanc, -1));
                unsigned char id_saved2_carre_blanc = face[get_position(face, WHITE, EDGE, id_saved0_carre_blanc, id_saved1_carre_blanc, -1)].id;
                near_cube= get_carre_on_the_same_cube(face, get_position(face, WHITE, EDGE, id_saved0_carre_blanc, id_saved1_carre_blanc, -1), EDGE);
                unsigned char id_saved2_near_cube=near_cube->id;
                face_saved = get_face_from_carre(near_cube);
                face_from_color=get_face_from_color(near_cube->color);
                // printf("actual_face = %d, face_needed: %d", face_saved, face_from_color);
                if((face!=UP)&&(face!=DOWN))
                    get_edges_from_otherfaces_to_white_cross(face);
                if(face_saved!=face_from_color)
                {
                    if(face==UP)
                    {
                        rotate_face(face_saved,1);
                        rotate_face(face_saved,1);
                    }
                    actual_face=get_face_from_carre(get_carre_from_id(id_saved2_near_cube));
                    //printf("actualised_face: %d", actual_face);
                    if((face==UP)||(face==DOWN))
                    {
                        while(actual_face!=face_from_color)
                        {
                            rotate_face(DOWN,1);
                            //printf("actual_face2: %d", actual_face);
                            actual_face=get_face_from_carre(get_carre_from_id(id_saved2_near_cube));
                        }
                        rotate_face(face_from_color,1);
                        rotate_face(face_from_color,1);
                    }
                }
                if(get_position(face, WHITE, EDGE, id_saved0_carre_blanc, id_saved1_carre_blanc, id_saved2_carre_blanc)!=-1)
                {
                    // printf("il y a encore encore un autre carr� blanc\n");
                    //printf("position carre: %d\n", get_position(face, WHITE, EDGE, id_saved0_carre_blanc, id_saved1_carre_blanc, id_saved2_carre_blanc));
                    near_cube= get_carre_on_the_same_cube(face, get_position(face, WHITE, EDGE, id_saved0_carre_blanc, id_saved1_carre_blanc, id_saved2_carre_blanc), EDGE);
                    unsigned char id_saved3_near_cube=near_cube->id;
                    face_saved = get_face_from_carre(near_cube);
                    face_from_color=get_face_from_color(near_cube->color);
                    //printf("actual_face = %d, face_needed: %d", face_saved, face_from_color);
                    if((face!=UP)&&(face!=DOWN))
                        get_edges_from_otherfaces_to_white_cross(face);
                    if(face_saved!=face_from_color)
                    {
                        if(face==UP)
                        {
                            rotate_face(face_saved,1);
                            rotate_face(face_saved,1);
                        }
                        actual_face=get_face_from_carre(get_carre_from_id(id_saved3_near_cube));
                        //printf("actualised_face: %d", actual_face);
                        if((face==UP)||(face==DOWN))
                        {
                            while(actual_face!=face_from_color)
                            {
                                rotate_face(DOWN,1);
                                //printf("actual_face3: %d", actual_face);
                                actual_face=get_face_from_carre(get_carre_from_id(id_saved3_near_cube));
                            }
                            rotate_face(face_from_color,1);
                            rotate_face(face_from_color,1);
                        }
                    }
                }
            }
        }



    }
    else
    {

    }
}

void get_edges_from_otherfaces_to_white_cross(carre_t *face)
{
    unsigned char id_saved0_carre_blanc=face[get_position(face, WHITE, EDGE, -1, -1, -1)].id;
    carre_t *near_cube=get_carre_on_the_same_cube(face, get_position(face, WHITE, EDGE, -1, -1, -1),EDGE);
    unsigned char id_saved0_near_cube=near_cube->id;
    carre_t *face_from_color= get_face_from_color(near_cube->color);
    carre_t *actual_face = get_face_from_carre(near_cube);

    switch(get_position(face, WHITE, EDGE, -1, -1, -1))
    {
    case 1:
        rotate_face(get_face_from_carre(get_carre_from_id(id_saved0_carre_blanc)), 1);
        carre_t *face0=get_face_from_carre(get_carre_from_id(id_saved0_near_cube));
        rotate_face(face0, 0);
        rotate_face(DOWN, 1);
        rotate_face(face0, 1);
        actual_face =get_face_from_carre(get_carre_from_id(id_saved0_near_cube)) ;
        while(actual_face!=face_from_color)
        {
            rotate_face(DOWN, 1);
            //printf("actual_face : %d, case 1", actual_face);
            actual_face =get_face_from_carre(get_carre_from_id(id_saved0_near_cube)) ;
        }
        rotate_face(face_from_color, 1);
        rotate_face(face_from_color, 1);
        break;
    case 3:
        ;
        carre_t *face1=get_face_from_carre(get_carre_from_id(id_saved0_near_cube));
        rotate_face(face1, 1);
        rotate_face(DOWN, 1);
        rotate_face(face1, 0);
        actual_face =get_face_from_carre(get_carre_from_id(id_saved0_near_cube)) ;
        while(actual_face!=face_from_color)
        {
            rotate_face(DOWN, 1);
            //printf("actual_face : %d, case 3", actual_face);
            actual_face =get_face_from_carre(get_carre_from_id(id_saved0_near_cube)) ;
        }
        rotate_face(face_from_color, 1);
        rotate_face(face_from_color, 1);
        break;
    case 5:
        ;
        carre_t *face2=get_face_from_carre(get_carre_from_id(id_saved0_near_cube));
        rotate_face(face2, 0);
        rotate_face(DOWN, 1);
        rotate_face(face2, 1);
        actual_face =get_face_from_carre(get_carre_from_id(id_saved0_near_cube)) ;
        while(actual_face!=face_from_color)
        {
            rotate_face(DOWN, 1);
            //printf("actual_face : %d, case 5", actual_face);
            actual_face =get_face_from_carre(get_carre_from_id(id_saved0_near_cube)) ;
        }
        rotate_face(face_from_color, 1);
        rotate_face(face_from_color, 1);
        break;
    case 7:
        actual_face=get_face_from_carre(get_carre_from_id(id_saved0_carre_blanc));
        //printf("face UP: %d, DOWN:%d, LEFT:%d, RIGHT:%d, FRONT:%d, BACK:%d", UP, DOWN, LEFT, RIGHT, FRONT, BACK);
        //printf("face actuelle: %d, face requise: %d", actual_face, face_from_color);
        while(actual_face!=face_from_color)
        {
            rotate_face(DOWN, 1);
            //printf("actual_face : %d, case 7", actual_face);
            actual_face =get_face_from_carre(get_carre_from_id(id_saved0_carre_blanc)) ;
        }
        rotate_face(DOWN, 1);
        carre_t * face3=get_face_from_carre(get_carre_from_id(id_saved0_carre_blanc));
        rotate_face(face3,1);
        rotate_face(get_face_from_carre(get_carre_from_id(id_saved0_near_cube)), 0);
        rotate_face(face3, 0);
        break;
    }


}
void verify_white_cross(void)
{
    if((UP[1].color==WHITE)&&(UP[3].color==WHITE)&&(UP[5].color==WHITE)&&(UP[7].color==WHITE)) {}
    else
    {
        if(get_position(DOWN, WHITE, EDGE, -1,-1, -1)!=-1)
            get_carre_blanc_on_the_white_face(DOWN);
        if(get_position(LEFT, WHITE, EDGE, -1,-1, -1)!=-1)
            get_carre_blanc_on_the_white_face(LEFT);
        if(get_position(RIGHT, WHITE, EDGE, -1,-1, -1)!=-1)
            get_carre_blanc_on_the_white_face(RIGHT);
        if(get_position(FRONT, WHITE, EDGE, -1,-1, -1)!=-1)
            get_carre_blanc_on_the_white_face(FRONT);
        if(get_position(BACK, WHITE, EDGE, -1,-1, -1)!=-1)
            get_carre_blanc_on_the_white_face(BACK);

    }
}

void get_corner_on_the_white_face(carre_t *face)
{
    signed char init_position=get_position(face, WHITE, CORNER, -1, -1, -1);
    if(init_position!=-1)
    {
        unsigned char id_saved0=face[init_position].id;
        if(face==UP)
        {


            switch(init_position)
            {
            case 0:
                rotate_face(LEFT, 0);
                rotate_face(DOWN, 0);
                rotate_face(LEFT, 1);
                treat_this_white_corner(id_saved0);
                break;

            case 2:
                rotate_face(RIGHT, 1);
                rotate_face(DOWN, 1);
                rotate_face(RIGHT, 0);
                treat_this_white_corner(id_saved0);
                break;
            case 6:
                rotate_face(LEFT, 1);
                rotate_face(DOWN, 1);
                rotate_face(LEFT, 0);
                treat_this_white_corner(id_saved0);
                break;
            case 8:
                rotate_face(RIGHT, 0);
                rotate_face(DOWN, 0);
                rotate_face(RIGHT, 1);
                treat_this_white_corner(id_saved0);
                break;
            }
        }
        else if(face==DOWN)
        {
            if(init_position!=-1)
            {
                switch(init_position)
                {
                case 0:
                    rotate_face(DOWN, 1);
                    break;
                case 6:
                    rotate_face(DOWN, 0);
                    rotate_face(DOWN, 0);
                    break;
                case 8:
                    rotate_face(DOWN, 0);
                    break;
                }
                rotate_face(RIGHT,0);
                rotate_face(DOWN, 0);
                rotate_face(DOWN, 0);
                rotate_face(RIGHT, 1);
                treat_this_white_corner(id_saved0);
            }
        }
        else
        {
            if((init_position==0)||(init_position==2))
            {
                carre_t *near_cube;
                near_cube=get_carre_on_the_same_cube(get_face_from_carre(get_carre_from_id(id_saved0)), get_position_from_id(id_saved0), CORNER);
                carre_t *face_from_near_cube=get_face_from_carre(near_cube);

                if(init_position==0)
                {
                    rotate_face(face_from_near_cube, 1);
                    rotate_face(DOWN, 1);
                    rotate_face(face_from_near_cube, 0);
                }
                if(init_position==2)
                {
                    rotate_face(face_from_near_cube, 0);
                    rotate_face(DOWN, 0);
                    rotate_face(face_from_near_cube, 1);
                }
                init_position=get_position_from_id(id_saved0);//acutalisation de la position du carr� blanc sur la face down
                switch(init_position)
                {
                case 0:
                    rotate_face(DOWN, 1);
                    break;
                case 6:
                    rotate_face(DOWN, 0);
                    rotate_face(DOWN, 0);
                    break;
                case 8:
                    rotate_face(DOWN, 0);
                    break;
                }
                rotate_face(RIGHT,0);
                rotate_face(DOWN, 0);
                rotate_face(DOWN, 0);
                rotate_face(RIGHT, 1);
            }
            treat_this_white_corner(id_saved0);
        }
    }
}

void treat_this_white_corner(signed char id)
{
    carre_t *white_corner=get_carre_from_id(id);
    carre_t *near_cube;
    near_cube=get_carre_on_the_same_cube(get_face_from_carre(white_corner), get_position_from_id(id), CORNER);
    carre_t *face_from_color= get_face_from_color(near_cube->color);
    carre_t *actual_face = get_face_from_carre(near_cube);
    signed char id_near_cube=near_cube->id;
    while(actual_face!=face_from_color)
    {
        rotate_face(DOWN, 1);
        actual_face =get_face_from_carre(get_carre_from_id(id_near_cube)) ;
        //SDL_Delay(2000);
    }
    /*for(int i=0; i<10; i++){
        if(actual_face34==face_from_color34){
            printf("face trouv�e \n");
            break;
        }
        rotate_face(DOWN, 1);
        actual_face34 =get_face_from_carre(get_carre_from_id(id_near_cube)) ;
        printf("i:%d\n", i);
    }*/
    if(get_position_from_id(id)==6)
    {
        carre_t *face=get_face_from_carre(get_carre_from_id(id));
        rotate_face(face, 0);
        rotate_face(DOWN, 0);
        rotate_face(face, 1);
    }
    else if(get_position_from_id(id)==8)
    {
        carre_t *face_near_cube=get_face_from_carre(get_carre_from_id(id_near_cube));
        rotate_face(DOWN, 0);
        rotate_face(face_near_cube, 0);
        rotate_face(DOWN, 1);
        rotate_face(face_near_cube, 1);
    }
    else
        printf("erreur fonction treat this white corer\n");

}

void verify_white_face(void)
{
    if(get_position(DOWN, WHITE, CORNER, -1, -1, -1)!=-1)
        get_corner_on_the_white_face(DOWN);
    if(get_position(LEFT, WHITE, CORNER, -1, -1, -1)!=-1)
        get_corner_on_the_white_face(LEFT);
    if(get_position(RIGHT, WHITE, CORNER, -1, -1, -1)!=-1)
        get_corner_on_the_white_face(RIGHT);
    if(get_position(BACK, WHITE, CORNER, -1, -1, -1)!=-1)
        get_corner_on_the_white_face(BACK);
    if(get_position(FRONT, WHITE, CORNER, -1, -1, -1)!=-1)
        get_corner_on_the_white_face(FRONT);
}

