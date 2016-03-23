/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TokensDefinition.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 16:34:03 by leeios            #+#    #+#             */
/*   Updated: 2016/03/14 17:41:52 by leeios           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "TokensDefinition.hpp"

namespace TokensDefinition
{
	tLexicon	sNegation::words =
	{
		"!"
	};
	tLexicon	sOperand::words =
	{
		"=>", "<=>"
	};
	tLexicon	sOperator::words =
	{
		"+", "|", "^"
	};
	tLexicon	sPriorities::words =
	{
		"(", ")"
	};

};
