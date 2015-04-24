#define GLM_FORCE_RADIANS
#include "Camera.hpp"
#include <glm/gtc/matrix_transform.hpp>
#include "glm/gtx/string_cast.hpp"
#include <iostream>

Camera::Camera(void) {
	_projection = glm::perspective(FOV, RATIO, ZNEAR, ZFAR);
	_view = glm::lookAt(
		glm::vec3(70.0f, 70.0f, 50.0f),
		glm::vec3(25.0f, 25.0f, 0.0f),
		glm::vec3(0.0f, 0.0f, 1.0f)
	);
	_vp = _projection * _view;
}

Camera::~Camera(void) {
}

const glm::mat4	Camera::getViewProj(void) const {
	return (_vp);
}

void				Camera::moveEye(const int &xpos, const int &ypos) {
	static int horizontalAngle = 0;
	static int verticalAngle = 0;

	horizontalAngle += M_SPEED * DTIME * float(_width / 2 - xpos);
	verticalAngle += M_SPEED * DTIME * float(_height / 2 - ypos);
	_direction = glm::vec3(
	    cos(verticalAngle) * sin(horizontalAngle),
	    sin(verticalAngle),
	    cos(verticalAngle) * cos(horizontalAngle)
	);
	_right = glm::vec3(
    	sin(horizontalAngle - 3.14f / 2.0f),
		0,
    	cos(horizontalAngle - 3.14f / 2.0f)
	);
	_up = glm::cross(_right, _direction);
	calculus();
}

void				Camera::setSize(const size_t &width, const size_t &height) {
	_width = width;
	_height = height;
}

void				Camera::moveForward(void) {
	_position += _direction * DTIME * SPEED;
	calculus();
}
void				Camera::moveBackward(void) {
	_position -= _direction * DTIME * SPEED;
	calculus();
}
void				Camera::strafeRight(void) {
	_position += _right * DTIME * SPEED;
	calculus();
}
void				Camera::strafeLeft(void) {
	_position -= _right * DTIME * SPEED;
	calculus();
}

void			Camera::calculus(void) {
	_view = glm::lookAt(
		_position,
		_position + _direction,
		_up
	);
	_vp = _projection * _view;
}
