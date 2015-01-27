#ifndef I_GUI_H
# define I_GUI_H

class I_gui
{
public:
	virtual ~I_gui(void) {};
	virtual void	init(void) = 0;
	virtual void	loop(void) = 0;
protected:
private:
};

#endif

