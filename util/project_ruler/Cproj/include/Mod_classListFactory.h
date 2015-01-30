#ifndef MOD_CLASS_LIST_FACTORY_H
# define MOD_CLASS_LIST_FACTORY_H

# include "IFactoryMod.h"
# include "Mod_classList.h"

class Mod_classListFactory : public IFactoryMod
{
public:
	Mod_classListFactory(void);
	~Mod_classListFactory(void);
	Mod_classList	*create();
	Mod_classList	*create(int, int, int, int);
protected:
private:
};

#endif

