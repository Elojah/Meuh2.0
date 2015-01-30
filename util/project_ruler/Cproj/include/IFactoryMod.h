#ifndef I_FACTORY_MOD_H
# define I_FACTORY_MOD_H

class IWinCurse_mod;

class IFactoryMod
{
public:
	virtual ~IFactoryMod(void) {};
	virtual IWinCurse_mod	*create() = 0;
	virtual IWinCurse_mod	*create(int, int, int, int) = 0;
protected:
private:
};

#endif
