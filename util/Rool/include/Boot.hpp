#ifndef BOOT_H
# define BOOT_H

# include "Menu.hpp"
# include <string>

class Boot : public Menu
{
public:
	Boot(void);
	~Boot(void);
protected:
private:
	void		newProject(ITEM *item);
	void		loop(void);
};

#endif
