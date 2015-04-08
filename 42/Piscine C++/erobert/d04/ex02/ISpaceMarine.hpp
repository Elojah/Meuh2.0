// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   ISpaceMarine.hpp                                   :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/09 17:05:02 by erobert           #+#    #+#             //
//   Updated: 2015/01/09 17:05:29 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef I_SPACE_MARINE_HPP
# define I_SPACE_MARINE_HPP

class ISpaceMarine
{
public:
    virtual ~ISpaceMarine(void) {}

    virtual ISpaceMarine	*clone(void) const = 0;
    virtual void			battleCry(void) const = 0;
    virtual void			rangedAttack(void) const = 0;
    virtual void			meleeAttack(void) const = 0;
};

#endif
