#include <iostream>
#include <GL/freeglut.h>
#include <ctime>
#include <cstdlib>
#include <GL/glext.h>
#include <cmath>
#include "./imports/leitorBMP.h"

using namespace std;

int gameSpeed = 10;
int _width = 900, _height = 900;
GLuint textureID[9];
int width_ = 900;
int heigth_ = 900;

GLdouble bgpos = 0;
GLdouble r = 0;

GLfloat LIGHT_DIFFUSE[] = {1.0, 1.0, 1.0, 1.0};
GLfloat LIGHT_POSITION[] = {0.5, 0.0, -0.5, 1.0};

GLfloat light_diffuse[] = {1.0, 0.0, 0.0, 1.0};
GLfloat light_ambient[] = {0.1, 0.5, 0.5, 1.0};
GLfloat light_specular[] = {1.0, 1.0, 1.0, 1.0};
GLfloat light_position[] = {1.0, 0.0, -5.0, 0.0};

GLdouble angle = 0.0;
GLdouble lx = 0.0f, lz = -1.0f;
GLdouble x = 0.0f, z = 5.0f;

void drawTextureSpace()
{

	glBindTexture(GL_TEXTURE_2D, textureID[3]);

	glBegin(GL_QUADS);
	glTexCoord2f(0, 0);
	glVertex3f(-100.0f, -15.0f, -100.0f);

	glTexCoord2f(1, 0);
	glVertex3f(-100.0f, -15.0f, 100.0f);

	glTexCoord2f(1, 1);
	glVertex3f(100.0f, -15.0f, 100.0f);

	glTexCoord2f(0, 1);
	glVertex3f(100.0f, -15.0f, -100.0f);
	glEnd();

	glBegin(GL_QUADS);
	glTexCoord2f(0, 0);
	glVertex3f(-100.0f, 15.0f, -100.0f);

	glTexCoord2f(1, 0);
	glVertex3f(-100.0f, 15.0f, 100.0f);

	glTexCoord2f(1, 1);
	glVertex3f(100.0f, 15.0f, 100.0f);

	glTexCoord2f(0, 1);
	glVertex3f(100.0f, 15.0f, -100.0f);
	glEnd();

	glBegin(GL_QUADS);
	glTexCoord2f(0, 0);
	glVertex3f(-100.0f, 100.0f, 15.0f);

	glTexCoord2f(1, 0);
	glVertex3f(-100.0f, -100.0f, 15.0f);

	glTexCoord2f(1, 1);
	glVertex3f(100.0f, -100.0f, 15.0f);

	glTexCoord2f(0, 1);
	glVertex3f(100.0f, 100.0f, 15.0f);
	glEnd();

	glPushMatrix();
	glRotated(1, 0, 0, 1);

	glBegin(GL_QUADS);
	glTexCoord2f(0, 0);
	glVertex3f(-100.0f, 100.0f, -15.0f);

	glTexCoord2f(1, 0);
	glVertex3f(-100.0f, -100.0f, -15.0f);

	glTexCoord2f(1, 1);
	glVertex3f(100.0f, -100.0f, -15.0f);

	glTexCoord2f(0, 1);
	glVertex3f(100.0f, 100.0f, -15.0f);
	glEnd();
	glPopMatrix();
}

void configureTexture()
{

	glEnable(GL_TEXTURE_2D);

	glGenTextures(9, textureID);

	loadBMP("./images/SUN.bmp");

	glBindTexture(GL_TEXTURE_2D, textureID[0]);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_BGR, GL_UNSIGNED_BYTE, data);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	loadBMP("./images/MERCURY.bmp");

	glBindTexture(GL_TEXTURE_2D, textureID[1]);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_BGR, GL_UNSIGNED_BYTE, data);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	loadBMP("./images/VENUS.bmp");

	glBindTexture(GL_TEXTURE_2D, textureID[2]);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_BGR, GL_UNSIGNED_BYTE, data);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	loadBMP("./images/EARTH.bmp");

	glBindTexture(GL_TEXTURE_2D, textureID[3]);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_BGR, GL_UNSIGNED_BYTE, data);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	loadBMP("./images/MARS.bmp");

	glBindTexture(GL_TEXTURE_2D, textureID[4]);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_BGR, GL_UNSIGNED_BYTE, data);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	loadBMP("./images/JUPYTER.bmp");

	glBindTexture(GL_TEXTURE_2D, textureID[5]);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_BGR, GL_UNSIGNED_BYTE, data);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	loadBMP("./images/SATURN.bmp");

	glBindTexture(GL_TEXTURE_2D, textureID[6]);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_BGR, GL_UNSIGNED_BYTE, data);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	loadBMP("./images/URANUS.bmp");

	glBindTexture(GL_TEXTURE_2D, textureID[7]);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_BGR, GL_UNSIGNED_BYTE, data);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	loadBMP("./images/NEPTUNE.bmp");

	glBindTexture(GL_TEXTURE_2D, textureID[8]);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_BGR, GL_UNSIGNED_BYTE, data);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
}

void configureLights()
{
	glEnable(GL_LIGHTING);

	glEnable(GL_DEPTH_TEST);

	glLightfv(GL_LIGHT0, GL_DIFFUSE, LIGHT_DIFFUSE);

	glLightfv(GL_LIGHT0, GL_POSITION, LIGHT_POSITION);

	glEnable(GL_LIGHT0);
}

void processSpecialKeys(int key, int xx, int yy)
{
	float amount = 0.5f;
	switch (key)
	{
	case GLUT_KEY_LEFT:
		angle -= 0.1f;
		lx = sin(angle);
		lz = -cos(angle);
		break;
	case GLUT_KEY_RIGHT:
		angle += 0.1f;
		lx = sin(angle);
		lz = -cos(angle);
		break;
	case GLUT_KEY_UP:
		x += lx * amount;
		z += lz * amount;
		break;
	case GLUT_KEY_DOWN:
		x -= lx * amount;
		z -= lz * amount;
		break;
	}
}
void timerFunc(int x)
{
	glutPostRedisplay();
	glutTimerFunc(gameSpeed, timerFunc, 0);
}
void configureCam()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0f, 1.0f, 0.1f, 100.0f);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glEnable(GL_DEPTH_TEST);
}
void processNormalKeys(unsigned char key, int x, int y)
{
	if (key == 27)
		exit(0);
}

GLUquadricObj *sun = NULL;
GLUquadricObj *mercury = NULL;
GLUquadricObj *venus = NULL;
GLUquadricObj *earth = NULL;
GLUquadricObj *mars = NULL;
GLUquadricObj *jupyter = NULL;
GLUquadricObj *saturn = NULL;
GLUquadricObj *uranus = NULL;
GLUquadricObj *neptune = NULL;

void loadTextures()
{
	sun = gluNewQuadric();

	gluQuadricDrawStyle(sun, GLU_FILL);
	gluQuadricTexture(sun, GL_TRUE);
	gluQuadricNormals(sun, GLU_SMOOTH);

	mercury = gluNewQuadric();

	gluQuadricDrawStyle(mercury, GLU_FILL);
	gluQuadricTexture(mercury, GL_TRUE);
	gluQuadricNormals(mercury, GLU_SMOOTH);

	venus = gluNewQuadric();

	gluQuadricDrawStyle(venus, GLU_FILL);
	gluQuadricTexture(venus, GL_TRUE);
	gluQuadricNormals(venus, GLU_SMOOTH);

	earth = gluNewQuadric();

	gluQuadricDrawStyle(earth, GLU_FILL);
	gluQuadricTexture(earth, GL_TRUE);
	gluQuadricNormals(earth, GLU_SMOOTH);

	mars = gluNewQuadric();

	gluQuadricDrawStyle(mars, GLU_FILL);
	gluQuadricTexture(mars, GL_TRUE);
	gluQuadricNormals(mars, GLU_SMOOTH);

	jupyter = gluNewQuadric();

	gluQuadricDrawStyle(jupyter, GLU_FILL);
	gluQuadricTexture(jupyter, GL_TRUE);
	gluQuadricNormals(jupyter, GLU_SMOOTH);

	saturn = gluNewQuadric();

	gluQuadricDrawStyle(saturn, GLU_FILL);
	gluQuadricTexture(saturn, GL_TRUE);
	gluQuadricNormals(saturn, GLU_SMOOTH);

	uranus = gluNewQuadric();

	gluQuadricDrawStyle(uranus, GLU_FILL);
	gluQuadricTexture(uranus, GL_TRUE);
	gluQuadricNormals(uranus, GLU_SMOOTH);

	neptune = gluNewQuadric();

	gluQuadricDrawStyle(neptune, GLU_FILL);
	gluQuadricTexture(neptune, GL_TRUE);
	gluQuadricNormals(neptune, GLU_SMOOTH);
}

void drawSun()
{
	glBindTexture(GL_TEXTURE_2D, textureID[0]);
	glTranslatef(0.0f, 1.0f, 0.0f);
	gluSphere(sun, 2.0f, 20, 20);
}

double mercuryhRot = 0.0;
void drawMercury()
{
	glBindTexture(GL_TEXTURE_2D, textureID[1]);
	glPushMatrix();
	glRotated(mercuryhRot += 0.1, 0, 1, 0);
	glColor3f(0.0f, 0.9f, 1.0f);
	glTranslatef(4.0f, 0.0f, 0.0f);
	gluSphere(mercury, 0.1f, 20, 20);
	glPopMatrix();
}

double venusRot = 0.0;
void drawVenus()
{
	glBindTexture(GL_TEXTURE_2D, textureID[2]);
	glPushMatrix();
	glRotated(venusRot += 0.12, 0, 1, 0);
	glColor3f(0.0f, 0.9f, 1.0f);
	glTranslatef(6.0f, 0.0f, 0.0f);
	gluSphere(venus, 0.2f, 20, 20);
	glPopMatrix();
}

double earthRot = 0.0;
void drawEarth()
{
	glBindTexture(GL_TEXTURE_2D, textureID[3]);
	glPushMatrix();
	glRotated(earthRot += 0.14, 0, 1, 0);
	glColor3f(0.0f, 0.9f, 1.0f);
	glTranslatef(8.0f, 0.0f, 0.0f);
	gluSphere(earth, 0.3f, 20, 20);
	glPopMatrix();
}

double marsRot = 0.0;
void drawMars()
{
	glBindTexture(GL_TEXTURE_2D, textureID[4]);
	glPushMatrix();
	glRotated(marsRot += 0.16, 0, 1, 0);
	glColor3f(0.0f, 0.9f, 1.0f);
	glTranslatef(10.0f, 0.0f, 0.0f);
	gluSphere(mars, 0.2f, 20, 20);
	glPopMatrix();
}

double jupyterRot = 0.0;
void drawJupyter()
{
	glBindTexture(GL_TEXTURE_2D, textureID[5]);
	glPushMatrix();
	glRotated(jupyterRot += 0.18, 0, 1, 0);
	glColor3f(0.0f, 0.9f, 1.0f);
	glTranslatef(12.0f, 0.0f, 0.0f);
	gluSphere(jupyter, 1.0f, 20, 20);
	glPopMatrix();
}

double saturnRot = 0.0;
void drawSaturn()
{
	glBindTexture(GL_TEXTURE_2D, textureID[6]);
	glPushMatrix();
	glRotated(saturnRot += 0.2, 0, 1, 0);
	glColor3f(0.0f, 0.9f, 1.0f);
	glTranslatef(14.0f, 0.0f, 0.0f);
	gluSphere(saturn, 0.85f, 20, 20);
	glPopMatrix();
}

double uranusRot = 0.0;
void drawUranus()
{
	glBindTexture(GL_TEXTURE_2D, textureID[7]);
	glPushMatrix();
	glRotated(uranusRot += 0.22, 0, 1, 0);
	glColor3f(0.0f, 0.9f, 1.0f);
	glTranslatef(16.0f, 0.0f, 0.0f);
	gluSphere(uranus, 0.35f, 20, 20);
	glPopMatrix();
}

double neptuneRot = 0.0;
void drawNeptune()
{
	glBindTexture(GL_TEXTURE_2D, textureID[8]);
	glPushMatrix();
	glRotated(neptuneRot += 0.24, 0, 1, 0);
	glColor3f(0.0f, 0.9f, 1.0f);
	glTranslatef(18.0f, 0.0f, 0.0f);
	gluSphere(neptune, 0.35f, 20, 20);
	glPopMatrix();
}

void draw()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.0, 0, 0.0, 0);
	glLoadIdentity();
	gluLookAt(x, 1.0f, z,
			  x + lx, 1.0f, z + lz,
			  0.0f, 1.0f, 0.0f);

	drawSun();
	drawMercury();
	drawVenus();
	drawEarth();
	drawMars();
	drawSaturn();
	drawJupyter();
	drawUranus();
	drawNeptune();

	glutSwapBuffers();
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(width_, heigth_);
	glutCreateWindow("SOLAR SYSTEM");
	glutDisplayFunc(draw);
	glutTimerFunc(10, timerFunc, 0);
	glutKeyboardFunc(processNormalKeys);
	glutSpecialFunc(processSpecialKeys);
	configureCam();
	configureTexture();
	configureLights();
	loadTextures();
	glutMainLoop();
	return 0;
}