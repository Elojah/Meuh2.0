#ifndef MAX_SWAP_H
# define MAX_SWAP_H

# include "IHeuristic.hpp"
class State;

class MaxSwap : public IHeuristic
{
public:
	MaxSwap(State const *s);
	~MaxSwap(void);
	int		eval(State const *s) const;
protected:
private:
	MaxSwap(void);

	tArray						_finalMap;
	unsigned int				_size;
};

#endif
