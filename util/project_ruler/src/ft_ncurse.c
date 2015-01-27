#include "project_ruler.h"

WINDOW	*create_win(int h, int w, int oy, int ox)
{
	WINDOW	*local_win;

	local_win = newwin(h, w, oy, ox);
	box(local_win, 0 , 0);
	wrefresh(local_win);
	return (local_win);
}

void destroy_win(WINDOW *local_win)
{
	wborder(local_win, ' ', ' ', ' ',' ',' ',' ',' ',' ');
	wrefresh(local_win);
	delwin(local_win);
}
