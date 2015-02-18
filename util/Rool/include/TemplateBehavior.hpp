#ifndef TEMPLATE_BEHAVIOR_H
# define TEMPLATE_BEHAVIOR_H

# include <string>
# include <vector>
# include <map>

class TemplateBehavior
{
public:
																			TemplateBehavior(void);
																			~TemplateBehavior(void);
	virtual bool															isBehavior(std::string const &str){(void)str;return (false);}
	virtual std::string														makeBehavior(void){return (std::string());}
	virtual void															init(const std::string &str, const std::string &pathSet) {
		path = pathSet;
		mapName = createMapName();
		genMapName = generateMapName(str);
		loopMapName = createLoopMapName();
	}
protected:
	typedef std::vector<std::string>										Strings;
	typedef std::string	(*lexNameFn)(const std::string&);
	typedef std::map<std::string, std::vector<std::map<std::string, std::string> > >	loopMap;

	std::string																path;
	std::map<std::string, lexNameFn>										mapName;
	loopMap																	loopMapName;
	std::map<std::string, std::string>										genMapName;

	virtual std::map<std::string, lexNameFn>								createMapName(void){return(std::map<std::string, lexNameFn>());}
	virtual loopMap															createLoopMapName(void){return(loopMap());}
	virtual std::map<std::string, std::string>								generateMapName(const std::string &str) {
		std::map<std::string, std::string>									result;

		for (std::map<std::string, lexNameFn>::const_iterator it = mapName.begin(); it != mapName.end(); it++) {
			result[it->first] = it->second(str);
		}
		return (result);
	}


/*
**Parse functions
*/
	static std::string														parseClassName(const std::string&);
	static std::string														parseIncGuard(const std::string&);
	static std::string														parseParents(const std::string&);
	static std::string														parseOldName(std::string const &str);
	static std::string														parseNewName(std::string const &str);
/*
**Parse loop functions
*/
	static std::vector<std::map<std::string, std::string> >					parseLoopParents(const std::string&);

/*
**Util functions
*/
	void																	createNewFile(const std::string&, const std::string&, const std::string&);
	void																	replaceMapToMap(const std::string&, const std::string&, std::map<std::string, std::string>&);
	void																	addToMakefile(const std::string&, bool);
	std::string																loopTemplate(const std::string&);
private:
};

#endif
