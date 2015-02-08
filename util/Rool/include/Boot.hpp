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
	static bool	sortFn(const ITEM *, const ITEM *);
	void		sortMenu(size_t length);
	void		createItems(const std::string&);
	void		loop(void);
	void		newProject(ITEM *item);
	void		openProject(ITEM *item);

};

#endif
