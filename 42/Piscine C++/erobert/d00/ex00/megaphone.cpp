// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   megaphone.cpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/05 09:38:16 by erobert           #+#    #+#             //
//   Updated: 2015/01/05 10:38:20 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>

char	*ft_toupper(char *str)
{
	int	i(0);

	while (str && str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] += 'A' - 'a';
		i++;
	}
	return (str);
}

int		main(int ac, char **av)
{
	int	i(0);

	if (ac == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	}
	else
	{
		while (++i < ac)
			std::cout << ft_toupper(av[i]);
	}
	std::cout << std::endl;
	return (0);
}
