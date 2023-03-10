#include <GL/glut.h>
#include <stdio.h>

float x1, x2, x3, x4, y1, y2, y3, y4;

void initGL() {
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(-10.0, 10.0, -10.0, 10.0);
}

void original() {
  glBegin(GL_LINE_LOOP);
  glColor3f(0.0f, 0.0f, 1.0f);
  glVertex2f(0.0, 3.0);
  glVertex2f(3.0, 3.0);
  glVertex2f(3.0, 0.0);
  glVertex2f(0.0, 0.0);
  glEnd();
}

void translate() {
  glTranslatef(1.0f, 5.0f, 0.0f);
  glBegin(GL_LINE_LOOP);
  glColor3f(1.0f, 0.0f, 0.0f);
  glVertex2f(0.0, 3.0);
  glVertex2f(3.0, 3.0);
  glVertex2f(3.0, 0.0);
  glVertex2f(0.0, 0.0);
  glEnd();
}

void scale() {
  glScalef(2.0f, 3.0f, 0.0f);
  glBegin(GL_LINE_LOOP);
  glColor3f(1.0f, 0.0f, 0.0f);
  glVertex2f(0.0, 3.0);
  glVertex2f(3.0, 3.0);
  glVertex2f(3.0, 0.0);
  glVertex2f(0.0, 0.0);
  glEnd();
}

void reflection() {
  GLfloat m[16] = {1.0f, 0.0f, 0.0f, 0.0f, 0.0f, -1.0f, 0.0f, 0.0f,
                   0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f,  0.0f, 1.0f};
  glMultMatrixf(m);
  glBegin(GL_LINE_LOOP);
  glColor3f(1.0f, 0.0f, 0.0f);
  glVertex2f(0.0, 3.0);
  glVertex2f(3.0, 3.0);
  glVertex2f(3.0, 0.0);
  glVertex2f(0.0, 0.0);
  glEnd();
}

void rotate() {
  glRotatef(-90, 0.0f, 0.0f, 1.0f);
  glBegin(GL_LINE_LOOP);
  glColor3f(1.0f, 0.0f, 0.0f);
  glVertex2f(0.0, 3.0);
  glVertex2f(3.0, 3.0);
  glVertex2f(3.0, 0.0);
  glVertex2f(0.0, 0.0);
  glEnd();
}

void display1() {
  glClear(GL_COLOR_BUFFER_BIT);
  glBegin(GL_LINE_LOOP);
  glColor3f(0.0f, 1.0f, 0.0f);
  glVertex2f(0.0, 10.0);
  glVertex2f(0.0, -10.0);
  glEnd();
  glBegin(GL_LINE_LOOP);
  glColor3f(0.0f, 1.0f, 0.0f);
  glVertex2f(10.0, 0.0);
  glVertex2f(-10.0, 0.0);
  glEnd();
  original();
  translate();
  glFlush();
}

void display2() {
  glClear(GL_COLOR_BUFFER_BIT);
  glBegin(GL_LINE_LOOP);
  glColor3f(0.0f, 1.0f, 0.0f);
  glVertex2f(0.0, 10.0);
  glVertex2f(0.0, -10.0);
  glEnd();
  glBegin(GL_LINE_LOOP);
  glColor3f(0.0f, 1.0f, 0.0f);
  glVertex2f(10.0, 0.0);
  glVertex2f(-10.0, 0.0);
  glEnd();
  original();
  scale();
  glFlush();
}

void display3() {
  glClear(GL_COLOR_BUFFER_BIT);
  glBegin(GL_LINE_LOOP);
  glColor3f(0.0f, 1.0f, 0.0f);
  glVertex2f(0.0, 10.0);
  glVertex2f(0.0, -10.0);
  glEnd();
  glBegin(GL_LINE_LOOP);
  glColor3f(0.0f, 1.0f, 0.0f);
  glVertex2f(10.0, 0.0);
  glVertex2f(-10.0, 0.0);
  glEnd();
  original();
  reflection();
  glFlush();
}

void display4() {
  glClear(GL_COLOR_BUFFER_BIT);
  glBegin(GL_LINE_LOOP);
  glColor3f(0.0f, 1.0f, 0.0f);
  glVertex2f(0.0, 10.0);
  glVertex2f(0.0, -10.0);
  glEnd();
  glBegin(GL_LINE_LOOP);
  glColor3f(0.0f, 1.0f, 0.0f);
  glVertex2f(10.0, 0.0);
  glVertex2f(-10.0, 0.0);
  glEnd();
  original();
  rotate();
  glFlush();
}

int main(int argc, char **argv) {
  int choice;
  printf("What kind of transformation operation you want to perform?\n");
  printf("1. Translation\n");
  printf("2. Scaling\n");
  printf("3. Reflection\n");
  printf("4. Rotation\n");
  scanf("%d", &choice);

  glutInit(&argc, argv);
  glutCreateWindow("Triangle Transformation Program");
  glutInitWindowSize(1600, 900);
  glutInitWindowPosition(0, 0);
  if (choice == 1) {
    glutDisplayFunc(display1);
  } else if (choice == 2) {
    glutDisplayFunc(display2);
  } else if (choice == 3) {
    glutDisplayFunc(display3);
  } else if (choice == 4) {
    glutDisplayFunc(display4);
  } else {
    printf("Invalid Input");
    return 0;
  }
  initGL();
  glutMainLoop();
  return 0;
}
