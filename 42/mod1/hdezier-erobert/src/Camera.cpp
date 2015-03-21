#include "Camera.hpp"
#include <math.h>
// #include <GL/glu.h>

Camera::Camera(void) {
	_position.x = 800.;
	_position.y = 700.;
	_position.z = 600.;
	_viewAt.x = 250.;
	_viewAt.y = 250.;
	_viewAt.z = 0.;
}

Camera::~Camera(void) {
}

void	Camera::setView(void) const {
	// glMatrixMode(GL_PROJECTION);
	// glLoadIdentity();
	// gluPerspective(60.0, 1.0, 0.1, 10000.0);
	// glMatrixMode(GL_MODELVIEW);
	// glLoadIdentity();
	// gluLookAt(_position.x, _position.y, _position.z,
	// 			_viewAt.x, _viewAt.y, _viewAt.z,
	// 			0.0, 0.0, 1.0);
}

void	Camera::rotateAround(float const pad) {
	float				tmp[2];

	tmp[0] = _position.x;
	tmp[1] = _position.y;
	_position.x = _viewAt.x + (tmp[0] - _viewAt.x) * cos(pad) - (tmp[1] - _viewAt.y) * sin(pad);
	_position.y = _viewAt.y + (tmp[0] - _viewAt.x) * sin(pad) + (tmp[1] - _viewAt.y) * cos(pad);
}

void	Camera::zoom(float const dist) {
	_position.x += dist * (_position.x - _viewAt.x);
	_position.y += dist * (_position.y - _viewAt.y);
	_position.z += dist * (_position.z - _viewAt.z);
}
