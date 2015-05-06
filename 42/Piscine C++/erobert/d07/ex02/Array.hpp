// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Array.hpp                                          :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/14 11:26:53 by erobert           #+#    #+#             //
//   Updated: 2015/01/14 14:16:30 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>
#include <stdexcept>

template<typename T = void *>
class Array
{
private:
	T				*_a;
	unsigned int	_size;
public:
	Array<T>(void):
		_size(0)
	{
		_a = new T[0];
	}
	Array<T>(Array<T> const &a)
	{
		int			i(-1);
		
		_size = a.size();
		_a = new T[_size];
		while (++i < _size)
			_a[i] = a[i];
	}
	Array<T>(unsigned int ui):
		_size(ui)
	{
		_a = new T[_size];
	}
	~Array<T>(void)
	{
		delete [] _a;
	}

	Array<T>			&operator=(Array<T> const &a)
	{
		unsigned int	i(-1);
		
		_size = a.size();
		delete [] _a;
		_a = new T[_size];
		while (++i < _size)
			_a[i] = a[i];
		return (*this);
	}
	T					&operator[](unsigned int ui) const
	{
		if (ui >= _size)
			throw std::out_of_range("out of range");
        return (_a[ui]);
	}	

	unsigned int		size(void) const
	{
		return (_size);
	}
};
