/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_set.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/14 12:28:00 by leeios            #+#    #+#             */
/*   Updated: 2016/08/14 21:31:18 by leeios           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPE_SET_H
# define TYPE_SET_H

# include <tuple>
# include <vector>

namespace type_set
{
	template<typename...Ts>
	using t_features = std::tuple<Ts...>;

	template<typename...Ts>
	using t_features_set = std::vector<t_features<Ts...>>;
};

#endif
