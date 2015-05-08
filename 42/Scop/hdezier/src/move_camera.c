#include "scop.h"

static void	move_point(t_point *p, float n)
{
	p->x += n;
	p->y += n;
	p->z += n;
}

void		move_camera(t_window *w, t_move t)
{
	if (t == LEFT)
		move_point(&(w->cam.center), -0.1);
	else if (t == RIGHT)
		move_point(&(w->cam.center), 0.1);
	else if (t == UP)
		move_point(&(w->cam.eye), 0.1);
	else if (t == DOWN)
		move_point(&(w->cam.eye), -0.1);
	else
		return ;
	refresh(w);
}
