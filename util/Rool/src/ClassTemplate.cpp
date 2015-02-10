#include "ClassTemplate.hpp"
#include <fstream>

ClassTemplate::ClassTemplate(void) {
}

ClassTemplate::ClassTemplate(std::string const &path) :
									_path(std::string(path)),
									_patternMap(_createPatternMap()),
									_mapName(_createMapName()) {
}

ClassTemplate::~ClassTemplate(void) {
}

std::string		ClassTemplate::create(const std::string &str) {
	_currentMapName = generateMapName(str);
	for (std::map<parseNameFn, patternFn>::const_iterator it = _patternMap.begin(); it != _patternMap.end(); it++) {
		if (it->first(str)) {
			return ((this->*(it->second))());
		}
	}
	return ("No pattern matched with entry ...");
}

std::map<std::string, std::string>	ClassTemplate::generateMapName(const std::string &str) {
	std::map<std::string, std::string>		result;

	for (std::map<std::string, lexNameFn>::const_iterator it = _mapName.begin(); it != _mapName.end(); it++) {
		result[it->first] = it->second(str);
	}
	return (result);
}

/*
**Parsing functions for replace name
*/
std::string		ClassTemplate::parseClassName(std::string const &str) {
	return (std::string(str));
}
std::string		ClassTemplate::parseIncGuard(std::string const &str) {
	return (std::string(str));
}
std::string		ClassTemplate::parseParent(std::string const &str) {
	return (std::string(str));
}
std::string		ClassTemplate::parseParentAccess(std::string const &str) {
	return (std::string(str));
}

/*
**Pattern functions for creating new
*/
bool			ClassTemplate::isUsualClass(std::string const &str) {
	(void)str;
	return (true);
}
std::string		ClassTemplate::makeUsualClass(void) {
	createNewFile("src", "src", ".cpp");
	createNewFile("include", "include", ".hpp");
	addToMakefile("CLASS");
	return ("Usual class " + _currentMapName["${CLASS_NAME}"] + " created successfully!");
}

/*
**Private functions______________________________________________________________________________________________________
*/

void	ClassTemplate::createNewFile(std::string const &type, std::string const &folder, std::string const &ext)
{
	std::ifstream	ifs(("./config/templates/" + type + ".Classtemplate").c_str());
	std::ofstream	ofs;
	std::string		line;
	std::size_t		found;

	ofs.open((_path + "/" + folder + "/" + _currentMapName["${CLASS_NAME}"] + ext).c_str());
	/*
	**Triple Loop, BIM !
	*/
	while (std::getline(ifs, line))
	{
		for (std::map<std::string, std::string>::iterator it = _currentMapName.begin(); it != _currentMapName.end(); it++) {
			while ((found = line.find(it->first)) != std::string::npos)
				line.replace(found, it->first.length(), it->second);
		}
		ofs << line << std::endl;
	}
	ifs.close();
	ofs.close();
}

void	ClassTemplate::addToMakefile(const std::string &type)
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
		tmpFile.insert(itRead + 1, "\t\t" + _currentMapName["${CLASS_NAME}"] + "\\");
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
**Map Init________________________________________________________________________________________________________________
*/

std::map<bool(*)(const std::string&), std::string(ClassTemplate::*)(void)>	ClassTemplate::_createPatternMap(void) {
	std::map<parseNameFn, patternFn>	m;

	m[&ClassTemplate::isUsualClass] = &ClassTemplate::makeUsualClass;
	/*Add differents patterns here (Interface/Inherit/etc.)*/
	return (m);
}

std::map<std::string, std::string(*)(const std::string&)>	ClassTemplate::_createMapName(void) {
	std::map<std::string, lexNameFn>	m;

	/*Add differents names here*/
	m["${CLASS_NAME}"] = &ClassTemplate::parseClassName;
	m["${INC_GUARD}"] = &ClassTemplate::parseIncGuard;
	m["${PARENT}"] = &ClassTemplate::parseParent;
	m["${PARENT_ACCESS}"] = &ClassTemplate::parseParentAccess;
	return (m);
}
