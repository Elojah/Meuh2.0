// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   TacticalMarine.cpp                                 :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/09 16:53:57 by erobert           #+#    #+#             //
//   Updated: 2015/01/09 17:22:58 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "TacticalMarine.hpp"

TacticalMarine::TacticalMarine(void)
{
    std::cout << "Tactical Marine ready for battle" << std::endl;
}

TacticalMarine::~TacticalMarine(void)
{
    std::cout << "Aaaargh ..." << std::endl;
}

TacticalMarine::TacticalMarine(TacticalMarine const &tM)
{
    std::cout << "Tactical Marine ready for battle" << std::endl;
    *this = tM;
}

TacticalMarine	&TacticalMarine::operator=(TacticalMarine const &tM)
{
	(void)tM;
    return *this;
}

ISpaceMarine	*TacticalMarine::clone(void) const
{
    TacticalMarine *tmp;

    tmp = new TacticalMarine(*this);
    return tmp;
}
void			TacticalMarine::battleCry(void) const
{
    std::cout << "For the holy PLOT !" << std::endl;
}
void			TacticalMarine::rangedAttack(void) const
{
    std::cout << "* attacks with bolter *" << std::endl;
}

void			TacticalMarine::meleeAttack(void) const
{
    std::cout << "* attacks with chainsword *" <<std::endl;
}
