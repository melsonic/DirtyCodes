#include <GL/freeglut.h>
#include <GL/freeglut_ext.h>
#include <GL/glu.h>
#include <iostream>

int W = 800, H = 600;

float px = 50.0, py = 100.0;
float deg = 90.0;

void initGL()
{
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(-200, 200, -200, 200);
  glPointSize(5.0);
  glFlush();
}

void drawPent(void)
{
  glBegin(GL_LINE_LOOP);
  // red
  glColor3f(1.0f, 0.0f, 0.0f);
  glVertex2f(-15.0, 10.0);
  glVertex2f(0.0, 20.0);
  glVertex2f(10.0, 10.0);
  glVertex2f(10.0, -15.0);
  glVertex2f(-15.0, -15.0);
  glEnd();
  glFlush();
}

void translate(float x, float y)
{
  glTranslatef(x, y, 0.0f);
  glBegin(GL_LINE_LOOP);
  // blue
  glColor3f(0.0f, 0.0f, 1.0f);
  glVertex2f(-15.0, 10.0);
  glVertex2f(0.0, 20.0);
  glVertex2f(15.0, 10.0);
  glVertex2f(15.0, -15.0);
  glVertex2f(-15.0, -15.0);
  glEnd();
  glFlush();
}

void translationLast()
{
  glScalef(0.5, 0.5, 0.0);
  glRotatef(-deg, 0.0f, 0.0f, 1.0f);
  glTranslatef(px, py, 0.0f);
  glScalef(2.0, 2.0, 0.0);
  glRotatef(deg, 0.0f, 0.0f, 1.0f);
  glBegin(GL_LINE_LOOP);
  // white
  glColor3f(1.0f, 1.0f, 1.0f);
  glVertex2f(-15.0, 10.0);
  glVertex2f(0.0, 20.0);
  glVertex2f(15.0, 10.0);
  glVertex2f(15.0, -15.0);
  glVertex2f(-15.0, -15.0);
  glEnd();
  glFlush();
}

void rotate()
{
  glRotatef(deg, 0.0f, 0.0f, 1.0f);
  glBegin(GL_LINE_LOOP);
  glColor3f(1.0f, 0.0f, 0.0f);
  glVertex2f(-15.0, 10.0);
  glVertex2f(0.0, 20.0);
  glVertex2f(15.0, 10.0);
  glVertex2f(15.0, -15.0);
  glVertex2f(-15.0, -15.0);
  glEnd();
  glFlush();
}

void scale()
{
  glScalef(2.0, 2.0, 0.0);
  glBegin(GL_LINE_LOOP);
  glColor3f(1.0f, 1.0f, 1.0f);
  glVertex2f(-15.0, 10.0);
  glVertex2f(0.0, 20.0);
  glVertex2f(15.0, 10.0);
  glVertex2f(15.0, -15.0);
  glVertex2f(-15.0, -15.0);
  glEnd();
  glFlush();
}

void display1(void)
{
  glClear(GL_CLEAR_BUFFER);
  glBegin(GL_LINE_LOOP);
  glColor3f(0.0f, 1.0f, 0.0f);
  glVertex2f(0.0, 500.0);
  glVertex2f(0.0, -500.0);
  glEnd();
  glBegin(GL_LINE_LOOP);
  glColor3f(0.0f, 1.0f, 0.0f);
  glVertex2f(500.0, 0.0);
  glVertex2f(-500.0, 0.0);
  glEnd();
  glBegin(GL_POINT);
  glVertex2i(px, py);
  glEnd();
  // drawPent();
  translate(px, py);
  translate(-px, -py);
  rotate();
  scale();
  translationLast();
  glFlush();
}

int main(int argc, char **argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowPosition(0, 0);
  glutInitWindowSize(1920, 1080);
  glutCreateWindow("pentagon");
  glutDisplayFunc(display1);
  initGL();
  glutMainLoop();
  return 0;
}
