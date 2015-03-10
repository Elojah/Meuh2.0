#ifndef N_TILES_H
# define N_TILES_H

# include "IHeuristic.hpp"
class State;

class NTiles : public IHeuristic
{
public:
	NTiles(State const *s);
	~NTiles(void);
	int		eval(State const *s) const;
protected:
private:
	NTiles(void);
	State			*_finalState;
	unsigned int	_size;
};

#endif
