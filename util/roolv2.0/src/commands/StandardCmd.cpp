/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StandardCmd.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/12 12:13:27 by leeios            #+#    #+#             */
/*   Updated: 2015/08/13 21:19:56 by leeios           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "StandardCmd.hpp"
#include "util.hpp"

StandardCmd::StandardCmd(const std::string &path) :
	_path(path) {
}

StandardCmd::~StandardCmd(void) {
	;
}

bool		StandardCmd::adhere(const std::string &strCmd) const {
	(void)strCmd;
	return (true);
}

const std::string			StandardCmd::exec(const std::string &strCmd) const {
	std::string			name(utils::parseClassName(strCmd));
	auto						inheritParents(
		utils::duplicateString("./config/models/inherit_parents.model", utils::parseParents(strCmd))
	);

	if (!inheritParents.empty()) {
		inheritParents.at(0) = ':';
	}
	const std::map<std::string, std::string> map {
		{"${NAME}", name},
		{"${GUARD}", utils::parseGuard(strCmd)},
		{"${INC_PARENTS}", utils::duplicateString("./config/models/inc_parents.model", utils::parseParents(strCmd))},
		{"${INHERIT_PARENTS}", inheritParents}
	};

	utils::touchFileVariables("./config/models/src.model", _path + "/src/" + name + ".cpp", map);
	utils::touchFileVariables("./config/models/inc.model", _path + "/inc/" + name + ".hpp", map);
	return ("New class " + name + " created");
}
