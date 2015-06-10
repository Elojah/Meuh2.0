#ifndef NODE_HPP
# define NODE_HPP

# define OPPONENT(n) ((n) == Board::P1 ? Board::P2 : Board::P1)
# define INT_MAX 0xFFFFFF

#include "Board.hpp"

class Node
{
public:
	Node(void);
	~Node(void);

	int		calculus(Board &b, Board::eValue const &player
		, int const &n, int rec, bool const &maxmin);
	void	create(void);

protected:
private:
	Node(Node const &src);
	Node&	operator=(Node const &rhs);

	Node		*_children;
	int			_value;
};

#endif
