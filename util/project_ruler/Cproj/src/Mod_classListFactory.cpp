#include "Mod_classListFactory.h"
#include "Mod_classList.h"

Mod_classListFactory::Mod_classListFactory(void)
{
	;
}

Mod_classListFactory::~Mod_classListFactory(void)
{
	;
}

Mod_classList	*Mod_classListFactory::create(void)
{
	return (new Mod_classList());
}

Mod_classList	*Mod_classListFactory::create(int h, int w, int y, int x)
{
	return (new Mod_classList(h, w, y, x));
}
