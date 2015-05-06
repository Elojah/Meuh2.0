// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Squad.cpp                                          :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/09 17:03:21 by erobert           #+#    #+#             //
//   Updated: 2015/01/09 17:14:00 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Squad.hpp"

Squad::Squad(void): 
	_count(0),
	_units(NULL)
{
}

Squad::~Squad(void)
{
    for (int i = 0; i < _count; i++)
	{
        delete _units[i];
    }
    delete []_units;
}

Squad::Squad(Squad const &s)
{
    *this = s;
}

Squad			&Squad::operator=(Squad const &s)
{
	if (this != &s)
	{
		for (int i = 0; i < _count; i++)
		{
			delete _units[i];
		}
		_count = s.getCount();
		_units = new ISpaceMarine*[_count];
		for (int i = 0; i < _count; i++)
		{
			_units[i] = s.getUnit(i);
		}
	}
	return (*this);
}

int				Squad::getCount(void) const
{
    return _count;
}
ISpaceMarine	*Squad::getUnit(int unit) const
{
    return _units[unit];
}

int				Squad::push(ISpaceMarine *unit)
{
    ISpaceMarine **tmp;

    tmp = new ISpaceMarine*[_count + 1];
    if (_count == 0)
	{
        tmp[0] = unit;
    }
	else
	{
        std::copy(_units, _units + _count, tmp);
        tmp[_count] = unit;
    }
    if (_units != NULL)
        delete [] _units;
    _units = tmp;
    _count += 1;
    return _count;
}
