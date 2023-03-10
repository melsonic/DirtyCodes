#include <GL/freeglut.h>
#include <GL/freeglut_std.h>
#include <GL/glu.h>
#include <iostream>
using namespace std;

int W = 500, H = 500;

/* GLfloat V1X = 200.0f, V1Y = 200.0f, V1Z = 0.0f;
GLfloat V2X = 300.0f, V2Y = 200.0f, V2Z = 0.0f;
GLfloat V3X = 250.0f, V3Y = 300.0f, V3Z = 0.0f; */

GLfloat V1X = 200.0f, V1Y = 200.0f, V1Z = 0.0f;
GLfloat V2X = 300.0f, V2Y = 200.0f, V2Z = 0.0f;
GLfloat V3X = 250.0f, V3Y = 300.0f, V3Z = 0.0f;

void myInit();

void myDisplay();

void drawTriangle();

void doTranslate(float x, float y, float z);

void doScale(float x, float y, float z);

void doReflect(float x, float y, float z);

void doRotate(float deg, float x, float y, float z);

int main(int argc, char **argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(W, H);
  glutInitWindowPosition(100, 100);
  glutCreateWindow("Triangle Transformations");
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
  drawTriangle();
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
    doReflect(0.0, 1.0, 0.0);
    break;
  case 4:
    doRotate(-45.0, 0.0, 0.0, 1.0);
    break;
  }
}

void drawTriangle()
{
  glBegin(GL_TRIANGLES);
  glVertex3f(V1X, V1Y, V1Z);
  glVertex3f(V2X, V2Y, V2Z);
  glVertex3f(V3X, V3Y, V3Z);
  glEnd();
  glFlush();
}

void doTranslate(float x, float y, float z)
{
  /* translate */
  glColor3f(0.0f, 1.0f, 0.0f);
  glTranslatef(x, y, z);
  cout << "Translated x-dir : " << x << " & y-dir : " << y << endl;
  drawTriangle();
}

void doScale(float x, float y, float z)
{
  glColor3f(1.0f, 0.0f, 0.0f);
  glScalef(x, y, z);
  cout << "Scaling done" << x << " and " << y << endl;
  drawTriangle();
}

void doReflect(float x, float y, float z)
{
  /* reflect */
  glColor3f (0.0f, 0.5f, 0.2f);
	if (x == 1.0) {
		V1Y = -V1Y; V2Y = -V2Y; V3Y = -V3Y;
    cout << "Reflected about x-axis" << endl;
	}
	if (y == 1.0) {
		V1X = -V1X; V2X = -V2X; V3X = -V3X;
    cout << "Reflected about y-axis" << endl;
	}
	drawTriangle ();
}

void doRotate(float deg, float x, float y, float z)
{
  /* rotate */
  glColor3f (0.0f, 0.0f, 1.0f);
	glRotatef (deg, x, y, z);
  cout << "Rotation done" << endl;
	drawTriangle ();
}

