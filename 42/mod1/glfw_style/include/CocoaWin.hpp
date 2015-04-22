#ifndef COCOA_WIN_H
# define COCOA_WIN_H
# define GL_GLEXT_PROTOTYPES

# include <vector>
# include <string>
# include <OpenGL/gl3.h>
# define __gl_h_
# include <GLFW/glfw3.h>
# define GLFW_INCLUDE_GLCOREARB

# include "Camera.hpp"
class Camera;
class AObject;
class Map;

class CocoaWin
{
public:
						CocoaWin(std::size_t, std::size_t);
						~CocoaWin(void);
	void				init(void);
	void				loop(Map const &map, Camera &cam);
	const Map			*getMap(void) const;
	Camera				*getCam(void) const;

protected:
private:
						CocoaWin(void);
	static void			key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
	static void			cursor_position_callback(GLFWwindow* window, double xpos, double ypos);

/*
**Window
*/
	GLFWwindow			*_window;
	std::size_t			_width;
	std::size_t			_height;
	const Map			*_map;
	Camera				*_cam;
/*
**Event
*/
/*
**GL
*/
};

#endif
