#include "arkanoid.h"

void		move_player(t_window *w, t_move t)
{
	if ((t == LEFT && w->player_x < 2)
		|| (t == RIGHT && w->player_x == WIDTH_MAP - 3))
		return ;
	add_unit(w, PLAYER_Y, w->player_x - (t * 2), EMPTY);
	add_unit(w, PLAYER_Y, w->player_x + (t * 2), PLAYER);
	w->player_x += t;
}
