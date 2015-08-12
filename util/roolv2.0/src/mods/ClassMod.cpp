/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassMod.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/10 20:13:46 by leeios            #+#    #+#             */
/*   Updated: 2015/08/12 12:00:35 by leeios           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClassMod.hpp"
#include "FileDir.hpp"
#include <string.h>
#include <dirent.h>
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
		if(!strcmp(lhsName, "Return") || !strcmp(rhsName, "New class")) {
			return (false);
		} else if(!strcmp(lhsName, "New class") || !strcmp(rhsName, "Return")) {
			return (true);
		} else {
			return (strcmp(lhsName, rhsName) > 0);
		}
	};
	std::sort(_menuItems, _menuItems + length, comp);
}

void			ClassMod::createItems(void) {
	DIR						*dir;
	struct dirent	*ent;
	std::string		value;

	addItem("New class", static_cast<Callback>(&ClassMod::newClass));
	addItem("Return", static_cast<Callback>(&ClassMod::endMenu));
	if ((dir = opendir((_path + "/include").c_str())) == NULL
			&& (dir = opendir((_path + "/inc").c_str())) == NULL) {
		notifyUser("Error opening include directory");
		return ;
	}
	while ((ent = readdir(dir)) != NULL) {
		int				found;

		value = std::string(ent->d_name);
		found = value.find_last_of(".");
		if (value.compare(found + 1, value.size(), "hpp") == 0
			&& !value.substr(0, found).empty()) {
			addItem(value.substr(0, found), static_cast<Callback>(&ClassMod::errorCallback));
		}
	}
	closedir(dir);
}

void		ClassMod::newClass(ITEM *item) {
	std::string	input(readUser());

	(void)item;
	utils::touchFile(_path + "/config/models/src.model", _path + "/src/" + input + ".cpp");
	utils::touchFile(_path + "/config/models/inc.model", _path + "/inc/" + input + ".hpp");
}
