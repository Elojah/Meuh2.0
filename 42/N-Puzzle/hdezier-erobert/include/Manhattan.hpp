#ifndef MANHATTAN_H
# define MANHATTAN_H

# include "IHeuristic.hpp"
class State;

class Manhattan : public IHeuristic
{
public:
	Manhattan(State const *s);
	~Manhattan(void);
	int		eval(State const *s) const;
protected:
private:
	Manhattan(void);
	unsigned int	_size;
	tArray			_finalMap;
};

#endif
