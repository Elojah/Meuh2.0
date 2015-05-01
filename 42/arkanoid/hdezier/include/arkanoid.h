#ifndef ARKANOID_H
# define ARKANOID_H

# define GL_GLEXT_PROTOTYPES
# include <OpenGL/gl3.h>
# define __gl_h_
# include <GLFW/glfw3.h>
# define GLFW_INCLUDE_GLCOREARB
# define HEIGHT 50
# define WIDTH 50
# define SIZE_CASE 10

enum				e_unit
{
	EMPTY = 0,
	PLAYER,
	ONE_PIECE,
	THREE_PIECE,
	NONE_PIECE
};

typedef struct		s_point
{
	float			x;
	float			y;
	float			z;
}					t_point;

typedef struct		s_window
{
	GLFWwindow		*window;
	int				map[HEIGHT * WIDTH + 1];
	float			player_x;
	t_point			buffer[HEIGHT * WIDTH * 3 + 1];
	unsigned int	current_level;
}					t_window;

/*
**Loop
*/
void				loop(t_window *w);

/*
**Key callback
*/
void				key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);

/*
**Error Handling
*/
void				ft_exit(int condition, char *message);

#endif
