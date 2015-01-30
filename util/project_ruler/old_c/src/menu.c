#include "project_ruler.h"
#include <signal.h>
#include <string.h>
#include <unistd.h>
#include <sys/ioctl.h>

void		display_menu(int sig)
{
	static char mes_menu[17] = {"Welcome on PCB"};
	struct winsize			ws;

	clear();
	if (ioctl(0, TIOCGWINSZ, &ws) == -1)
		return ;

	attron(A_BOLD | A_UNDERLINE);
	mvaddstr(1, (ws.ws_col - 17) / 2, mes_menu);
	refresh();
	signal(SIGWINCH, display_menu);
	sig = sig;
}
