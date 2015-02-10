#ifndef CLASS_TEMPLATE_H
# define CLASS_TEMPLATE_H

# include <string>
# include <vector>
# include <map>
# include "ITemplate.hpp"

class ClassTemplate : public ITemplate
{
public:
	ClassTemplate(const std::string&);
	~ClassTemplate(void);
protected:
private:
	ClassTemplate(void);

/*
**Init
*/
	std::map<parseNameFn, patternFn>					createPatternMap(void);
	std::map<std::string, lexNameFn>					createMapName(void);

/*
**Match/Pattern
*/
	static bool											isUsualClass(const std::string&);
	std::string											makeUsualClass(void);

/*
**Parse functions
*/
	static std::string									parseClassName(const std::string&);
	static std::string									parseIncGuard(const std::string&);
	static std::string									parseParent(const std::string&);
	static std::string									parseParentAccess(const std::string&);

/*
**Util functions
*/
	void	createNewFile(const std::string&, const std::string&, const std::string&);
	void	addToMakefile(const std::string&);
};

#endif
