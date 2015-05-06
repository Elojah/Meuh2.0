#ifndef COMMANDCENTER_CLASS_HPP
# define COMMANDCENTER_CLASS_HPP

# include "Ressource.class.hpp"
# include "Building.class.hpp"

class Scv;



// ************************************************************************** //
//                          The CommandCenter class                           //
// ************************************************************************** //
class CommandCenter : public Building {


public:

	CommandCenter( int x, int y );

	~CommandCenter( void );


	Scv *	createScv( void ) const;
	void	acceptRessources( Ressource::type_e type, int amount );


 private:

	int		_minerals;
	int		_gas;

	CommandCenter( void );
	CommandCenter( CommandCenter const & s );
	CommandCenter &	operator=( CommandCenter const & s );

};



#endif // ******************************************* COMMANDCENTER_CLASS_HPP //
