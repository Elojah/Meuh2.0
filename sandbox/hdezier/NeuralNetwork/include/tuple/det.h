/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   det.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 13:15:42 by leeios            #+#    #+#             */
/*   Updated: 2017/01/15 17:39:07 by leeios           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TUPLE_DET_H
# define TUPLE_DET_H

namespace tuple
{
	/*
	a b c
	d e f
	g h i
	a * e * i
	*/
	template<typename Tuple, typename TDet>
	const TDet			det(Tuple const&& t)
	{
		;
	}
};


#endif
