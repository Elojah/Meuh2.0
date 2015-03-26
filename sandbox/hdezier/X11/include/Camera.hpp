#ifndef CAMERA_H
# define CAMERA_H

# include <GL/gl.h>
# include "glm/glm.hpp"

class Camera
{
public:
	Camera(void);
	~Camera(void);
	void	setView(float scale);
protected:
private:
	GLuint			_progID;
	glm::mat4		_projection;
	glm::mat4		_view;
	glm::mat4		_model;
};

#endif
