#ifndef I_GUI_H
# define I_GUI_H

class IGui
{
public:
	virtual ~IGui(void) {};
	virtual void	init_window(void) = 0;
	virtual void	loop(void) = 0;
protected:
private:
};

#endif

