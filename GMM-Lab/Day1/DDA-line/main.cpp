#include<iostream>
#include <GL/gl.h>
#include <GL/glut.h>

float x1, x2, y1, y2;
int W=600, H=600;

void display(void) {
  float dy, dx, step, x, y, k, Xin, Yin;
  dx = x2 - x1;
  dy = y2 - y1;
  if (abs(dx) > abs(dy))
    step = abs(dx);
  else
    step = abs(dy);
  Xin = dx / step;
  Yin = dy / step;
  x = x1 + (W/2), y = y1 + (H/2);
  std::cout << "x : " << x1 << " : y : " << y1 << "\n";
  glBegin(GL_POINTS);
  glVertex2i(x, y);
  glEnd();
  for (k = 1; k <= step; k++) {
    x = x + Xin;
    y = y + Yin;
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
  }
  glFlush();
}

void myInit (void) {
  glClearColor(0.0, 0.0, 0.0, 0.0);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}

int main(int argc, char ** argv) {

  std::cin >> x1 >> y1 >> x2 >> y2;
  

  glutInit( & argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  // glutInitWindowPosition(100, 100);
  glutInitWindowSize(W, H);
  glutCreateWindow("DDA Line Drawing");
  myInit ();
  glutDisplayFunc(display);
  glutMainLoop();
}
