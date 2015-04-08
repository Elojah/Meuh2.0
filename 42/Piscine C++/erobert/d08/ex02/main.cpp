// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/15 14:07:21 by erobert           #+#    #+#             //
//   Updated: 2015/01/15 18:55:45 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <list>
#include <iostream>
#include "MutantStack.hpp"

int								main(void)
{
	MutantStack<int>			mstack;

	mstack.push(5);
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.top() << std::endl;
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	MutantStack<int>::iterator	it = mstack.begin();
	MutantStack<int>::iterator	ite = mstack.end();
//	std::list<int>::iterator	it = mstack.begin();
//	std::list<int>::iterator		ite = mstack.end();

	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
//	std::stack<int> s(mstack);
	return (0);
}
