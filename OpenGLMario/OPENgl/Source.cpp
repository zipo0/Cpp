#include <GL/glut.h> 
#include <cstdlib>
#include <iostream>
#include <winuser.h>
using namespace std;
void printqu(int xo, int yo, int x, int y, int mashtab, float r, float g, float b)
{
	
	glColor3f(r, g, b);
	glBegin(GL_QUADS);
	glVertex2i(xo+x* mashtab, yo+y * mashtab);
	glVertex2i(xo+(x-1) * mashtab, yo+y * mashtab);
	glVertex2i(xo+(x-1) * mashtab, yo+(y+1) * mashtab);
	glVertex2i(xo+x * mashtab, yo+(y+1) * mashtab);
	glEnd();
}
void printmario(int x, int y, int mashtab)
{
	printqu(x, y, 0, 0, mashtab, 1.1, 0.5, 0);
	printqu(x, y, 1, 0, mashtab, 0.1, 0.5, 0);
	printqu(x, y, 2, 0, mashtab, 0.1, 0.5, 0);
	printqu(x, y, 3, 0, mashtab, 0.1, 0.5, 0);
	printqu(x, y, 1, 1, mashtab, 0.1, 0.5, 0);
	printqu(x, y, 2, 1, mashtab, 0.1, 0.5, 0);
	printqu(x, y, 3, 1, mashtab, 0.1, 0.5, 0);
	printqu(x, y, 2, 2, mashtab, 1.0, 0, 0);
	printqu(x, y, 3, 2, mashtab, 1.0, 0, 0);
	printqu(x, y, 4, 2, mashtab, 1.0, 0, 0);

	for (int i = 0; i < 8;i++)
	 printqu(x, y, 2+i, 3, mashtab, 1.0, 0, 0);

	printqu(x, y, 8, 0, mashtab, 0.1, 0.5, 0);
	printqu(x, y, 9, 0, mashtab, 0.1, 0.5, 0);
	printqu(x, y, 10, 0, mashtab, 0.1, 0.5, 0);
	printqu(x, y, 11, 0, mashtab, 0.1, 0.5, 0);
	printqu(x, y, 8, 1, mashtab, 0.1, 0.5, 0);
	printqu(x, y, 9, 1, mashtab, 0.1, 0.5, 0);
	printqu(x, y, 10, 1, mashtab, 0.1, 0.5, 0);

	printqu(x, y, 7, 2, mashtab, 1.0, 0, 0);
	printqu(x, y, 8, 2, mashtab, 1.0, 0, 0);
	printqu(x, y, 9, 2, mashtab, 1.0, 0, 0);
	for (int i = 0; i < 6; i++)
		printqu(x, y, 3 + i, 4, mashtab, 1.0, 0, 0);
	for (int i = 0; i < 2; i++)
		printqu(x, y, 5 + i, 5, mashtab, 1.0, 0, 0);
	printqu(x, y, 4, 5, mashtab, 0.8, 0.7, 0.1);
	printqu(x, y, 7, 5, mashtab, 0.8, 0.7, 0.1);
	for (int i = 0; i < 2; i++)
		printqu(x, y, 0 + i, 3, mashtab, 0.8, 0.7, 0.1);
	for (int i = 0; i < 3; i++)
		printqu(x, y, 0 + i, 4, mashtab, 0.8, 0.7, 0.1);
	for (int i = 0; i < 2; i++)
		printqu(x, y, 0 + i, 5, mashtab, 0.8, 0.7, 0.1);
	printqu(x, y, 3, 5, mashtab, 1, 0.0, 0);
	printqu(x, y, 8, 5, mashtab, 1, 0.0, 0);

	for (int i = 0; i < 4; i++)
		printqu(x, y, 0 + i, 6, mashtab, 0.1, 0.5, 0);
	for (int i = 0; i < 3; i++)
		printqu(x, y, 1 + i, 7, mashtab, 0.1, 0.5, 0);
	for (int i = 0; i < 2; i++)
		printqu(x, y, 2 + i, 8, mashtab, 0.1, 0.5, 0);
	for (int i = 0; i < 3; i++)
		printqu(x, y, 4 , 8-i, mashtab, 1, 0.0, 0);
	printqu(x, y, 5, 7, mashtab, 0.1, 0.5, 0);
	printqu(x, y, 6, 7, mashtab, 0.1, 0.5, 0);
	printqu(x, y, 5, 8, mashtab, 0.1, 0.5, 0);
	printqu(x, y, 6, 8, mashtab, 0.1, 0.5, 0);
	printqu(x, y, 7, 8, mashtab, 0.1, 0.5, 0);
	printqu(x, y, 5, 5, mashtab, 1, 0, 0);
	printqu(x, y, 6, 5, mashtab, 1, 0, 0);
	for (int i = 0; i < 3; i++)
		printqu(x, y, 5 + i, 6, mashtab, 1.0, 0, 0);
	printqu(x, y, 7, 7, mashtab, 1, 0.0, 0);
	for (int i = 0; i < 3; i++)
		printqu(x, y, 8 + i, 7, mashtab, 0.1, 0.5, 0);
	for (int i = 0; i < 4; i++)
		printqu(x, y, 8 + i, 6, mashtab, 0.1, 0.5, 0);
	printqu(x, y, 9, 5, mashtab, 0.1, 0.5, 0);
	for (int i = 0; i < 3; i++)
		printqu(x, y, 9 + i, 4, mashtab, 0.8, 0.7, 0.1);
	for (int i = 0; i < 2; i++)
		printqu(x, y, 10 + i, 5, mashtab, 0.8, 0.7, 0.1);
	for (int i = 0; i < 2; i++)
		printqu(x, y, 10 + i, 3, mashtab, 0.8, 0.7, 0.1);
	printqu(x, y, 2, 5, mashtab, 0.1, 0.5, 0);
	for (int i = 0; i < 7; i++)
		printqu(x, y, 3 + i, 9, mashtab, 0.8, 0.7, 0.1);
	for (int i = 0; i < 4; i++)
		printqu(x, y, 3 + i, 10, mashtab, 0.8, 0.7, 0.1);
	for (int i = 0; i < 3; i++)
		printqu(x, y, 5 + i, 11, mashtab, 0.8, 0.7, 0.1);
	for (int i = 0; i < 3; i++)
		printqu(x, y, 4 + i, 12, mashtab, 0.8, 0.7, 0.1);
	for (int i = 0; i < 2; i++)
		printqu(x, y, 5 + i, 13, mashtab, 0.8, 0.7, 0.1);
	for (int i = 0; i < 3; i++)
		printqu(x, y, 8 + i, 12, mashtab, 0.8, 0.7, 0.1);
	for (int i = 0; i < 3; i++)
		printqu(x, y, 9 + i, 11, mashtab, 0.8, 0.7, 0.1);
	printqu(x, y, 8, 13, mashtab, 0.8, 0.7, 0.1);
	printqu(x, y, 2, 11, mashtab, 0.8, 0.7, 0.1);
	printqu(x, y, 2, 12, mashtab, 0.8, 0.7, 0.1);
	for (int i = 0; i < 4; i++)
		printqu(x, y, 7 + i, 10, mashtab, 0.2, 0.2, 0.2);
	printqu(x, y, 8, 11, mashtab, 0.2, 0.2, 0.2);
	printqu(x, y, 7, 13, mashtab, 0.2, 0.2, 0.2);
	printqu(x, y, 7, 12, mashtab, 0.2, 0.2, 0.2);
	for (int i = 0; i < 3; i++)
		printqu(x, y, 2 + i, 13, mashtab, 0.2, 0.2, 0.2);
	for (int i = 0; i < 3; i++)
		printqu(x, y, 3 , 11 + i, mashtab, 0.2, 0.2, 0.2);
	for (int i = 0; i < 3; i++)
		printqu(x, y, 1, 10 + i, mashtab, 0.2, 0.2, 0.2);
	printqu(x, y, 2, 10, mashtab, 0.2, 0.2, 0.2);
	printqu(x, y, 4, 11, mashtab, 0.2, 0.2, 0.2);
	for (int i = 0; i < 9; i++)
		printqu(x, y, 2 + i, 14, mashtab, 1.0, 0, 0);
	for (int i = 0; i < 5; i++)
		printqu(x, y, 3 + i, 15, mashtab, 1.0, 0, 0);
}
int x = 250;
int y = 50;
int dy = 30; 
bool jump = false;
void displayfunc(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_QUADS);
	glColor3f(1.0, 0.0, 0.0);
	glVertex2i(10, 20);
	glVertex2i(10, 10);
	glVertex2i(20, 10);
	glVertex2i(20, 20);
	glEnd();
	
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_QUADS);
	glColor3f(0.0, 0.0, 1.0);
	glVertex2i(0, 50);
	glVertex2i(10000, 50);
	glVertex2i(10000, 0);
	glVertex2i(0, 0);
	glEnd();

	
	cout << "display\n";
	printmario(x, y,15);

	
	glutSwapBuffers();
}
void reshape(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, w, 0, h);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}
void timer(int value) {
	
	if (GetKeyState(VK_LEFT) & 0x8000)
	{
		x -= 50;
	}
	if (GetKeyState(VK_RIGHT) & 0x8000)
	{
		x += 50;
	}
	if ((GetKeyState(VK_UP) & 0x8000) && !jump)
	{
		jump = true;
	}
	
	if (jump)
	{
		y = y + dy;
		dy--;
		if (y<=50)
		{
			jump = false;
			dy = 30;
		}
	}
	displayfunc();
	glutTimerFunc(33, timer, 0);
}
int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA);
	glutInitWindowSize(1024, 768);
	glutInitWindowPosition(200, 100);
	glutCreateWindow("it's me! MARIO!");
	glutReshapeFunc(reshape);
	glutDisplayFunc(displayfunc);
	glutTimerFunc(33, timer, 0);
	glutMainLoop();
}