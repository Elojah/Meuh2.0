#ifndef I_MODULE_HPP
# define I_MODULE_HPP

# include <string>

class IModule
{
public:
	virtual ~IModule(void) {}
	virtual bool	initMod(void) = 0;
	virtual bool	update(void) = 0;
protected:
private:
};

#endif
