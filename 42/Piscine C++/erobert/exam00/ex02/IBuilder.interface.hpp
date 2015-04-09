// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   IBuilder.interface.hpp                             :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: exam <marvin@42.fr>                        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/09 20:57:46 by exam              #+#    #+#             //
//   Updated: 2015/01/16 13:19:38 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef I_BUILDER_INTERFACE_HPP
# define I_BUILDER_INTERFACE_HPP

# include "Building.class.hpp"

class IBuilder
{
protected:
	virtual Building	*_buildCommandCenter(int x, int y);
	virtual Building	*_buildBarrack(int x, int y);
	virtual Building	*_buildSupplyDepot(int x, int y);
	virtual Building	*_buildBunker(int x, int y);
public:
	enum building_e
	{
		COMMAND_CENTER = 1,
		BARRACKS,
		SUPPLY_DEPOT,
		BUNKER
	};

	IBuilder(void) {}
	IBuilder(IBuilder const &iB);
	virtual ~IBuilder(void) = 0;

	virtual IBuilder	&operator=(IBuilder const &i) = 0;

	virtual Building	*createBuilding(building_e building, int x, int y) = 0;

};

#endif
