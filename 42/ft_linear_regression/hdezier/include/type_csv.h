/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_csv.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/10 19:04:06 by hdezier           #+#    #+#             */
/*   Updated: 2016/08/10 20:17:10 by hdezier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPE_CSV_H
# define TYPE_CSV_H

# include <array>
# include <stdint.h>

namespace type_csv
{
	template<uint8_t NDimension>
	using csv_params = std::array<float, NDimension>;
};

#endif
