#ifndef TEMPLATE_H
# define TEMPLATE_H

# include <string>
# include <map>

class Template
{
public:
	Template(const std::string&);
	~Template(void);
	void												create(const std::string&);
protected:
private:
	typedef bool		(*parseNameFn)(const std::string&);
	typedef void		(Template::*patternFn)(const std::string&);
	typedef std::string	(*lexNameFn)(const std::string&);

	Template(void);
	std::string											_path;
	std::map<std::string, std::string>					_currentMapName;
	static std::map<std::string, std::string>			generateNameMap(const std::string &str);

	static const std::map<parseNameFn, patternFn>	_patternMap;
	static std::map<parseNameFn, patternFn>			_createPatternMap(void);

	static const std::map<std::string, lexNameFn>		_mapName;
	static std::map<std::string, lexNameFn>			_createMapName(void);

	static bool											isUsualClass(const std::string&);
	void												makeUsualClass(const std::string&);

	static std::string									parseClassName(const std::string&);
	static std::string									parseIncGuard(const std::string&);
	static std::string									parseParent(const std::string&);
	static std::string									parseParentAccess(const std::string&);
};

#endif
