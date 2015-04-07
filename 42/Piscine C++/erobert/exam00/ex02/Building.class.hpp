#ifndef BUILDING_CLASS_HPP
# define BUILDING_CLASS_HPP

# include <string>
# include <iostream>


// ************************************************************************** //
//                             The Building class                             //
// ************************************************************************** //
class Building {


public:

	Building( std::string const & type, int x, int y, int cHP, int mHP );

	virtual ~Building( void );

	int					getIndex( void ) const;
	std::string const &	getType ( void ) const;
	int					getX    ( void ) const;
	int					getY    ( void ) const;
	int					getCHP  ( void ) const;
	int					getMHP  ( void ) const;

	Building &	operator+=( int hp );
	Building &	operator-=( int hp );

	void	destroy( void );

protected:

	int				_index;
	std::string		_type;
	int				_x;
	int				_y;
	int				_cHP;
	int 			_mHP;

	static int		counter;

private:

	Building( void );
	Building( Building const & _ );
	Building &	operator=( Building const & _ );

};


std::ostream &	operator<<( std::ostream & o, Building const & b );



#endif // ************************************************ BUILDING_CLASS_HPP //
