// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Scv.class.hpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: exam <marvin@42.fr>                        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/09 20:59:53 by exam              #+#    #+#             //
//   Updated: 2015/01/16 13:31:40 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef SCV_CLASS_HPP
# define SCV_CLASS_HPP

#include <string>
#include <iostream>
#include "IBuilder.interface.hpp"
#include "Ressource.class.hpp"
#include "CommandCenter.class.hpp"
#include "Barracks.class.hpp"
#include "SupplyDepot.class.hpp"
#include "Bunker.class.hpp"
#include "Unit.class.hpp"

class Scv: 
	public Unit,
	public IBuilder
{
private:
	int					_rn;
	Ressource::type_e	_rt;

protected:
	virtual Building	*_buildCommandCenter(int x, int y);
	virtual Building	*_buildBarrack(int x, int y);
	virtual Building	*_buildSupplyDepot(int x, int y);
	virtual Building	*_buildBunker(int x, int y);

public:
	typedef Building	*(Scv::*scvBld)(int x, int y);

	Scv(void);
	Scv(Scv const &s);
	Scv(int const x, int const y);
	virtual ~Scv(void);

	virtual Scv			&operator=(Scv const &s);

	virtual void		die(void);
	virtual void		move(int x, int y);
	virtual Building	*createBuilding(building_e building, int x, int y);
	void				gatherRessources(Ressource &ressource);
	void				returnRessources(CommandCenter &cc);
};

#endif
