#include "scop.h"

static void	move_point(t_point *p, t_point *dir, float n)
{
	p->x += dir->x * n * MOVE_SPEED;
	p->y += dir->y * n * MOVE_SPEED;
	p->z += dir->z * n * MOVE_SPEED;
}

void		move_camera(t_window *w, t_move t)
{
	if (t == LEFT)
		move_point(&(w->cam.center), &(w->cam.right), -1);
	else if (t == RIGHT)
		move_point(&(w->cam.center), &(w->cam.right), 1);
	else if (t == FORWARD)
		move_point(&(w->cam.eye), &(w->cam.forward), 1);
	else if (t == BACK)
		move_point(&(w->cam.eye), &(w->cam.forward), -1);
	else if (t == UP)
		move_point(&(w->cam.center), &(w->cam.up), 1);
	else if (t == DOWN)
		move_point(&(w->cam.center), &(w->cam.up), -1);
	else
		return ;
	refresh(w);
}
