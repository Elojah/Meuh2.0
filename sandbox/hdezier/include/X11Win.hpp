#ifndef X11_WIN_H
# define X11_WIN_H

# include <cstddef>
# include <X11/Xlib.h>
# include <X11/Xutil.h>
# include <GL/gl.h>
# include <GL/glx.h>

class X11Win
{
public:
						X11Win(std::size_t, std::size_t);
						~X11Win(void);
	void				init(void);
	void				loop(void);
protected:
private:
	typedef GLXContext(*glXCreateContextAttribsARBProc)(Display*, GLXFBConfig, GLXContext, Bool, const int*);
						X11Win(void);
	void				assignBestFBC(void);
/*
**X11
*/
	Display				*_d;
	Window			_w;
	Colormap			_cmap;
	int					_screen;
	std::size_t			_width;
	std::size_t			_height;
/*
**Event
*/
	XEvent				_e;
/*
**GL
*/
	GLXFBConfig		_fbc;
	GLXContext			_ctx;
};

#endif
