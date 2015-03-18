#include <array>
#include <algorithm>
#include "Puzzle.hpp"
#include "State.hpp"
#include "Manhattan.hpp"
#include "LinearConflict.hpp"
#include "Hamming.hpp"
#include "MaxSwap.hpp"
#include "NTiles.hpp"

Puzzle::Puzzle(std::vector<int> &v, size_t size, int mask) :
	_maxStates(0),
	_maxStatesOpen(1),
	_size(size),
	_solution(NULL)
{
	/*Init State*/
	State						*s;
	std::array<int, MAX_CASE>	tmp;
	size_t						n(0);

	for (std::vector<int>::iterator it = v.begin(); it != v.end(); ++it)
	{
		tmp[n++] = (*it);
	}
	s = new State(_size, tmp);
	_openset.insert(s);
	/*!Init State*/

	_finalState = new State(_size, std::array<int, MAX_CASE>{{}});
	_finalState->finalFillArray();

	std::cout << "Initial state: " << std::endl;
	s->display();
	std::cout << "to final state: " << std::endl;
	_finalState->display();
	assignHeuristics();
	std::cout << "Nb available heuristics:\t" << _heuristics.size() << std::endl;
	setHeuristics(mask);
	std::cout << "Nb heuristics specified:\t" << _h.size() << std::endl;
}

Puzzle::~Puzzle(void)
{
	for (tStates::iterator it = _openset.begin(); it != _openset.end(); ++it)
		delete (*it);
	for (tStates::iterator it = _closedset.begin(); it != _closedset.end(); ++it)
		delete (*it);
	for (std::vector<IHeuristic *>::const_iterator it = _heuristics.begin(); it != _heuristics.end(); ++it)
		delete (*it);
}

void					Puzzle::assignHeuristics(void)
{
	_heuristics.push_back(new Manhattan(_finalState));
	_heuristics.push_back(new NTiles(_finalState));
	_heuristics.push_back(new Hamming(_finalState));
	_heuristics.push_back(new LinearConflict(_finalState));
	// _heuristics.push_back(new MaxSwap(_finalState));
}

void									Puzzle::setHeuristics(int mask)
{
	size_t								i;
	for (i = 0; i < _heuristics.size(); ++i)
	{
		if (mask & (1 << i))
			_h.push_back(_heuristics[i]);
	}
}

bool									Puzzle::isSolvable(void) const
{
	MaxSwap								valid(_finalState);
	size_t								allPermutations;
	size_t								emptyPermutations;
	size_t								startEmptyPos;
	size_t								finalEmptyPos;

	startEmptyPos = (*(_openset.begin()))->getEmptyPos();
	finalEmptyPos = _finalState->getEmptyPos();
	allPermutations = valid.eval(*(_openset.begin()));

	emptyPermutations = ((startEmptyPos > finalEmptyPos) ?
					startEmptyPos / _size - finalEmptyPos / _size
						+ (startEmptyPos % _size > finalEmptyPos % _size ?
							startEmptyPos % _size - finalEmptyPos % _size : finalEmptyPos % _size - startEmptyPos % _size)
					: finalEmptyPos / _size - startEmptyPos / _size
						+ (startEmptyPos % _size > finalEmptyPos % _size ?
							startEmptyPos % _size - finalEmptyPos % _size : finalEmptyPos % _size - startEmptyPos % _size));
	return ((_size % 2 && (emptyPermutations % 2) == (allPermutations % 2))
		|| (_size % 2 == 0 && (allPermutations % 2 == 0)));
}

int										Puzzle::eval(State *s) const
{
	int			result;

	if ((result = s->getValue()) != NONE_SET)
		return (result);
	result = 0;
	for (std::vector<IHeuristic *>::const_iterator it = _h.begin(); it != _h.end(); ++it)
		result += (*it)->eval(s);
	s->setValue(result);
	return (result);
}

Puzzle::tStates::iterator			Puzzle::containState(State const *s, tStates &tS)
{
	tStates::iterator				first;

	for (tStates::iterator i = tS.begin(); i != tS.end(); ++i)
	{
		if ((*i)->getValue() > s->getValue())
			return (tS.end());
		if (*s == **i)
			return (i);
	}
	return (tS.end());
}

bool			Puzzle::solve(void)
{
	State									*tmp;
	tStates::iterator						inOpen;
	tStates::iterator						inClosed;
	tStates::iterator						inSet;
	tStates::const_iterator					e;
	std::array<State *, 4>::iterator		is;
	std::array<State *, 5>					s;
	char									input[256];

	std::cout << "Solving puzzle ... Please wait for few seconds ..." << std::endl;
	eval(*(_openset.begin()));
	while (_openset.size() > 0)
	{
		if (_openset.size() > _maxStatesOpen)
			_maxStatesOpen = _openset.size();
		e = _openset.begin();

		/*DEBOG*/
		// (*e)->display();
		// std::cout << "Value:\t" << (*e)->getValue() << std::endl;
		// std::cout << "Open size:\t" << _openset.size() << std::endl;
		// for (tStates::iterator it = _openset.begin(); it != _openset.end(); ++it) {
		// 	(*it)->display();
		// }
		// std::cout << "Closed size:\t" << _closedset.size() << std::endl;
		// for (tStates::iterator it = _closedset.begin(); it != _closedset.end(); ++it) {
		// 	(*it)->display();
		// 	std::cout << "Closed value:\t" << (*it)->getValue() << std::endl;
		// }
		/*DEBOG*/

		if (**e == *_finalState)
		{
			_solution = *e;
			std::cout << "Success !" << std::endl;
			return (true);
		}
		tmp = (*e);
		_openset.erase(e);
		_closedset.insert(tmp);
		s = tmp->expand();
		for (is = s.begin(); *is != NULL; ++is)
		{
			eval(*is);
			inOpen = containState(*is, _openset);
			inClosed = containState(*is, _closedset);
			inSet = (inClosed != _closedset.end() ? inClosed : inOpen);
			(*is)->setPrevious(tmp);
			if (inSet == _openset.end())
				_openset.insert(*is);
			else if ((*is)->getDepth() < (*inSet)->getDepth())
			{
				(*inSet)->setPrevious(tmp);
				delete (*is);
				if (inClosed != _closedset.end())
				{
					_openset.insert(*inSet);
					_closedset.erase(inSet);
				}
			}
			else
				delete (*is);
		}
		_maxStates++;
		if (_maxStates % MAX_DEPTH_SEARCH == 0)
		{
			std::cout << _maxStates << " states have been tested, do you want to continue ? y/n" << std::endl;
			std::cin.get(input, 256);
			if (input[0] != 'y')
				break ;
		}
	}
	return (false);
}

void				Puzzle::printResult(void) const
{
	char					input[256];
	std::vector<State *>	path;
	State					*tmp;

	std::cout << "◦ Total number of states ever selected in the opened set:\t\t\t\t" << _maxStatesOpen << std::endl;
	std::cout << "◦ Maximum number of states ever represented in memory at the same time:\t\t\t" << _openset.size() + _closedset.size() << std::endl;
	std::cout << "◦ Number of moves required to transition from the initial state to the final state:\t" << _solution->getDepth() << std::endl;
	tmp = _solution;
	while (tmp != NULL)
	{
		path.insert(path.begin(), tmp);
		tmp = tmp->getPrevious();
	}
	std::cout << "Print result ? y/n" << std::endl;
	std::cin.get(input, 256);
	if (input[0] != 'y')
		return ;
	for (std::vector<State *>::iterator it = path.begin(); it != path.end(); ++it)
		(*it)->display();
}
