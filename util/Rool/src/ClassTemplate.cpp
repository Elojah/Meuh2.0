#include "ClassTemplate.hpp"
#include <fstream>
#include <string.h>

ClassTemplate::ClassTemplate(void) {
}

ClassTemplate::ClassTemplate(std::string const &pathSet) : ITemplate(pathSet) {
}

ClassTemplate::~ClassTemplate(void) {
}

/*
**Init
*/
std::map<bool(*)(const std::string&), std::string(ITemplate::*)(void)>	ClassTemplate::createPatternMap(void) {
	std::map<parseNameFn, patternFn>	m;

	m[&ClassTemplate::isReplaceClassName] = static_cast<patternFn>(&ClassTemplate::makeReplaceClassName);
	m[&ClassTemplate::isUsualClass] = static_cast<patternFn>(&ClassTemplate::makeUsualClass);
	m[&ClassTemplate::isInherit] = static_cast<patternFn>(&ClassTemplate::makeInheritClass);
	/*Add differents patterns here (Interface/Inherit/etc.)*/
	return (m);
}

std::map<std::string, std::string(*)(const std::string&)>	ClassTemplate::createMapName(void) {
	std::map<std::string, lexNameFn>	m;

	/*Add differents names here*/
	m["${CLASS_NAME}"] = static_cast<lexNameFn>(&ClassTemplate::parseClassName);
	m["${INC_GUARD}"] = static_cast<lexNameFn>(&ClassTemplate::parseIncGuard);
	m["${PARENTS}"] = static_cast<lexNameFn>(&ClassTemplate::parseParent);
	m["${OLD_REPLACE}"] = static_cast<lexNameFn>(&ClassTemplate::parseOldName);
	m["${NEW_REPLACE}"] = static_cast<lexNameFn>(&ClassTemplate::parseNewName);
	return (m);
}

/*
**Match/Pattern
*/
bool			ClassTemplate::isUsualClass(std::string const &str) {
	(void)str;
	return (str.at(0) != '$');
}
std::string		ClassTemplate::makeUsualClass(void) {
	createNewFile("src", "src", ".cpp");
	createNewFile("include", "include", ".hpp");
	addToMakefile("CLASS");
	return ("Usual class " + genMapName["${CLASS_NAME}"] + " created successfully!");
}

bool			ClassTemplate::isReplaceClassName(std::string const &str) {
	if (str.find("${NEW_REPLACE=") != std::string::npos
		&& str.find("${OLD_REPLACE=") != std::string::npos) {
		return (true);
	}
	return (false);
}
std::string		ClassTemplate::makeReplaceClassName(void) {
	std::map<std::string, std::string>	newMap;

	newMap = generateMapName(genMapName["${NEW_REPLACE}"]);
	genMapName = generateMapName(genMapName["${OLD_REPLACE}"]);
	replaceMapToMap("src", ".cpp", newMap);
	replaceMapToMap("include", ".hpp", newMap);
	/*REPLACE IN MAKEFILE !*/
	return (genMapName["${CLASS_NAME}"] + " has successfully been replaced by " + newMap["${CLASS_NAME}"]);
}
bool		ClassTemplate::isInherit(std::string const &str) {
	return (str.find(':') != std::string::npos);
}
std::string		ClassTemplate::makeInheritClass(void) {
	Strings		parents;
	char		*pch;

	makeUsualClass();
	pch = strtok(genMapName["${PARENTS}"],",");
	while (pch != NULL) {
		parents.push_back(std::string(pch));
		pch = strtok (NULL, ",");
	}
	addParents(parents);/*All together for 1 ifs, 1 ofs*/
	return ("");
}

/*
**Parse functions
*/
std::string		ClassTemplate::parseClassName(std::string const &str) {
	std::size_t	found;

	if ((found = str.find_first_of(':')) != std::string::npos) {
		return (str.substr(0, found - 1));
	}
	return (std::string(str));
}
std::string		ClassTemplate::parseIncGuard(std::string const &str) {
	std::string				result;
	std::string				tmp;

	tmp = parseClassName(str);
	for (std::string::size_type i = 0; i < tmp.size(); ++i)
	{
		if (tmp[i] >= 'A' && tmp[i] <= 'Z' && i != 0)
			result.push_back('_');
		result.push_back(std::toupper(tmp[i]));
	}
	return (result);
}
std::string		ClassTemplate::parseParent(std::string const &str) {
	std::size_t	found;

	if ((found = str.find_first_of(':')) != std::string::npos) {
		return (str.substr(str.find_last_of(' ') + 1));
	}
	return ("");
}

std::string		ClassTemplate::parseOldName(std::string const &str) {
	std::size_t	found;

	if ((found = str.find("${OLD_REPLACE=")) != std::string::npos) {
		found += 14;/*HARDCODE*/
		return (str.substr(found, str.find_first_of('}', found) - found));
	}
	return ("");
}
std::string		ClassTemplate::parseNewName(std::string const &str) {
	std::size_t	found;

	if ((found = str.find("${NEW_REPLACE=")) != std::string::npos) {
		found += 14;/*HARDCODE*/
		return (str.substr(found, str.find_first_of('}', found) - found));
	}
	return ("");
}

/*
**Util functions
*/
void	ClassTemplate::createNewFile(std::string const &type, std::string const &folder, std::string const &ext)
{
	std::ifstream	ifs(("./config/templates/" + type + ".template").c_str());
	std::ofstream	ofs;
	std::string		line;
	std::size_t		found;

	ofs.open((path + '/' + folder + '/' + genMapName["${CLASS_NAME}"] + ext).c_str());
	/*
	**Triple Loop, BIM !
	*/
	while (std::getline(ifs, line))
	{
		for (std::map<std::string, std::string>::iterator it = genMapName.begin(); it != genMapName.end(); it++) {
			while ((found = line.find(it->first)) != std::string::npos) {
				line.replace(found, it->first.length(), it->second);
			}
		}
		ofs << line << std::endl;
	}
	ifs.close();
	ofs.close();
}

void	ClassTemplate::replaceMapToMap(const std::string &dir, const std::string &ext
	, std::map<std::string, std::string> &newMap) {
	std::ifstream	ifs;
	std::ofstream	ofs;
	std::string		line;
	std::size_t		found;

	ifs.open((path + '/' + dir + '/' + genMapName["${CLASS_NAME}"] + ext).c_str());
	ofs.open((path + '/' + dir + '/' + newMap["${CLASS_NAME}"] + ext).c_str());
	/*
	**Triple Loop, BIM !
	*/
	while (std::getline(ifs, line))
	{
		for (std::map<std::string, std::string>::iterator it = genMapName.begin(); it != genMapName.end(); it++) {
			found = 0;
			while ((found = line.find(it->second, found)) != std::string::npos) {
				line.replace(found, it->second.length(), newMap[it->first]);
				found++;
			}
		}
		ofs << line << std::endl;
	}
	ifs.close();
	ofs.close();
	remove((path + '/' + dir + '/' + genMapName["${CLASS_NAME}"] + ext).c_str());
}

void	ClassTemplate::addToMakefile(const std::string &type)
{
	std::ifstream	ifs((path + "/Makefile").c_str());
	std::ofstream	ofs;
	std::string		line;
	Strings			tmpFile;

	while (std::getline(ifs, line))
		tmpFile.push_back(line);
	for (Strings::iterator itRead = tmpFile.begin(); itRead != tmpFile.end(); ++itRead) {
		if ((*itRead).compare(0, type.length(), type) != 0)
			continue ;
		tmpFile.insert(itRead + 1, "\t\t" + genMapName["${CLASS_NAME}"] + "\\");
		break ;
	}
	ifs.close();
	ofs.open((path + "/Makefile").c_str());
	for (Strings::iterator itWrite = tmpFile.begin(); itWrite != tmpFile.end(); ++itWrite) {
		ofs << *itWrite << std::endl;
	}
	ofs.close();
}

void	ClassTemplate::addParents(std::vector<std::string> &parents) {
	std::ifstream	ifs;
	std::ofstream	ofs;
	std::string		line;
	std::size_t		found;

	for (Strings::iterator it = parents.begin(); it != parents.end(); ++it) {
		;
	}
}
