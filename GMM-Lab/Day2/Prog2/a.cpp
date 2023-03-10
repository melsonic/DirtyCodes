#include <GL/freeglut.h>
#include <GL/freeglut_std.h>
#include <GL/glu.h>
#include <iostream>
using namespace std;

int W = 500, H = 500;

/* GLfloat V1X = 200.0f, V1Y = 200.0f, V1Z = 0.0f;
GLfloat V2X = 300.0f, V2Y = 200.0f, V2Z = 0.0f;
GLfloat V3X = 250.0f, V3Y = 300.0f, V3Z = 0.0f; */

int a = 0, b = 3;

void myInit();

void myDisplay();

void displaySq();

void doTranslate(float x, float y, float z);

void doScale(float x, float y, float z);

void doReflect(float x, float y, float z);

void doRotate(float deg, float x, float y, float z);

void displayLine(int x1, int y1, int x2, int y2);

int main(int argc, char **argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(W, H);
  glutInitWindowPosition(100, 100);
  glutCreateWindow("Square Transformations");
  myInit();
  glutDisplayFunc(myDisplay);
  glutMainLoop();

  return 0;
}

void myInit()
{
  	glClear (GL_COLOR_BUFFER_BIT);
    glClearColor (0.0, 0.0, 0.0, 0.0);
    glColor3f (0.0f, 0.5f, 0.5f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D (-500, 500, -500, 500);
    
    glBegin (GL_LINE_LOOP);
    	glVertex3f (-400.0, 0.0, 0.0);
    	glVertex3f (400.0, 0.0, 0.0);
    glEnd ();
    
    glBegin (GL_LINE_LOOP);
    	glVertex3f (0.0, -400.0, 0.0);
    	glVertex3f (0.0, 400.0, 0.0);
    glEnd ();
    
    glFlush ();
}

void myDisplay()
{
  glColor3f(1.0, 1.0, 1.0);
  displaySq();
  cout << "Select the option : " << endl;
  cout << "1. Translate" << endl;
  cout << "2. Scale" << endl;
  cout << "3. Reflect" << endl;
  cout << "4. Rotate" << endl;

  int option;
  cin >> option;

  switch (option)
  {
  case 1:
    doTranslate(50.0, 50.0, 0.0);
    break;
  case 2:
    doScale(1.5, 1.5, 0.0);
    break;
  case 3:
    // doReflect(0.0, 1.0, 0.0);
    break;
  case 4:
    doRotate(-45.0, 0.0, 0.0, 1.0);
    break;
  }
}

void displayLine(int x1, int y1, int x2, int y2)
{
  x1 *= 50; x2 *= 50;
  y1 *= 100; y2 *= 100;
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

void displaySq(void)
{
  displayLine(a, a, b, a);
  displayLine(b, a, b, b);
  displayLine(b, b, a, b);
  displayLine(a, b, a, a);
}

void doTranslate(float x, float y, float z)
{
  glColor3f(0.0f, 1.0f, 0.0f);
  glTranslatef(x, y, z);
  cout << "Translated x-dir : " << x << " & y-dir : " << y << endl;
  displaySq();
}

void doScale(float x, float y, float z)
{
  glColor3f(1.0f, 0.0f, 0.0f);
  glScalef(x, y, z);
  cout << "Scaling done" << x << " and " << y << endl;
  displaySq();
}

void doReflect(float x, float y, float z)
{
  GLfloat m[16] = {
    1.0f, 0.0f, 0.0f, 0.0f,
    0.0f, -1.0f, 0.0f, 0.0f,
    0.0f, 0.0f, 1.0f, 0.0f,
    0.0f, 0.0f, 0.0f, 1.0f
	};
	glMultMatrixf(m);
	glBegin(GL_LINE_LOOP);
      glColor3f(1.0f, 0.0f, 0.0f);
      glVertex2f(0.0,3.0);
      glVertex2f(3.0,3.0);
      glVertex2f(3.0,0.0);
      glVertex2f(0.0,0.0);
   glEnd();
}

void doRotate(float deg, float x, float y, float z)
{
  glColor3f (0.0f, 0.0f, 1.0f);
	glRotatef (deg, x, y, z);
  cout << "Rotation done" << endl;
	displaySq();
}