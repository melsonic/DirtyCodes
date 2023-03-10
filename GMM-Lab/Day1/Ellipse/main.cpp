#include <GL/freeglut.h>
#include <bits/stdc++.h>


int cx = 400, cy = 400, r1 = 300, r2 = 200;

void displayRec(void)
{
	glPointSize(2.0);
	for(double i=0.0; i<=45.0; i++){
		float xi = r1*(float)cos(i*(M_PI/180));
		float yi = r2*(float)sin(i*(M_PI/180));
		glBegin(GL_POINTS);
			glVertex2f(cx+xi, cy+yi);
			glVertex2f(cx+yi, cy+xi);
			glVertex2f(cx-xi, cy+yi);
			glVertex2f(cx-yi, cy+xi);
			glVertex2f(cx+xi, cy-yi);
			glVertex2f(cx+yi, cy-xi);
			glVertex2f(cx-xi, cy-yi);
			glVertex2f(cx-yi, cy-xi);
		glEnd();
	}
	glFlush();
}

void myinit()
{
  glClearColor(1.0, 1.0, 1.0, 1.0);
  glColor3f(0.0, 1.0, 0.0);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0, 800, 0, 800);
}

int main(int argc, char **argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

  glutInitWindowPosition(80, 80);
  glutInitWindowSize(800, 800);
  glutCreateWindow("Circle X");

  glutDisplayFunc(displayRec);
  myinit();
  glutMainLoop();
}
