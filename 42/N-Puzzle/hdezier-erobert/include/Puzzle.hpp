#ifndef PUZZLE_H
# define PUZZLE_H

# define BUF_SIZE 1024
# define MAX_SIZE 256
# define MAX_CASE 65536
# define MAX_DEPTH 5
# define NONE_SET -1

# include <vector>
# include <array>
# include <iostream>

class IHeuristic;
class State;

class Puzzle
{
public:
	Puzzle(unsigned int);
	~Puzzle(void);
	bool						resolve(void);
protected:
private:
	Puzzle(void);

	static std::vector<State *>::iterator	containState(State const *s, std::vector<State *> &v);
	std::vector<State *>::iterator			bestEval(void);
	int										eval(State *s);

	std::vector<State *>		_openset;
	std::vector<State *>		_closedset;
	State						*_finalState;
	unsigned int				_size;
	std::vector<IHeuristic *>	_h;
	Puzzle						&operator=(Puzzle const &p);
};

#endif
