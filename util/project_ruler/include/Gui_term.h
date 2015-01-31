#ifndef GUI_TERM_H
# define GUI_TERM_H

# include "Igui.h"
# include <string>
class	WinCurse_menu;
class	WinCurse_proj;

class Gui_term : public Igui
{
public:
	Gui_term(void);
	~Gui_term(void);
	void	init(void);
	void	start(void);
protected:
private:
	WinCurse_menu	*_startMenu;
	WinCurse_proj		*_cProj;

	void	_createNewProject(std::string s);
};

#endif

