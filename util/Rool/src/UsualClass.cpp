#include "UsualClass.hpp"

UsualClass::UsualClass(void) {
}

UsualClass::~UsualClass(void) {
}

bool																		UsualClass::isBehavior(std::string const &str) {
	(void)str;
	return (true);
}

std::string																	UsualClass::makeBehavior(void) {
	createNewFile("src", "src", ".cpp");
	createNewFile("include", "include", ".hpp");
	addToMakefile("CLASS", false);
	return ("Usual class " + genMapName["${CLASS_NAME}"] + " created successfully!");
}

std::map<std::string, std::string(*)(const std::string&)>					UsualClass::createMapName(void) {
	std::map<std::string, lexNameFn>	m;

	/*Add differents names here*/
	m["${CLASS_NAME}"] = static_cast<lexNameFn>(&TemplateBehavior::parseClassName);
	m["${INC_GUARD}"] = static_cast<lexNameFn>(&TemplateBehavior::parseIncGuard);
	m["${PARENTS}"] = static_cast<lexNameFn>(&TemplateBehavior::parseParents);
	return (m);
}

std::map<std::string, std::vector<std::map<std::string, std::string> > >	UsualClass::createLoopMapName(void) {
	loopMap			m;

	/*Add differents names here*/
	if (genMapName.find("${PARENTS}") != genMapName.end()) {/*Not mandatory ?*/
		m["${PARENTS}"] = TemplateBehavior::parseLoopParents(genMapName["${PARENTS}"]);
	}
	return (m);
}
