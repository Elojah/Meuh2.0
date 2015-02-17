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
	m[&ClassTemplate::isInherit] = static_cast<patternFn>(&ClassTemplate::makeInheritClass);
	m[&ClassTemplate::isInterface] = static_cast<patternFn>(&ClassTemplate::makeInterface);
	m[&ClassTemplate::isUsualClass] = static_cast<patternFn>(&ClassTemplate::makeUsualClass);
	/*Add differents patterns here (Interface/Inherit/etc.)*/
	return (m);
}

std::map<std::string, std::string(*)(const std::string&)>	ClassTemplate::createMapName(void) {
	std::map<std::string, lexNameFn>	m;

	/*Add differents names here*/
	m["${CLASS_NAME}"] = static_cast<lexNameFn>(&ClassTemplate::parseClassName);
	m["${INC_GUARD}"] = static_cast<lexNameFn>(&ClassTemplate::parseIncGuard);
	m["${PARENTS}"] = static_cast<lexNameFn>(&ClassTemplate::parseParents);
	m["${OLD_REPLACE}"] = static_cast<lexNameFn>(&ClassTemplate::parseOldName);
	m["${NEW_REPLACE}"] = static_cast<lexNameFn>(&ClassTemplate::parseNewName);
	return (m);
}

/*
**Match/Pattern
*/
bool			ClassTemplate::isUsualClass(std::string const &str) {
	(void)str;
	return (str.at(0) != '$' && str.find(':') == std::string::npos);
}
std::string		ClassTemplate::makeUsualClass(void) {
	createNewFile("src", "src", ".cpp");
	createNewFile("include", "include", ".hpp");
	addToMakefile("CLASS", false);
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
	std::map<std::string, std::string>	oldMap;

	oldMap = generateMapName(genMapName["${OLD_REPLACE}"]);
	genMapName = generateMapName(genMapName["${NEW_REPLACE}"]);
	replaceMapToMap("src", ".cpp", oldMap);
	replaceMapToMap("include", ".hpp", oldMap);
	addToMakefile("\t\t" + oldMap["${CLASS_NAME}"] + "\\", true);
	return (oldMap["${CLASS_NAME}"] + " has successfully been replaced by " + genMapName["${CLASS_NAME}"]);
}

bool			ClassTemplate::isInterface(std::string const &str) {
	return ((str.c_str())[0] == 'I' && (str.c_str())[1] >= 'A' && (str.c_str())[1] <= 'Z');
}
std::string		ClassTemplate::makeInterface(void) {
	createNewFile("interface", "include", ".hpp");
	addToMakefile("INTERFACE", false);
	return ("Interface " + genMapName["${CLASS_NAME}"] + " created successfully!");
}

bool		ClassTemplate::isInherit(std::string const &str) {
	return (str.find(':') != std::string::npos);
}
std::string		ClassTemplate::makeInheritClass(void) {
	char		*pch;

	pch = strtok(strdup(genMapName["${PARENTS}"].c_str()),",");
	while (pch != NULL) {
		_parents.push_back(std::string(pch));
		pch = strtok(NULL, ",");
	}
	createNewFile("inherit_src", "src", ".cpp");
	createNewFile("inherit_include", "include", ".hpp");
	addToMakefile("CLASS", false);
	return ("Inherit class " + genMapName["${CLASS_NAME}"] + " created successfully!");
}

/*
**Parse functions
*/
std::string		ClassTemplate::parseClassName(std::string const &str) {
	std::size_t	found;

	if ((found = str.find_first_of(':')) != std::string::npos) {
		return (str.substr(0, found));
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
std::string		ClassTemplate::parseParents(std::string const &str) {
	std::size_t	found;

	if ((found = str.find_first_of(':')) != std::string::npos) {
		return (str.substr(found + 1));
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
	std::size_t		foundEnd;

	ofs.open((path + '/' + folder + '/' + genMapName["${CLASS_NAME}"] + ext).c_str());
	/*
	**Triple Loop, BIM !
	*/
	while (std::getline(ifs, line))
	{
		for (std::map<std::string, std::string>::iterator it = genMapName.begin(); it != genMapName.end(); it++) {
			found = 0;
			while ((found = line.find(it->first, found)) != std::string::npos) {
				line.replace(found, it->first.length(), it->second);
				found++;
			}
		}
		if ((found = line.find("$[")) != std::string::npos) {
			found += 2;
			foundEnd = line.find(']', found);
			line.replace(found - 2, foundEnd + 1, loopTemplate(line.substr(found, foundEnd - found)));
		}
		ofs << line << std::endl;
	}
	ifs.close();
	ofs.close();
}

void	ClassTemplate::replaceMapToMap(const std::string &dir, const std::string &ext
	, std::map<std::string, std::string> &oldMap) {
	std::ifstream	ifs;
	std::ofstream	ofs;
	std::string		line;
	std::size_t		found;

	ifs.open((path + '/' + dir + '/' + oldMap["${CLASS_NAME}"] + ext).c_str());
	ofs.open((path + '/' + dir + '/' + genMapName["${CLASS_NAME}"] + ext).c_str());
	/*
	**Triple Loop, BIM !
	*/
	while (std::getline(ifs, line))
	{
		for (std::map<std::string, std::string>::iterator it = oldMap.begin(); it != oldMap.end(); it++) {
			found = 0;
			while ((found = line.find(it->second, found)) != std::string::npos) {
				line.replace(found, it->second.length(), genMapName[it->first]);
				found++;
			}
		}
		ofs << line << std::endl;
	}
	ifs.close();
	ofs.close();
	remove((path + '/' + dir + '/' + oldMap["${CLASS_NAME}"] + ext).c_str());
}

void	ClassTemplate::addToMakefile(const std::string &type, bool removeOld)
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
		if (removeOld) {
			tmpFile.erase(itRead);
		}
		break ;
	}
	ifs.close();
	ofs.open((path + "/Makefile").c_str());
	for (Strings::iterator itWrite = tmpFile.begin(); itWrite != tmpFile.end(); ++itWrite) {
		ofs << *itWrite << std::endl;
	}
	ofs.close();
}

/*
**PARENT_ACCESS = 0
**PARENT_NAME = 1
** BOURRIN/NOT GENERIC
*/
std::string		ClassTemplate::loopTemplate(const std::string &fileName) {
	std::ifstream	ifs(("./config/templates/" + fileName + ".template").c_str());
	std::string		line;
	std::string		lineToAppend;
	std::string		result;
	std::size_t		found;
	std::size_t		foundParse;

	if (ifs.fail()) {
		return ("[ERROR<File " + fileName + " not found>]");
	}
	std::getline(ifs, line, '^');
	for (Strings::iterator it = _parents.begin(); it != _parents.end(); ++it) {
		lineToAppend = std::string(line);
		foundParse = it->find_last_of(' ');
		if ((found = lineToAppend.find("${PARENT_ACCESS}")) != std::string::npos) {
			lineToAppend.replace(found, 16, it->substr(0, foundParse));
			if (it == _parents.begin()) {
				lineToAppend.insert(found, ": ");
			} else {
				lineToAppend.insert(found, ", ");
			}
		}
		if ((found = lineToAppend.find("${PARENT_NAME}")) != std::string::npos) {
			lineToAppend.replace(found, 14, it->substr(foundParse + 1));
		}
		result.append(lineToAppend);
	}
	return (result);
}
