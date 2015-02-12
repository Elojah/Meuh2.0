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
	m[&MemberTemplate::isMethod] = static_cast<patternFn>(&MemberTemplate::makeMethod);
	return (m);
}

std::map<std::string, std::string(*)(const std::string&)>				MemberTemplate::createMapName(void) {
	std::map<std::string, lexNameFn>	m;

	/*Add differents names here*/
	m["${METHOD_NAME}"] = static_cast<lexNameFn>(&MemberTemplate::parseMethodName);
	return (m);
}
/*
**Match/Pattern
*/
bool																	MemberTemplate::isMethod(std::string const &str) {
	(void)str;
	(void)str;
	return (true);
}
std::string																MemberTemplate::makeMethod(void) {
	return ("Method " + genMapName["${METHOD_NAME}"] + " created successfully !");
}

/*
**Parse functions
*/
std::string																MemberTemplate::parseMethodName(std::string const &str) {
	return (std::string(str));
}

std::string																MemberTemplate::parseAttName(std::string const &str) {
	return (std::string(str));
}

std::string																MemberTemplate::parseAccess(std::string const &str) {
	return (std::string(str));
}

std::string																MemberTemplate::parseArguments(std::string const &str) {
	return (std::string(str));
}
