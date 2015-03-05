#include "Puzzle.hpp"

Puzzle::Puzzle(std::istream &is)
{
	unsigned int	i;
	unsigned int	j;

	_size = 4;
	(void)is;
	for (i = 0; i < _size; ++i) {
		for (j = 0; j < _size; ++j) {
			_map[i][j].value = i % _size + j;
			_map[i][j].result = i % _size + j + 1;
		}
	}
}

Puzzle::~Puzzle(void) {}

void			Puzzle::parseFile(std::ifstream &ifs)
{
	char		buf[BUF_SIZE];

//	ifs.getline(buf)
	(void)ifs;
	(void)buf;
}

void			Puzzle::move(char const dir)
{
	sCase			tmp;
	int				inc[2];

	inc[0] = dir < 2 ? 0 : 1;
	inc[1] = dir < 2 ? 1 : 0;
	inc[0] *= dir % 2 ? 1 : -1;
	inc[1] *= dir % 2 ? 1 : -1;
	inc[0] += _empty[0];
	inc[1] += _empty[1];
	if (inc[0] >= 0 && inc[0] < static_cast<int>(_size)
		&& inc[1] >= 0 && inc[1] < static_cast<int>(_size)) {
		tmp = _map[EMPTY];
		_map[EMPTY] = _map[INC];
		_map[INC] = tmp;
	}
}

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

unsigned int	Puzzle::heuristicManhattan(unsigned int const x, unsigned int const y) const{
	unsigned int		i;
	unsigned int		j;
	unsigned int		count(0);

	for (i = 0; i < _size; ++i) {
		for (j = 0; j < _size; ++j) {
			if (_map[x][y].value == _map[i][j].result) {
				return (count);
			}
			count++;
		}
	}
}

void			Puzzle::resolve(void) {
	std::vector<unsigned int>	openset;
	std::vector<unsigned int>	closedset;

	openset.reserve(_size * _size);
	closedset.reserve(_size * _size);
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
