#include "arkanoid.h"


#include <stdio.h>
static void		display_map(t_window *w)
{
	return ;
	for (int i = 0; i < WIDTH_MAP; ++i)
	{
		for (int j = 0; j < HEIGHT_MAP; ++j)
		{
			printf("\t%d\t"
				, w->map[i * WIDTH_MAP + j]
				);
		}
	}
}

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
	display_map(w);
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
