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
        for(int i=0; i<9; i++)
        {
            if((face[i].id==id0_excluded)||(face[i].id==id1_excluded)||(face[i].id==id2_excluded))
                continue;
            if(i%2==0){
                if(i==4)
                    continue;
                else if(face[i].color==color23)
                    retour=i;
            }
        }
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

    if(color==BACK[4].color)
        face_returned=&BACK[0];
    else if(color==DOWN[4].color)
        face_returned=&DOWN[0];
    else if(color==UP[4].color)
        face_returned=&UP[0];
    else if(color==FRONT[4].color)
        face_returned=&FRONT[0];
    else if(color==RIGHT[4].color)
        face_returned=&RIGHT[0];
    else if(color==LEFT[4].color)
        face_returned=&LEFT[0];
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
    static int i=0;
    carre_t *nb_rotation_sauvegarde[3];
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
    nb_rotation++;

    nb_rotation_sauvegarde[i] = face;
    if(i>0)
    {
        if(nb_rotation_sauvegarde[i] ==nb_rotation_sauvegarde[i-1] )
        {
            nb_rotation--;
        }
        if(((nb_rotation_sauvegarde[i] == nb_rotation_sauvegarde[i-2]) && (nb_rotation_sauvegarde[i] ==nb_rotation_sauvegarde[i-1])) && (i>1))
        {
            nb_rotation--;
        }
    }
    if(i==0){
        if(nb_rotation_sauvegarde[0]==nb_rotation_sauvegarde[3])
        {
            nb_rotation--;
        }
        if((nb_rotation_sauvegarde[0]==nb_rotation_sauvegarde[2]) && (nb_rotation_sauvegarde[0]==nb_rotation_sauvegarde[1]))
        {
            nb_rotation--;
        }
    }
    if(i==1){
        if(nb_rotation_sauvegarde[1]==nb_rotation_sauvegarde[3] && nb_rotation_sauvegarde[1]==nb_rotation_sauvegarde[2])
        {
            nb_rotation--;
        }
    }
    if(i==3)
    {
        i=0;
    }
    else
    {
        i++;
    }


}

void get_carre_blanc_on_the_white_face(carre_t *face)
{
    if(get_position(face, UP[4].color, EDGE, -1, -1, -1)!=-1) // gestion du cas ou 1, 2, 3, ou 4 carrés se trouvent déjà sur la face *face: partie fonctionnelle
    {
        //printf("position carre: %d\n", get_position(face, WHITE, EDGE, -1, -1, -1));
        unsigned char id_saved0_carre_blanc=face[get_position(face, UP[4].color, EDGE, -1, -1, -1)].id;
        carre_t *near_cube=get_carre_on_the_same_cube(face, get_position(face, UP[4].color, EDGE, -1, -1, -1),EDGE);
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
                actual_face =get_face_from_carre(get_carre_from_id(id_saved0_near_cube)) ;
            }
        }
        if(face==DOWN)
        {
            rotate_face(face_from_color, 1);
            rotate_face(face_from_color, 1);
        }
        if(get_position(face, UP[4].color, EDGE, id_saved0_carre_blanc, -1, -1)!=-1)
        {
            //printf("il y a un autre carré blanc\n");
            //printf("position carre: %d\n", get_position(face, WHITE, EDGE, id_saved0_carre_blanc, -1, -1));
            unsigned char id_saved1_carre_blanc = face[get_position(face, UP[4].color, EDGE, id_saved0_carre_blanc, -1, -1)].id;
            near_cube= get_carre_on_the_same_cube(face, get_position(face, UP[4].color, EDGE, id_saved0_carre_blanc, -1, -1), EDGE);
            unsigned char id_saved1_near_cube=near_cube->id;
            carre_t *face_saved = get_face_from_carre(near_cube);
            face_from_color=get_face_from_color(near_cube->color);
            if((face!=UP)&&(face!=DOWN))
                get_edges_from_otherfaces_to_white_cross(face);
            if(face_saved!=face_from_color)
            {
                if(face==UP)//modifié
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
            if(get_position(face, UP[4].color, EDGE, id_saved0_carre_blanc, id_saved1_carre_blanc, -1)!=-1)
            {
                //printf("il y a encore un autre carré blanc\n");
                //printf("position carre: %d\n", get_position(face, WHITE, EDGE, id_saved0_carre_blanc, id_saved1_carre_blanc, -1));
                unsigned char id_saved2_carre_blanc = face[get_position(face, UP[4].color, EDGE, id_saved0_carre_blanc, id_saved1_carre_blanc, -1)].id;
                near_cube= get_carre_on_the_same_cube(face, get_position(face, UP[4].color, EDGE, id_saved0_carre_blanc, id_saved1_carre_blanc, -1), EDGE);
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
                if(get_position(face, UP[4].color, EDGE, id_saved0_carre_blanc, id_saved1_carre_blanc, id_saved2_carre_blanc)!=-1)
                {
                    // printf("il y a encore encore un autre carré blanc\n");
                    //printf("position carre: %d\n", get_position(face, WHITE, EDGE, id_saved0_carre_blanc, id_saved1_carre_blanc, id_saved2_carre_blanc));
                    near_cube= get_carre_on_the_same_cube(face, get_position(face, UP[4].color, EDGE, id_saved0_carre_blanc, id_saved1_carre_blanc, id_saved2_carre_blanc), EDGE);
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
    unsigned char id_saved0_carre_blanc=face[get_position(face, UP[4].color, EDGE, -1, -1, -1)].id;
    carre_t *near_cube=get_carre_on_the_same_cube(face, get_position(face, UP[4].color, EDGE, -1, -1, -1),EDGE);
    unsigned char id_saved0_near_cube=near_cube->id;
    carre_t *face_from_color= get_face_from_color(near_cube->color);
    carre_t *actual_face = get_face_from_carre(near_cube);

    switch(get_position(face, UP[4].color, EDGE, -1, -1, -1))
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
    if((UP[1].color==UP[4].color)&&(UP[3].color==UP[4].color)&&(UP[5].color==UP[4].color)&&(UP[7].color==UP[4].color)) {}
    else
    {
        if(get_position(DOWN, UP[4].color, EDGE, -1,-1, -1)!=-1)
            get_carre_blanc_on_the_white_face(DOWN);
        if(get_position(LEFT, UP[4].color, EDGE, -1,-1, -1)!=-1)
            get_carre_blanc_on_the_white_face(LEFT);
        if(get_position(RIGHT, UP[4].color, EDGE, -1,-1, -1)!=-1)
            get_carre_blanc_on_the_white_face(RIGHT);
        if(get_position(FRONT, UP[4].color, EDGE, -1,-1, -1)!=-1)
            get_carre_blanc_on_the_white_face(FRONT);
        if(get_position(BACK, UP[4].color, EDGE, -1,-1, -1)!=-1)
            get_carre_blanc_on_the_white_face(BACK);

    }
}

void get_corner_on_the_white_face(carre_t *face)
{
    signed char init_position=get_position(face, UP[4].color, CORNER, -1, -1, -1);
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
                init_position=get_position_from_id(id_saved0);//acutalisation de la position du carré blanc sur la face down
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
            printf("face trouvée \n");
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
        printf("erreur fonction treat this white corner\n");

}

void verify_white_face(void)
{
    if(get_position(DOWN, UP[4].color, CORNER, -1, -1, -1)!=-1)
        get_corner_on_the_white_face(DOWN);
    if(get_position(LEFT, UP[4].color, CORNER, -1, -1, -1)!=-1)
        get_corner_on_the_white_face(LEFT);
    if(get_position(RIGHT, UP[4].color, CORNER, -1, -1, -1)!=-1)
        get_corner_on_the_white_face(RIGHT);
    if(get_position(BACK, UP[4].color, CORNER, -1, -1, -1)!=-1)
        get_corner_on_the_white_face(BACK);
    if(get_position(FRONT, UP[4].color, CORNER, -1, -1, -1)!=-1)
        get_corner_on_the_white_face(FRONT);
}

void step_3_do_color_edges(void)
{
    get_colored_edges_on_this_face(FRONT);
    get_colored_edges_on_this_face(BACK);
    get_colored_edges_on_this_face(LEFT);
    get_colored_edges_on_this_face(RIGHT);
}

void get_colored_edges_on_this_face(carre_t *face)
{
    if((face[3].color==face[4].color)&&(get_face_from_carre(get_carre_on_the_same_cube(face, 3, EDGE))==get_face_from_color(get_carre_on_the_same_cube(face, 3, EDGE)->color)))
    {}
    else
    {
        signed char id_of_searched_cube=get_id_from_searched_cube(face[4].color, ((get_face_from_carre(get_carre_on_the_same_cube(face, 3, EDGE)))[4]).color);
        signed char position=get_position_from_id(id_of_searched_cube);
        if(position==3)
        {
            get_this_edge_in_the_right_place(&(get_face_from_carre(get_carre_from_id(id_of_searched_cube))[7]), 1);
            id_of_searched_cube=get_carre_on_the_same_cube(get_face_from_carre(get_carre_from_id(id_of_searched_cube)),get_position_from_id(id_of_searched_cube), EDGE)->id;
        }
        if(position==5)
        {
            get_this_edge_in_the_right_place(&(get_face_from_carre(get_carre_from_id(id_of_searched_cube))[7]), 0);
            id_of_searched_cube=get_carre_on_the_same_cube(get_face_from_carre(get_carre_from_id(id_of_searched_cube)),get_position_from_id(id_of_searched_cube), EDGE)->id;
        }
        carre_t *actual_face=get_face_from_carre(get_carre_from_id(id_of_searched_cube));
        carre_t *face_needed=get_face_from_color(get_carre_from_id(id_of_searched_cube)->color);
        while(actual_face!=face_needed)
        {
            rotate_face(DOWN, 1);
            actual_face =get_face_from_carre(get_carre_from_id(id_of_searched_cube)) ;
            if(actual_face==DOWN)
            {
                actual_face=get_face_from_carre(get_carre_on_the_same_cube(get_face_from_carre(get_carre_from_id(id_of_searched_cube)), get_position_from_id(id_of_searched_cube), EDGE));
            }
        }
        if(get_carre_on_the_same_cube(actual_face, 7, EDGE)->color==get_face_from_carre(get_carre_on_the_same_cube(actual_face, 3, EDGE))[4].color)
            get_this_edge_in_the_right_place(get_carre_from_id(id_of_searched_cube), 1);
        else if(get_carre_on_the_same_cube(actual_face, 7, EDGE)->color==get_face_from_carre(get_carre_on_the_same_cube(actual_face, 5, EDGE))[4].color)
            get_this_edge_in_the_right_place(get_carre_from_id(id_of_searched_cube), 0);
        else
            printf("erreur\n");
    }
}

//PARTIES ENTIEREMENT FONCTIONNELLE VERIFIEE
void get_this_edge_in_the_right_place(carre_t * carre, signed char cote) //cote droit: 1, cote gauche: 0
{
    carre_t *face=get_face_from_carre(carre);
    carre_t *face_right=get_face_on_the_right(face);
    carre_t *face_left=get_face_on_the_left(face);
    if(cote)
    {
        rotate_face(DOWN, 1);
        rotate_face(face_right, 1);
        rotate_face(DOWN, 0);
        rotate_face(face_right, 0);
        rotate_face(DOWN, 0);
        rotate_face(face, 0);
        rotate_face(DOWN, 1);
        rotate_face(face, 1);
    }
    else
    {
        rotate_face(DOWN, 0);
        rotate_face(face_left, 0);
        rotate_face(DOWN, 1);
        rotate_face(face_left, 1);
        rotate_face(DOWN, 1);
        rotate_face(face, 1);
        rotate_face(DOWN, 0);
        rotate_face(face, 0);
    }
}
carre_t *get_face_on_the_right(carre_t *face)
{
    carre_t *retour;
    if(face==LEFT)
        retour=BACK;
    if(face==RIGHT)
        retour=FRONT;
    if(face==FRONT)
        retour=LEFT;
    if(face==BACK)
        retour=RIGHT;
    return retour;
}

carre_t *get_face_on_the_left(carre_t *face)
{
    carre_t *retour;
    if(face==LEFT)
        retour=FRONT;
    if(face==RIGHT)
        retour=BACK;
    if(face==FRONT)
        retour=RIGHT;
    if(face==BACK)
        retour=LEFT;
    return retour;
}


signed char get_id_from_searched_cube(color_t color1, color_t color2)
{
    signed char id_returned=0;
    signed char position0 = 0;
    signed char id_excluded[3]= {0,0,0};
    for(int i=0; i<3; i++)
    {
        position0=get_position(LEFT, color1, EDGE, LEFT[1].id, id_excluded[0], id_excluded[1]);
        if(position0==-1)
            break;
        else
        {
            if(get_carre_on_the_same_cube(LEFT, position0, EDGE)->color==color2)
            {
                id_returned=LEFT[position0].id;
                goto fin;
            }
            else
            {
                id_excluded[i]=LEFT[position0].id;
            }
        }
    }
    for(int i=0; i<3; i++)
    {
        position0=get_position(RIGHT, color1, EDGE, RIGHT[1].id, id_excluded[0], id_excluded[1]);
        if(position0==-1)
            break;
        else
        {
            if(get_carre_on_the_same_cube(RIGHT, position0, EDGE)->color==color2)
            {
                id_returned=RIGHT[position0].id;
                goto fin;
            }
            else
            {
                id_excluded[i]=RIGHT[position0].id;
            }
        }
    }

    for(int i=0; i<3; i++)
    {
        position0=get_position(FRONT, color1, EDGE, FRONT[1].id, id_excluded[0], id_excluded[1]);
        if(position0==-1)
            break;
        else
        {
            if(get_carre_on_the_same_cube(FRONT, position0, EDGE)->color==color2)
            {
                id_returned=FRONT[position0].id;
                goto fin;
            }
            else
            {
                id_excluded[i]=FRONT[position0].id;
            }
        }
    }

    for(int i=0; i<3; i++)
    {
        position0=get_position(BACK, color1, EDGE, BACK[1].id, id_excluded[0], id_excluded[1]);
        if(position0==-1)
            break;
        else
        {
            if(get_carre_on_the_same_cube(BACK, position0, EDGE)->color==color2)
            {
                id_returned=BACK[position0].id;
                goto fin;
            }
            else
            {
                id_excluded[i]=BACK[position0].id;
            }
        }
    }

    for(int i=0; i<3; i++)
    {
        position0=get_position(DOWN, color1, EDGE, id_excluded[0], id_excluded[1], id_excluded[2]);
        if(position0==-1)
            break;
        else
        {
            if(get_carre_on_the_same_cube(DOWN, position0, EDGE)->color==color2)
            {
                id_returned=get_carre_on_the_same_cube(DOWN, position0, EDGE)->id;
                goto fin;
            }
            else
            {
                id_excluded[i]=DOWN[position0].id;
            }
        }
    }
fin:
    return id_returned;
}
void affich_id(void)
{
    for(int i=0; i<9; i++)
        printf("BACK[%d].id=%d\n",i,BACK[i].id);
    for(int i=0; i<9; i++)
        printf("FRONT[%d].id=%d\n",i,FRONT[i].id);
    for(int i=0; i<9; i++)
        printf("LEFT[%d].id=%d\n",i,LEFT[i].id);
    for(int i=0; i<9; i++)
        printf("RIGHT[%d].id=%d\n",i,RIGHT[i].id);
}
void step_4_yellow_cross(void)
{
    while((DOWN[1].color!=DOWN[4].color)||(DOWN[3].color!=DOWN[4].color)||(DOWN[5].color!=DOWN[4].color)||(DOWN[7].color!=DOWN[4].color))
    {
        if(get_configuration_yellow_cross()==7)
        {
            printf("config initiale =7\n");
            treat_this_yellow_cross_configuration(1);
            treat_this_yellow_cross_configuration(get_configuration_yellow_cross());
        }
        else
            treat_this_yellow_cross_configuration(get_configuration_yellow_cross());
    }

}

unsigned char get_configuration_yellow_cross(void)
{
    unsigned char returned_config;
    if((DOWN[3].color==DOWN[4].color)&&(DOWN[5].color==DOWN[4].color))
    {
        returned_config=1;
    }
    else if((DOWN[1].color==DOWN[4].color)&&(DOWN[7].color==DOWN[4].color))
    {
        returned_config=2;
    }
    else if((DOWN[1].color==DOWN[4].color)&&(DOWN[3].color==DOWN[4].color))
    {
        returned_config=3;
    }
    else if((DOWN[1].color==DOWN[4].color)&&(DOWN[5].color==DOWN[4].color))
    {
        returned_config=4;
    }
    else if((DOWN[3].color==DOWN[4].color)&&(DOWN[7].color==DOWN[4].color))
    {
        returned_config=5;
    }
    else if((DOWN[5].color==DOWN[4].color)&&(DOWN[7].color==DOWN[4].color))
    {
        returned_config=6;
    }
    else
    {
        returned_config=7;
    }
    return returned_config;
}

void treat_this_yellow_cross_configuration(unsigned char config)
{
    switch(config)
    {
    case 1:
        rotate_face(FRONT, 1);
        rotate_face(LEFT, 1);
        rotate_face(DOWN, 1);
        rotate_face(LEFT, 0);
        rotate_face(DOWN, 0);
        rotate_face(FRONT, 0);
        break;
    case 2:
        rotate_face(RIGHT, 1);
        rotate_face(FRONT, 1);
        rotate_face(DOWN, 1);
        rotate_face(FRONT, 0);
        rotate_face(DOWN, 0);
        rotate_face(RIGHT, 0);
        break;
    case 3:
        rotate_face(BACK, 1);
        rotate_face(DOWN, 1);
        rotate_face(RIGHT, 1);
        rotate_face(DOWN, 0);
        rotate_face(RIGHT, 0);
        rotate_face(BACK, 0);
        break;
    case 4:
        rotate_face(LEFT, 1);
        rotate_face(DOWN, 1);
        rotate_face(BACK, 1);
        rotate_face(DOWN, 0);
        rotate_face(BACK, 0);
        rotate_face(LEFT, 0);
        break;
    case 5:
        rotate_face(RIGHT, 1);
        rotate_face(DOWN, 1);
        rotate_face(FRONT, 1);
        rotate_face(DOWN, 0);
        rotate_face(FRONT, 0);
        rotate_face(RIGHT, 0);
        break;
    case 6:
        rotate_face(FRONT, 1);
        rotate_face(DOWN, 1);
        rotate_face(LEFT, 1);
        rotate_face(DOWN, 0);
        rotate_face(LEFT, 0);
        rotate_face(FRONT, 0);
        break;
    case 7:
        break;
    default:
        printf("erreur fonction treat_this_yellow_cross_configuration");
        break;
    }
}

void step_5_yellow_corner(void)
{
    unsigned char config=get_configuration_yellow_corner();
    carre_t *faceR;
    carre_t *faceU=DOWN;
    carre_t *faceL;
    carre_t *faceF;
    carre_t *faceD=UP;;
    if((config==1)||(config==5)||(config==9)||(config==13)||(config==17)||(config==21)||(config==23))
    {
        faceR=LEFT;
        faceL=RIGHT;
        faceF=FRONT;
    }
    else if((config==2)||(config==6)||(config==10)||(config==14)||(config==18)||(config==24)||(config==22))
    {
        faceR=FRONT;
        faceL=BACK;
        faceF=RIGHT;
    }
    else if((config==3)||(config==7)||(config==11)||(config==15)||(config==19)||(config==25))
    {
        faceR=RIGHT;
        faceL=LEFT;
        faceF=BACK;
    }
    else if((config==4)||(config==8)||(config==12)||(config==16)||(config==20)||(config==26))
    {
        faceR=BACK;
        faceL=FRONT;
        faceF=LEFT;
    }
    //cas 5
    if((config>=1)&&(config<=4))
    {
        rotate_face(faceR, 0);
        if(config==1)
        {
            faceU=FRONT;
            faceD=BACK;
        }
        if(config==2)
        {
            faceU=RIGHT;
            faceD=LEFT;
        }
        if(config==3)
        {
            faceU=BACK;
            faceD=FRONT;
        }
        if(config==4)
        {
            faceU=LEFT;
            faceD=RIGHT;
        }
        rotate_face(faceU, 0);
        rotate_face(faceR, 1);
        rotate_face(faceD, 0);
        rotate_face(faceR, 0);
        rotate_face(faceU, 1);
        rotate_face(faceR, 1);
        rotate_face(faceD, 1);
    }
    //cas 6
    else if((config>=5)&&(config<=8))
    {
        rotate_face(faceR, 0);
        if(config==5)
        {
            faceU=FRONT;
            faceD=BACK;
        }
        else if(config==6)
        {
            faceU=RIGHT;
            faceD=LEFT;
        }
        else if(config==7)
        {
            faceU=BACK;
            faceD=FRONT;
        }
        else if(config==8)
        {
            faceU=LEFT;
            faceD=RIGHT;
        }
        rotate_face(faceU, 1);
        rotate_face(faceR, 1);
        rotate_face(faceD, 0);
        rotate_face(faceR, 0);
        rotate_face(faceU, 0);
        rotate_face(faceR, 1);
        rotate_face(faceD, 1);
    }
    //cas 7
    else if((config>=9)&&(config<=12))
    {
        rotate_face(faceR, 1);
        rotate_face(faceR, 1);
        rotate_face(faceD, 1);
        rotate_face(faceR, 0);
        rotate_face(faceU, 1);
        rotate_face(faceU, 1);
        rotate_face(faceR, 1);
        rotate_face(faceD, 0);
        rotate_face(faceR, 0);
        rotate_face(faceU, 1);
        rotate_face(faceU, 1);
        rotate_face(faceR, 0);
    }
    //cas 1
    else if((config>=13)&&(config<=16))
    {
        rotate_face(faceR, 1);
        rotate_face(faceU, 0);
        rotate_face(faceL, 0);
        rotate_face(faceU, 1);
        rotate_face(faceR, 0);
        rotate_face(faceU, 0);
        rotate_face(faceL, 1);
    }
    //cas 2
    else if((config>=17)&&(config<=20))
    {
        rotate_face(faceL, 0);
        rotate_face(faceU, 1);
        rotate_face(faceR, 1);
        rotate_face(faceU, 0);
        rotate_face(faceL, 1);
        rotate_face(faceU, 1);
        rotate_face(faceR, 0);
    }
    //cas 3
    else if((config>=21)&&(config<=22))
    {
        rotate_face(faceF, 1);
        for(int i=0; i<3; i++)
        {
            rotate_face(faceR, 1);
            rotate_face(faceU, 1);
            rotate_face(faceR, 0);
            rotate_face(faceU, 0);
        }
        rotate_face(faceF, 0);
    }
    //cas 4
    else if((config>=23)&&(config<=26))
    {
        rotate_face(faceR, 1);
        rotate_face(DOWN, 1);
        rotate_face(DOWN, 1);
        rotate_face(faceR, 0);
        rotate_face(faceR, 0);
        rotate_face(DOWN, 0);
        rotate_face(faceR, 1);
        rotate_face(faceR, 1);
        rotate_face(DOWN, 0);
        rotate_face(faceR, 0);
        rotate_face(faceR, 0);
        rotate_face(DOWN, 0);
        rotate_face(DOWN, 0);
        rotate_face(faceR, 1);
    }
}
unsigned char get_configuration_yellow_corner(void)
{
    unsigned char returned_config=0;//https://www.theologeek.ch/rubiks-cube/

    signed char position=get_position(DOWN, DOWN[4].color, CORNER, -1, -1, -1);
    if(position!=-1)
    {
        signed char position2=get_position(DOWN, DOWN[4].color, CORNER, DOWN[position].id, -1, -1);
        if(position2!=-1)
        {
            //cas 5
            if((LEFT[6].color==DOWN[4].color)&&(RIGHT[8].color==DOWN[4].color))
                returned_config=1;
            else if((FRONT[6].color==DOWN[4].color)&&(BACK[8].color==DOWN[4].color))
                returned_config=2;
            else if((RIGHT[6].color==DOWN[4].color)&&(LEFT[8].color==DOWN[4].color))
                returned_config=3;
            else if((FRONT[8].color==DOWN[4].color)&&(BACK[6].color==DOWN[4].color))
                returned_config=4;
            //cas 6
            else if((FRONT[8].color==DOWN[4].color)&&(LEFT[6].color==DOWN[4].color))
                returned_config=5;
            else if((FRONT[6].color==DOWN[4].color)&&(RIGHT[8].color==DOWN[4].color))
                returned_config=6;
            else if((RIGHT[6].color==DOWN[4].color)&&(BACK[8].color==DOWN[4].color))
                returned_config=7;
            else if((BACK[6].color==DOWN[4].color)&&(LEFT[8].color==DOWN[4].color))
                returned_config=8;
            //cas 7
            else if((FRONT[6].color==DOWN[4].color)&&(FRONT[8].color==DOWN[4].color))
                returned_config=9;
            else if((RIGHT[6].color==DOWN[4].color)&&(RIGHT[8].color==DOWN[4].color))
                returned_config=10;
            else if((BACK[6].color==DOWN[4].color)&&(BACK[8].color==DOWN[4].color))
                returned_config=11;
            else if((LEFT[6].color==DOWN[4].color)&&(LEFT[8].color==DOWN[4].color))
                returned_config=12;
        }
        else
        {
            //cas 1
            if((FRONT[6].color==DOWN[4].color)&&(BACK[6].color==DOWN[4].color)&&(LEFT[6].color==DOWN[4].color))
                returned_config=13;
            else if((FRONT[6].color==DOWN[4].color)&&(RIGHT[6].color==DOWN[4].color)&&(LEFT[6].color==DOWN[4].color))
                returned_config=14;
            else if((BACK[6].color==DOWN[4].color)&&(RIGHT[6].color==DOWN[4].color)&&(FRONT[6].color==DOWN[4].color))
                returned_config=15;
            else if((LEFT[6].color==DOWN[4].color)&&(BACK[6].color==DOWN[4].color)&&(RIGHT[6].color==DOWN[4].color))
                returned_config=16;
            //cas 2
            else if((FRONT[8].color==DOWN[4].color)&&(RIGHT[8].color==DOWN[4].color)&&(BACK[8].color==DOWN[4].color))
                returned_config=17;
            else if((RIGHT[8].color==DOWN[4].color)&&(BACK[8].color==DOWN[4].color)&&(LEFT[8].color==DOWN[4].color))
                returned_config=18;
            else if((BACK[8].color==DOWN[4].color)&&(LEFT[8].color==DOWN[4].color)&&(FRONT[8].color==DOWN[4].color))
                returned_config=19;
            else if((LEFT[8].color==DOWN[4].color)&&(FRONT[8].color==DOWN[4].color)&&(RIGHT[8].color==DOWN[4].color))
                returned_config=20;
        }
    }
    else
    {
        //cas 3
        if((FRONT[6].color==DOWN[4].color)&&(FRONT[8].color==DOWN[4].color)&&(BACK[6].color==DOWN[4].color)&&(BACK[8].color==DOWN[4].color))
            returned_config=21;
        else if((RIGHT[6].color==DOWN[4].color)&&(RIGHT[8].color==DOWN[4].color)&&(LEFT[6].color==DOWN[4].color)&&(LEFT[8].color==DOWN[4].color))
            returned_config=22;
        //cas 4
        else if((FRONT[6].color==DOWN[4].color)&&(RIGHT[6].color==DOWN[4].color)&&(RIGHT[8].color==DOWN[4].color)&&(BACK[8].color==DOWN[4].color))
            returned_config=23;
        else if((RIGHT[6].color==DOWN[4].color)&&(BACK[6].color==DOWN[4].color)&&(BACK[8].color==DOWN[4].color)&&(LEFT[8].color==DOWN[4].color))
            returned_config=24;
        else if((BACK[6].color==DOWN[4].color)&&(LEFT[6].color==DOWN[4].color)&&(LEFT[8].color==DOWN[4].color)&&(FRONT[8].color==DOWN[4].color))
            returned_config=25;
        else if((LEFT[6].color==DOWN[4].color)&&(FRONT[6].color==DOWN[4].color)&&(FRONT[8].color==DOWN[4].color)&&(RIGHT[8].color==DOWN[4].color))
            returned_config=26;
    }
    return returned_config;
}
