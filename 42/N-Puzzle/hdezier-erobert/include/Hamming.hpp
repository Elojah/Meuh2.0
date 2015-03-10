#ifndef HAMMING_H
# define HAMMING_H

# include "IHeuristic.hpp"
class State;

class Hamming : public IHeuristic
{
public:
	Hamming(State const *s);
	~Hamming(void);
	int		eval(State const *s) const;
protected:
private:
	Hamming(void);

	State			*_finalState;
	unsigned int	_size;
};

#endif
