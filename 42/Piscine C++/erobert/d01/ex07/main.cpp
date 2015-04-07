// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/06 17:44:03 by erobert           #+#    #+#             //
//   Updated: 2015/01/06 18:51:44 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>
#include <fstream>
#include <string>

static int			ftReplace(char *file, char **av)
{
	std::ifstream	ifs(av[1]);
	std::ofstream	ofs(file);
	std::string		s1(av[2]);
	std::string		s2(av[3]);
	std::string		line;
	
    if (!ifs || !ofs)
	{
		std::cerr << "open error"
				  << std::endl;
        return (1);
    }
    while (std::getline(ifs, line))
    {
        while (line.find(s1) != std::string::npos)
			line.replace(line.find(s1), s1.length(), s2);
        ofs << line
			<< std::endl;
    }
	return (0);
}

int			main(int ac, char **av)
{
	std::string	file;

	if (ac != 4)
	{
		std::cout << "av: filename, s1, s2"
				  << std::endl;
		return (1);
	}
	file = std::string(av[1]) + ".replace";
	return (ftReplace((char *)file.c_str(), av));
}
