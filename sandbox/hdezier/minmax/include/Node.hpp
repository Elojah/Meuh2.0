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

	int			calculus(Board &b, Board::eValue const &player
					, int const &n, int rec, bool const &maxmin);
	void		create(void);
	int const	&getMax(void) const;
	int const	&getMin(void) const;
	void		deleteExceptOne(int n);
	Node		*getChild(int n);

protected:
private:

	typedef Node* NodePtr;

	Node(Node const &src);
	Node&	operator=(Node const &rhs);

	void	calcMaxMin(Board &b, Board::eValue const &player,
							int rec, bool const &maxmin);

	Node		**_children;
	int			_value;
	int			_max;
	int			_min;
	int			_maxIndex;
	int			_minIndex;
};

#endif
