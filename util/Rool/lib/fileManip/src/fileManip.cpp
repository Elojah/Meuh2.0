#include "fileManip.hpp"
#include <fstream>

const static std::string		schemaDir = "./config/templates/";

void	createNewFile(std::string const &schema, std::string const &fileName
	, std::map<std::string, std::string> &mapName, loopMap &loopMapName) {
	std::ifstream	ifs((schemaDir + schema + ".template").c_str());
	std::ofstream	ofs;
	std::string		line;
	std::string		tmp;
	std::size_t		found;
	std::size_t		foundEnd;
	std::size_t		len;

	ofs.open((fileName).c_str());
	while (std::getline(ifs, line))
	{
		found = 0;
		while ((found = line.find("${", found)) != std::string::npos) {
			foundEnd = line.find('}', found);
			len = foundEnd - found + 1;
			tmp = line.substr(found, len);
			if (mapName.find(tmp) == mapName.end()) {
				line.replace(found, len, "");
			} else {
				line.replace(found, len, mapName[tmp]);
			}
			found++;
		}
		found = 0;
		while ((found = line.find("$[", found)) != std::string::npos) {
			foundEnd = line.find(']', found);
			len = foundEnd - found + 1;
			tmp = line.substr(found, len);
			line.replace(found, len, loopTemplate(tmp, loopMapName));
			found = foundEnd;
		}
		ofs << line << std::endl;
	}
	ifs.close();
	ofs.close();
}

/*
** fileName = "$[file]"
** static ?
*/
std::string		loopTemplate(const std::string &fileName, loopMap &loopMapName) {
	std::ifstream	ifs((schemaDir + fileName.substr(2, fileName.length() - 3) + ".template").c_str());
	std::string		loopVar;
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
	std::getline(ifs, loopVar);
	if (loopMapName.find(loopVar) == loopMapName.end() || loopMapName[loopVar].empty()) {/*Not mandatory ?*/
		return ("");
	}
	std::getline(ifs, line, '^');
	for (std::vector<std::map<std::string, std::string> >::iterator it = loopMapName[loopVar].begin(); it != loopMapName[loopVar].end(); ++it) {
		/*Same bloc than createnewfile, shortcut ?*/
		lineToAppend = std::string(line);
		found = 0;
		while ((found = lineToAppend.find("${", found)) != std::string::npos) {
			foundEnd = lineToAppend.find('}', found);
			len = foundEnd - found + 1;
			tmp = lineToAppend.substr(found, len);
			if (it->find(tmp) == it->end()) {
				lineToAppend.replace(found, len,"");
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
			lineToAppend.replace(found, len, loopTemplate(tmp, loopMapName));
			found = foundEnd;
		}
		result.append(lineToAppend);
	}
	return (result);
}

void	replaceMapToMap(const std::string &oldFileName, const std::string &newFileName
	, std::map<std::string, std::string> &oldMap, std::map<std::string, std::string> &newMap) {
	std::ifstream	ifs;
	std::ofstream	ofs;
	std::string		line;
	std::size_t		found;

	ifs.open((oldFileName).c_str());
	ofs.open((newFileName).c_str());
	/*
	**Triple Loop, BIM !
	*/
	while (std::getline(ifs, line))
	{
		for (std::map<std::string, std::string>::iterator it = oldMap.begin(); it != oldMap.end(); it++) {
			found = 0;
			while ((found = line.find(it->second, found)) != std::string::npos) {
				line.replace(found, it->second.length(), newMap[it->first]);
				found++;
			}
		}
		ofs << line << std::endl;
	}
	ifs.close();
	ofs.close();
	remove((oldFileName).c_str());
}

void	addToFile(const std::string &oldName, const std::string &newName, const std::string &filePath, bool removeOld)
{
	std::ifstream	ifs((filePath).c_str());
	std::ofstream	ofs;
	std::string		line;
	Strings			tmpFile;

	while (std::getline(ifs, line)) {
		tmpFile.push_back(line);
	}
	for (Strings::iterator itRead = tmpFile.begin(); itRead != tmpFile.end(); ++itRead) {
		if ((*itRead).find(oldName) != std::string::npos) {
			continue ;
		}
		tmpFile.insert(itRead + 1, "\t\t" + newName + "\\");
		if (removeOld) {
			tmpFile.erase(itRead);
		}
		break ;
	}
	ifs.close();
	ofs.open((filePath).c_str());
	for (Strings::iterator itWrite = tmpFile.begin(); itWrite != tmpFile.end(); ++itWrite) {
		ofs << *itWrite << std::endl;
	}
	ofs.close();
}
