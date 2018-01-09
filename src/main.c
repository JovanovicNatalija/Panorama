#include <stdlib.h>
#include "panorama.h"

static void on_keyboard(unsigned char key, int x, int y);
static void on_reshape(int width, int height);
static void on_display(void);

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);

	glutInitWindowSize(300,300);
	glutInitWindowPosition(100,100);
	glutCreateWindow("panorama");

	glutKeyboardFunc(on_keyboard);
	glutReshapeFunc(on_reshape);
	glutDisplayFunc(on_display);

	glClearColor(0.7, 0.7, 0.7, 0.7);
	glEnable(GL_DEPTH_TEST);
	glLineWidth(1.5);
    
	glutMainLoop();

	return 0;
}

static void on_keyboard(unsigned char key, int x, int y) {
	switch(key) {
		case 27:
			exit(0);
			break;
	}
}

static void on_display(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(-10, 10, 25,
              0, 0, 0, 
              0, 1, 0);

 	nacrtaj_panoramu();
    
    glutSwapBuffers();
}


static void on_reshape(int width, int height) {
	glViewport(0, 0, width, height);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(30, (float) width/height, 1, 100);
}