#ifndef RESSOURCE_CLASS_HPP
# define RESSOURCE_CLASS_HPP

# include <iostream>



// ************************************************************************** //
//                            The Ressource class                             //
// ************************************************************************** //
class Ressource {

public:

	enum type_e		{ MINERAL = 1, GAS };

	type_e const	type;

	virtual ~Ressource( void );

	friend std::ostream &	operator<<( std::ostream & o, Ressource const & r );

	int		getX( void ) const;
	int		getY( void ) const;
	bool	isDepleted( void ) const;
	int		gather( void );

protected:

	Ressource( type_e type, int x, int y, int amount );

	int			_index;
	int			_x;
	int			_y;
	int			_amount;

	static int	counter;

private:

	Ressource( void );
	Ressource( Ressource & _ );

	Ressource &		operator=( Ressource & _ );

};




// ************************************************************************** //
//                             The Mineral class                              //
// ************************************************************************** //
class Mineral : public Ressource {

public:

	Mineral( int x, int y, int amount );


private:

	Mineral( void );
	Mineral( Mineral & _ );

	Mineral &	operator=( Mineral & _ );

};



// ************************************************************************** //
//                               The Gas class                                //
// ************************************************************************** //
class Gas : public Ressource {

public:

	Gas( int x, int y, int amount );


private:

	Gas( void );
	Gas( Gas & _ );

	Gas &	operator=( Gas & _ );

};



#endif // *********************************************** RESSOURCE_CLASS_HPP //
