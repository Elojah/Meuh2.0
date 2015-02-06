#ifndef BOOT_H
# define BOOT_H

# include "Menu.hpp"
# include <string>

class Boot : public Menu
{
public:
	Boot(const std::string&);
	~Boot(void);
protected:
private:
	Boot(void);
};

#endif
