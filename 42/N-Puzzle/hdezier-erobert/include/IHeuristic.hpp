#ifndef I_HEURISTIC_H
# define I_HEURISTIC_H

# define MAX_SIZE 4

# include <array>

class State;

class IHeuristic
{
public:
	virtual ~IHeuristic(void){}
	virtual void	init(State const *s){(void)s;}
	virtual int		eval(State const *s){(void)s;return (0);}
protected:
	typedef std::array<std::array<int, MAX_SIZE>, MAX_SIZE>	mapArray;
private:
};

#endif
