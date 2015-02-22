#include "UsualClass.hpp"
#include "parseStr.hpp"
#include "fileManip.hpp"

UsualClass::UsualClass(void) {
}

UsualClass::~UsualClass(void) {
}

bool																		UsualClass::isBehavior(std::string const &str) {
	(void)str;
	return (true);
}

std::string																	UsualClass::makeBehavior(void) {
	createNewFile("src", path + "/src/" + genMapName["${CLASS_NAME}"] + ".cpp", genMapName, loopMapName);
	createNewFile("include", path + "/include/" + genMapName["${CLASS_NAME}"] + ".hpp", genMapName, loopMapName);
	addToFile("CLASS", genMapName["${CLASS_NAME}"], path + "/Makefile", false);
	return ("Usual class " + genMapName["${CLASS_NAME}"] + " created successfully!");
}

std::map<std::string, std::string(*)(const std::string&)>					UsualClass::createMapName(void) {
	std::map<std::string, parseStr>	m;

	/*Add differents names here*/
	m["${CLASS_NAME}"] = &parseClassName;
	m["${INC_GUARD}"] = &parseIncGuard;
	m["${PARENTS}"] = &parseParents;
	return (m);
}

std::map<std::string, std::vector<std::map<std::string, std::string> > >	UsualClass::createLoopMapName(void) {
	loopMap			m;

	/*Add differents names here*/
	if (genMapName.find("${PARENTS}") != genMapName.end()) {/*Not mandatory ?*/
		m["${PARENTS}"] = parseLoopParents(genMapName["${PARENTS}"]);
	}
	return (m);
}
