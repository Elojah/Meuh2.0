#ifndef PUZZLE_H
# define PUZZLE_H

# define BUF_SIZE 1024
# define MAX_DEPTH_SEARCH 5000
# define NONE_SET -1

# include <vector>
# include <array>
# include <iostream>

# include "State.hpp"
class State;
class IHeuristic;

class Puzzle
{
public:
												Puzzle(std::vector<int> &v, size_t size);
												~Puzzle(void);
	bool										solve(void);
	bool										isSolvable(void) const;
protected:
private:
												Puzzle(void);

	struct cmpState {
		bool operator() (State const *a, State const *b) {
			return (a->getValue() < b->getValue());
		}
	};

	void										assignHeuristics(void);
	void										setHeuristics(int mask);
	static std::vector<State *>::iterator		containState(State const *s, std::vector<State *> &v);
	std::vector<State *>::const_iterator		bestEval(void);
	int											eval(State *s) const;

	std::vector<State *>						_openset;
	std::vector<State *>						_closedset;
	State										*_finalState;
	unsigned int								_size;
	std::vector<IHeuristic *>					_h;
	Puzzle										&operator=(Puzzle const &p);

	std::vector<IHeuristic *>					_heuristics;
};

#endif
