#ifndef SCOP_H
# define SCOP_H

# define GL_GLEXT_PROTOTYPES
# ifdef __APPLE__
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
# define MAX_VERTEX 256
# define MAX_INDEX 1024
# define MAX_NORMAL 1024
# define MAX_TEX 1024

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

typedef struct		s_coord
{
	GLfloat			u;
	GLfloat			v;
}					t_coord;

typedef struct		s_point
{
	GLfloat			x;
	GLfloat			y;
	GLfloat			z;
}					t_point;

typedef struct		s_object
{
	unsigned char	name[64];
	GLuint			vertex_array_id;
	GLuint			prog_id;

	GLuint			ve_index_buffer;
	GLuint			ve_index_buffer_data[(MAX_INDEX + 1) * 3];
	GLuint			te_index_buffer;
	GLuint			te_index_buffer_data[(MAX_INDEX + 1) * 3];
	GLuint			no_index_buffer;
	GLuint			no_index_buffer_data[(MAX_INDEX + 1) * 3];
	unsigned int	index_buffer_size;

	GLuint			vertex_buffer;
	t_point			vertex_buffer_data[MAX_VERTEX + 1];
	unsigned int	vertex_buffer_size;

	GLuint			normal_buffer;
	t_point			normal_buffer_data[MAX_NORMAL + 1];
	unsigned int	normal_buffer_size;

	GLuint			tex_buffer;
	t_coord			tex_buffer_data[MAX_TEX + 1];
	unsigned int	tex_buffer_size;
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
