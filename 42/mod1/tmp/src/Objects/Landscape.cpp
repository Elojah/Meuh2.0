#include "Landscape.hpp"
#include <GL/gl.h>

Landscape::Landscape(void) {
}

Landscape::~Landscape(void) {
}

void	Landscape::draw(void) {
  glColor3f(1.0f, 0.0f, 0.0f); // Red
  glVertex2f(-0.5f, -0.5f);    // x, y
  glVertex2f( 0.5f, -0.5f);
  glVertex2f( 0.5f,  0.5f);
  glVertex2f(-0.5f,  0.5f);
}
