#include "Mod_classList.h"
#include <dirent.h>
#include <fstream>

Mod_classList::Mod_classList(void) :
	WinCurse_menu()
{
	;
}

Mod_classList::Mod_classList(int h, int w, int y, int x) :
	WinCurse_menu(h, w, y, x)
{
	;
}

Mod_classList::~Mod_classList(void)
{
	;
}

void	Mod_classList::init(std::string s)
{
	DIR				*dir;
	struct dirent	*ent;
	Strings			srcs;
	std::string		value;
	int				found;

	_path = s;
	s += "/src";
	if ((dir = opendir(s.c_str())) == NULL)
		return ;
	while ((ent = readdir(dir)) != NULL)
	{
		value = std::string(ent->d_name);
		found = value.find_last_of(".");
		if (value.compare(found + 1, value.size(), "cpp") == 0
			&& !value.substr(0, found).empty())
			srcs.push_back(value.substr(0, found));
	}
	closedir(dir);

	srcs.push_back("New");
	setValues(srcs, "Classes/Interfaces");
	value = choosen_value();
	if (value == "New")
		_createNewClass();
	_showAttributes(value);
}

void	Mod_classList::_showAttributes(std::string s)
{
	Strings			attr;
	std::string		line;
	line = _path + "/src/" + s + ".cpp";
	std::ifstream	ifs(line.c_str());
	std::size_t		found;

	if (!ifs)
		return ;
	/*Parse to check Interface & remove & New*/
	while (std::getline(ifs, line))
	{
		if ((found = line.find(s)) != std::string::npos && line [0] != '#')
			attr.push_back(line.substr(found + s.size() + 2));
	}
	attr.push_back("Return");
	setValues(attr, s);
	line = choosen_value();
	if (line.compare("Return") == 0)
		this->init(_path);
	/*else {
	**TODO attributes selected ?
	}*/
}

void	Mod_classList::_createNewClass(void)
{
	std::string	name;

	name = readUser();
	_createNewFile(name, std::string("src"), std::string(".cpp"));
	_createNewFile(name, std::string("include"), std::string(".hpp"));
	_addToMakefile(name);
	this->init(_path);
}

void	Mod_classList::_addToMakefile(const std::string name)
{
	std::ifstream	ifs((_path + "/Makefile").c_str());
	std::ofstream	ofs;
	std::string		line;
	Strings			tmpFile;

	while (std::getline(ifs, line))
		tmpFile.push_back(line);
	for (Strings::iterator itRead = tmpFile.begin(); itRead != tmpFile.end(); ++itRead) {
		if ((*itRead).compare(0, 5, "CLASS") != 0)
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

void	Mod_classList::_createNewFile(const std::string &name
	, const std::string &folder, const std::string &ext)
{
	std::ifstream	ifs(("./cfg/templates/" + folder + ".template").c_str());
	std::ofstream	ofs;
	std::string		line;
	std::string		nameMaj;
	std::size_t		found;

	nameMaj = _nameMaj(name);
	ofs.open((_path + "/" + folder + "/" + name + ext).c_str());
	while (std::getline(ifs, line))
	{
		while ((found = line.find("${NAME}")) != std::string::npos)/*HARDCODE SRC NAME*/
			line.replace(found, 7, name);
		while ((found = line.find("${NAME_MAJ}")) != std::string::npos)/*HARDCODE SRC NAME*/
			line.replace(found, 11, nameMaj);
		ofs << line << std::endl;
	}
	ifs.close();
	ofs.close();
}

std::string	Mod_classList::_nameMaj(std::string str)
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
