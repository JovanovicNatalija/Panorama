#include "panorama.h"

void draw_panorama() {


	/* crtam dva kruga */
	glColor3f(0.59, 0, 0.09);
	for(float u = 0; u < 2*PI + EPS; u += PI/50)
    {
    	glBegin(GL_LINES);
    		glVertex3f(5*cos(u), 5*sin(u), 1);
    		glVertex3f(5*cos(u + PI/50), 5*sin(u + PI/50), 1);

    		glVertex3f(5*cos(u), 5*sin(u), -1);
    		glVertex3f(5*cos(u + PI/50), 5*sin(u + PI/50), -1);
    	glEnd();
    }

    /* crtam liniju koja prolazi kroz centar ovih krugova */
    glBegin(GL_LINES);
    	glVertex3f(0, 0, 1.5);
    	glVertex3f(0, 0, -1.5);
    glEnd();

    /* _\|/_
        /|\
       crtam ove linija unutar krugova
       linije koje povezuju krajeve upravo nacrtanih linija
       i dodajem sedista 
       uz pomoc panorama parametra vrsi se kretanje panorame
    */
    for(float u = panorama_parameter; u <= 2*PI + panorama_parameter; u += PI/10)
    {
        glColor3f(0.59, 0, 0.09);
    	glBegin(GL_LINES);
    		glVertex3f(5*cos(u), 5*sin(u), 1);
    		glVertex3f(0, 0, 1);
            
            glVertex3f(5*cos(u), 5*sin(u), -1);
    		glVertex3f(0, 0, -1);

    		glVertex3f(5*cos(u), 5*sin(u), 1);
    		glVertex3f(5*cos(u), 5*sin(u), -1);
    	glEnd();

    	draw_seat(5*cos(u), 5*sin(u));
    }


    /* po dva trougla i po dva cetvorougla praveci drzace za krugove sa obe strane */
    glColor3f(0.34, 0.01, 0.1);
    glBegin(GL_TRIANGLES);
    	glVertex3f(0, 0, -1.5);
    	glVertex3f(-1, -7, -1.5);
    	glVertex3f(1, -7, -1.5);

    	glVertex3f(0, 0, -1);
    	glVertex3f(-1, -7, -1);
    	glVertex3f(1, -7, -1);

    	glVertex3f(0, 0, 1);
    	glVertex3f(-1, -7, 1);
    	glVertex3f(1, -7, 1);

    	glVertex3f(0, 0, 1.5);
    	glVertex3f(-1, -7, 1.5);
    	glVertex3f(1, -7, 1.5);
    glEnd();

    glBegin(GL_QUADS);
    	glVertex3f(0, 0, 1);
    	glVertex3f(0, 0, 1.5);
    	glVertex3f(1, -7, 1.5);
    	glVertex3f(1, -7, 1);

    	glVertex3f(0, 0, 1);
    	glVertex3f(0, 0, 1.5);
    	glVertex3f(-1, -7, 1.5);
    	glVertex3f(-1, -7, 1);

    	glVertex3f(0, 0, -1);
    	glVertex3f(0, 0, -1.5);
    	glVertex3f(1, -7, -1.5);
    	glVertex3f(1, -7, -1);

    	glVertex3f(0, 0, -1);
    	glVertex3f(0, 0, -1.5);
    	glVertex3f(-1, -7, -1.5);
    	glVertex3f(-1, -7, -1);
    glEnd();
}

void draw_seat(float x, float y) {
	/* naslon za ledja */
	glBegin(GL_POLYGON);
		glColor3f(0.34, 0.01, 0.1);
		glVertex3f(x, y, 1);
		glVertex3f(x, y, -1);
		glVertex3f(x, y-1, -1);
		glVertex3f(x, y-1, 1);
	glEnd();

	/* donji deo sedista */
	glPushMatrix();
		glColor3f(0.6, 0.4, 0.8);
		glTranslatef(x-0.25, y-1, 0);
		glScalef(0.5, 0.1, 2);
		glutSolidCube(1);
	glPopMatrix();

	/* naslon sa desne strane */
	glPushMatrix();
		glColor3f(0.34, 0.01, 0.1);
		glTranslatef(x-0.25, y-0.75, -1);
		glScalef(0.5, 0.5, 0.1);
		glutSolidCube(1);
	glPopMatrix();

	/* naslon sa leve strane */
	glPushMatrix();
		glColor3f(0.34, 0.01, 0.1);
		glTranslatef(x-0.25, y-0.75, 1);
		glScalef(0.5, 0.5, 0.1);
		glutSolidCube(1);
	glPopMatrix();
}

