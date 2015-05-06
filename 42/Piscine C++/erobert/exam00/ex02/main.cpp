#include <iostream>

#include "Ressource.class.hpp"

#include "Building.class.hpp"
#include "Barracks.class.hpp"
#include "Bunker.class.hpp"
#include "CommandCenter.class.hpp"
#include "SupplyDepot.class.hpp"

#include "IBuilder.interface.hpp"
#include "Unit.class.hpp"
#include "Marine.class.hpp"
#include "Scv.class.hpp"


int		main( void ) {

	Ressource * r0 =	new Mineral( 10, 10, 15 );
	Ressource * r1 =	new Mineral( 11, 9, 5000 );
	Ressource * r2 =	new Gas( 14, 11, 5000 );

	CommandCenter	cc( 12, 13 );
	Building *		ba =	NULL;
	Building *		sd =	NULL;
	Building *		bu =	NULL;

	Scv *	s0 =	cc.createScv();
	Scv *	s1 =	cc.createScv();
	Scv *	s2 =	cc.createScv();

	Marine *	m0 =	NULL;
	Marine *	m1 =	NULL;

	while( !(r0->isDepleted()) ) {
			s0->gatherRessources( *r0 );
			s1->gatherRessources( *r1 );
			s2->gatherRessources( *r2 );
			s0->returnRessources( cc );
			s1->returnRessources( cc );
			s2->returnRessources( cc );
		}

	ba = s0->createBuilding( IBuilder::BARRACKS, 8, 17 );
	m0 = static_cast<Barracks *>( ba )->createMarine();
	m1 = static_cast<Barracks *>( ba )->createMarine();

	sd = s1->createBuilding( IBuilder::SUPPLY_DEPOT, 16, 11 );
	bu = s2->createBuilding( IBuilder::BUNKER, 16, 19 );

	delete bu;
	delete sd;
	delete ba;

	delete m0;
	delete m1;

	delete s0;
	delete s1;
	delete s2;

	delete r0;
	delete r1;
	delete r2;

	return 0;
}
