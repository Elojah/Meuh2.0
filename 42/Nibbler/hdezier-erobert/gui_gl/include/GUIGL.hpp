#ifndef G_U_I_G_L_H
# define G_U_I_G_L_H
# define GL_GLEXT_PROTOTYPES

# include <vector>
# include <string>
# include <OpenGL/gl3.h>
# define __gl_h_
# include <GLFW/glfw3.h>
# define GLFW_INCLUDE_GLCOREARB

# define BUFFER_OFFSET(i) ((char *)NULL + (i))
# define SIZE_CASE 50

# include "IGUINibbler.hpp"

class GUIGL : public IGUINibbler
{
public:
	GUIGL(void);
	virtual ~GUIGL(void);
	GUIGL(GUIGL const &src);
	GUIGL&	operator=(GUIGL const &rhs);

	virtual void			initMap(std::vector<int> const &map,
									int height, int width);
	virtual void			updateDisplay(tNibbler const &tN, int apple, int score);
	virtual Game::eEvent	getEvent(void);

protected:
private:

	struct sPoint {
		GLfloat x;
		GLfloat y;
	};

	static void				key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
	void					initBuffers(void);

	GLFWwindow				*_window;
	std::size_t				_width;
	std::size_t				_height;
	std::vector<int>		_map;

	/*
	**GL
	*/
	GLuint			_vertexBuffer;
	GLuint			_indexBuffer;
	GLuint			_vertexArrayID;
	GLuint			_progID;

	sPoint			*_vertex_buffer_data;
	GLuint			*_index_buffer_data;

};

extern "C"
{
	GUIGL					*createGUI(void);
	void					deleteGUI(GUIGL *gN);
}

#endif
