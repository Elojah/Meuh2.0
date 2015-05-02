#include "arkanoid.h"

static void		refresh_buffers(t_window *w)
{
	glBufferData(GL_ARRAY_BUFFER, sizeof(w->map), w->map, GL_STATIC_DRAW);
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
		render(w);
		glfwSwapBuffers(w->window);
        glfwPollEvents();
		refresh_buffers(w);
	}
}
