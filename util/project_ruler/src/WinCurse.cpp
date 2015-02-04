#include "WinCurse.h"
#include <sys/ioctl.h>

WinCurse::WinCurse(void)
{
	_setDefaultSize();
	_win = newwin(_size.h, _size.w, _size.y, _size.x);
	keypad(_win, TRUE);
	wrefresh(_win);
}

WinCurse::WinCurse(int h, int w, int y, int x)
{
	_size.h = h;
	_size.w = w;
	_size.y = y;
	_size.x = x;
	_win = newwin(h, w, y, x);
	keypad(_win, TRUE);
	wrefresh(_win);
}

WinCurse::~WinCurse(void)
{
	wborder(_win, ' ', ' ', ' ',' ',' ',' ',' ',' ');
	wrefresh(_win);
	delwin(_win);
}

std::string	WinCurse::readUser(void) const
{

	WinCurse	field(1, _size.w - 2, _size.h - 1, 2);
	char		str[64];

	echo();
	wgetstr(field.getWin(), str);
	noecho();
	return (std::string(str));
}

void	WinCurse::notifyUser(const std::string &str) const
{

	WinCurse	field(1, _size.w - 2, _size.h - 1, 2);

	waddstr(field.getWin(), str.c_str());
	/*Some asynchrnous stuff could be great*/
}

WINDOW	*WinCurse::getWin(void)
{
	return (_win);
}

std::string		WinCurse::_getFileName(std::string const s)
{
	std::string	result;

	result = s.substr(s.find_last_of("/\\") + 1);
	return (result);
}

std::string		WinCurse::_getFilePath(std::string const s)
{
	std::string	result;

	result = s.substr(0, s.find_last_of("/\\"));
	return (result);
}

void	WinCurse::_setDefaultSize(void)
{
	struct winsize			ws;

	if (ioctl(0, TIOCGWINSZ, &ws) == -1)
		return ;
	_size.h = ws.ws_row;
	_size.w = ws.ws_col;
	_size.y = 0;
	_size.x = 0;
}

