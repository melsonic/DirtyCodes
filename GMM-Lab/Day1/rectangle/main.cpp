#include <GL/freeglut.h>
// #include <iostream>

/* void displayRec() {
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f(1.0, 0.0, 0.0);

  glBegin(GL_POINTS);
    glVertex2i(100, 100);
    glVertex2i(400, 400);
    glVertex2i(100, 400);
    glVertex2i(400, 100);
  glEnd();

  glFlush();
} */

int a = 100, b = 400;

void displayLine(int x1, int y1, int x2, int y2)
{
  float dy, dx, step, x, y, k, Xin, Yin;
  dx = x2 - x1;
  dy = y2 - y1;
  if (abs(dx) > abs(dy))
  {
    step = abs(dx);
  }
  else
    step = abs(dy);
  Xin = dx / step;
  Yin = dy / step;
  x = x1;
  y = y1;
  glBegin(GL_POINTS);
  glVertex2i(x, y);
  glEnd();
  for (k = 1; k <= step; k++)
  {
    x = x + Xin;
    y = y + Yin;
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
  }
  glFlush();
}

void displayRec(void)
{
  displayLine(a, a, b, a);
  displayLine(b, a, b, b);
  displayLine(b, b, a, b);
  displayLine(a, b, a, a);
}

void myinit()
{
  glClearColor(1.0, 1.0, 1.0, 1.0);
  glColor3f(1.0, 0.0, 0.0);
  glPointSize(5.0);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0.0, 499.0, 0.0, 499.0);
}

int main(int argc, char **argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

  glutInitWindowPosition(80, 80);
  glutInitWindowSize(800, 600);
  glutCreateWindow("Creating a Rectangle");

  glutDisplayFunc(displayRec);
  myinit();
  glutMainLoop();
}
