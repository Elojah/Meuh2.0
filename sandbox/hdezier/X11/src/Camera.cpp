#include "Camera.hpp"
#include "LoadShaders.h"
#include "glm/gtc/matrix_projection.hpp"

Camera::Camera(void) {
	_progID = LoadShaders("./src/shaders/CameraVert.glsl", "");
}

Camera::~Camera(void) {
}

void		Camera::setView(float scale) {
	GLuint		matrixID;
	glm::mat4		mvp;

	_projection = glm::perspective(45.0f, 4.0f / 3.0f, 0.1f, 100.0f);
	_view = glm::lookAt(
		glm::vec3(4,3,3),
		glm::vec3(0,0,0),
		glm::vec3(0,1,0)
	);
	_model = glm::mat4(scale); // Changez pour chaque modèle !
	mvp = _projection * _view * _model; // Souvenez-vous, la multiplication de matrice fonctionne dans l'autre sens

	matrixID = glGetUniformLocation(_progID, "mvp");
	glUniformMatrix4fv(matrixID, 1, GL_FALSE, &mvp[0][0]);
}
