#include "ReplaceClassName.hpp"

ReplaceClassName::ReplaceClassName(void) {
}

ReplaceClassName::~ReplaceClassName(void) {
}

bool			ReplaceClassName::isBehavior(std::string const &str) {
	if (str.find("${NEW_NAME=") != std::string::npos
		&& str.find("${OLD_NAME=") != std::string::npos) {
		return (true);
	}
	return (false);
}
std::string		ReplaceClassName::makeBehavior(void) {
	std::map<std::string, std::string>	oldMap;

	oldMap = generateMapName(genMapName["${OLD_NAME}"]);
	genMapName = generateMapName(genMapName["${NEW_NAME}"]);
	replaceMapToMap("src", ".cpp", oldMap);
	replaceMapToMap("include", ".hpp", oldMap);
	addToMakefile("\t\t" + oldMap["${CLASS_NAME}"] + "\\", true);
	return (oldMap["${CLASS_NAME}"] + " has successfully been replaced by " + genMapName["${CLASS_NAME}"]);
}

std::map<std::string, std::string(*)(const std::string&)>	ReplaceClassName::createMapName(void) {
	std::map<std::string, lexNameFn>	m;

	/*Add differents names here*/
	m["${CLASS_NAME}"] = static_cast<lexNameFn>(&TemplateBehavior::parseClassName);
	m["${INC_GUARD}"] = static_cast<lexNameFn>(&TemplateBehavior::parseIncGuard);
	m["${OLD_NAME}"] = static_cast<lexNameFn>(&ReplaceClassName::parseOldName);
	m["${NEW_NAME}"] = static_cast<lexNameFn>(&ReplaceClassName::parseNewName);
	return (m);
}

/*
**Parse functions supp
*/
std::string		ReplaceClassName::parseOldName(std::string const &str) {
	std::size_t	found;

	if ((found = str.find("${OLD_NAME=")) != std::string::npos) {
		found += 11;/*HARDCODE*/
		return (str.substr(found, str.find_first_of('}', found) - found));
	}
	return ("");
}
std::string		ReplaceClassName::parseNewName(std::string const &str) {
	std::size_t	found;

	if ((found = str.find("${NEW_NAME=")) != std::string::npos) {
		found += 11;/*HARDCODE*/
		return (str.substr(found, str.find_first_of('}', found) - found));
	}
	return ("");
}
