#ifndef I_HEURISTIC_H
# define I_HEURISTIC_H

# include <array>
# include "State.hpp"
class State;

class IHeuristic
{
public:
	virtual ~IHeuristic(void){}
	virtual void	init(State const *s){(void)s;}
	virtual int		eval(State const *s) const {(void)s;return (0);}
protected:
	typedef int					**mapArray;
private:
};

#endif
