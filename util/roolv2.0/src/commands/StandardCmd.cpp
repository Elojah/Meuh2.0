/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StandardCmd.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/12 12:13:27 by leeios            #+#    #+#             */
/*   Updated: 2015/08/12 14:01:23 by leeios           ###   ########.fr       */
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
	utils::touchFile(_path + "/config/models/src.model", _path + "/src/" + strCmd + ".cpp");
	utils::touchFile(_path + "/config/models/inc.model", _path + "/inc/" + strCmd + ".hpp");
	return (std::string("ok ok"));
}
