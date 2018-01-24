#ifndef PANORAMA_H
#define PANORAMA_H

#include <math.h>
#include <GL/glut.h>

#define PI 3.14159265359
#define EPS 0.01

/* parametar za kretanje panorame */
float panorama_parameter;

void draw_panorama();
void draw_seat(float x, float y);

#endif

