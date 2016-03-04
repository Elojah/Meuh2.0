/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TOperator.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/04 15:25:15 by leeios            #+#    #+#             */
/*   Updated: 2016/03/04 15:44:47 by leeios           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_OPERATOR_HPP
# define T_OPERATOR_HPP

# include "IToken.hpp"

class TOperator : public IToken
{
public:
	TOperator(void);
	virtual ~TOperator(void) override;
	virtual eResponse		detect(const std::string &str) const override;
	virtual void			getNextTokens(tok_indexes &mask) const override;
	virtual IToken			*getNewInstance(const std::string &s) const override;
protected:
private:
	static bool			_isOperatorSymbol(const char c);
};

#endif
