#ifndef MOD_ATTR_LIST_FACTORY_H
# define MOD_ATTR_LIST_FACTORY_H

# include "IFactoryMod.h"
# include "Mod_attrList.h"

class Mod_attrListFactory : public IFactoryMod
{
public:
	Mod_attrListFactory(void);
	~Mod_attrListFactory(void);
	Mod_attrList	*create();
	Mod_attrList	*create(int, int, int, int);
protected:
private:
};

#endif

