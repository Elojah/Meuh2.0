#ifndef M_LOG_HPP
# define M_LOG_HPP

# include "AWindow.hpp"
# include "IModule.hpp"

class MLog : public AWindow, public IModule
{
public:
	explicit MLog(const std::string &s);
	virtual ~MLog(void);
	virtual bool	initMod(void);
	virtual bool	update(void);
protected:
private:
	std::string		_logFile;
};

#endif
