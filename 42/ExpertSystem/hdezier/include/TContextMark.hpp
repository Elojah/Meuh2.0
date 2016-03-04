/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TContextMark.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/04 15:34:51 by leeios            #+#    #+#             */
/*   Updated: 2016/03/04 16:04:51 by leeios           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_CONTEXT_MARK_HPP
# define T_CONTEXT_MARK_HPP

# include "IToken.hpp"

class TContextMark : public IToken
{
public:
	TContextMark(void);
	virtual ~TContextMark(void) override;
	virtual eResponse		detect(const std::string &str) const override;
	virtual void			getNextTokens(tok_indexes &mask) const override;
	virtual IToken			*getNewInstance(const std::string &s) const override;
protected:
private:
	static bool				_isCtxMarkSymbol(const char c);
};

#endif
