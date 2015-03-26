#ifndef I_OBJECT_H
# define I_OBJECT_H

# include <GL/gl.h>
# include <glm/glm.hpp>

class IObject
{
public:
	virtual ~IObject(void) {}
	virtual void	draw(void) const {
		glBindVertexArray(_vertexArrayID);
		glDrawArrays(GL_TRIANGLES, 0, 3);
		glBindVertexArray(0);
	}
	glm::mat4		mvp;
protected:
	GLuint			_vertexBuffer;
	GLuint			_colorBuffer;
	GLuint			_vertexArrayID;
	GLuint			_progID;
	GLuint			_matrixID;
private:
};

#endif
