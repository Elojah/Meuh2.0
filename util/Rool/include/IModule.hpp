#ifndef I_MODULE_H
# define I_MODULE_H

# include <string>

class IModule
{
public:
	virtual ~IModule(void) {}
	virtual void		init(const std::string &path, const std::string &name) {
		_path = path;
		_name = name;
	}
protected:
	std::string		_path;
	std::string		_name;
private:
};

#endif
