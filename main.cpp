#include <iostream>
#include <GL/freeglut.h>
#include <ctime>
#include <cstdlib>
#include <GL/glext.h>
#include <cmath>
#include "./imports/leitorBMP.h"

using namespace std;

//SISTEMA SOLAR 3D

int gameSpeed = 10;
int _width = 900, _height = 900;
GLuint textureID[9]; //GLOBAL
int width_ = 900;
int heigth_ = 900;

GLdouble bgpos = 0;
GLdouble r = 0;

GLfloat LIGHT_DIFFUSE[] = {1.0, 1.0, 1.0, 1.0}; //COR VERMELHA
GLfloat LIGHT_POSITION[] = {0.5, 0.0, -0.5, 1.0};

GLfloat light_diffuse[] = {1.0, 0.0, 0.0, 1.0};
GLfloat light_ambient[] = {0.1, 0.5, 0.5, 1.0};
GLfloat light_specular[] = {1.0, 1.0, 1.0, 1.0};
GLfloat light_position[] = {1.0, 0.0, -5.0, 0.0};
GLdouble angle = 0.0;			//Angulo da camera
GLdouble lx = 0.0f, lz = -1.0f; //Direção da camera
GLdouble x = 0.0f, z = 5.0f;	//Posição da camera

void drawSnowMan()
{
	glColor3f(1.0f, 1.0f, 1.0f);
	// Desenhar corpo
	glTranslatef(0.0f, 0.75f, 0.0f);
	glutSolidSphere(0.75f, 20, 20);
	// Desenhar cabeça
	glTranslatef(0.0f, 1.0f, 0.0f);
	glutSolidSphere(0.25f, 20, 20);
	// Desenhar olhos
	glPushMatrix();
	glColor3f(0.0f, 0.0f, 0.0f);
	glTranslatef(0.05f, 0.10f, 0.18f);
	glutSolidSphere(0.05f, 10, 10);
	glTranslatef(-0.1f, 0.0f, 0.0f);
	glutSolidSphere(0.05f, 10, 10);
	glPopMatrix();
	// Desenhar nariz
	glColor3f(1.0f, 0.5f, 0.5f);
	glutSolidCone(0.08f, 0.5f, 10, 2);
}

void drawTextureSpace()
{

	glBindTexture(GL_TEXTURE_2D, textureID[3]);

	//desenhendo chão
	// glColor3f(1, 1, 1);
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

	glGenTextures(3, textureID);

	loadBMP("./images/SUN.bmp");

	glBindTexture(GL_TEXTURE_2D, textureID[0]); //inserindo textura na memoria para configurar ela

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_BGR, GL_UNSIGNED_BYTE, data); //se necessário ver documentação para entender os parametros.

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	loadBMP("./images/EARTH.bmp");

	glBindTexture(GL_TEXTURE_2D, textureID[1]); //inserindo textura na memoria para configurar ela

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_BGR, GL_UNSIGNED_BYTE, data); //se necessário ver documentação para entender os parametros.

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	loadBMP("./images/MOON.bmp");

	glBindTexture(GL_TEXTURE_2D, textureID[2]); //inserindo textura na memoria para configurar ela

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_BGR, GL_UNSIGNED_BYTE, data); //se necessário ver documentação para entender os parametros.

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	loadBMP("./images/SPACE.bmp");

	glBindTexture(GL_TEXTURE_2D, textureID[3]); //inserindo textura na memoria para configurar ela

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_BGR, GL_UNSIGNED_BYTE, data); //se necessário ver documentação para entender os parametros.

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
}

void configureLights()
{ //referente as cores / iluminação

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
GLUquadricObj *earth = NULL;

void loadTextures()
{

	sun = gluNewQuadric();

	gluQuadricDrawStyle(sun, GLU_FILL);
	gluQuadricTexture(sun, GL_TRUE);
	gluQuadricNormals(sun, GLU_SMOOTH);

	earth = gluNewQuadric();

	gluQuadricDrawStyle(earth, GLU_FILL);
	gluQuadricTexture(earth, GL_TRUE);
	gluQuadricNormals(earth, GLU_SMOOTH);
}

void drawSun()
{
	glBindTexture(GL_TEXTURE_2D, textureID[0]);
	glTranslatef(0.0f, 1.0f, 0.0f);
	gluSphere(sun, 2.0f, 20, 20);
}

double earthRot = 0.0;
void drawEarth()
{
	glBindTexture(GL_TEXTURE_2D, textureID[1]);
	glPushMatrix();
	glRotated(earthRot += 0.1, 0, 1, 0);
	glColor3f(0.0f, 0.9f, 1.0f);
	glTranslatef(8.0f, 0.0f, 0.0f);
	gluSphere(earth, 0.25f, 20, 20);
	glPopMatrix();
}

// double earthRot = 0.0;
void drawMercury()
{
	glBindTexture(GL_TEXTURE_2D, textureID[1]);
	glPushMatrix();
	glRotated(earthRot += 0.1, 0, 1, 0);
	glColor3f(0.0f, 0.9f, 1.0f);
	glTranslatef(4.0f, 0.0f, 0.0f);
	gluSphere(earth, 0.25f, 20, 20);
	glPopMatrix();
}


void drawTextureCircle()
{

	// glClearColor(0.0, 0, 0.0, 0);
	// glClear(GL_COLOR_BUFFER_BIT);

	// drawTextureSpace();

	glBindTexture(GL_TEXTURE_2D, textureID[1]);

	glColor3f(1, 1, 1);
	glBegin(GL_POLYGON);
	for (double i = 0; i < 2 * M_PI; i += (2 * M_PI) / 32)
	{

		double X = cos(i) * 0.5;
		double Y = sin(i) * 0.5;

		double TX = cos(i) * 0.5 + 0.5;
		double TY = sin(i) * 0.5 + 0.5;

		glTexCoord2d(TX, TY);
		glVertex2d(X, Y);
	}

	glEnd();
	// glutSwapBuffers();
}

void draw()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.0, 0, 0.0, 0);
	glLoadIdentity();
	gluLookAt(x, 1.0f, z,
			  x + lx, 1.0f, z + lz,
			  0.0f, 1.0f, 0.0f);

	// drawTextureSpace();
	drawSun();
	drawEarth();

	// gluSphere(sphere, 2.0, 20, 20);
	// drawTextureCircle();

	glutSwapBuffers();
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(width_, heigth_);
	glutCreateWindow("SISTEMA SOLAR");
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