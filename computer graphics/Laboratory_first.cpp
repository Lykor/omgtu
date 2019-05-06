#include <GL/glut.h>
#include <random>

void myInit(void);
void myDisplay(void);


int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(100, 150);
	glutCreateWindow("Not First Program");

	myInit();
	glutDisplayFunc(myDisplay);
	glutMainLoop();
}
void myInit(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glPointSize(20.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 640, 0, 480);
}
void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glBegin(GL_TRIANGLES);

	glColor3f(1.0, 0.0, 0.0);
	
	glEdgeFlag(GL_FALSE);
	glVertex2d(50, 300);
	
	glVertex2d(150, 300);
	glEdgeFlag(GL_TRUE);
	glVertex2d(100, 400);
	

	glEdgeFlag(GL_FALSE);
	glVertex2d(150, 300);
	glEdgeFlag(GL_TRUE);
	glVertex2d(100, 400);
	glVertex2d(150, 400);

	glEdgeFlag(GL_FALSE);
	glVertex2d(50, 300);
	glEdgeFlag(GL_TRUE);
	glVertex2d(100, 300);
	glVertex2d(75, 250);

	glEdgeFlag(GL_FALSE);
	glVertex2d(100, 300);
	glEdgeFlag(GL_TRUE);
	glVertex2d(150, 300);
	glVertex2d(125, 250);

	glEnd();

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_QUADS);

	glColor3f(0.0, 0.0, 1.0);

	glVertex2i(400, 100);
	glVertex2i(300, 200);
	glVertex2i(300, 250);

	glVertex2i(450, 100);


	glEnd();

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glEnable(GL_POLYGON_STIPPLE);
	GLubyte texture[] = { 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, 0xAA,0xBB,0xCC,0xDD,0xAA,0xBB,0xCC,0xDD, 0x04,0x60,0x06,0x20,0x04,0x30,0x0C,0x20, 0xAA,0xBB,0xCC,0xDD,0xAA,0xBB,0xCC,0xDD, 0x04,0x06,0x60,0x20,0x44,0x03,0xC0,0x22, 0xAA,0xBB,0xCC,0xDD,0xAA,0xBB,0xCC,0xDD, 0x44,0x01,0x80,0x22,0x44,0x01,0x80,0x22, 0xAA,0xBB,0xCC,0xDD,0xAA,0xBB,0xCC,0xDD, 0x66,0x01,0x80,0x66,0x33,0x01,0x80,0xCC, 0xAA,0xBB,0xCC,0xDD,0xAA,0xBB,0xCC,0xDD, 0x07,0xE1,0x87,0xE0,0x03,0x3F,0xFC,0xC0, 0xAA,0xBB,0xCC,0xDD,0xAA,0xBB,0xCC,0xDD, 0x06,0x64,0x26,0x60,0x0C,0xCC,0x33,0x30, 0xAA,0xBB,0xCC,0xDD,0xAA,0xBB,0xCC,0xDD, 0x10,0x63,0xC6,0x08,0x10,0x30,0x0C,0x08, 0xAA,0xBB,0xCC,0xDD,0xAA,0xBB,0xCC,0xDD };
	glPolygonStipple(texture);
	glBegin(GL_TRIANGLES);

	glColor3f(1.0, 0.0, 0.0);

	glVertex2i(50, 50);
	glVertex2i(150, 150);
	glVertex2i(300, 80);
	glEnd();
	glDisable(GL_POLYGON_STIPPLE);


	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glBegin(GL_POLYGON);

	glColor3f(1.0, 0.0, 0.0);

	glVertex2i(470, 30);
	glVertex2i(360, 50);
	glVertex2i(435, 40);
	glVertex2i(320, 70);
	glVertex2i(280, 120);


	glEnd();




	
	

	
	glFlush();
}