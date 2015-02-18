#include "UsualInterface.hpp"

UsualInterface::UsualInterface(void) {
}

UsualInterface::~UsualInterface(void) {
}

bool			UsualInterface::isBehavior(std::string const &str) {
	return ((str.c_str())[0] == 'I' && (str.c_str())[1] >= 'A' && (str.c_str())[1] <= 'Z');
}
std::string		UsualInterface::makeBehavior(void) {
	createNewFile("interface", "include", ".hpp");
	addToMakefile("INTERFACE", false);
	return ("Interface " + genMapName["${CLASS_NAME}"] + " created successfully!");
}

std::map<std::string, std::string(*)(const std::string&)>	UsualInterface::createMapName(void) {
	std::map<std::string, lexNameFn>	m;

	/*Add differents names here*/
	m["${CLASS_NAME}"] = static_cast<lexNameFn>(&TemplateBehavior::parseClassName);
	m["${INC_GUARD}"] = static_cast<lexNameFn>(&TemplateBehavior::parseIncGuard);
	m["${PARENTS}"] = static_cast<lexNameFn>(&TemplateBehavior::parseParents);
	return (m);
}

std::map<std::string, std::vector<std::map<std::string, std::string> > >	UsualInterface::createLoopMapName(void) {
	loopMap			m;

	/*Add differents names here*/
	if (genMapName.find("${PARENTS}") != genMapName.end()) {/*Not mandatory ?*/
		m["${PARENTS}"] = parseLoopParents(genMapName["${PARENTS}"]);
	}
	return (m);
}
