#include <array>
#include <algorithm>
#include "Puzzle.hpp"
#include "State.hpp"
#include "Manhattan.hpp"
#include "LinearConflict.hpp"
#include "Hamming.hpp"
#include "MaxSwap.hpp"
#include "NTiles.hpp"

Puzzle::Puzzle(std::vector<int> &v, size_t size, int mask) : _size(size) {
	/*Init State*/
	State						*s;
	std::array<int, MAX_CASE>	tmp;
	unsigned int				n(0);

	for (std::vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
		tmp[n++] = (*it);
	}
	s = new State(_size, tmp);
	_openset.push_back(s);
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
	std::cout << "Nb heuristics:\t" << _h.size() << std::endl;
}

Puzzle::~Puzzle(void) {
	for (std::vector<State *>::iterator it = _openset.begin(); it != _openset.end(); ++it) {
		delete (*it);
	}
	for (std::vector<State *>::iterator it = _closedset.begin(); it != _closedset.end(); ++it) {
		delete (*it);
	}
	for (std::vector<IHeuristic *>::const_iterator it = _heuristics.begin(); it != _heuristics.end(); ++it) {
		delete (*it);
	}
}

void					Puzzle::assignHeuristics(void) {
	_heuristics.push_back(new Manhattan(_finalState));
	_heuristics.push_back(new NTiles(_finalState));
	_heuristics.push_back(new Hamming(_finalState));
	_heuristics.push_back(new LinearConflict(_finalState));
	_heuristics.push_back(new MaxSwap(_finalState));
}

void									Puzzle::setHeuristics(int mask) {
	size_t								i;
	for (i = 0; i < _heuristics.size(); ++i) {
		if (mask & (1 << i)) {
			_h.push_back(_heuristics[i]);
		}
	}
}

bool									Puzzle::isSolvable(void) const {
	MaxSwap									valid(_finalState);
	unsigned int							allPermutations;
	unsigned int							emptyPermutations;
	std::array<unsigned int, 2>				startEmptyPos;
	std::array<unsigned int, 2>				finalEmptyPos;

	startEmptyPos = (_openset.front())->getEmptyPos();
	finalEmptyPos = _finalState->getEmptyPos();
	allPermutations = valid.eval(_openset.front());
	emptyPermutations = (startEmptyPos[0] > finalEmptyPos[0] ? startEmptyPos[0] - finalEmptyPos[0] : finalEmptyPos[0] - startEmptyPos[0])
			+ (startEmptyPos[1] > finalEmptyPos[1] ? startEmptyPos[1] - finalEmptyPos[1] : finalEmptyPos[1] - startEmptyPos[1]);
	std::cout << "Nb Permutations:\t" << allPermutations << std::endl;
	std::cout << "Empty position moves:\t" << emptyPermutations << std::endl;
	return ((_size % 2 && (emptyPermutations % 2) == (allPermutations % 2))
		|| (_size % 2 == 0 && (allPermutations % 2 == 0)));
}

int										Puzzle::eval(State *s) const {
	int			result;

	if ((result = s->getValue()) != NONE_SET) {
		return (result);
	}
	result = 0;
	for (std::vector<IHeuristic *>::const_iterator it = _h.begin(); it != _h.end(); ++it) {
		result += (*it)->eval(s);
	}
	s->setValue(result);
	return (result);
}

std::vector<State *>::const_iterator			Puzzle::bestEval(void) {
	if (_openset.size() < 5) {
		std::sort(_openset.begin(), _openset.end(), cmpState());
	} else {
		std::sort(_openset.end() - 4, _openset.end(), cmpState());
		std::inplace_merge(_openset.begin(), _openset.end() - 4, _openset.end(), cmpState());
	}
	return (_openset.begin());
}

std::vector<State *>::iterator			Puzzle::containState(State const *s, std::vector<State *> &v) {
	return (std::find_if(v.begin(), v.end(),
		[&](const State *i) {
			return (*s == *i);
		}
	));
}

bool			Puzzle::solve(void) {
	bool									succes(true);
	static unsigned int						nbStateTested(0);
	std::vector<State *>::iterator			inOpen;
	std::vector<State *>::iterator			inClosed;
	std::vector<State *>::iterator			inSet;
	std::vector<State *>::const_iterator	e;
	std::array<State *, 4>					s;
	std::array<State *, 4>::iterator		is;

	std::cout << "Solving puzzle ... Please wait for few seconds ..." << std::endl;
	eval(_openset.front());
	while (_openset.size() > 0 && succes) {
		e = bestEval();
		(*e)->display();
		std::cout << "Value:\t" << (*e)->getValue() << std::endl;
		if (**e == *_finalState) {
			(*e)->display();
			std::cout << "Depth:\t" << (*e)->getDepth() << std::endl;
			std::cout << "Success !" << std::endl;
			return (true);
		}

		_closedset.push_back(*e);
		_openset.erase(e);
		e = _closedset.end();
		e--;
		s = (*e)->expand();

		for (is = s.begin(); *is != NULL && is != s.end(); ++is) {
			inOpen = Puzzle::containState(*is, _openset);
			inClosed = Puzzle::containState(*is, _closedset);
			inSet = inClosed != _closedset.end() ? inClosed : inOpen;
			if (inClosed == _closedset.end() && inOpen == _openset.end()) {
				(*is)->setPrevious(*e);
				eval(*is);
				_openset.push_back(*is);
			} else if ((*is)->getDepth() < (*inSet)->getDepth()) {
				delete (*inSet);
				(*inSet) = (*is);
				if (inClosed != _closedset.end()) {
					eval(*inClosed);
					_openset.push_back(*inClosed);
					_closedset.erase(inClosed);
				}
			}
		}
		nbStateTested++;
		if (nbStateTested > MAX_DEPTH_SEARCH) {
			break ;
		}
	}
	return (false);
}

/*
◦ Total number of states ever selected in the "opened" set (complexity in time)
= Add a max value ?
◦ Maximum number of states ever represented in memory at the same time
during the search (complexity in size)
= Max value on both vecs
◦ Number of moves required to transition from the initial state to the final state,
according to the search
= Count previous value
◦ The ordered sequence of states that make up the solution, according to the
search
= previous
◦ The puzzle may be unsolvable, in which case you have to inform the user and
exit
= TODO !!!!
*/
