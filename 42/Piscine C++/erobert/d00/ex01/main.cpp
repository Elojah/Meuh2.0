// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/05 10:42:48 by erobert           #+#    #+#             //
//   Updated: 2015/01/05 16:58:00 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "./map.h"

static void		ft_add(Contact *contacts, int id)
{
	std::string	input;

	std::cout << "Enter first name: ";
	std::getline (std::cin, input);
	contacts[id].setFname(input);
	std::cout << "Enter last name: ";
	std::getline (std::cin, input);
	contacts[id].setLname(input);
	std::cout << "Enter nick name: ";
	std::getline (std::cin, input);
	contacts[id].setNname(input);
	std::cout << "Enter login: ";
	std::getline (std::cin, input);
	contacts[id].setLogin(input);
	std::cout << "Enter postal address: ";
	std::getline (std::cin, input);
	contacts[id].setPaddr(input);
	std::cout << "Enter email address: ";
	std::getline (std::cin, input);
	contacts[id].setEaddr(input);
	std::cout << "Enter phone number: ";
	std::getline (std::cin, input);
	contacts[id].setPnumb(input);
	std::cout << "Enter birthday date: ";
	std::getline (std::cin, input);
	contacts[id].setBdate(input);
	std::cout << "Enter favorite meal: ";
	std::getline (std::cin, input);
	contacts[id].setFavoriteMeal(input);
	std::cout << "Enter underwears colors: ";
	std::getline (std::cin, input);
	contacts[id].setUnderwearsColors(input);
	std::cout << "Enter darkestSecret: ";
	std::getline (std::cin, input);
	contacts[id].setDarkestSecret(input);
	std::cout << "Done" << std::endl;
}

static void		ft_print(std::string str)
{
	size_t		i(0);

	i = str.size();
	if (i > 10)
	{
		str.resize(7);
		std::cout.width(7);
		std::cout << std::right << str;
		std::cout << "...";
	}
	else
	{
		std::cout.width(10);
		std::cout << std::right << str;
	}
}

static void		ft_search(Contact *contacts, int id)
{
	int			index(0);
	std::string	str;

	while (index < id)
	{
		std::cout.width(10); std::cout << std::right << index;
		std::cout << "|";
		ft_print(contacts[index].getFname());
		std::cout << "|";
		ft_print(contacts[index].getLname());
		std::cout << "|";
		ft_print(contacts[index++].getNname());
		std::cout << std::endl;
	}
	ft_contact(contacts, id);
}

void			ft_contact(Contact *contacts, int id)
{
	std::string	input;
	int			i(0);

	std::cout << "Enter id: ";
	std::getline (std::cin, input);
	i = input.data()[0] - '0';
	if (input.size() == 1 && i >= 0 && i < id)
	{
		ft_print(contacts[i].getFname());
		std::cout << std::endl;
		ft_print(contacts[i].getLname());
		std::cout << std::endl;
		ft_print(contacts[i].getNname());
		std::cout << std::endl;
		ft_print(contacts[i].getLogin());
		std::cout << std::endl;
		ft_print(contacts[i].getPaddr());
		std::cout << std::endl;
		ft_print(contacts[i].getEaddr());
		std::cout << std::endl;
		ft_print(contacts[i].getPnumb());
		std::cout << std::endl;
		ft_print(contacts[i].getBdate());
		std::cout << std::endl;
		ft_print(contacts[i].getFavoriteMeal());
		std::cout << std::endl;
		ft_print(contacts[i].getUnderwearsColors());
		std::cout << std::endl;
		ft_print(contacts[i].getDarkestSecret());
		std::cout << std::endl;
	}
	else
		std::cout << "Wrong" << std::endl;
}

int				main(void)
{
	std::string	input;
	Contact		contacts[8];
	int			id(0);

	std::getline(std::cin, input);
	while (input.compare("EXIT"))
	{
		if (!input.compare("ADD"))
		{
			if (id > 7)
				std::cout << "Full" << std::endl;
			else
				ft_add(contacts, id++);
		}
		if (!input.compare("SEARCH"))
		{
			ft_search(contacts, id);
		}
		std::getline (std::cin, input);
	}
	return (0);
}
