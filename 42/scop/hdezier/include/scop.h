#ifndef SCOP_H
# define SCOP_H

# define GL_GLEXT_PROTOTYPES
# ifdef __MAC__
#  include <OpenGL/gl3.h>
# else
#  include <GL/gl.h>
# endif
# define __gl_h_
# include <GLFW/glfw3.h>
# define GLFW_INCLUDE_GLCOREARB
# define REFRESH_TIME 0.016
# define BUFFER_OFFSET(i) ((char *)NULL + (i))
# define MAX_LENGTH_SHADERS 1024

# define W_WIDTH 1200
# define W_HEIGHT 800

# define M_PI 3.14159265359
# define MIN(a, b) (((a) > (b) ? (b) : (a)))
# define ABS(a) (((a) > 0) ? (a) : (-a))
# define SQ(n) ((n) * (n))

typedef enum		e_move
{
	LEFT = -1,
	RIGHT = 1,
}					t_move;

typedef struct		s_point
{
	GLfloat			x;
	GLfloat			y;
	GLfloat			z;
}					t_point;

typedef struct		s_object
{
	GLuint			vertex_array_id;
	GLuint			prog_id;
	GLuint			vertex_buffer;
	t_point			*vertex_buffer_data;
	unsigned int	vertex_buffer_size;
	GLuint			index_buffer;
	GLuint			*index_buffer_data;
	unsigned int	index_buffer_size;
	t_point			*normal_data;
	t_point			*tex_data;
	unsigned char	name[64];
}					t_object;

typedef struct		s_window
{
	GLFWwindow		*window;
	t_object		obj;
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
void				load_obj(t_object *obj, char *filename);

/*
**Key callback
*/
void				key_callback(GLFWwindow *window, int key, int scancode
	, int action, int mods);

/*
**Load shaders
*/
GLuint				load_shaders(const char *vertex_file_path
	, const char *fragment_file_path);

/*
**Move player
*/
void				move_camera(t_window *w, t_move t);

#endif
