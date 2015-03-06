#ifndef PUZZLE_H
# define PUZZLE_H

# define BUF_SIZE 1024
# define MAX_SIZE 4
# define EMPTY _empty[0]][_empty[1]
# define INC inc[0]][inc[1]

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

	bool							containState(State const *s);
	std::vector<State *>::iterator	bestEval(void);
	int								eval(State const *s);

	std::vector<State *>		_openset;
	std::vector<State *>		_closedset;
	State						*_finalState;
	unsigned int				_size;
	std::vector<IHeuristic *>	_h;
	Puzzle						&operator=(Puzzle const &p);
};

#endif
