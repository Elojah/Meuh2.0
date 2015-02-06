#ifndef WINDOW_H
# define WINDOW_H

# include <ncurses.h>
# include <string>

class Window
{
public:
	Window(void);
	Window(int, int, int, int);
	~Window(void);
	WINDOW			*getWin(void) const;
	std::string			readUser(void) const;
	void				notifyUser(const std::string&) const;

protected:
	WINDOW			*win;
	WINDOW			*user;
	int					h;
	int					w;
	int					y;
	int					x;
private:
	void				_setDefaultSize(void);
};

#endif
