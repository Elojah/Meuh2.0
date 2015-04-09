// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Human.hpp                                          :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/06 18:15:00 by erobert           #+#    #+#             //
//   Updated: 2015/01/06 20:16:46 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //


#ifndef HUMAN_HPP
# define HYMAN_HPP

# include <iostream>
# include <string>

class Human
{
private:
	void	meleeAttack(std::string const &target);
	void	rangedAttack(std::string const &target);
	void	intimidatingShout(std::string const &target);

public:
	typedef void	(Human::*human_f) (std::string const &);

	void	action(std::string const &action_name, std::string const &target);
};

#endif
