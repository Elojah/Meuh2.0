#ifndef X11_WIN_H
# define X11_WIN_H

# include <cstddef>
# include <X11/Xlib.h>

class X11Win
{
public:
						X11Win(std::size_t, std::size_t);
						~X11Win(void);
	void				init(void);
	void				loop(void);
protected:
private:
						X11Win(void);
	Display				*_d;
	Window			_root;
	Window			_w;
	Visual				*_v;
	int					_screen;
	std::size_t			_width;
	std::size_t			_height;
	XEvent				_e;
};

#endif
