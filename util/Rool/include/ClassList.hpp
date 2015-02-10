#ifndef CLASS_LIST_H
# define CLASS_LIST_H

# include "IModule.hpp"
# include "Menu.hpp"
# include <string>

class ClassList : public IModule, public Menu
{
public:
	ClassList(int, int, int, int);
	~ClassList(void);
	void		init(const std::string&, const std::string&);
protected:
private:
	ClassList(void);
	void		createItems(void);

	/*
	**Callbacks
	*/
	void		newClass(ITEM *);
	void		listAttributes(ITEM *item);
};

#endif
