// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   TacticalMarine.hpp                                 :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/09 16:54:32 by erobert           #+#    #+#             //
//   Updated: 2015/01/09 16:54:47 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef TACTICAL_MARINE_HPP
# define TACTICAL_MARINE_HPP

# include "ISpaceMarine.hpp"
# include <iostream>

class TacticalMarine : public ISpaceMarine
{
public:
    TacticalMarine(void);
    TacticalMarine(TacticalMarine const &src);
    virtual ~TacticalMarine(void);

    TacticalMarine &operator=(TacticalMarine const &src);

    virtual ISpaceMarine* clone(void) const;
    virtual void battleCry(void) const;
    virtual void rangedAttack(void) const;
    virtual void meleeAttack(void) const;
};

#endif
