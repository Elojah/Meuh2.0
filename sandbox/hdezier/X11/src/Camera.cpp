#define GLM_FORCE_RADIANS
#include "Camera.hpp"
#include <glm/gtc/matrix_transform.hpp>

Camera::Camera(void) {
	_projection = glm::perspective(45.0f, 4.0f / 3.0f, 0.1f, 100.0f);
	_view = glm::lookAt(
		glm::vec3(4, 3, 3),
		glm::vec3(0, 0, 0),
		glm::vec3(0, 1, 0)
	);
	_vp = _projection * _view;
}

Camera::~Camera(void) {
}

const glm::mat4	Camera::getViewProj(void) const {
	return (_vp);
}
