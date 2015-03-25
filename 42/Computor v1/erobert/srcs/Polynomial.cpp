// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Polynomial.cpp                                     :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/25 14:58:23 by erobert           #+#    #+#             //
//   Updated: 2015/03/25 19:19:39 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Polynomial.hpp"

Polynomial::Polynomial(void) {};
Polynomial::~Polynomial(void) {};

void								Polynomial::displayReducedForm(void)
{
	std::vector<float>::iterator	ib(_vector.begin());
	std::vector<float>::iterator	it(_vector.end());
	size_t							degree(_vector.size());
	bool							first(true);

	std::cout << "The reduced form is:";
	while(ib != it--)
	{
		degree--;
		if (*it)
		{
			std::cout << " ";
			if (*it >= 0)
			{
				if (!first)
					std::cout << "+ ";
				std::cout << YELLOW << *it << END;
			}
			else
			{
				std::cout << "- ";
				std::cout << YELLOW << -*it << END;
			}
			first = false;
			if (degree)
			{
				std::cout << BLUE << "x" << END;
				if (degree > 1)
					std::cout << "^" << degree;
			}
		}
	}
	if (!_vector[2] && !_vector[1] && !_vector[0])
		std::cout << YELLOW << " 0";
	std::cout << " = " << YELLOW << "0" << END << std::endl;
}
void								Polynomial::displayDelta(void)
{
	std::cout << "The delta is: "
			  << BLUE << _delta << END
			  << std::endl;
}
void								Polynomial::displaySolution(void)
{
	if (!_vector[2] && !_vector[1] && !_vector[0])
		std::cout << "All C is solution." << std::endl;
	else if (_delta > 0)
		std::cout << "The two solutions are: "
				  << GREEN << _solution[0] << END
				  << " and "
				  << GREEN << _solution[1] << END << std::endl;
	else if (_delta < 0)
		std::cout << "The two solutions are: "
				  << GREEN << _solution[0] << END
				  << " + "
				  << BLUE << "i"
				  << GREEN << _solution[1] << END
				  << " and "
				  << GREEN << _solution[0] << END
				  << " + "
				  << BLUE << "i"
				  << GREEN << _solution[1] << END << std::endl;
	else
		std::cout << "The solution is: "
				  << GREEN << _solution[0] << END << std::endl;
}
void								Polynomial::solve(std::vector<float> p)
{
	std::vector<float>::iterator	ib;
	std::vector<float>::iterator	it;

	_vector = p;
	displayReducedForm();
	ib = _vector.begin();
	it = _vector.end();
	ib++;
	ib++;
	while (--it != ib)
	{
		if (*it)
		{
			std::cout << "Can't solve degree superior to 3." << std::endl;
			return ;
		}
	}
	if (!_vector[2])
	{
		_delta = 0;
		_solution[0] = -_vector[0] / _vector[1];
		displaySolution();
		return ;
	}
	_delta = _vector[1] * _vector[1] - 4 * _vector[2] * _vector[0];
	if (_delta > 0)
	{
		_solution[0] = (-_vector[1] + sqrt(_delta)) / (2 * _vector[2]);
		_solution[1] = (-_vector[1] - sqrt(_delta)) / (2 * _vector[2]);
	}
	else if (_delta < 0)
	{
		_solution[0] = -_vector[1] / (2 * _vector[2]);
		_solution[1] = sqrt(-_delta) / (2 * _vector[2]);
	}
	else
		_solution[0] = -_vector[1] / (2 * _vector[2]);
	displayDelta();
	displaySolution();
}

float								Polynomial::sqrt(float x)
{
	int								i(0);
	float							xn;
	float							xn1;

	xn = x;
	while (i++ < 32)
	{	
		xn1 = (xn + x / xn) / 2;
		xn = xn1;
	}
	return (xn1);
}
