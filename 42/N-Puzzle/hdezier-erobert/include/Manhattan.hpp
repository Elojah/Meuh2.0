#ifndef MANHATTAN_H
# define MANHATTAN_H

# include "IHeuristic.hpp"
class State;

class Manhattan : public IHeuristic
{
public:
	Manhattan(State const *s);
	~Manhattan(void);
	int		eval(State const *s);
protected:
private:
	Manhattan(void);
	State			*_finalState;
	unsigned int	_size;
};

#endif
