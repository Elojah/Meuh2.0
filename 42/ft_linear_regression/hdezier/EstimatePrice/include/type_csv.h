/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_csv.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/10 19:04:06 by hdezier           #+#    #+#             */
/*   Updated: 2016/08/13 21:05:25 by leeios           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPE_CSV_H
# define TYPE_CSV_H

# include <array>
# include <stdint.h>

namespace type_csv
{
	template<uint8_t NDimension>
	using csv_params = std::array<double, NDimension>;
};

#endif
