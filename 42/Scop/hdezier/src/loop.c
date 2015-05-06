#include "scop.h"

void		loop(t_window *w)
{
	double	t;
	double	prev_t;

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	glDepthFunc(GL_LESS);
	while (!glfwWindowShouldClose(w->window))
	{
		if ((t = glfwGetTime()) < prev_t + REFRESH_TIME) {
			continue ;
		}
		prev_t = t;
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		// refresh_buffers(w);
		render(w);
		glfwSwapBuffers(w->window);
		glfwPollEvents();
	}
}
