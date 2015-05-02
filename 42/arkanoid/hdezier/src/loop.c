#include "arkanoid.h"

static void		refresh_buffers(t_window *w)
{
	(void)w;
}

void		loop(t_window *w)
{
	double	t;
	double	prev_t;

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);
	while (!glfwWindowShouldClose(w->window))
	{
		if ((t = glfwGetTime()) < prev_t + REFRESH_TIME) {
			continue ;
		}
		prev_t = t;
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		refresh_buffers(w);
		render(w);
		glfwSwapBuffers(w->window);
        glfwPollEvents();
	}
}
