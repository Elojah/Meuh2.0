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
	int				isInLine(std::array<int, MAX_SIZE> line, int n);

	State			*_finalState;
	unsigned int	_size;
};

#endif
