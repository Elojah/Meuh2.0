#ifndef CAMERA_H
# define CAMERA_H
# define GL_GLEXT_PROTOTYPES

# define FOV 45.0f
# define RATIO 4.0f / 3.0f
# define ZNEAR 0.1f
# define ZFAR 500.0f
# define SPEED 3.0f
# define M_SPEED 0.005f

# include <OpenGL/gl3.h>
# include <glm.hpp>

enum eDirection {
	CONSTANT = 0,
	RIGHT = 1,
	LEFT = 2,
	UP = 3,
	DOWN = 4
};

class Camera
{
public:
	Camera(void);
	~Camera(void);
	const glm::mat4	getViewProj(void) const;
	void				moveEye(const int &xpos, const int &ypos, const size_t &width, const size_t &height);
	void				translate(const eDirection &dir);
protected:
private:
	glm::mat4		_view;
	glm::mat4		_projection;
	glm::mat4		_vp;
	glm::vec3		_direction;
	glm::vec3		_right;
	glm::vec3		_up;
};

#endif
