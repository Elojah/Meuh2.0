#include <array>
#include "Puzzle.hpp"
#include "State.hpp"

Puzzle::Puzzle(unsigned int size) : _size(size)
{
	State	s(_size, std::array<int, 16>{{
		1, 5, 2, 4,
		7, 8, 9, 3,
		6, 5, 0, 10,
		11, 12, 13, 14
		}});

	_finalState = new State(4, std::array<int, 16>{{}});
	_finalState->finalFillArray();
	_openset.push_back(&s);
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
	unsigned int					i;
	std::vector<State *>::iterator	e;
	std::array<State *, MAX_SIZE>	s;

	while (_openset.size() > 0 && succes) {
		e = _openset.begin();
		(*e)->display();
		if (*e == _finalState) {
			return (true);
		}
		_closedset.push_back(*e);
		_openset.erase(e);
		s = (*e)->expand();
		for (i = 0; i < _size; ++i) {
			if (!containState(s[i])) {
				_openset.push_back(s[i]);
			} else {
				;
			}
		}
		succes = false;
	}
	return (true);
}

void		Puzzle::showStates(void) {
	for (std::vector<State *>::iterator oit = _openset.begin(); oit != _openset.end(); ++oit) {
		(*oit)->display();
	}
	for (std::vector<State *>::iterator cit = _closedset.begin(); cit != _closedset.end(); ++cit) {
		(*cit)->display();
	}
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
