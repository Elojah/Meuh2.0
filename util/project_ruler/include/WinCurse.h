#ifndef WINCURSE_H
# define WINCURSE_H

# include <ncurses.h>
# include <string>

class WinCurse
{
public:
	WinCurse(void);
	WinCurse(int, int, int, int);
	~WinCurse(void);
	WINDOW	*getWin(void);
	std::string		readUser(void) const;
	void	notifyUser(const std::string &str) const;
protected:
	typedef struct	s_winSize
	{
		int			h;
		int			w;
		int			y;
		int			x;
	}				t_winSize;
	WINDOW			*_win;
	t_winSize		_size;
	static std::string		_getFileName(std::string s);
	static std::string		_getFilePath(std::string s);
private:
	void	_setDefaultSize(void);
};

#endif

