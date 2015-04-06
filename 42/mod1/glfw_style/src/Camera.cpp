#define GLM_FORCE_RADIANS
#include "Camera.hpp"
#include <gtc/matrix_transform.hpp>
#include "gtx/string_cast.hpp"
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

void				Camera::moveEye(const int &xpos, const int &ypos, const size_t &width, const size_t &height) {
	static int horizontalAngle = 0;
	static int verticalAngle = 0;
	static int deltaTime = 1.0f / 60.0f;

	horizontalAngle += M_SPEED * deltaTime * float(width / 2 - xpos);
	verticalAngle += M_SPEED * deltaTime * float(height / 2 - ypos);
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
	_up = glm::cross(right, direction);
	// Move forward
	if (glfwGetKey( GLFW_KEY_UP ) == GLFW_PRESS){
		position += direction * deltaTime * speed;
	}
	// Move backward
	if (glfwGetKey( GLFW_KEY_DOWN ) == GLFW_PRESS){
		position -= direction * deltaTime * speed;
	}
	// Strafe right
	if (glfwGetKey( GLFW_KEY_RIGHT ) == GLFW_PRESS){
		position += right * deltaTime * speed;
	}
	// Strafe left
	if (glfwGetKey( GLFW_KEY_LEFT ) == GLFW_PRESS){
		position -= right * deltaTime * speed;
	}
	_vp = _projection * _view;
}

void				Camera::translate(const eDirection &dir) {
	std::cout << glm::to_string(_view) << std::endl;
	if (dir == UP) {
		_view = glm::translate(
			_view,
			-1.01f * glm::vec3(_view[2][0], _view[2][1], _view[2][2]));
	} else if (dir == DOWN) {
		_view = glm::translate(
			_view,
			1.01f * glm::vec3(_view[2][0], _view[2][1], _view[2][2]));
	}
	_vp = _projection * _view;
}
