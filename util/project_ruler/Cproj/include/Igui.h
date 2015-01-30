#ifndef I_GUI_H
# define I_GUI_H

#include <ncurses.h>

class Igui
{
public:
	virtual ~Igui(void) {};
	virtual void	init(void) = 0;
	virtual void	start(void) = 0;
protected:
private:
};

#endif

