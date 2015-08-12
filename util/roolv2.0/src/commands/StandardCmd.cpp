/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StandardCmd.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/12 12:13:27 by leeios            #+#    #+#             */
/*   Updated: 2015/08/12 12:39:27 by leeios           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "StandardCmd.hpp"

StandardCmd::StandardCmd(void) {
	;
}

StandardCmd::~StandardCmd(void) {
	;
}

bool		StandardCmd::adhere(const std::string &strCmd) const {
	(void)strCmd;
	return (false);
}

const std::string			StandardCmd::exec(const std::string &strCmd) const {
	(void)strCmd;
	return (std::string());
}
