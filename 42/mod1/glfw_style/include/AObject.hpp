#ifndef A_OBJECT_H
# define A_OBJECT_H
# define GL_GLEXT_PROTOTYPES
# include <OpenGL/gl3.h>
# define __gl_h_
# include <glm/glm.hpp>
# include "Camera.hpp"
class Camera;

# define MAX_RAIN_PARTICLE 1000
# define BUFFER_OFFSET(i) ((char *)NULL + (i))
# define WIDTH_MAP 100
# define HEIGHT_MAP 100

class AObject
{
public:
	virtual ~AObject(void) {
		glDeleteBuffers(1, &_vertexBuffer);
		glDeleteBuffers(1, &_indexBuffer);
		glDeleteVertexArrays(1, &_vertexArrayID);
		glDeleteProgram(_progID);
	}
	virtual void	init(void) = 0;
	virtual bool	loop(int const) = 0;
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

	struct						sPoint {
		GLfloat					x;
		GLfloat					y;
		GLfloat					z;
	};


	glm::mat4		mvp;
	GLuint			_vertexBuffer;
	GLuint			_indexBuffer;
	GLuint			_vertexArrayID;
	GLuint			_progID;
	GLuint			_matrixID;
private:
};

#endif
