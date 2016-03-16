/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IExpr.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 11:05:28 by leeios            #+#    #+#             */
/*   Updated: 2016/03/16 11:08:23 by leeios           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef I_EXPR_HPP
# define I_EXPR_HPP


class IExpr
{
public:
	virtual ~IExpr(void) {}
	virtual bool	eval(void) const = 0;
protected:
private:
};

#endif
