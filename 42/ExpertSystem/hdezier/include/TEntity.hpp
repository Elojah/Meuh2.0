/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TEntity.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 18:16:21 by leeios            #+#    #+#             */
/*   Updated: 2016/03/03 20:14:30 by leeios           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_ENTITY_HPP
# define T_ENTITY_HPP

#include "IToken.hpp"

class TEntity : public IToken
{
public:
	TEntity(void);
	virtual ~TEntity(void) override;
	virtual eResponse		detect(const std::string &str) const override;
	virtual void			getNextTokens(tok_indexes &mask) const override;
	virtual IToken			*getNewInstance(const std::string &s) const override;
protected:
private:
};

#endif
