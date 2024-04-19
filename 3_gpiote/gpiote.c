#include "gpiote.h"

void GPIOTE_init(){
    //EVENT MED TOGGLE, EVENT NÅR PINNE 13 TRIGGES
    GPIOTE->CONFIG[4] = 1 | (13 << 8) | (2 << 16) ;
    //TASKS MED TOGGLE, PINNER FOR LED-LYSENE
    GPIOTE->CONFIG[0] = 3 | (17 << 8) | (3 << 16) | (1<<20);
    GPIOTE->CONFIG[1] = 3 | (18 << 8) | (3 << 16) | (1<<20);
    GPIOTE->CONFIG[2] = 3 | (19 << 8) | (3 << 16) | (1<<20);
    GPIOTE->CONFIG[3] = 3 | (20 << 8) | (3 << 16) | (1<<20);
}