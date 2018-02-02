#ifndef PANORAMA_H
#define PANORAMA_H 

#include <math.h>
#include <GL/glut.h>

#define PI 3.14159265359
#define EPS 0.01

/* ugao rotacije kamere */
float angle;

/* parametar za kretanje panorame */
float panorama_parameter;

/* parametar brzine kretanja panorame */
float panorama_speed;

/* funkcije za crtanje panorame i sedista */
void draw_panorama();
void draw_seat(float x, float y);

#endif

