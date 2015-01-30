#include "project_ruler.h"
#include <signal.h>

void	init_ncurse(void)
{
	initscr();
	display_menu(0);
	signal(SIGWINCH, display_menu);
	getch();
	endwin();
}
