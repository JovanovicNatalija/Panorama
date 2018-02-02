#include "light.h"

/* parametri ambijentalnog, difuznog i spekularnog svetla */
GLfloat ambient_light[] = {0.1, 0.1, 0.1, 1};
GLfloat diffuse_light[] = {0.7, 0.7, 0.7, 1};
GLfloat specular_light[] = {0.9, 0.9, 0.9, 1};

void draw_reflector() {
	/* crtam sam reflektor */
	glColor3f(0.33, 0.41, 0.2);
	glNormal3f(-2, 0, 1);
	glBegin(GL_POLYGON);
		glVertex3f(0.25, 2.5, 0.25);
		glVertex3f(0.25, 2, 0.25);
		glVertex3f(0.50, 1.5, 0.75);
		glVertex3f(0.50, 3, 0.75);
	glEnd();

	glNormal3f(0, -1, 1);
	glBegin(GL_POLYGON);
		glVertex3f(0.25, 2.5, 0.25);
		glVertex3f(0.50, 3, 0.75);
		glVertex3f(-0.50, 3, 0.75);
		glVertex3f(-0.25, 2.5, 0.25);
	glEnd();

	glNormal3f(2, 0, 1);
	glBegin(GL_POLYGON);
		glVertex3f(-0.25, 2.5, 0.25);
		glVertex3f(-0.50, 3, 0.75);
		glVertex3f(-0.50, 1.5, 0.75);
		glVertex3f(-0.25, 2, 0.25);
	glEnd();

	glNormal3f(0, 1, 1);
	glBegin(GL_POLYGON);
		glVertex3f(-0.25, 2, 0.25);
		glVertex3f(-0.50, 1.5, 0.75);
		glVertex3f(0.50, 1.5, 0.75);
		glVertex3f(0.25, 2, 0.25);
	glEnd();

	/*crtam stub na kome se nalazi reflektor*/
	glColor3f(0.72, 0.53, 0.04);
	glScalef(0.1, 1, 0.1);
	glutSolidCube(5);
}

/* u svakom od narednih funkcija 'set_light' podesava se po
   jedno od svetala. Crtam reflektor prethodno napisanom
   funkcijom draw_reflector(), i rotiram i transliram kako bi reflektori
   bili dovedeni u odgovarajuce pozicije. Nakon toga podesavam
   koordinate svetla za svaki od reflektora. */
void set_light1() {
	glPushMatrix();
		glTranslatef(-6.75, -4.5, 6.75);
		glRotatef(135, 0, 1, 0);
		draw_reflector();
	glPopMatrix();
	
	GLfloat light_position[] = {-6.50, -2.25, 6.50, 1};
    
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glLightfv(GL_LIGHT0, GL_AMBIENT, ambient_light);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse_light);
    glLightfv(GL_LIGHT0, GL_SPECULAR, specular_light);
}


void set_light2() {
	glPushMatrix();
		glTranslatef(6.75, -4.5, 6.75);
		glRotatef(225, 0, 1, 0);
		draw_reflector();
	glPopMatrix();
	
	GLfloat light_position[] = {6.50, -2.25, 6.50, 1};

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT1);
    glLightfv(GL_LIGHT1, GL_POSITION, light_position);
    glLightfv(GL_LIGHT1, GL_AMBIENT, ambient_light);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, diffuse_light);
    glLightfv(GL_LIGHT1, GL_SPECULAR, specular_light);
}

void set_light3() {
	glPushMatrix();
		glTranslatef(6.75, -4.5, -6.75);
		glRotatef(-45, 0, 1, 0);
		draw_reflector();
	glPopMatrix();
	
	GLfloat light_position[] = {6.50, -2.25, -6.50, 1};
  
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT2);
    glLightfv(GL_LIGHT2, GL_POSITION, light_position);
    glLightfv(GL_LIGHT2, GL_AMBIENT, ambient_light);
    glLightfv(GL_LIGHT2, GL_DIFFUSE, diffuse_light);
    glLightfv(GL_LIGHT2, GL_SPECULAR, specular_light);
}

void set_light4() {
	glPushMatrix();
		glTranslatef(-6.75, -4.5, -6.75);
		glRotatef(45, 0, 1, 0);
		draw_reflector();
	glPopMatrix();
	
	GLfloat light_position[] = {-6.50, -2.25, -6.50, 1};

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT3);
    glLightfv(GL_LIGHT3, GL_POSITION, light_position);
    glLightfv(GL_LIGHT3, GL_AMBIENT, ambient_light);
    glLightfv(GL_LIGHT3, GL_DIFFUSE, diffuse_light);
    glLightfv(GL_LIGHT3, GL_SPECULAR, specular_light);
}