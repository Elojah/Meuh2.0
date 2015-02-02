#ifndef I_WINCURSE_MOD_H
# define I_WINCURSE_MOD_H

# include <string>

class IWinCurse_mod
{
public:
	virtual ~IWinCurse_mod(void) {};
	virtual void	init(std::string) = 0;
protected:
private:
};

#endif

