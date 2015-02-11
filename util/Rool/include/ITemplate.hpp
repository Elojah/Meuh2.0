#ifndef I_TEMPLATE_H
# define I_TEMPLATE_H

# include <string>
# include <vector>
# include <map>

class ITemplate
{
public:
	ITemplate(const std::string &pathSet) :
											path(std::string(pathSet)){}
	~ITemplate(void){}
	virtual void							initMaps(void) {
		patternMap = createPatternMap();
		mapName = createMapName();
	}
	virtual std::string						create(const std::string &str) {
		genMapName = generateMapName(str);
		for (std::map<parseNameFn, patternFn>::const_iterator it = patternMap.begin(); it != patternMap.end(); it++) {
			if (it->first(str)) {
				return ((this->*(it->second))());
			}
		}
		return ("No pattern matched with entry ...");
	}

protected:
	typedef std::vector<std::string>	Strings;
	typedef bool		(*parseNameFn)(const std::string&);
	typedef std::string	(ITemplate::*patternFn)(void);
	typedef std::string	(*lexNameFn)(const std::string&);

	std::string											path;
	std::map<std::string, std::string>					genMapName;
	std::map<parseNameFn, patternFn>					patternMap;
	std::map<std::string, lexNameFn>					mapName;

	ITemplate(void){}

	virtual std::map<parseNameFn, patternFn>			createPatternMap(void){return(std::map<parseNameFn, patternFn>());}
	virtual std::map<std::string, lexNameFn>			createMapName(void){return(std::map<std::string, lexNameFn>());}


	virtual std::map<std::string, std::string>					generateMapName(const std::string &str) {
		std::map<std::string, std::string>		result;

		for (std::map<std::string, lexNameFn>::const_iterator it = mapName.begin(); it != mapName.end(); it++) {
			result[it->first] = it->second(str);
		}
		return (result);
	}

private:
};

#endif
