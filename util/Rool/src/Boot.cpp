#include "Boot.hpp"
#include <fstream>
#include <iostream>

Boot::Boot(void)
{
	;
}

Boot::Boot(std::string const &str) : Menu()
{
	std::ifstream	ifs(str.c_str());
	std::string		line;
	ListItem		list;

	if (ifs.fail())
	{
		std::cout << "Error: File " << str << " doesn't exist." << std::endl;
		return ;
	}
	while (std::getline(ifs, line))
	{
		if (line.at(0) == '#')
			continue ;
		list.push_back((t_item_full){line, "", NULL});
	}
	list.push_back((t_item_full){"New project", "", NULL});
	ifs.close();
	setTitle("Projects list");
	setItems(list);
	waitUser();
}

Boot::~Boot(void)
{
	;
}
