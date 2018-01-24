#include <stdlib.h>
#include "panorama.h"
#include "worker.h"
#include "light.h"

#define TIMER_ID 0
#define TIMER_INTERVAL 20

static float animation_ongoing;

static void on_keyboard(unsigned char key, int x, int y);
static void on_reshape(int width, int height);
static void on_display(void);
static void on_timer(int value);
static void draw_floor();

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);

	glutInitWindowSize(300, 300);
	glutInitWindowPosition(100,100);
	glutCreateWindow("panorama");

	glutKeyboardFunc(on_keyboard);
	glutReshapeFunc(on_reshape);
	glutDisplayFunc(on_display);

	glClearColor(0, 0, 0, 0);
	glEnable(GL_DEPTH_TEST);
	glLineWidth(1.5);
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_NORMALIZE);
    
	glutMainLoop();

	return 0;
}

static void on_keyboard(unsigned char key, int x, int y) {
	switch(key) {
		case 27:
			exit(0);
			break;

		/* pritiskom na 'u' worker podize ruku i nakon sto je podigne
		   pocinje kretanje panorame */
		case 'u':
			if(!animation_ongoing) {
				glutTimerFunc(TIMER_INTERVAL, on_timer, TIMER_ID);
				animation_ongoing = 1;
				up_down_hand = 1;
			}
			break;

		/* pritiskom na 'd' worker spusta ruku i cim krene da je spusta panorama se 
			zaustavi */
		case 'd':
			if(animation_ongoing == 1 && worker_parameter == 90){
				up_down_hand = 0;
			}
			break;

	}
}

static void on_display(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(10, 15, 30,
              0, -3, 0, 
              0, 1, 0);

    set_light1();
    set_light2();
    set_light3();
    set_light4();
    draw_floor();
 	draw_panorama();
 	draw_worker();
    
    glutSwapBuffers();
}


static void on_reshape(int width, int height) {
	glViewport(0, 0, width, height);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(30, (float) width/height, 1, 100);
}

static void on_timer(int value) {
	if(value != TIMER_ID)
		return;

	/* uvecavamo parametar za panoramu i na taj nacin panorama se krece */
	if(worker_parameter == 90) {
	 	panorama_parameter += 0.01;
	}
	
	/* upravljamo rukom worker-a tj. spustamo je i podizemo pomocu worker_parametra
	   takodje zaustavljamo animaciju kada se ruka spusti */
	if(worker_parameter < 90 && worker_parameter >= 0 && up_down_hand == 1) {
		worker_parameter += 1;
	}if(worker_parameter <= 90 && worker_parameter > 0 && up_down_hand == 0){
		worker_parameter -= 1;
	}if(worker_parameter == 0)
		animation_ongoing = 0;

	glutPostRedisplay();

    if(animation_ongoing) {
    	glutTimerFunc(TIMER_INTERVAL, on_timer, TIMER_ID);
    }
}

void draw_floor() {
	glColor3f(0.33, 0.41, 0.2);
	glBegin(GL_POLYGON);
		glVertex3f(-7, -7, 7);
		glVertex3f(7, -7, 7);
		glVertex3f(7, -7, -7);
		glVertex3f(-7, -7, -7);
	glEnd();
}