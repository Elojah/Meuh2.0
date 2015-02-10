#ifndef MEMBER_TEMPLATE_H
# define MEMBER_TEMPLATE_H

# include <string>
# include "ITemplate.hpp"

class MemberTemplate : public ITemplate
{
public:
	MemberTemplate(const std::string&);
	~MemberTemplate(void);
protected:
private:
	MemberTemplate(void);

/*
**Init
*/
	std::map<parseNameFn, patternFn>					createPatternMap(void);
	std::map<std::string, lexNameFn>					createMapName(void);

/*
**Match/Pattern
*/
	static bool											isMethod(std::string const &str);
	std::string											makeMethod(void);

/*
**Parse functions
*/
	static std::string									parseMethodName(std::string const &str);
	static std::string									parseAttName(std::string const &str);
	static std::string									parseAccess(std::string const &str);
	static std::string									parseArguments(std::string const &str);

/*
**Util functions
*/
};

#endif
