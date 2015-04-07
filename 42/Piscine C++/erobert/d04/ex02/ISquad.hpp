// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   ISquad.hpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/09 17:04:37 by erobert           #+#    #+#             //
//   Updated: 2015/01/09 17:11:53 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef I_SQUAD_HPP
# define I_SQUAD_HPP

# include "ISpaceMarine.hpp"

class ISquad
{
public:
    virtual ~ISquad(void) {}

    virtual int getCount(void) const = 0;
    virtual ISpaceMarine* getUnit(int) const = 0;

    virtual int push(ISpaceMarine*) = 0;
};

#endif
