#include "Node.hpp"
#include "Rules.hpp"
#include <stddef.h>
#include <iostream>

Node::Node(void) :
	_children(NULL),
	_value(-1),
	_maxIndex(-1),
	_minIndex(-1)
{}

Node::~Node(void)
{
	if (_children != NULL)
		delete [] _children;
}

int const	&Node::getMax(void) const
{
	return (_maxIndex);
}

int const	&Node::getMin(void) const
{
	return (_minIndex);
}

void	Node::create(void)
{
	if (_children == NULL)
		_children = new Node[BOARD_SIZE];
}

Node	&Node::getChild(int n)
{
	if (_children == NULL)
		return (NULL);
	return (_children[n]);
}

void	Node::calcMaxMin(Board &b, Board::eValue const &player
	, int rec, bool const &maxmin)
{
	int			current;

	for (int i = 0; i < BOARD_SIZE; ++i)
	{
		if (b.isPlayable(i) && b[i] == Board::EMPTY
			&& !Rules::insertDoubleFreeThrees(b, i, player))
		{
			_children[i].create();
			current = _children[i].calculus(b, OPPONENT(player), i, rec - 1, !maxmin);
			if (maxmin && current > _max)
			{
				_max = current;
				_maxIndex = i;
			}
			else if (!maxmin && current < _min)
			{
				_min = current;
				_minIndex = i;
			}
		}
	}
}

int		Node::calculus(Board &b, Board::eValue const &player
	, int const &n, int rec, bool const &maxmin)
{
	int			result(0);
	int			captures(0);/*useless*/

	// std::cout << "Calculus node:\n\trec:\t" << rec
	// 						<< "\n\tvalue:\t" << _value
	// 						<< "\n\tplayer:\t" << player
	// 						<< std::endl;
	_value = b.play(n, player, captures, true);
	if (rec == 0 || _value >= PTS_WIN)
		result = _value;
	else
		result = calcMaxMin(b, player, rec, maxmin);
	b.unplay(n, player, captures);
	return (result);
}
