#ifndef LINEAR_CONFLICT_H
# define LINEAR_CONFLICT_H

# include "IHeuristic.hpp"
class State;

class LinearConflict : public IHeuristic
{
public:
	LinearConflict(State const *s);
	~LinearConflict(void);
	int		eval(State const *s) const;
protected:
private:
	LinearConflict(void);
	int				isInLine(int line, int n) const;
	int				isInColumn(int col, int n) const;

	unsigned int	_size;
	tArray			_finalMap;
};

#endif
