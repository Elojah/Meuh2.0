#include "TemplateBehavior.hpp"
#include <fstream>
#include <strings.h>
#include <stdlib.h>
#include <cstring>

TemplateBehavior::TemplateBehavior(void){
}

TemplateBehavior::~TemplateBehavior(void){
}

/*
**Parse functions
*/
std::string		TemplateBehavior::parseClassName(std::string const &str) {
	std::size_t	found;

	if ((found = str.find(':')) != std::string::npos) {
		return (str.substr(0, found));
	}
	return (std::string(str));
}
std::string		TemplateBehavior::parseIncGuard(std::string const &str) {
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
std::string		TemplateBehavior::parseParents(std::string const &str) {
	std::size_t	found;

	if ((found = str.find(':')) != std::string::npos) {
		return (str.substr(found + 1));
	}
	return (std::string());
}

std::string		TemplateBehavior::parseOldName(std::string const &str) {
	std::size_t	found;

	if ((found = str.find("${OLD_REPLACE=")) != std::string::npos) {
		found += 14;/*HARDCODE*/
		return (str.substr(found, str.find('}', found) - found));
	}
	return ("");
}
std::string		TemplateBehavior::parseNewName(std::string const &str) {
	std::size_t	found;

	if ((found = str.find("${NEW_REPLACE=")) != std::string::npos) {
		found += 14;/*HARDCODE*/
		return (str.substr(found, str.find('}', found) - found));
	}
	return ("");
}
std::vector<std::map<std::string, std::string> >					TemplateBehavior::parseLoopParents(const std::string &str) {
	char											*pch;
	char											*toFree;
	std::vector<std::map<std::string, std::string> >	result;
	std::map<std::string, std::string>				tmp;
	std::string										wholeParent;
	std::size_t										found;
	std::size_t										foundEnd;

	pch = std::strtok((toFree = strdup(str.c_str())),",");
	while (pch != NULL) {
		wholeParent = std::string(pch);
		found = wholeParent.find_first_not_of(' ');
		tmp["${ACCESS}"] = wholeParent.substr(found, (foundEnd = wholeParent.find(' ', found)) - found + 1);
		found = wholeParent.find_first_not_of(' ', foundEnd);
		tmp["${CLASS_NAME}"] = wholeParent.substr(found, wholeParent.find(' ', found) - found + 1);
		result.push_back(std::map<std::string, std::string>(tmp));
		pch = std::strtok(NULL,",");
	}
	free(toFree);
	return (result);
}


/*
**Util functions
*/
void	TemplateBehavior::createNewFile(std::string const &type, std::string const &folder, std::string const &ext)
{
	std::ifstream	ifs(("./config/templates/" + type + ".template").c_str());
	std::ofstream	ofs;
	std::string		line;
	std::string		tmp;
	std::size_t		found;
	std::size_t		foundEnd;
	std::size_t		len;

	ofs.open((path + '/' + folder + '/' + genMapName["${CLASS_NAME}"] + ext).c_str());
	while (std::getline(ifs, line))
	{
		found = 0;
		while ((found = line.find("${", found)) != std::string::npos) {
			foundEnd = line.find('}', found);
			len = foundEnd - found + 1;
			tmp = line.substr(found, len);
			if (genMapName.find(tmp) == genMapName.end()) {
				line.replace(found, len, "");
			} else {
				line.replace(found, len, genMapName[tmp]);
			}
			found++;
		}
		found = 0;
		while ((found = line.find("$[", found)) != std::string::npos) {
			foundEnd = line.find(']', found);
			len = foundEnd - found + 1;
			tmp = line.substr(found, len);
			line.replace(found, len, loopTemplate(tmp));
			found = foundEnd;
		}
		ofs << line << std::endl;
	}
	ifs.close();
	ofs.close();
}
std::string		TemplateBehavior::loopTemplate(const std::string &fileName) {
	std::ifstream	ifs(("./config/templates/" + fileName.substr(2, fileName.length() - 3) + ".template").c_str());
	std::string		line;
	std::string		tmp;
	std::string		lineToAppend;
	std::string		result;
	std::size_t		found;
	std::size_t		foundEnd;
	std::size_t		len;
	std::map<std::string, std::string>	toLoop;

	if (ifs.fail()) {
		return ("[ERROR<File " + fileName + " not found>]");
	}
	std::getline(ifs, line);
	if (loopMapName.find(line) == loopMapName.end() || loopMapName[line].empty()) {/*Not mandatory ?*/
		return ("");
	}
	std::getline(ifs, line, '^');
	for (std::vector<std::map<std::string, std::string> >::iterator it = loopMapName[line].begin(); it != loopMapName[line].end(); ++it) {
		/*Same bloc than createnewfile, shortcut ?*/
		lineToAppend = std::string(line);
		found = 0;
		while ((found = lineToAppend.find("${", found)) != std::string::npos) {
			foundEnd = lineToAppend.find('}', found);
			len = foundEnd - found + 1;
			tmp = lineToAppend.substr(found, len);
			if (it->find(tmp) != it->end()) {
				lineToAppend.replace(found, len, "");
			} else {
				lineToAppend.replace(found, len, (*it)[tmp]);
			}
			found++;
		}
		found = 0;
		while ((found = lineToAppend.find("$[", found)) != std::string::npos) {
			foundEnd = lineToAppend.find(']', found);
			len = foundEnd - found + 1;
			tmp = lineToAppend.substr(found, len);
			lineToAppend.replace(found, len, loopTemplate(tmp));
			found = foundEnd;
		}
		result.append(lineToAppend);
	}
	return (result);
}

void	TemplateBehavior::replaceMapToMap(const std::string &dir, const std::string &ext
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

void	TemplateBehavior::addToMakefile(const std::string &type, bool removeOld)
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
