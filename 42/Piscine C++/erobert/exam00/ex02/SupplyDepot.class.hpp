#ifndef SUPPLYDEPOT_CLASS_HPP
# define SUPPLYDEPOT_CLASS_HPP

# include "Building.class.hpp"



// ************************************************************************** //
//                          The SupplyDepot class                             //
// ************************************************************************** //
class SupplyDepot : public Building {

public:

	SupplyDepot( int x, int y );

	~SupplyDepot( void );


 private:

	SupplyDepot( void );
	SupplyDepot( SupplyDepot const & s );
	SupplyDepot &	operator=( SupplyDepot const & s );

};



#endif // ********************************************* SUPPLYDEPOT_CLASS_HPP //
