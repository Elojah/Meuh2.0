#ifndef LINEAR_CONFLICT_H
# define LINEAR_CONFLICT_H

# include "IHeuristic.hpp"
class State;

class LinearConflict : public IHeuristic
{
public:
	LinearConflict(State const *s);
	~LinearConflict(void);
	int		eval(State const *s);
protected:
private:
	LinearConflict(void);
	State			*_finalState;
	unsigned int	_size;
};

#endif
