/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TPriorities.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/04 16:14:52 by leeios            #+#    #+#             */
/*   Updated: 2016/03/04 16:15:11 by leeios           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_PRIORITIES_HPP
# define T_PRIORITIES_HPP

# include "IToken.hpp"

class TPriorities : public IToken
{
public:
	TPriorities(void);
	virtual ~TPriorities(void);
	virtual eResponse		detect(const std::string &str) const override;
	virtual void			getNextTokens(tok_indexes &mask) const override;
	virtual IToken			*getNewInstance(const std::string &s) const override;
protected:
private:
	static bool				_isPrioritySymbol(const char c);
};

#endif
