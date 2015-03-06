#include <array>
#include "Puzzle.hpp"
#include "State.hpp"
#include "Manhattan.hpp"

Puzzle::Puzzle(unsigned int size) : _size(size)
{
	/*Init State*/
	State	*s;

	s = new State(_size, std::array<int, 16>{{
		11, 5, 2, 4,
		7, 8, 9, 3,
		6, 5, 1, 10,
		14, 12, 13, 0
	}});
	_openset.push_back(s);
	/*!Init State*/

	_finalState = new State(4, std::array<int, 16>{{}});
	_finalState->finalFillArray();

	/*Add heuristics here*/
	_h.push_back(new Manhattan(_finalState));
	/*!Add heuristics here*/
}

Puzzle::~Puzzle(void) {}

/*
**
**Wikipedia A*
**http://en.wikipedia.org/wiki/A*_search_algorithm
**
function A*(start,goal)
	closedset := the empty set  	// The set of nodes already evaluated.
	openset := {start}  	// The set of tentative nodes to be evaluated, initially containing the start node
	came_from := the empty map  	// The map of navigated nodes.

	g_score[start] := 0 	// Cost from start along best known path.
	// Estimated total cost from start to goal through y.
	f_score[start] := g_score[start] + heuristic_cost_estimate(start, goal)

	while openset is not empty
	current := the node in openset having the lowest f_score[] value
		if current = goal
			return reconstruct_path(came_from, goal)

		remove current from openset
		add current to closedset
		for each neighbor in neighbor_nodes(current)
			if neighbor in closedset
				continue
			tentative_g_score := g_score[current] + dist_between(current,neighbor)

			if neighbor not in openset or tentative_g_score < g_score[neighbor]
				came_from[neighbor] := current
				g_score[neighbor] := tentative_g_score
				f_score[neighbor] := g_score[neighbor] + heuristic_cost_estimate(neighbor, goal)
				if neighbor not in openset
					add neighbor to openset

	return failure

function reconstruct_path(came_from,current)
	total_path := [current]
	while current in came_from:
		current := came_from[current]
		total_path.append(current)
	return total_path
*/

int				Puzzle::eval(State const *s) {
	int			result(0);
	for (std::vector<IHeuristic *>::iterator it = _h.begin(); it != _h.end(); ++it) {
		result += (*it)->eval(s);
	}
	return (result);
}

std::vector<State *>::iterator	Puzzle::bestEval(void) {
	std::vector<State *>::iterator					min;

	min = _openset.begin();
	for (std::vector<State *>::iterator it = _openset.begin() + 1; it != _openset.end(); ++it) {
		if (eval(*it) < eval(*min)) {
			min = it;
		}
	}
	return (min);
}

bool			Puzzle::containState(State const *s) {
	for (std::vector<State *>::iterator oit = _openset.begin(); oit != _openset.end(); ++oit) {
		if (s == *oit) {
			return (true);
		}
	}
	for (std::vector<State *>::iterator cit = _closedset.begin(); cit != _closedset.end(); ++cit) {
		if (s == *cit) {
			return (true);
		}
	}
	return (false);
}

bool			Puzzle::resolve(void) {
	bool							succes(true);
	std::vector<State *>::iterator			e;
	std::array<State *, MAX_SIZE>			s;
	std::array<State *, MAX_SIZE>::iterator	is;

	while (_openset.size() > 0 && succes) {
		e = bestEval();/*Choose good one heuristic*/
		if (*e == _finalState) {
			return (true);
		}
		_closedset.push_back(*e);
		_openset.erase(e);
		s = (*e)->expand();
		(*e)->display();
		std::cout << "Expand to :" << std::endl;
		for (is = s.begin(); *is != NULL && is != s.end(); ++is) {
			(*is)->display();
			if (!containState(*is)) {
				_openset.push_back(*is);
			} else if (eval(*is) > eval(*e)) {
				;
			}
		}
	}
	return (true);
}

/*
◦ Total number of states ever selected in the "opened" set (complexity in time)
◦ Maximum number of states ever represented in memory at the same time
during the search (complexity in size)
◦ Number of moves required to transition from the initial state to the final state,
according to the search
◦ The ordered sequence of states that make up the solution, according to the
search
◦ The puzzle may be unsolvable, in which case you have to inform the user and
exit
*/
