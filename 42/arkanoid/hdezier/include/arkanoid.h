#ifndef ARKANOID_H
# define ARKANOID_H

# define GL_GLEXT_PROTOTYPES
# include <OpenGL/gl3.h>
# define __gl_h_
# include <GLFW/glfw3.h>
# define GLFW_INCLUDE_GLCOREARB

# define REFRESH_TIME 0.016
# define HEIGHT_MAP 50
# define WIDTH_MAP 50
# define SIZE_CASE 10
# define BUFFER_OFFSET(i) ((char *)NULL + (i))
# define MAX_LENGTH_SHADERS 1024

typedef enum		e_unit
{
					PLAYER = -1,
					EMPTY = 0,
					ONE_PIECE,
					THREE_PIECE,
					NONE_PIECE
}					t_unit;

typedef struct		s_point
{
	float			x;
	float			y;
}					t_point;

typedef struct		s_gl
{
	GLuint			vertex_array_ID;
	GLuint			prog_ID;
	GLuint			vertex_buffer;
	t_point			vertex_buffer_data[HEIGHT_MAP * WIDTH_MAP + 1];
	GLuint			index_buffer;
	GLuint			index_buffer_data[HEIGHT_MAP * WIDTH_MAP * 6 + 1];
}					t_gl;

typedef struct		s_window
{
	GLFWwindow		*window;
	GLuint			map_ID;
	t_unit			map[HEIGHT_MAP * WIDTH_MAP + 1];
	t_gl			display;
	float			player_x;
	unsigned int	current_level;
}					t_window;

/*
**Loop
*/
void				loop(t_window *w);

/*
**Rendering
*/
void				render(t_window *w);

/*
**Load map
*/
void				load_map(t_window *w, char *filename);


/*
**Key callback
*/
void				key_callback(GLFWwindow* window, int key, int scancode
	, int action, int mods);

/*
**
*/
GLuint				load_shaders(const char *vertex_file_path
	, const char *fragment_file_path);

#endif
