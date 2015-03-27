// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Polynomial.hpp                                     :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/25 14:52:51 by erobert           #+#    #+#             //
//   Updated: 2015/03/26 14:03:20 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef POLYNOMIAL_HPP
# define POLYNOMIAL_HPP

# include <iostream>
# include <vector>

# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define BLUE "\033[34m"
# define END "\033[0m"

class Polynomial
{
public:
	Polynomial(void);
	~Polynomial(void);

	void				displayReducedForm(void);
	void				displayDelta(void);
	void				displaySolution(void);
	void				solve(std::vector<float> p);
private:
	std::vector<float>	_vector;
	size_t				_degree;
	double				_delta;
	double				_solution[4];

	Polynomial(Polynomial const &p);

	Polynomial			&operator=(Polynomial const &p);

	void				getDegree(void);
	float				sqrt(float x);
};

#endif
