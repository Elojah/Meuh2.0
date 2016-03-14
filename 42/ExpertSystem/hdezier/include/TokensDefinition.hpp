/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TokensDefinition.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 16:34:03 by leeios            #+#    #+#             */
/*   Updated: 2016/03/14 17:36:58 by leeios           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENS_DEFINITION_HPP
# define TOKENS_DEFINITION_HPP

#define TOKEN_STRUCT_WORDS(name)\
	struct		name\
	{\
		name(void) = default;\
		virtual ~name(void) = default;\
		static tLexicon	words;\
	};\

#define TOKEN_STRUCT_DETECT(name, fn)\
	struct		name\
	{\
		name(void) = default;\
		virtual ~name(void) = default;\
		static eResponse		detect(const std::string &str)\
		{\
			fn\
		}\
	};\


# include <string>
# include <vector>

# include "IToken.hpp"

namespace	TokensDefinition
{
	typedef const std::vector<std::string>	tLexicon;

	TOKEN_STRUCT_WORDS(sNegation);
	TOKEN_STRUCT_WORDS(sOperator);
	TOKEN_STRUCT_WORDS(sPriorities);
	TOKEN_STRUCT_WORDS(sOperand);
	TOKEN_STRUCT_DETECT(sContextMark,
	{
		if (str.at(0) == '?' || str.at(0) == '=')
		{
			if (str.size() == 1)
					return (eResponse::OK);
				else if (str.compare("=>") != 0)
					return (eResponse::COMPLETE);
			}
			return (eResponse::NONE);
		}
	);
	TOKEN_STRUCT_DETECT
	(sComment,
	{
		if (str.back() == '\0')
			return (eResponse::COMPLETE);
		if (str.at(0) == '#')
			return (eResponse::OK);
		return (eResponse::NONE);
	}
	);
	TOKEN_STRUCT_DETECT
	(sEntity,
	{
		if (std::isalnum(str.back()))
			return (eResponse::OK);
		else if (std::isalnum(str.at(0)))
			return (eResponse::COMPLETE);
		else
			return (eResponse::NONE);
	}
	);
};

#endif
