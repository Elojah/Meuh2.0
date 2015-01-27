#ifndef GUI_TERM_H
# define GUI_TERM_H

# include "I_gui.h"
class	I_WinCurse;

class Gui_term : public I_gui
{
public:
	Gui_term(void);
	~Gui_term(void);
	void	init(void);
	void	loop(void);
protected:
private:
	I_WinCurse	*win;
};

#endif

