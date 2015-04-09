// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Span.hpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/15 11:29:38 by erobert           #+#    #+#             //
//   Updated: 2015/01/15 12:21:30 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <algorithm>
# include <stdexcept>
# include <cmath>

class Span
{
private:
	unsigned int		_ui;
	std::vector<int>	_vct;

	Span(void);
public:
	Span(Span const &s);
	Span(unsigned int ui);
	~Span(void);

	Span				&operator=(Span const &s);

	unsigned int		getUI(void) const;
	std::vector<int>	getVct(void) const;

	void				addNumber(int i);
	int					shortestSpan(void) const;
	int					longestSpan(void) const;
};

#endif
