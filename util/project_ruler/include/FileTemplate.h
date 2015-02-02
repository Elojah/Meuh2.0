#ifndef FILE_TEMPLATE_H
# define FILE_TEMPLATE_H

# include <vector>
# include <map>
# include <string>

class FileTemplate
{
public:
	FileTemplate(void);
	~FileTemplate(void);
	void	createFile(const std::string&, std::string);
protected:
private:
	typedef std::vector<std::string>	Strings;

	std::string											_path;

	void	_createNewFile(const std::string&, const std::string&, const std::string&, const std::string&);
	void	_addToMakefile(const std::string name, const std::string type);
	static bool			_parseInterface(const std::string &s);
	static Strings		_parseInheritance(const std::string &s);

	static std::map<std::string, std::string(*)(const std::string&)>		_mapName;
	static std::map<std::string, std::string(*)(const std::string&)>		_createMapName(void);
	static std::string		_nameMaj(const std::string&);
	static std::string		_nameCpy(const std::string&);
	static std::string		_nameParent(const std::string &str);
	static std::string		_accessParent(const std::string &str);
};

#endif

