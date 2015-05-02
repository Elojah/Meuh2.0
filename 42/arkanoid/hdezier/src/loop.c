#include "arkanoid.h"
#include <math.h>

static void		bound_ball(t_window *w, int i)
{
	(void)i;
	w->ball.direction += M_PI;
	if (w->ball.direction > M_PI * 2)
		w->ball.direction -= M_PI * 2;
}

static void		forward_ball(t_window *w)
{
	int			i;
	float		x;
	float		y;
	int			n;

	i = -1;
	x = cosf(w->ball.direction);
	y = sinf(w->ball.direction);
	while (++i < BALL_PRECISION + 2)
	{
		w->ball.vertex_buffer_data[i].x += x / SPEED;
		w->ball.vertex_buffer_data[i].y += y / SPEED;
		if (w->ball.vertex_buffer_data[i].x < 0)
			continue ;
		n = (floor(w->ball.vertex_buffer_data[i].y * WIDTH_MAP) * WIDTH_MAP
			+ floor(w->ball.vertex_buffer_data[i].x * WIDTH_MAP)) * 6;
		if (w->map[n] != EMPTY)
			bound_ball(w, i);
		if (w->map[n] == PLAYER)
			continue ;
		add_unit(w, floor(w->ball.vertex_buffer_data[i].x * WIDTH_MAP)
			, floor(w->ball.vertex_buffer_data[i].y * WIDTH_MAP)
			, EMPTY);
	}
}

static void		refresh_buffers(t_window *w)
{
	forward_ball(w);
	glBindBuffer(GL_ARRAY_BUFFER, w->map_ID);
	glBufferData(GL_ARRAY_BUFFER, sizeof(w->map), w->map, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, w->ball.vertex_buffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(w->ball.vertex_buffer_data)
		, w->ball.vertex_buffer_data, GL_STATIC_DRAW);
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
