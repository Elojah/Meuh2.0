#ifndef COCOA_WIN_H
# define COCOA_WIN_H
# define GL_GLEXT_PROTOTYPES
# define GLFW_INCLUDE_GLU

# include <vector>
# include <string>
# include <OpenGL/gl3.h>
# define __gl_h_
# include <GLFW/glfw3.h>

# include "Camera.hpp"
class Camera;
class IObject;
class Map;

class CocoaWin
{
public:
						CocoaWin(std::size_t, std::size_t);
						~CocoaWin(void);
	void				init(void);
	void				loop(Map const &map, Camera &cam);
protected:
private:
						CocoaWin(void);
/*
**X11
*/
	GLFWwindow			*_window;
	std::size_t			_width;
	std::size_t			_height;
/*
**Event
*/
/*
**GL
*/
};

#endif
