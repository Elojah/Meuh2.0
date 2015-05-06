#include "arkanoid.h"

void		loop(t_window *w)
{
	double	t;
	double	prev_t;

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);

	while (!glfwWindowShouldClose(w->window))
	{
		if ((t = glfwGetTime()) < prev_t + 0.016) {
			continue ;
		}
		prev_t = t;
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glfwSwapBuffers(w->window);
        glfwPollEvents();
	}
}
