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
	typedef std::vector<std::string>	Strings;
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
	static bool											isReplaceClassName(std::string const&);
	std::string											makeReplaceClassName(void);
	static bool											isInherit(std::string const &str);
	std::string											makeInheritClass(void);

/*
**Parse functions
*/
	static std::string									parseClassName(const std::string&);
	static std::string									parseIncGuard(const std::string&);
	static std::string									parseParent(const std::string&);
	static std::string									parseOldName(std::string const &str);
	static std::string									parseNewName(std::string const &str);

/*
**Util functions
*/
	void	createNewFile(const std::string&, const std::string&, const std::string&);
	void	replaceMapToMap(const std::string&, const std::string&, std::map<std::string, std::string>&);
	void	addToMakefile(const std::string&);
	void	addParents(std::vector<std::string>&);
};

#endif
