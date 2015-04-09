// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Human.cpp                                          :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/06 18:23:36 by erobert           #+#    #+#             //
//   Updated: 2015/01/06 20:16:55 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Human.hpp"

void	Human::meleeAttack(std::string const &target)
{
	std::cout << "meleeAttack on "
			  << target
			  << std::endl;
}
void	Human::rangedAttack(std::string const &target)
{
	std::cout << "rangedAttack on "
			  << target
			  << std::endl;
}
void	Human::intimidatingShout(std::string const &target)
{
	std::cout << "intimidatingShout on "
			  << target
			  << std::endl;
}

void	Human::action(std::string const &action_name, std::string const &target)
{
	human_f		a[3] = {
		&Human::meleeAttack,
		&Human::rangedAttack,
		&Human::intimidatingShout,
	};
	std::string	names[3] = {
		"meleeAttack",
		"rangedAttack",
		"intimidatingShout",
	};
	int			i(-1);

	while (++i < 3)
	{
		if (!action_name.compare(names[i]))
			(this->*a[i])(target);
	}
}
