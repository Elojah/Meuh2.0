#ifndef I_TOKEN_H
# define I_TOKEN_H

# include <string>
# include <set>
# include <ctype.h>

struct sReadToken{
	std::string		word;
	int				type;
};

enum {
	NONE = 0,
	FOUND,
	COMPLETE,
	MASTER
};

enum {
	NO_VALID = 0,
	ENTITY,
	GATE,
	EQUAL,
	COMMENT
};

class IToken
{
public:
	virtual ~IToken(void) {};

	typedef std::set<std::string>		tSymbols;

	virtual int				detect(const char &c) = 0;
	virtual int				apply(std::string const &s) = 0;
	virtual int				getPriority(void) const = 0;
	virtual void				reset(void) {
		_read.word.clear();
	}
	virtual sReadToken		getAsRead(void) const {
		return (_read);
	}
protected:
	sReadToken			_read;
	tSymbols				_sym;
private:
};

#endif
