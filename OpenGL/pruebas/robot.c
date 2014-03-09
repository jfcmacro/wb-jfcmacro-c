#include <GL/gl.h>
#include <GL/glu.h>
#include "aux.h"

static int shoulder = 0, elbow = 0;

void elbowAdd(void)
{
  elbow = (elbow + 5) % 360;
}

void elbowSubtract(void)
{
  elbow = (elbow - 5) % 360;
}

void shoulderAdd(void)
{
  shoulder = (shoulder + 5) % 360;
}

void shoulderSubtract(void)
{
  shoulder = (shoulder - 5) % 360;
}

void display(void)
{
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f(1.0, 1.0, 1.0);

  glPushMatrix();
  glTranslatef(-1.0, 0.0, 0.0);
  glRotatef((GLfloat) shoulder, 0.0, 0.0, 1.0);
  glTranslatef(1.0, 0.0, 0.0);
  auxWireBox(2.0, 0.4, 1.0);

  glTranslate(1.0, 0.0, 0.0);
  glRotatef((GLfloat) elbow, 0.0, 0.0, 1.0);
  glTranslatef(1.0, 0.0, 0.0);
  auxWireBox(2.0, 0.4, 1.0);
  
  glPopMatrix();
  glFlush();
}

void myinit(void)
{
  glShadeModle(GL_FLAT);
}

void myReshape(GLsizei w, GLsizei h)
{
  glvViewport(0, 0, w, h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(65.0, (GLfloat) w/ (GLfloat) h, 1.0, 20.0);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentify();
  glTranslatef(0.0, 0.0, -5.0);
}

int
main(int argc, char **argv)
{
  auxInitDisplayMode(AUX_SINGLE | AUX_RGBA);
  auxInitPosition(0, 0, 400, 400);
  auxInitWindow(argv[0]);
  myinit();
  auxKeyFunc(AUX_LEFT, shoulderSubtract);
  auxKeyFunc(AUX_RIGHT, shoulderAdd);
  auxKeyFunc(AUX_UP, elbowAdd);
  auxKeyFunc(AUX_DOWN, elbowSubtract);
  auxReshapeFunc(myReshape);
  auxMainLoop(display);
}
