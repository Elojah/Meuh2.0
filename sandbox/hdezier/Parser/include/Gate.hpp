#ifndef GATE_H
# define GATE_H

# include "IToken.hpp"

class Gate : public IToken
{
public:
	Gate(void);
	~Gate(void);
	int				detect(const char &c);
	int				apply(std::string const &s);
	int				getPriority(void) const;
protected:
private:
};

#endif
