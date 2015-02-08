#ifndef I_MODULE_H
# define I_MODULE_H

# include <string>

class IModule
{
public:
	virtual ~IModule(void) {}
	std::string		_path;
	std::string		_name;
	virtual void		init(const std::string &path, const std::string &name) {
		_path = path;
		_name = name;
	}
protected:
private:
};

#endif
