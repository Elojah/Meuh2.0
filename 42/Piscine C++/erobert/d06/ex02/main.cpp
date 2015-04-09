// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/13 15:35:00 by erobert           #+#    #+#             //
//   Updated: 2015/01/13 16:21:01 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <cstdlib>
#include <ctime>
#include <iostream>

class Base
{
public:
	virtual ~Base(void) {}
};
class A: public Base
{
public:
	virtual ~A(void) {}
};

class B: public Base
{
public:
	virtual ~B(void) {}
};

class C: public Base
{
public:
	virtual ~C(void) {}
};

Base		*generate(void)
{
	int		i(0);

	std::srand(clock());
	i = std::rand() % 3;
	if (!i)
	{
		std::cout << "A created" << std::endl;
		return (new A());
	}
	if (i == 1)
	{
		std::cout << "B created" << std::endl;
		return (new B());
	}
	else
	{
		std::cout << "C created" << std::endl;
		return (new C());
	}
}

void		identify_from_pointer(Base *p)
{
	if (dynamic_cast<A *>(p) != NULL)
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B *>(p) != NULL)
		std::cout << "B" << std::endl;
	else
		std::cout << "C" << std::endl;
}
void		identify_from_reference(Base &p)
{
	try
	{
		dynamic_cast<A &>(p);
		std::cout << "A" << std::endl;
	}
	catch (std::exception &e)
	{
		try
		{
			dynamic_cast<B &>(p);
			std::cout << "B" << std::endl;
		}
		catch (std::exception &e)
		{std::cout << "C" << std::endl;}
	}
}

int			main(void)
{
	Base	*p;

	std::cout << "------------------" << std::endl;
	p = generate();
	std::cout << "From ptr: ";
	identify_from_pointer(p);
	std::cout << "From ref: ";
	identify_from_reference(*p);
	delete p;
	std::cout << "------------------" << std::endl;
	p = generate();
	std::cout << "From ptr: ";
	identify_from_pointer(p);
	std::cout << "From ref: ";
	identify_from_reference(*p);
	delete p;
	std::cout << "------------------" << std::endl;
	p = generate();
	std::cout << "From ptr: ";
	identify_from_pointer(p);
	std::cout << "From ref: ";
	identify_from_reference(*p);
	delete p;
	std::cout << "------------------" << std::endl;
	p = generate();
	std::cout << "From ptr: ";
	identify_from_pointer(p);
	std::cout << "From ref: ";
	identify_from_reference(*p);
	delete p;
	return (0);
}
