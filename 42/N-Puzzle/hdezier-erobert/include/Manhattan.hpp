#ifndef MANHATTAN_H
# define MANHATTAN_H

# include "IHeuristic.hpp"
class State;

class Manhattan: public IHeuristic
{
public:
	Manhattan(State const &s);
	~Manhattan(void);

	virtual int		eval(State const &s) const;
private:
	unsigned int	_size;
	tArray			_finalMap;

	Manhattan(void);
	Manhattan(Manhattan const &m);

	Manhattan		&operator=(Manhattan const &m);
};

#endif
