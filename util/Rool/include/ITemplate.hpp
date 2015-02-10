#ifndef I_TEMPLATE_H
# define I_TEMPLATE_H

# include <string>
# include <vector>
# include <map>

class ITemplate
{
public:
	ITemplate(const std::string&);
	virtual ~ITemplate(void){}
	virtual std::string		create(const std::string&){return ("ERROR: ITemplate not override");}
protected:
	typedef std::vector<std::string>	Strings;
	typedef bool		(*parseNameFn)(const std::string&);
	typedef std::string	(ITemplate::*patternFn)(void);
	typedef std::string	(*lexNameFn)(const std::string&);

	std::string											path;

	const std::map<parseNameFn, patternFn>				patternMap;
	virtual std::map<parseNameFn, patternFn>			createPatternMap(void);

	const std::map<std::string, lexNameFn>				mapName;
	virtual std::map<std::string, lexNameFn>			createMapName(void);

	std::map<std::string, std::string>					genMapName;
	virtual std::map<std::string, std::string>			generateMapName(const std::string &str);

private:
};

#endif
