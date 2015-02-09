#include "Template.hpp"

Template::Template(void) {
}

Template::Template(std::string const &path) {
	_path = std::string(path);
}

Template::~Template(void) {
}

void			Template::create(const std::string &str) {
	_currentMapName = generateNameMap(str);
	for (std::map<parseNameFn, patternFn>::const_iterator it = _patternMap.begin(); it != _patternMap.end(); it++) {
		if (it->first(str)) {
			(this->*(it->second))(str);
			return ;
		}
	}
}

std::map<std::string, std::string>	Template::generateNameMap(const std::string &str) {
	std::map<std::string, std::string>		result;

	for (std::map<std::string, lexNameFn>::const_iterator it = _mapName.begin(); it != _mapName.end(); it++) {
		result[it->first] = it->second(str);
	}
	return (result);
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

std::map<bool(*)(const std::string&), void(Template::*)(const std::string&)>	Template::_createPatternMap(void) {
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

const std::map<bool(*)(const std::string&), void(Template::*)(const std::string&)>
	Template::_patternMap = _createPatternMap();

const std::map<std::string, std::string(*)(const std::string&)>
	Template::_mapName = Template::_createMapName();
