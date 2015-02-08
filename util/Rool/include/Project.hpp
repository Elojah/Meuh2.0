#ifndef PROJECT_H
# define PROJECT_H

# include "Menu.hpp"

class Project : public Menu
{
public:
					Project(const std::string&);
					~Project(void);
protected:
private:
	std::string		_path;
	std::string		_name;

					Project(void);
	void			loop(void);
	void			createItems(void);

};

#endif
