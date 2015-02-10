#include "MemberTemplate.hpp"

MemberTemplate::MemberTemplate(void) {
	;
}

MemberTemplate::MemberTemplate(std::string const &pathSet) : ITemplate(pathSet) {
}

MemberTemplate::~MemberTemplate(void) {
}

/*
**Init
*/
std::map<bool(*)(const std::string&), std::string(ITemplate::*)(void)>	MemberTemplate::createPatternMap(void) {
	std::map<parseNameFn, patternFn>	m;

	/*Add differents patterns here (static const/method attribute/etc.)*/
	return (m);
}

std::map<std::string, std::string(*)(const std::string&)>	MemberTemplate::createMapName(void) {
	std::map<std::string, lexNameFn>	m;

	/*Add differents names here*/
	return (m);
}
