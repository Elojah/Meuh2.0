#include "Window.hpp"
#include <sys/ioctl.h>

Window::Window(void)
{
	_setDefaultSize();
	win = newwin(h, w, y, x);
	user = newwin(1, w - 2, h - 1, 2);
	keypad(win, TRUE);
	wrefresh(win);
	refresh();
}

Window::Window(int hSet, int wSet, int ySet, int xSet) :
											h(hSet),
											w(wSet),
											y(ySet),
											x(xSet)
{
	win = newwin(h, w, y, x);
	user = newwin(1, w - 2, h - 1, 2);
	keypad(win, TRUE);
	wrefresh(win);
	refresh();
}

Window::~Window(void)
{
	wborder(win, ' ', ' ', ' ',' ',' ',' ',' ',' ');
	wrefresh(win);
	delwin(win);
}

std::string	Window::readUser(void) const
{
	char		str[64];

	echo();
	wgetstr(user, str);
	noecho();
	return (std::string(str));
}

void	Window::notifyUser(const std::string &str) const
{
	waddstr(user, str.c_str());
	/*Some asynchrnous stuff could be great*/
}

void	Window::_setDefaultSize(void)
{
	struct winsize			ws;

	if (ioctl(0, TIOCGWINSZ, &ws) == -1)
		return ;
	h = ws.ws_row;
	w = ws.ws_col;
	y = 0;
	x = 0;
}

