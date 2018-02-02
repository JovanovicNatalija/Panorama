#include <stdlib.h>
#include "panorama.h"
#include "worker.h"
#include "light.h"

#define TIMER_ID 0
#define TIMER_INTERVAL 20

/* parametar koji govori da li je animacija u toku*/
static float animation_ongoing;

/* x, y i z koordinate pozicije kamere */
static float camera_positionX;
static float camera_positionY; 
static float camera_positionZ; 

/* ugao za koji se kamera rotira iz panorama.h */
extern float angle;

/* funkcija za podesavanje materijala */
static void set_material(void);

/* callback funkcije */
static void on_keyboard(unsigned char key, int x, int y);
static void on_reshape(int width, int height);
static void on_display(void);
static void on_timer(int value);

/* funkcija za crtanje poda */
static void draw_floor(void);

int main(int argc, char** argv) {
	/* inicijalizujem glut */
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);

	/* kreiram prozor */ 
	glutInitWindowSize(700, 500);
	glutInitWindowPosition(100,100);
	glutCreateWindow("panorama");

	/* registrujem callback funkcije */
	glutKeyboardFunc(on_keyboard);
	glutReshapeFunc(on_reshape);
	glutDisplayFunc(on_display);

	/* openGl inicijalizacija */
	glClearColor(0, 0, 0, 0);
	glEnable(GL_DEPTH_TEST);
	glLineWidth(1.5);
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_NORMALIZE);

	/* inicijalne vrednosti pozicije kamere */
	camera_positionX = 0;
	camera_positionY = 0;
	camera_positionZ = 30;
    
    /* glavna petlja */
	glutMainLoop();

	return 0;
}

static void on_keyboard(unsigned char key, int x, int y) {
	switch(key) {
		/* pritiskom na esc izlazi se iz programa */
		case 27:
			exit(0);
			break;

		/* pritiskom na 'w' worker podize ruku i nakon sto je podigne
		   pocinje kretanje panorame */
		case 'w':
			if(!animation_ongoing) {
				glutTimerFunc(TIMER_INTERVAL, on_timer, TIMER_ID);
				animation_ongoing = 1;
				up_down_hand = 1;
			}
			break;

		/* pritiskom na 's' worker spusta ruku i panorama se polako zaustavlja */
		case 's':
			if(animation_ongoing == 1 && worker_parameter == 90){
				up_down_hand = 0;
			}
			break;

		/* pomeram kameru ulevo */
		case 'a':
			angle -= PI/90;
			camera_positionX = 30*sin(angle);
			camera_positionZ = 30*cos(angle);
			glutPostRedisplay();
			break;

		/* pomeram kameru udesno */
		case 'd':
			angle += PI/90;
			camera_positionX = 30*sin(angle);
			camera_positionZ = 30*cos(angle);
			glutPostRedisplay();
			break;
	}
}

static void on_display(void) {
	/* brisem prethodni sadrzaj prozora */
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	/* podesavam kameru */
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(camera_positionX, camera_positionY, camera_positionZ,
              0, -2.5, 0, 
              0, 1, 0);

    set_material();
    set_light1();
    set_light2();
    set_light3();
    set_light4();
    draw_floor();
 	draw_panorama();
 	draw_worker();
    
    /* saljem novodobijenu sliku na ekran */ 
    glutSwapBuffers();
}


static void on_reshape(int width, int height) {
	/* podesavam viewport */
	glViewport(0, 0, width, height);

	/* podesavam projekciju */
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(30, (float) width/height, 1, 100);
}

static void on_timer(int value) {
	if(value != TIMER_ID)
		return;

	/* ako je ruka worker-a podignuta povecavace se brzina panorame sve do 0.02,
	   a inace cim ruka pocne da se spusta smanjivace se brzine sve do 0 */
	if(worker_parameter == 90 && panorama_speed < 0.02) {
		panorama_speed += 0.0001;
	} else if (up_down_hand == 0 && panorama_speed > 0) {
		panorama_speed -= 0.0001;
	}

	/* panorama se krece uvecavanjem panorama parametra, osim u slucaju kada se ruka podize
	   i jos uvek nije stigla do pozicije gde ce pokrenuti panoramu */
	if(up_down_hand == 1 && worker_parameter != 90);
	else {
	 	panorama_parameter += panorama_speed;
	}
	
	/* upravljamo rukom worker-a tj. spustamo je i podizemo pomocu worker_parametra */
	if(worker_parameter < 90 && worker_parameter >= 0 && up_down_hand == 1) {
		worker_parameter += 1;
	}if(worker_parameter <= 90 && worker_parameter > 0 && up_down_hand == 0){
		worker_parameter -= 1;
	}

	/* ukoliko je ruka spustena ili se panorama zaustavila zaustavicemo animaciju */
	if(worker_parameter == 0 && (round(panorama_speed * 10000) == 0 && up_down_hand == 0))
		animation_ongoing = 0;

	/* ponovno iscrtavanje scene */
	glutPostRedisplay();

    if(animation_ongoing) {
    	glutTimerFunc(TIMER_INTERVAL, on_timer, TIMER_ID);
    }
}

void draw_floor(void) {
	glColor3f(0.33, 0.41, 0.2);
	glNormal3f(0, 1, 0);
	glBegin(GL_POLYGON);
		glVertex3f(-7, -7, 7);
		glVertex3f(-7, -7, -7);
		glVertex3f(7, -7, -7);
		glVertex3f(7, -7, 7);
	glEnd();
}

void set_material(void) {
	/* ambijentalna refleksija materijala */
	GLfloat material_ambient[] = {0.9, 0.9, 0.9, 1};
	/* difuzna refleksija materijala */
    GLfloat material_diffuse[] = {0.5, 0.5, 0.5, 1};
    /* spekularna refleksija materijala */
    GLfloat material_specular[] = {0.3, 0.3, 0.3, 1};
    /* glatkost materijala */
    GLfloat shininess = 10;

    /* podesavam parametre materijala */
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, material_ambient);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, material_diffuse);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, material_specular);
    glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, shininess);
}