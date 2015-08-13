/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StandardCmd.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/12 12:13:27 by leeios            #+#    #+#             */
/*   Updated: 2015/08/13 16:54:40 by leeios           ###   ########.fr       */
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

const std::string			StandardCmd::exec(const std::string &strCmd) {
	std::map<std::string, std::string> map{
		{"${NAME}", utils::parseClassName(strCmd)},
		{"${GUARD}", utils::parseGuard(strCmd)}
	};

	utils::touchFileVariables("./config/models/src.model", _path + "/src/" + strCmd + ".cpp", map);
	utils::touchFileVariables("./config/models/inc.model", _path + "/inc/" + strCmd + ".hpp", map);
	return ("New class " + strCmd + " created");
}
