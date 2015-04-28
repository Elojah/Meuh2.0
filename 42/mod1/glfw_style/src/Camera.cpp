#define GLM_FORCE_RADIANS
#include "Camera.hpp"
#include <glm/gtc/matrix_transform.hpp>
#include "glm/gtx/string_cast.hpp"
#include <iostream>

Camera::Camera(void) {
	_position = glm::vec3(0.0f, 30.0f, 0.0f);
	_direction = glm::vec3(0.0f, 0.0f, 1.0f);
	_up = glm::vec3(0.0f, 1.0f, 0.0f);

	_projection = glm::perspective(FOV, RATIO, ZNEAR, ZFAR);
	_view = glm::lookAt(
		_position,
		_position + _direction,
		_up
	);
	_vp = _projection * _view;
}

Camera::~Camera(void) {
}

const glm::mat4	&Camera::getViewProj(void) const {
	return (_vp);
}

void				Camera::moveEye(const int &xpos, const int &ypos) {
	static float		horizontalAngle = 3.14f;
	static float		verticalAngle = 0;
	static int			oldX = xpos;
	static int			oldY = ypos;
	static glm::vec3	right = glm::vec3(0.0f, 1.0f, 0.0f);

	horizontalAngle += M_SPEED * float(oldX - xpos);
	verticalAngle += M_SPEED * float(oldY - ypos);
	oldX = xpos;
	oldY = ypos;
	_direction = glm::vec3(
	    cos(verticalAngle) * sin(horizontalAngle),
	    sin(verticalAngle),
	    cos(verticalAngle) * cos(horizontalAngle)
	);
	right = glm::vec3(
		sin(horizontalAngle - M_PI / 2.0f),
		0,
		cos(horizontalAngle - M_PI / 2.0f)
	);
	_up = glm::cross(right, _direction);
	calculus();
}

void				Camera::setSize(const size_t &width, const size_t &height) {
	_width = width;
	_height = height;
}

void				Camera::moveForward(void) {
	_position += _direction * SPEED;
	calculus();
}
void				Camera::moveBackward(void) {
	_position -= _direction * SPEED;
	calculus();
}
void				Camera::moveUp(void) {
	_position += _up * SPEED;
	calculus();
}
void				Camera::moveDown(void) {
	_position -= _up * SPEED;
	calculus();
}

void				Camera::strafeRight(void) {
	_position += glm::normalize(glm::cross(_direction, _up)) * SPEED;
	calculus();
}
void				Camera::strafeLeft(void) {
	_position -= glm::normalize(glm::cross(_direction, _up)) * SPEED;
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
