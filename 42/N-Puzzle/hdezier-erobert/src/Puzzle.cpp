#include <array>
#include "Puzzle.hpp"
#include "State.hpp"
#include "Manhattan.hpp"
#include "LinearConflict.hpp"
#include "Hamming.hpp"
#include "MaxSwap.hpp"
#include "NTiles.hpp"

Puzzle::Puzzle(std::vector<int> &v, size_t size) : _size(size) {
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

	/*Add heuristics here*/
	_h.push_back(new Manhattan(_finalState));
	_h.push_back(new NTiles(_finalState));
	// _h.push_back(new Hamming(_finalState));
	// _h.push_back(new LinearConflict(_finalState));
	// _h.push_back(new MaxSwap(_finalState));
	/*!Add heuristics here*/
}

Puzzle::~Puzzle(void) {}

int										Puzzle::eval(State *s) {
	int			result;

	if ((result = s->getValue()) != NONE_SET) {
		return (result);
	}
	result = 0;
	for (std::vector<IHeuristic *>::iterator it = _h.begin(); it != _h.end(); ++it) {
		result += (*it)->eval(s);
	}
	s->setValue(result);
	return (result);
}

std::list<State *>::iterator			Puzzle::bestEval(void) {
	std::list<State *>::iterator					min;

	min = _openset.begin();
	for (std::list<State *>::iterator it = _openset.begin(); it != _openset.end(); ++it) {
		if (eval(*it) < eval(*min)) {
			min = it;
		}
	}
	return (min);
}

std::list<State *>::iterator			Puzzle::containState(State const *s, std::list<State *> &v) {
	for (std::list<State *>::iterator oit = v.begin(); oit != v.end(); ++oit) {
		if (*s == **oit) {
			return (oit);
		}
	}
	return (v.end());
}

bool			Puzzle::resolve(void) {
	bool									succes(true);
	static unsigned int						depth(0);
	std::list<State *>::iterator			inOpen;
	std::list<State *>::iterator			inClosed;
	std::list<State *>::iterator			e;
	std::array<State *, 4>					s;
	std::array<State *, 4>::iterator		is;

	while (_openset.size() > 0 && succes) {
		e = bestEval();
		if (**e == *_finalState) {
			(*e)->display();
			std::cout << "Success !" << std::endl;
			return (true);
		}

		_closedset.push_back(*e);
		_openset.erase(e);
		e = _closedset.end();
		e--;
		s = (*e)->expand();

		(*e)->display();
		std::cout << "Evaluated to: " << eval(*e) << std::endl;
		// std::cout << "Expand to :" << std::endl;
		for (is = s.begin(); *is != NULL && is != s.end(); ++is) {
			// (*is)->display();
			inOpen = Puzzle::containState(*is, _openset);
			inClosed = Puzzle::containState(*is, _closedset);
			// std::cout << "Evaluated expand to: " << eval(*is) << std::endl;
			if (inClosed == _closedset.end() && inOpen == _openset.end()) {
				(*is)->setPrevious(*e);
				_openset.push_back(*is);
			} else if (inOpen != _openset.end() && eval(*is) >= eval(*e)) {
				// _openset.erase(inOpen);
				// _closedset.push_back(*inOpen);
			}
		}
		// std::cout << "Open sets: " << _openset.size() << std::endl;
		// std::cout << "Closed sets: " << _closedset.size() << std::endl;
		std::cout << "Depth : " << depth << std::endl;
		depth++;
		if (depth > 5000) {
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
