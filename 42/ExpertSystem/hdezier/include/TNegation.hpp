#ifndef T_NEGATION_HPP
# define T_NEGATION_HPP

# include "IToken.hpp"

class TNegation : public IToken
{
public:
	TNegation(void);
	virtual ~TNegation(void) override;
	virtual eResponse		detect(const std::string &str) const override;
	virtual void			getNextTokens(tok_indexes &mask) const override;
	virtual IToken			*getNewInstance(const std::string &s) const override;
protected:
private:
	static bool				_isNegationSymbol(const char c);
};

#endif
