#ifndef CLASS_TEMPLATE_H
# define CLASS_TEMPLATE_H

# include <string>
# include <vector>
# include <map>
# include "ITemplate.hpp"

class ClassTemplate
{
public:
	ClassTemplate(const std::string&);
	~ClassTemplate(void);
	std::string											create(const std::string&);
protected:
private:
	ClassTemplate(void);

	void	createNewFile(const std::string&, const std::string&, const std::string&);
	void	addToMakefile(const std::string&);

/*
**Init
*/
	std::map<parseNameFn, patternFn>					createPatternMap(void);
	std::map<std::string, lexNameFn>					createMapName(void);
	std::map<std::string, std::string>					generateMapName(const std::string &str);

	static bool											isUsualClass(const std::string&);
	std::string											makeUsualClass(void);

	static std::string									parseClassName(const std::string&);
	static std::string									parseIncGuard(const std::string&);
	static std::string									parseParent(const std::string&);
	static std::string									parseParentAccess(const std::string&);
};

#endif
