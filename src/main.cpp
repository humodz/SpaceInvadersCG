#include <iostream>
#include <GL/glut.h>

#include "Controller.h"
#include "Ship.h"
#include "Shot.h"

using namespace std;

Ship player;

void onDisplay(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-3, 3, -2, 2);

	// colocar todas as funcoes de .draw() aqui:
	player.draw();

	glutSwapBuffers();
}

void onTimerTick(int step)
{
	// colocar todas as funcoes de .update() aqui:
	player.update();

	glutTimerFunc(1000 / 30, onTimerTick, step + 1);
	glutPostRedisplay();
}

int main(int argc, char **argv)
{
	// Initialize window
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(600, 400);
	glutInitWindowPosition(300, 100);
	glutCreateWindow("Rosinha Invaders");

	// Register callback functions
	Controller::registerCallbacks();
	glutDisplayFunc(onDisplay);
	glutTimerFunc(0, onTimerTick, 0);

	glutMainLoop();

	return 0;
}
