#include "arkanoid.h"

void		add_unit(t_window *w, int x, int y, t_unit type)
{
	unsigned int	n;
	GLint			value;

	n = (x * WIDTH_MAP + y) * 6;
	if (n > WIDTH_MAP * HEIGHT_MAP * 6 - 6)
		return ;
	value = type;
	w->map[n] = value;
	w->map[n + 1] = value;
	w->map[n + 2] = value;
	w->map[n + 3] = value;
	w->map[n + 4] = value;
	w->map[n + 5] = value;
}
