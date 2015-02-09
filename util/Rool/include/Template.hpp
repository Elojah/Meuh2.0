#ifndef TEMPLATE_H
# define TEMPLATE_H

# include <string>
# include <map>

class Template
{
public:
	Template(void);
	~Template(void);
protected:
private:
	typedef bool		(*parseNameFn)(const std::string&);
	typedef void		(*patternFn)(const std::string&);
	typedef std::string	(*lexNameFn)(const std::string&);

	static const std::map<parseNameFn, patternFn>	_patternMap;
	static std::map<parseNameFn, patternFn>			_createPatternMap(void);

	static const std::map<std::string, lexNameFn>		_mapName;
	static std::map<std::string, lexNameFn>			_createMapName(void);

	static bool			isUsualClass(const std::string&);
	static void			makeUsualClass(const std::string&);

	static std::string		parseClassName(const std::string&);
	static std::string		parseIncGuard(const std::string&);
	static std::string		parseParent(const std::string&);
	static std::string		parseParentAccess(const std::string&);
};

#endif
