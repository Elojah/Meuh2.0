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


void	FileTemplate::createFile(std::string const &name, std::string path)
{
	Strings		tmp;

	_path = path;
	if (_parseInterface(name))
	{
		_createNewFile(name, std::string("interface"), std::string("include"), std::string(".hpp"));
		_addToMakefile(name, "INTERFACE");
	}
	else if (!(tmp = _parseInheritance(name)).empty())
	{
		;
	}
	else
	{
		_createNewFile(name, std::string("src"), std::string("src"), std::string(".cpp"));
		_createNewFile(name, std::string("include"), std::string("include"), std::string(".hpp"));
		_addToMakefile(name, "CLASS");
	}
}

void	FileTemplate::_addToMakefile(const std::string name, const std::string type)
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
		tmpFile.insert(itRead + 1, "\t\t" + name + "\\");
		break ;
	}
	ifs.close();
	ofs.open((_path + "/Makefile").c_str());
	for (Strings::iterator itWrite = tmpFile.begin(); itWrite != tmpFile.end(); ++itWrite) {
		ofs << *itWrite << std::endl;
	}
	ofs.close();
}

void	FileTemplate::_createNewFile(std::string const &name, std::string const &type
	, std::string const &folder, std::string const &ext)
{
	std::ifstream	ifs(("./cfg/templates/" + type + ".template").c_str());
	std::ofstream	ofs;
	std::string		line;
	std::string		namePreproc;
	std::size_t		found;

	namePreproc = _nameMaj(name);
	ofs.open((_path + "/" + folder + "/" + name + ext).c_str());
	while (std::getline(ifs, line))
	{
		while ((found = line.find("${NAME}")) != std::string::npos)/*HARDCODE SRC NAME*/
			line.replace(found, 7, name);
		while ((found = line.find("${NAME_MAJ}")) != std::string::npos)/*HARDCODE SRC NAME*/
			line.replace(found, 11, namePreproc);
		ofs << line << std::endl;
	}
	ifs.close();
	ofs.close();
}

bool	FileTemplate::_parseInterface(std::string const &s)
{
	return ((s.c_str())[0] == 'I' && (s.c_str())[1] >= 'A' && (s.c_str())[1] <= 'Z');
}

std::vector<std::string>	FileTemplate::_parseInheritance(const std::string &s)
{
	std::size_t	found;
	Strings		result;

/*Jusre un if ici */
	found = s.find(':');
	if (found == std::string::npos)
		return (result);
	return (result);
}

std::string	FileTemplate::_nameCpy(std::string const &str)
{
	return std::string(str);
}

std::string	FileTemplate::_nameMaj(std::string const &str)
{
	std::string				result;

	for (std::string::size_type i = 0; i < str.size(); ++i)
	{
		if (str[i] >= 'A' && str[i] <= 'Z' && i != 0)
			result.push_back('_');
		result.push_back(std::toupper(str[i]));
	}
	return (result);
}

std::string	FileTemplate::_nameParent(std::string const &str)
{
	return std::string(str);
}

std::string	FileTemplate::_accessParent(std::string const &str)
{
	return std::string(str);
}

std::map<std::string, std::string(*)(const std::string&)>	FileTemplate::_createMapName(void)
{
	typedef std::string	(*replaceName)(const std::string&);
	std::map<std::string, replaceName>	m;
	m.insert(std::pair<std::string, replaceName>(
		"${NAME}",
		&(FileTemplate::_nameCpy)
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
