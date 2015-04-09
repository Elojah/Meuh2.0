#include <iostream>
#include "Marine.class.hpp"


int		main( void ) {

	Marine	m0;
	Marine	m1( 23, 56 );
	Marine	m2( m1 );

	m0 = m1;

	std::cout << m0 << std::endl;
	std::cout << m1 << std::endl;
	std::cout << m2 << std::endl;

	m2.die();

	m0.move( 22, 56 );
	m1.move( 24, 56 );

	m1.stimpack();

	while ( m0.getCHP() > 0 && m1.getCHP() > 0 ) {
		m0.attack( m1 );
		m1.attack( m0 );
	}

	return 0;
}
