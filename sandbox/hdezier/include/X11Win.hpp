#ifndef X11_WIN_H
# define X11_WIN_H

# include <X11/Xlib.h>

class X11Win
{
public:
	X11Win(void);
	~X11Win(void);
	void	init(void);
protected:
private:
	Display		*_d;
	Window		*_root;
};

#endif
