#include "worker.h"


void draw_worker() {
	glTranslatef(0, -5.75, 2.20);
	glScalef(0.4, 0.4, 0.4);

	/* crtam glavu worker-a */
	glPushMatrix();
		glColor3f(0.72, 0.53, 0.04);
		glTranslatef(0, 2, 0);
		glutSolidSphere(1, 30, 30);
	glPopMatrix();
	
	/* crtam telo worker-a */
	glPushMatrix();
		glColor3f(0.34, 0.01, 0.1);
		glScalef(1, 1, 0.25);
		glutSolidCube(2);
	glPopMatrix();

	/* crtam ruke worker-a */
	glPushMatrix();
		glColor3f(0.72, 0.53, 0.04);
		glTranslatef(1.25, 0.75, 0);
		/* koristim worker parametar kojom worker pomera ruku */
		glRotatef(worker_parameter, 2, 0, 0);
		glTranslatef(0, -0.75, 0);
		glScalef(0.25, 1, 0.25);
		glutSolidCube(2);
	glPopMatrix();

	glPushMatrix();
		glColor3f(0.72, 0.53, 0.04);
		glTranslatef(-1.25, 0, 0);
		glScalef(0.25, 1, 0.25);
		glutSolidCube(2);
	glPopMatrix();

	/* crtam noge worker-a */
	glPushMatrix();
		glColor3f(0.72, 0.53, 0.04);
		glTranslatef(-0.75, -2, 0);
		glScalef(0.25, 1, 0.25);
		glutSolidCube(2);
	glPopMatrix();

	glPushMatrix();
		glColor3f(0.72, 0.53, 0.04);
		glTranslatef(0.75, -2, 0);
		glScalef(0.25, 1, 0.25);
		glutSolidCube(2);
	glPopMatrix();
}