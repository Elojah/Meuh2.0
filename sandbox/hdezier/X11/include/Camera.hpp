#ifndef CAMERA_H
# define CAMERA_H
# define GL_GLEXT_PROTOTYPES

# include <GL/gl.h>
# include <glm/glm.hpp>

class Camera
{
public:
	Camera(void);
	~Camera(void);
	const glm::mat4	getViewProj(void) const;
	;
protected:
private:
	glm::mat4		_view;
	glm::mat4		_projection;
	glm::mat4		_vp;
};

#endif
