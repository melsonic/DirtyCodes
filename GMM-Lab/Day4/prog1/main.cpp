#include <GL/glut.h>
#include <bits/stdc++.h>
#include <math.h>
#include <stdio.h>

void display();
using namespace std;
float xmin = -30;
float ymin = 10;
float xmax = 20;
float ymax = 60;
float xd1, yd1, xd2, yd2;
float xdd1, ydd1, xdd2, ydd2;

vector<int> ptx = {-40, -10, -10, 30, -20, 10, 10, 30, -40, -20};
vector<int> pty = {20, 70, 50, 80, 30, 20, -20, 30, 70, 100};

map<string, const int> umap = {{"A", 0}, {"B", 1}, {"C", 2}, {"D", 3},
                                      {"E", 4}, {"F", 5}, {"G", 6}, {"H", 7},
                                      {"I", 8}, {"J", 9}};

vector<string> regions = {"1001", "1000", "1010", "0001", "0000",
                          "0010", "0101", "0100", "0110"};
vector<float> xr = {-60, 0, 60, -60, 0, 60, -60, 0, 60};
vector<float> yr = {80, 80, 80, 40, 40, 40, -30, -30, -30};

void init(void) {

  glClearColor(0.0, 0, 0, 0);
  glMatrixMode(GL_PROJECTION);
  gluOrtho2D(-100, 100, -100, 100);
  glColor3f(0.0, 0.0, 1.0);
  glBegin(GL_LINE_LOOP);
  glVertex2f(xd1, yd1);
  glVertex2f(xd2, yd2);
  glEnd();
}

int code(float x, float y) {
  int c = 0;
  if (y > ymax)
    c = 8;
  if (y < ymin)
    c = 4;
  if (x > xmax)
    c = c | 2;
  if (x < xmin)
    c = c | 1;
  return c;
}

void cohen_Line(float x1, float y1, float x2, float y2) {
  int c1 = code(x1, y1);
  int c2 = code(x2, y2);
  float m = (y2 - y1) / (x2 - x1);
  while ((c1 | c2) > 0) {
    if ((c1 & c2) > 0) {
      exit(0);
    }

    float xi = x1;
    float yi = y1;
    int c = c1;
    if (c == 0) {
      c = c2;
      xi = x2;
      yi = y2;
    }
    float x, y;
    if ((c & 8) > 0) {
      y = ymax;
      x = xi + 1.0 / m * (ymax - yi);
    } else if ((c & 4) > 0) {
      y = ymin;
      x = xi + 1.0 / m * (ymin - yi);
    } else if ((c & 2) > 0) {
      x = xmax;
      y = yi + m * (xmax - xi);
    } else if ((c & 1) > 0) {
      x = xmin;
      y = yi + m * (xmin - xi);
    }

    if (c == c1) {
      xd1 = x;
      yd1 = y;
      c1 = code(xd1, yd1);
    }

    if (c == c2) {
      xd2 = x;
      yd2 = y;
      c2 = code(xd2, yd2);
    }
  }

  //  display();
}

void mykey(unsigned char key, int x, int y) {
  if (key == 'c') {
    cout << "Hello";
    cohen_Line(xd1, yd1, xd2, yd2);
    glFlush();
  }
}
void display() {

  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f(0.0, 1.0, 0.0);

  glBegin(GL_POINT);
  glVertex2i(0, 0);
  glEnd();

  // draw the regions
  glBegin(GL_LINE_LOOP);
  glVertex2i(-400.0, ymax);
  glVertex2i(400.0, ymax);
  glEnd();
  glBegin(GL_LINE_LOOP);
  glVertex2i(-400.0, ymin);
  glVertex2i(400.0, ymin);
  glEnd();

  glBegin(GL_LINE_LOOP);
  glVertex2i(xmin, -400.0);
  glVertex2i(xmin, 400.0);
  glEnd();
  glBegin(GL_LINE_LOOP);
  glVertex2i(xmax, -400.0);
  glVertex2i(xmax, 400.0);
  glEnd();

  // draw region codes
  for (int i = 0; i < 9; i++) {
    string st = regions[i];
    glRasterPos2f(xr[i], yr[i]);
    for (int j = 0; j < 4; j++) {
      glutBitmapCharacter(GLUT_BITMAP_8_BY_13, st[j]);
    }
  }

  glColor3f(1.0, 0.0, 0.0);
  glBegin(GL_LINES);
  glVertex2i(xdd1, ydd1);
  glVertex2i(xdd2, ydd2);
  glEnd();

  glColor3f(0.0, 0.0, 1.0);
  glPointSize(5.0);
  cout << xd1 << " " << yd1 << " " << xd2 << " " << yd2 << endl;
  glBegin(GL_POINTS);
  glVertex2i(xd1, yd1);
  glVertex2i(xd2, yd2);
  glEnd();

  glFlush();
}

int main(int argc, char **argv) {
  printf("Enter line :");
  string inp = "AB";
	const int ia = umap[inp[0]];
	const int ib = umap[inp[1]];
  xd1 = ptx[ia];
  yd1 = pty[ia];
  xd2 = ptx[ib];
  yd2 = pty[ib];
  xdd1 = xd1, ydd1 = yd1, xdd2 = xd2, ydd2 = yd2;
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowPosition(0, 0);
  glutInitWindowSize(800, 800);
  glutCreateWindow("Clipping");
  cohen_Line(xd1, yd1, xd2, yd2);
  glutDisplayFunc(display);
  glutKeyboardFunc(mykey);
  init();
  glutMainLoop();
  return 0;
}
