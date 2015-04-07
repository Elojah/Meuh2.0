// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Squad.hpp                                          :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/09 17:10:17 by erobert           #+#    #+#             //
//   Updated: 2015/01/09 17:11:38 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef SQUAD_HPP
# define SQUAD_HPP

# include <iostream>
# include "ISquad.hpp"
# include "ISpaceMarine.hpp"

class Squad : public ISquad
{
private:
    int				_count;
    ISpaceMarine	**_units;
public:
    Squad(void);
    Squad(Squad const &src);
    virtual ~Squad(void);

    virtual int				getCount(void) const;
    virtual ISpaceMarine	*getUnit(int unit) const;
    virtual int				push(ISpaceMarine* unit);

    Squad					&operator=(Squad const &src);
};

#endif
