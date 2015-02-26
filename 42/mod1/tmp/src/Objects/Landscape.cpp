#include "Landscape.hpp"
#include <GL/gl.h>

Landscape::Landscape(void) {
}

Landscape::~Landscape(void) {
}

void	Landscape::draw(void) {
	glColor3f(  1.0, 0.0, 0.0);
	glVertex3f(-0.5, 0.0, 0.0);

	glColor3f(  0.0, 0.0, 1.0);
	glVertex3f( 0.0, 0.5, 0.0);

	glColor3f(  0.0, 1.0, 0.0);
	glVertex3f( 0.5, 0.0, 0.0);
}
