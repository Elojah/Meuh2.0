// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/13 12:23:56 by erobert           #+#    #+#             //
//   Updated: 2015/01/13 18:26:18 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <string>
#include <iostream>
#include <cstdlib>

static void		ft_char(std::string &str)
{
	std::cout << "char: ";
	std::cout << "'" << str << "'" << std::endl;
	std::cout << "int: ";
	std::cout << static_cast<int>(str.c_str()[0]) << std::endl;
	std::cout << "float: ";
	std::cout << static_cast<float>(str.c_str()[0]) << "f" << std::endl;
	std::cout << "double: ";
	std::cout << static_cast<double>(str.c_str()[0]) << std::endl;
}

static int		ft_isint(char const *str)
{
	int			i(0);

	while (str[i])
	{
		if (str[i++] != '0')
			return (0);
	}
	return (1);
}

static int		ft_isnum(char const *str)
{
	int			i(0);
	int			point(0);
	int			f(0);

	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i])
	{
		if (str[i] == '.')
		{
			point++;
			if (ft_isint(str + i + 1))
				return (0);
		}
		else if (str[i] == 'f' && str[i + 1] != '\0')
			return (-1);
		else if (str[i] == 'f')
			f++;
		else if (!std::isdigit(str[i]))
			return (-1);
		i++;
	}
	if (point > 1)
		return (-1);
	if (f == 1)
		return (1);
	if (point == 1)
		return (2);
	return (0);
}

static int		ft_special(std::string &str)
{
	int			i(-1);
	char		tab[3][5] = {"nan", "-inf", "+inf"};

	while (++i < 3)
	{
		if (!str.compare(tab[i]))
		{
			std::cout << "char: ";
			std::cout << "impossible" << std::endl;
			std::cout << "int: ";
			std::cout << "impossible" << std::endl;
			std::cout << "float: ";
			std::cout << tab[i] << "f" << std::endl;
			std::cout << "double: ";
			std::cout << tab[i] << std::endl;
			return (1);
		}
	}
	return (0);
}

int				main(int ac, char **av)
{
	std::string	str;
	char		*p(NULL);
	int			out;
	char        tab[32][4] = {"\\0", "SOH", "STX", "ETX", "EOT", "ENQ", "ACK",
							  "\\a", "\\b", "\\t", "\\n", "\\v", "\\f", "\\r",
							  "SO", "SI", "DLE", "DC1", "DC2", "DC3", "DC4",
							  "NAK", "SYN", "ETB","CAN", "EM", "SUB", "\\e",
							  "FS", "GS", "RS", "US"};
	if (ac != 2)
	{
		std::cout << "convert STRING" << std::endl;
		return (0);
	}
	str = av[1];
	if (str.size() == 1 && !std::isdigit(str[0]))
		ft_char(str);
	else if (ft_special(str))
		;
	else if ((out = ft_isnum(str.c_str())) != -1)
	{
		if (out)
		{
			std::cout << "char: ";
			std::cout << "impossible" << std::endl;
			std::cout << "int: ";
			std::cout << "impossible" << std::endl;
			if (out == 1)
			{
				float f = std::strtof(const_cast<char *>(str.c_str()), &p);
				std::cout << "float: ";
				std::cout << static_cast<float>(f) << "f" << std::endl;
				std::cout << "double: ";
				std::cout << static_cast<double>(f) << std::endl;
			}
			else
			{
				double d = std::strtod(const_cast<char *>(str.c_str()), &p);
				std::cout << "float: ";
				std::cout << static_cast<float>(d) << "f" << std::endl;
				std::cout << "double: ";
				std::cout << static_cast<double>(d) << std::endl;
			}
		}
		else
		{
			int i = std::atoi(const_cast<char *>(str.c_str()));
			std::cout << "char: ";
			if (i > -1 && i < 32)
				std::cout << "'" << tab[i] << "'" << std::endl;
			else if (i < 127)
				std::cout << "'" << static_cast<char>(i) << "'" << std::endl;
			else if (i == 127)
				std::cout << "'DEL'" << std::endl;
			else
				std::cout << "impossible" << std::endl;
			std::cout << "int: ";
			std::cout << static_cast<int>(i) << std::endl;
			std::cout << "float: ";
			std::cout << static_cast<float>(i) << "f" << std::endl;
			std::cout << "double: ";
			std::cout << static_cast<double>(i) << std::endl;
		}
	}
	else
	{
		std::cout << "char: ";
		std::cout << "impossible" << std::endl;
		std::cout << "int: ";
		std::cout << "impossible" << std::endl;
		std::cout << "float: ";
		std::cout << "impossible" << std::endl;
		std::cout << "double: ";
		std::cout << "impossible" << std::endl;
	}
	return (0);
}
