/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TComment.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 18:16:13 by leeios            #+#    #+#             */
/*   Updated: 2016/03/03 20:14:17 by leeios           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_COMMENT_HPP
# define T_COMMENT_HPP

#include "IToken.hpp"

class TComment : public IToken
{
public:
	TComment(void);
	virtual ~TComment(void) override;
	virtual eResponse		detect(const std::string &str) const override;
	virtual void			getNextTokens(tok_indexes &mask) const override;
	virtual IToken			*getNewInstance(const std::string &s) const override;
protected:
private:
};

#endif
