#include "Template.hpp"

Template::Template(void) {
}

Template::~Template(void) {
}

/*
**Parsing functions for replace name
*/
std::string		Template::parseClassName(std::string const &str) {
	return (std::string(str));
}
std::string		Template::parseIncGuard(std::string const &str) {
	return (std::string(str));
}
std::string		Template::parseParent(std::string const &str) {
	return (std::string(str));
}
std::string		Template::parseParentAccess(std::string const &str) {
	return (std::string(str));
}

/*
**Pattern functions for creating new
*/
bool			Template::isUsualClass(std::string const &str) {
	(void)str;
	return (true);
}
void			Template::makeUsualClass(std::string const &str) {
	(void)str;
	/*
	**createSrc, createInclude, addMakefile
	*/
}

std::map<bool(*)(const std::string&), void(*)(const std::string&)>	Template::_createPatternMap(void) {
	std::map<parseNameFn, patternFn>	m;

	m[&Template::isUsualClass] = &Template::makeUsualClass;
	/*Add differents patterns here (Interface/Inherit/etc.)*/
	return (m);
}

std::map<std::string, std::string(*)(const std::string&)>	Template::_createMapName(void) {
	std::map<std::string, lexNameFn>	m;

	/*Add differents names here*/
	m["${CLASS_NAME}"] = &Template::parseClassName;
	m["${INC_GUARD}"] = &Template::parseIncGuard;
	m["${PARENT}"] = &Template::parseParent;
	m["${PARENT_ACCESS}"] = &Template::parseParentAccess;
	return (m);
}

const std::map<bool(*)(const std::string&), void(*)(const std::string&)>
	Template::_patternMap = _createPatternMap();

const std::map<std::string, std::string(*)(const std::string&)>
	Template::_mapName = Template::_createMapName();
