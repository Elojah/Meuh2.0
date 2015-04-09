#ifndef BUNKER_CLASS_HPP
# define BUNKER_CLASS_HPP

# include "Building.class.hpp"


// ************************************************************************** //
//                             The Bunker class                               //
// ************************************************************************** //
class Bunker : public Building {

public:

	Bunker( int x, int y );

	~Bunker( void );

	void	loadUnit( Unit * u );
	Unit *	unloadUnit( void );


 private:

	Unit *	_slots[4];
	int		_freeIndex;

	Bunker( void );
	Bunker( Bunker const & _ );
	Bunker &	operator=( Bunker const & _ );

};



#endif // ************************************************** BUNKER_CLASS_HPP //
