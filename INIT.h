#ifndef INIT_H_INCLUDED
#define INIT_H_INCLUDED
typedef enum {
    RED = 1 ,BLUE = 2,WHITE = 3,GREEN = 4,YELLOW = 5 ,ORANGE = 6
} color_t;

typedef enum{
    face_up=1, face_down=2, face_left=3, face_right=4, face_front=5, face_back=6
}face_t;

typedef struct carre{
    unsigned char position;
    unsigned char id;
    color_t color;
    face_t face;
}carre_t;



carre_t UP[9], DOWN[9], LEFT[9], RIGHT[9], FRONT[9], BACK[9];

void init_carre(carre_t *carre);
void global_init(void);
#endif // INIT_H_INCLUDED
