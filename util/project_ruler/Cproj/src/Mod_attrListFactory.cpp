#include "Mod_attrListFactory.h"
#include "Mod_attrList.h"

Mod_attrListFactory::Mod_attrListFactory(void)
{
	;
}

Mod_attrListFactory::~Mod_attrListFactory(void)
{
	;
}


Mod_attrList	*Mod_attrListFactory::create(void)
{
	return (new Mod_attrList());
}

Mod_attrList	*Mod_attrListFactory::create(int h, int w, int y, int x)
{
	return (new Mod_attrList(h, w, y, x));
}
