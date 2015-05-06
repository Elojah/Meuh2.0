#ifndef BARRACKS_CLASS_HPP
# define BARRACKS_CLASS_HPP

# include "Building.class.hpp"
# include "Marine.class.hpp"



// ************************************************************************** //
//                             The Barracks class                             //
// ************************************************************************** //
class Barracks : public Building {

public:

	Barracks( int x, int y );

	~Barracks( void );


	Marine *	createMarine( void ) const;


 private:

	Barracks( void );
	Barracks( Barracks const & s );
	Barracks &	operator=( Barracks const & s );

};



#endif // ************************************************ BARRACKS_CLASS_HPP //
