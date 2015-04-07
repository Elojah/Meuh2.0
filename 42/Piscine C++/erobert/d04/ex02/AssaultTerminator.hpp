// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   AssaultTerminator.hpp                              :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/09 16:52:34 by erobert           #+#    #+#             //
//   Updated: 2015/01/09 16:53:00 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef ASSAULT_TERMINATOR_HPP
# define ASSAULT_TERMINATOR_HPP

# include "ISpaceMarine.hpp"
# include <iostream>

class AssaultTerminator : public ISpaceMarine
{
public:
    AssaultTerminator(void);
    AssaultTerminator(AssaultTerminator const &src);
    virtual ~AssaultTerminator(void);

    AssaultTerminator &operator=(AssaultTerminator const &src);

    virtual ISpaceMarine* clone(void) const;
    virtual void battleCry(void) const;
    virtual void rangedAttack(void) const;
    virtual void meleeAttack(void) const;
};

#endif
