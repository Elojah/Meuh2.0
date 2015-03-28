#ifndef I_OBJECT_H
# define I_OBJECT_H

# include <GL/gl.h>
# include <glm/glm.hpp>
# include "Camera.hpp"
class Camera;

class IObject
{
public:
	virtual ~IObject(void) {}
	virtual void	draw(void) const {
		glBindVertexArray(_vertexArrayID);
		glDrawArrays(GL_TRIANGLES, 0, 3);
		glBindVertexArray(0);
	}
	virtual void	refresh(Camera const &cam) {
		mvp = cam.getViewProj() * glm::mat4(1.0f);
		_matrixID = glGetUniformLocation(_progID, "mvp");
	}
protected:
	glm::mat4		mvp;
	GLuint			_vertexBuffer;
	GLuint			_colorBuffer;
	GLuint			_vertexArrayID;
	GLuint			_progID;
	GLuint			_matrixID;
private:
};

#endif
