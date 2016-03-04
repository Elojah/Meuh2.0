/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TOperand.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/04 15:25:31 by leeios            #+#    #+#             */
/*   Updated: 2016/03/04 15:26:54 by leeios           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_OPERAND_HPP
# define T_OPERAND_HPP

# include "IToken.hpp"

class TOperand : public IToken
{
public:
	TOperand(void);
	virtual ~TOperand(void) override;
	virtual eResponse		detect(const std::string &str) const override;
	virtual void			getNextTokens(tok_indexes &mask) const override;
	virtual IToken			*getNewInstance(const std::string &s) const override;
protected:
private:
};

#endif
