#ifndef COCOA_WIN_H
# define COCOA_WIN_H
// # define GLFW_INCLUDE_GLCOREARB

# include <vector>
# include <string>
# include <OpenGL/gl3.h>

class IObject;

class CocoaWin
{
public:
						CocoaWin(std::size_t, std::size_t);
						~CocoaWin(void);
	void				init(void);
	void				loop(std::vector<IObject *>&);
protected:
private:
						CocoaWin(void);
	void				assignBestFBC(void);
	void				loopObjects(int const, std::vector<IObject *>&);

/*
**X11
*/
	std::size_t			_width;
	std::size_t			_height;
/*
**Event
*/
	size_t				_e;
};

#endif
