#include "FileTemplate.h"
#include <fstream>

FileTemplate::FileTemplate(void)
{
	;
}

FileTemplate::~FileTemplate(void)
{
	;
}

/*
**Define parsing & creation from string read
*/
void	FileTemplate::createFile(std::string const &entry, std::string &path)
{
	_path = path;
	if (_parseInterface(entry))
	{
		_createNewFile(entry, "interface", "include", ".hpp");
		_addToMakefile(entry, "INTERFACE");
	}
	else if (_parseInheritance(entry))
	{
		_createNewFile(entry, "inherit_src", "src", ".cpp");
		_createNewFile(entry, "inherit_include", "include", ".hpp");
		_addToMakefile(entry, "CLASS");
	}
	else
	{
		_createNewFile(entry, "src", "src", ".cpp");
		_createNewFile(entry, "include", "include", ".hpp");
		_addToMakefile(entry, "CLASS");
	}
}

void	FileTemplate::_createNewFile(std::string const &entry, std::string const &type
	, std::string const &folder, std::string const &ext)
{
	std::ifstream	ifs(("./cfg/templates/" + type + ".template").c_str());
	std::ofstream	ofs;
	std::string		line;
	std::string		tmpName;
	std::size_t		found;

	ofs.open((_path + "/" + folder + "/" + _nameClass(entry) + ext).c_str());
	while (std::getline(ifs, line))
	{
		/*Not opti, calculus tmpName too many times
		**Make fct _initMap() ?
		**/
		for (std::map<std::string, std::string(*)(const std::string&)>::iterator it = _mapName.begin();
				it != _mapName.end(); it++) {
			tmpName = it->second(entry);
			while ((found = line.find(it->first)) != std::string::npos)
				line.replace(found, it->first.length(), tmpName);
		}
		ofs << line << std::endl;
	}
	ifs.close();
	ofs.close();
}

void	FileTemplate::_addToMakefile(const std::string &name, const std::string &type)
{
	std::ifstream	ifs((_path + "/Makefile").c_str());
	std::ofstream	ofs;
	std::string		line;
	Strings			tmpFile;

	while (std::getline(ifs, line))
		tmpFile.push_back(line);
	for (Strings::iterator itRead = tmpFile.begin(); itRead != tmpFile.end(); ++itRead) {
		if ((*itRead).compare(0, type.length(), type) != 0)
			continue ;
		tmpFile.insert(itRead + 1, "\t\t" + _nameClass(name) + "\\");
		break ;
	}
	ifs.close();
	ofs.open((_path + "/Makefile").c_str());
	for (Strings::iterator itWrite = tmpFile.begin(); itWrite != tmpFile.end(); ++itWrite) {
		ofs << *itWrite << std::endl;
	}
	ofs.close();
}

/*
**Boolean parsing to define behavior
*/
bool	FileTemplate::_parseInterface(std::string const &s)
{
	return ((s.c_str())[0] == 'I' && (s.c_str())[1] >= 'A' && (s.c_str())[1] <= 'Z');
}

bool	FileTemplate::_parseInheritance(const std::string &s)
{
	return (s.find(':') != std::string::npos);
}

/*
**Replacement name in templates
*/
std::string	FileTemplate::_nameClass(std::string const &str)
{
	/*parse class name*/
	return str.substr(0, str.find(':'));
}

std::string	FileTemplate::_nameMaj(std::string const &str)
{
	std::string				result;
	std::string				tmp;

	tmp = _nameClass(str);
	for (std::string::size_type i = 0; i < tmp.size(); ++i)
	{
		if (tmp[i] >= 'A' && tmp[i] <= 'Z' && i != 0)
			result.push_back('_');
		result.push_back(std::toupper(tmp[i]));
	}
	return (result);
}

std::string	FileTemplate::_nameParent(std::string const &str)
{
	return (str.substr(str.find(' ') + 1));
}

std::string	FileTemplate::_accessParent(std::string const &str)
{
	std::size_t	found;

	found = str.find(':');
	return (str.substr(found + 1, str.find(' ') - found - 1));
}

std::map<std::string, std::string(*)(const std::string&)>	FileTemplate::_createMapName(void)
{
	typedef std::string	(*replaceName)(const std::string&);
	std::map<std::string, replaceName>	m;
	m.insert(std::pair<std::string, replaceName>(
		"${NAME}",
		&(FileTemplate::_nameClass)
		));
	m.insert(std::pair<std::string, replaceName>(
		"${NAME_MAJ}",
		&(FileTemplate::_nameMaj)
		));
	m.insert(std::pair<std::string, replaceName>(
		"${PARENT}",
		&(FileTemplate::_nameParent)
		));
	m.insert(std::pair<std::string, replaceName>(
		"${PARENT_ACCESS}",
		&(FileTemplate::_accessParent)
		));
	return (m);
}

std::map<std::string, std::string(*)(const std::string&)>	FileTemplate::_mapName = FileTemplate::_createMapName();
