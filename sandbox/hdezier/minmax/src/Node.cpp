#include "Node.hpp"
#include "Rules.hpp"
#include <stddef.h>
#include <iostream>

Node::Node(void) :
	_children(NULL),
	_value(-1),
	_max(0),
	_min(0xFFFFFF),
	_maxIndex(-1),
	_minIndex(-1)
{}

Node::~Node(void)
{
	if (_children != NULL)
		delete [] _children;
}


void		Node::deleteExceptOne(int n)
{
	for (int i = 0; i < BOARD_SIZE; ++i)
	{
		if (i == n)
			continue ;
		delete _children[i];
	}
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
	{
		_children = new NodePtr[BOARD_SIZE];
		for (int i = 0; i < BOARD_SIZE; ++i)
			_children[i] = new Node();
	}
}

Node	*Node::getChild(int n)
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
			_children[i]->create();
			current = _children[i]->calculus(b, OPPONENT(player), i, rec - 1, !maxmin);
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
	bool		hasPlayed(false);
	int			captures(0);/*useless*/

	// std::cout << "Calculus node:\n\trec:\t" << rec
	// 						<< "\n\tvalue:\t" << _value
	// 						<< "\n\tplayer:\t" << player
	// 						<< std::endl;

	if (_value == -1)/*5 posible conditions*/
	{
		_value = b.play(n, player, captures, true);
		hasPlayed = true;
		calcMaxMin(b, player, rec, maxmin);
	}
	if (rec == 0 || _value > 1023)
		result = _value;
	else if (maxmin)
		result = _max;
	else if (!maxmin)
		result = _min;
	if (hasPlayed)
		b.unplay(n, player, captures);
	return (result); //Use value here ?
}
