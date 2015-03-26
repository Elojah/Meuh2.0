#ifndef EQUAL_H
# define EQUAL_H

# include "IToken.hpp"

class Equal : public IToken
{
public:
	Equal(void);
	~Equal(void);
	int				detect(const char &c);
	int				apply(std::string const &s);
	int				getPriority(void) const;
protected:
private:
};

#endif
