/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassMod.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/10 20:13:46 by leeios            #+#    #+#             */
/*   Updated: 2015/08/10 20:35:46 by leeios           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClassMod.hpp"
#include <string.h>
#include <algorithm>

ClassMod::ClassMod(int h, int w, int x, int y) :
	Menu(h, w, x, y) {
}

ClassMod::~ClassMod(void) {
	;
}

void		ClassMod::construct(const std::string &path, const std::string &name) {
	_path = path;
	_name = name;
	simpleCreate(_name);
}

void			ClassMod::sortItems(const int &length) {
	const static auto comp = [](const ITEM *lhs, const ITEM *rhs) -> bool {
		const char *lhsName = item_name(lhs);
		const char *rhsName = item_name(rhs);
		if(strcmp(lhsName, "New class") || !strcmp(rhsName, "Return")) {
			return (false);
		} else if(!strcmp(rhsName, "New project") || strcmp(lhsName, "Return")) {
			return (true);
		} else {
			return (strcmp(lhsName, rhsName) > 0);
		}
	};
	std::sort(_menuItems, _menuItems + length, comp);
}

void			ClassMod::createItems(void) {
	addItem("New class", static_cast<Callback>(&ClassMod::endMenu));
	addItem("Return", static_cast<Callback>(&ClassMod::endMenu));
}
