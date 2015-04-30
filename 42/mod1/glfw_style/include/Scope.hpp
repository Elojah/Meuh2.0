#ifndef SCOPE_H
# define SCOPE_H

# include "AToken.hpp"

class Scope: public AToken
{
public:
	Scope(void);
	~Scope(void);
	int				detect(const char &c);
	int				getType(void) const;
protected:
private:
};

#endif
