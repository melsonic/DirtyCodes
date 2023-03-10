#include <stdio.h>
#include <GL/glut.h>

GLfloat px = 100, py = 200;
GLfloat X = 150, Y = 250;

GLfloat V1X = 0.0f+px, V1Y = 100.0f+py, V1Z = 0.0f;
GLfloat V2X = 100.0f+px, V2Y = 100.0f+py, V2Z = 0.0f;
GLfloat V3X = 100.0f+px, V3Y = 0.0f+py, V3Z = 0.0f;
GLfloat V4X = 0.0f+px, V4Y = 0.0f+py, V4Z = 0.0f;
GLfloat V5X = 50.0f+px, V5Y = 125.0f+py, V5Z = 0.0f;


void myInit () {
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

void drawPentagon () {
    glBegin (GL_LINE_LOOP);
    	glVertex3f (V1X, V1Y, V1Z);
    	glVertex3f (V5X, V5Y, V5Z);
    	glVertex3f (V2X, V2Y, V2Z);
    	glVertex3f (V3X, V3Y, V3Z);
    	glVertex3f (V4X, V4Y, V4Z);
    glEnd ();
    glFlush ();
}

void drawPivot(){
	glBegin (GL_POINTS);
		glColor3f(0.0f,0.0f,1.0f);
		glVertex2d(X, Y);
	glEnd ();
	glFlush();
}

void translateP (float x, float y, float z) {
	glColor3f (0.0f, 1.0f, 0.0f);
	glTranslatef (x, y, z);
	drawPentagon ();
}

void rotateP (float deg, float x, float y, float z) {
	glColor3f (0.0f, 1.0f, 0.0f);
	glRotatef (deg, x, y, z);
	translateP (100.0, -400.0, 0.0);
	glColor3f (0.0f, 0.0f, 1.0f);
	drawPentagon ();
}

void scaleP (float x, float y, float z) {
	glColor3f (0.0f, 1.0f, 0.0f);
	glScalef (x, y, z);
	translateP (150.0, 250.0, 0.0);
	drawPentagon ();
}

void reflectP (float x, float y, float z) {
	glColor3f (0.0f, 0.5f, 0.2f);
	if (x == 1.0) {
		V1Y = -V1Y; V2Y = -V2Y; V3Y = -V3Y;
	}
	if (y == 1.0) {
		V1X = -V1X; V2X = -V2X; V3X = -V3X;
	}
	drawPentagon ();
} 
void myDisplay () {
	glColor3f (1.0, 1.0, 1.0);
	drawPentagon();
	drawPivot();
    printf ("Final output: \n");
	translateP (-X, -Y, 0.0);
	rotateP (90.0, 0.0, 0.0, 1.0);
	scaleP (0.5, 0.5, 0.0);
	translateP (0.0, 0.0, 0.0);
	translateP (500, -300.0, 0.0);
}
  
int main (int argc, char **argv) {
    glutInit (&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition (0, 0);
    glutInitWindowSize (900, 900);
    glutCreateWindow ("2D TRANSFORMATION OVER THE TRIANGLE");
    glutDisplayFunc (myDisplay);
    myInit ();
    glutMainLoop ();
    return 0;
}
