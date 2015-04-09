// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   AssaultTerminator.cpp                              :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/09 16:53:06 by erobert           #+#    #+#             //
//   Updated: 2015/01/09 17:22:48 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "AssaultTerminator.hpp"

AssaultTerminator::AssaultTerminator(void)
{
    std::cout << "* teleport from space *" << std::endl;
}

AssaultTerminator::~AssaultTerminator(void)
{
    std::cout << "I'll be back ..." << std::endl;
}

AssaultTerminator::AssaultTerminator(AssaultTerminator const &aT)
{
    std::cout << "* teleport from space *" << std::endl;
    *this = aT;
}

AssaultTerminator	&AssaultTerminator::operator=(AssaultTerminator const &aT)
{
	(void)aT;
    return (*this);
}

ISpaceMarine		*AssaultTerminator::clone(void) const
{
    return (new AssaultTerminator(*this));
}
void				AssaultTerminator::battleCry(void) const
{
    std::cout << "This code is unclean. PURIFY IT !" << std::endl;
}
void				AssaultTerminator::rangedAttack(void) const
{
    std::cout << "* does nothing *" << std::endl;
}
void				AssaultTerminator::meleeAttack(void) const
{
    std::cout << "* attacks with chainsfists *" <<std::endl;
}
