#include "Node.hpp"
#include <stddef.h>
#include <iostream>

Node::Node(void) :
	_children(NULL),
	_value(0)
{}

Node::~Node(void)
{
	if (_children != NULL)
		delete[] _children;
}

void	Node::create(void)
{
	if (_children == NULL)
		_children = new Node[BOARD_SIZE];
}

int		Node::calculus(Board &b, Board::eValue const &player
	, int const &n, int rec, bool const &maxmin)
{
	int			captures(0);
	int			current;
	int			result;

	std::cout << "Calculus node:\n\trec:\t" << rec
							<< "\n\tvalue:\t" << _value
							<< "\n\tplayer:\t" << player
							<< std::endl;
	result = maxmin ? 0 : INT_MAX;
	if (_value == 0)
		_value = b.play(n, player, captures);
	if (rec == 0)
	{
		b.unplay(n, player, captures);
		return (_value);
	}
	for (int i = 0; i < BOARD_SIZE; ++i)
	{
		if (b.isPlayable(i) && b[i] == Board::EMPTY)// && !Rules::insertDoubleFreeThrees(i))
		{
			_children[i].create();
			current = _children[i].calculus(b, OPPONENT(player), i, rec - 1, !maxmin);
			if ((maxmin && current > result)
				|| (!maxmin && current < result))
				result = current;
		}
	}
	b.unplay(n, player, captures);
	return (result + _value);
}
