#ifndef WORKER_H
#define WORKER_H

#include <GL/glut.h>

/* parametar za pomeranje ruke */
float worker_parameter;

/* parametar koji nam govori da li se ruka spusta ili se podize */
int up_down_hand;

/* funkcija koja crta worker-a */
void draw_worker();

#endif
