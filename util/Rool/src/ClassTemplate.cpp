#include "ClassTemplate.hpp"
#include <fstream>

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

	m[&ClassTemplate::isUsualClass] = static_cast<patternFn>(&ClassTemplate::makeUsualClass);
	/*Add differents patterns here (Interface/Inherit/etc.)*/
	return (m);
}

std::map<std::string, std::string(*)(const std::string&)>	ClassTemplate::createMapName(void) {
	std::map<std::string, lexNameFn>	m;

	/*Add differents names here*/
	m["${CLASS_NAME}"] = static_cast<lexNameFn>(&ClassTemplate::parseClassName);
	m["${INC_GUARD}"] = static_cast<lexNameFn>(&ClassTemplate::parseIncGuard);
	m["${PARENT}"] = static_cast<lexNameFn>(&ClassTemplate::parseParent);
	m["${PARENT_ACCESS}"] = static_cast<lexNameFn>(&ClassTemplate::parseParentAccess);
	return (m);
}

/*
**Match/Pattern
*/
bool			ClassTemplate::isUsualClass(std::string const &str) {
	(void)str;
	return (true);
}
std::string		ClassTemplate::makeUsualClass(void) {
	createNewFile("src", "src", ".cpp");
	createNewFile("include", "include", ".hpp");
	addToMakefile("CLASS");
	return ("Usual class " + genMapName["${CLASS_NAME}"] + " created successfully!");
}

/*
**Parse functions
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
**Util functions
*/
void	ClassTemplate::createNewFile(std::string const &type, std::string const &folder, std::string const &ext)
{
	std::ifstream	ifs(("./config/templates/" + type + ".Classtemplate").c_str());
	std::ofstream	ofs;
	std::string		line;
	std::size_t		found;

	ofs.open((path + "/" + folder + "/" + genMapName["${CLASS_NAME}"] + ext).c_str());
	/*
	**Triple Loop, BIM !
	*/
	while (std::getline(ifs, line))
	{
		for (std::map<std::string, std::string>::iterator it = genMapName.begin(); it != genMapName.end(); it++) {
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
