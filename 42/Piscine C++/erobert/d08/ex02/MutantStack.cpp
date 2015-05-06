// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   MutantStack.cpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/15 15:10:11 by erobert           #+#    #+#             //
//   Updated: 2015/01/15 18:36:17 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "MutantStack.hpp"

template<typename T>
MutantStack<T>::MutantStack(void)
{
	MutantStack::iterator = 0;
}
template<typename T>
MutantStack<T>::MutantStack(MutantStack const &mS)
{
	MutantStack::iterator = 0;
}
template<typename T>
MutantStack<T>::~MutantStack(void) {}
/*
template<typename T>
MutantStack			&MutantStack<T>::operator=(MutantStack const &mS)
{
	return (*this);
	}*/
template<typename T>
bool				&MutantStack<T>::operator==(MutantStack const &rhs)
{
	return (_s == rhs.getS());
}
template<typename T>
bool				&MutantStack<T>::operator!=(MutantStack const &rhs)
{
	return (_s != rhs.getS());
}
template<typename T>
bool				&MutantStack<T>::operator<(MutantStack const &rhs)
{
	return (_s < rhs.getS());
}
template<typename T>
bool				&MutantStack<T>::operator<=(MutantStack const &rhs)
{
	return (_s <= rhs.getS());
}
template<typename T>
bool				&MutantStack<T>::operator>(MutantStack const &rhs)
{
	return (_s > rhs.getS());
}
template<typename T>
bool				&MutantStack<T>::operator>=(MutantStack const &rhs)
{
	return (_s >= rhs.getS());
}

template<typename T>
std::stack<T, std::list<T> >	&MutantStack<T>::getS(void) const
{
	return (_s);
}

template<typename T>
bool				MutantStack<T>::empty(void) const
{
	return (_s.empty());
}
template<typename T>
size_t				MutantStack<T>::size(void) const
{
	return (_s.size());
}
template<typename T>
T								&MutantStack<T>::top(void)
{
	return (_s.top());
}
template<typename T>
T const				&MutantStack<T>::top(void) const
{
	return (_s.top());
}
template<typename T>
void				MutantStack<T>::push(T const &val)
{
	_s.push(val);
}
template<typename T>
void				MutantStack<T>::pop(void)
{
	_s.pop();
}
