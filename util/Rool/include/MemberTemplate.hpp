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

	std::map<parseNameFn, patternFn>					createPatternMap(void);
	std::map<std::string, lexNameFn>					createMapName(void);

};

#endif
