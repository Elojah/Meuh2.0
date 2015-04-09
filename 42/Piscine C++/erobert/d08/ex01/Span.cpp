// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Span.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/15 11:36:32 by erobert           #+#    #+#             //
//   Updated: 2015/01/15 13:32:30 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Span.hpp"

Span::Span(Span const &s)
{
	*this = s;
}
Span::Span(unsigned int ui):
	_ui(ui),
	_vct()
{
}
Span::~Span(void) {}

Span					&Span::operator=(Span const &s)
{
	if (this != &s)
	{
		_ui = s.getUI();
		_vct = s.getVct();
	}
	return (*this);
}

unsigned int			Span::getUI(void) const
{
	return (_ui);
}
std::vector<int>		Span::getVct(void) const
{
	return (_vct);
}

void					Span::addNumber(int i)
{
	if (_vct.size() >= _ui)
		throw std::out_of_range("out of range");
	else
		_vct.push_back(i);
}
int						Span::shortestSpan(void) const
{
	std::vector<int>	tmp(_vct);
	unsigned int		i(0);
	int					span;

	std::sort(tmp.begin(), tmp.end());
//	tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());
	if (tmp.size() < 2)
		throw std::logic_error("less than two number");
	else
		span = abs(tmp[0] - tmp[1]);
	while (++i + 1 < tmp.size()) 
	{
		if (abs(tmp[i] - tmp[i + 1]) < span)
			span = abs(tmp[i] - tmp[i + 1]);
	}
	return (span);
}
int						Span::longestSpan(void) const
{
	int		min;
	int		max;

	if (_vct.size() < 2)
		throw std::logic_error("less than two number");
	min = *min_element(_vct.begin(), _vct.end());
	max = *max_element(_vct.begin(), _vct.end());
	return (abs(max - min));
}
