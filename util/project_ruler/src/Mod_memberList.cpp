#include "Mod_memberList.h"
#include <fstream>

Mod_memberList::Mod_memberList(void) :
	WinCurse_menu()
{
	;
}

Mod_memberList::Mod_memberList(int h, int w, int y, int x) :
	WinCurse_menu(h, w, y, x)
{
	;
}

Mod_memberList::~Mod_memberList(void)
{
	;
}

void	Mod_memberList::init(std::string path, std::string attClass)
{
	_path = path;
	_class = attClass;
	_showClass();
}

void	Mod_memberList::_showClass(void)
{
	std::string	value;
	Strings		attr;
	Strings		methods;
	Strings		items;

	attr = _parseAttributes();
	// methods = _parseMethods();
	items.reserve(attr.size() + methods.size());
	items.insert(items.end(), methods.begin(), methods.end());
	items.insert(items.end(), attr.begin(), attr.end());
	setValues(items, _class);

	value = choosen_value();
	if (value.compare("Return") != 0)
	{
		/*TODO
		**Attributes selected
		*/
	}
}


std::vector<std::string>	Mod_memberList::_parseAttributes(void)
{
	Strings			result;
	std::string		line;
	line = _path + "/include/" + _class + ".hpp";
	std::ifstream	ifs(line.c_str());

	if (!ifs)
		return (result);
	while (std::getline(ifs, line))
	{
		/*Compare to class _class instead ?*/
		if (line.find("class " + _class) != std::string::npos
			&& std::getline(ifs, line) && line.compare("{") == 0)
		{
			while (std::getline(ifs, line) && line.compare("};") != 0)
			{
				if (line.compare("public:") != 0 && line.compare("protected:") != 0
					&& line.compare("private:") != 0)
					line.insert(0, "  ");
				result.push_back(line);
				while (ifs.peek() == '\t' || ifs.peek() == ' ')
					ifs.ignore();
			}
		}
	}
	ifs.close();
	return (result);
}

std::vector<std::string>	Mod_memberList::_parseMethods(void)
{
	Strings			result;
	std::string		line;
	line = _path + "/src/" + _class + ".cpp";
	std::ifstream	ifs(line.c_str());
	std::size_t		found;

	if (!ifs)
		return (result);
	while (std::getline(ifs, line))
	{
		if ((found = line.find(_class)) != std::string::npos && line [0] != '#')
			result.push_back(line.substr(found + _class.size() + 2));
	}
	ifs.close();
	return (result);
}
