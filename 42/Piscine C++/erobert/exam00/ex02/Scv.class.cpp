// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Scv.class.cpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: exam <marvin@42.fr>                        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/09 21:14:21 by exam              #+#    #+#             //
//   Updated: 2015/01/16 13:42:13 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Scv.class.hpp"

Scv::Scv(void):
	Unit("SCV T-280", 0, 0, 5, 60, 60)
{
	std::cout << "Unit #" << _index << ": SCV good to go, sir." <<std::endl;
}
Scv::Scv(Scv const &s):
	Unit(s),
	IBuilder()
{
	*this = s;
	std::cout << "Unit #" << _index << ": SCV good to go, sir." <<std::endl;
}
Scv::Scv(int const x, int const y):
	Unit("SCV T-280", x, y, 5, 60, 60)
{
	std::cout << "Unit #" << _index << ": SCV good to go, sir." <<std::endl;
}
Scv::~Scv(void)
{
	std::cout << "Unit #" << _index << ": SCV good to go, sir." <<std::endl;
}

Scv				&Scv::operator=(Scv const &s)
{
	if (this != &s)
	{
		;
	}
	return (*this);
}

void			Scv::die(void)
{
	_cHP = 0;
	std::cout << "Unit #" << _index << ": * noise of an exploding SCV *." <<std::endl;
}
void			Scv::move(int x, int y)
{
	std::cout << "Unit #" << _index << " (" << _type
			  << ") is moving from " << _x << "/" << _y
			  << " to " << x << "/" << y << "." << std::endl;
	std::cout << "Unit #" << _index << ": Affirmative." <<std::endl;
	_x = x;
	_y = y;
}
void			Scv::gatherRessources(Ressource &rsrc)
{
	if (rsrc.isDepleted() || _rn)
		return ;
	if (_x != rsrc.getX() || _y != rsrc.getY())
		move(rsrc.getX(), rsrc.getY());
	_rn = rsrc.gather();
	_rt = rsrc.type;
	std::cout << "Unit #" << _index;
	std::cout << " (" << _rt << ") gathered ";
	std::cout << _rn << " " << rsrc.type << "." << std::endl;
}
void			Scv::returnRessources(CommandCenter &cc)
{
	if (_x != cc.getX() && _y != cc.getY())
		move(cc.getX(), cc.getY());
	cc.acceptRessources(_rt, _rn);
}
Building		*Scv::_buildCommandCenter(int x, int y)
{
	std::cout << "Unit #" << _index << ": Command center finished, sir."
			  << std::endl;
	return (new CommandCenter(x, y));
}
Building		*Scv::_buildBarrack(int x, int y)
{
	std::cout << "Unit #" << _index << ": Barrack finished, sir."
			  << std::endl;
	return (new Barracks(x, y));
}
Building		*Scv::_buildSupplyDepot(int x, int y)
{
	std::cout << "Unit #" << _index << ": Supply depot finished, sir."
			  << std::endl;
	return (new SupplyDepot(x, y));
}
Building		*Scv::_buildBunker(int x, int y)
{
	std::cout << "Unit #" << _index << ": Bunker finished, sir."
			  << std::endl;
	return (new Bunker(x, y));
}

Building		*Scv::createBuilding(building_e building, int x, int y)
{
	scvBld		fcts[4] = {
		&Scv::_buildCommandCenter,
		&Scv::_buildBarrack,
		&Scv::_buildSupplyDepot,
		&Scv::_buildBunker
	};

	if (building < 1 || building > 4)
	{
		std::cout << "Unit #" << _index << ": No such building, sir." 
				  << std::endl;
		return (NULL);
	}
//	return (NULL);
	return ((this->*(fcts[building - 1]))(x, y));
}
