/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CsvLineParser.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/10 18:47:39 by hdezier           #+#    #+#             */
/*   Updated: 2016/09/05 20:13:50 by hdezier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CSV_LINE_PARSER_H
# define CSV_LINE_PARSER_H

# include <iostream>
# include <string>
# include "err.h"
# include "type_csv.h"

template<uint8_t NDimension>
class CsvLineParser
{
public:
	CsvLineParser(void) = default;
	~CsvLineParser(void) = default;

	typedef type_csv::csv_params<NDimension>	local_csv_params;

	inline static e_err		read_csv_line(const std::string &line, local_csv_params &result)
	{
		const size_t	i_final = line.size();
		size_t			i_begin = 0;
		size_t			i_end = line.find(',');
		for (uint8_t i = 0; i < NDimension && i_begin != i_final; ++i)
		{
			if (i_end == std::string::npos)
				i_end = i_final;
			try
			{
				result[i] = std::stod(line.substr(i_begin, i_end - i_begin));
			}
			catch (...)
			{
				return (e_err::BAD_FORMAT_CSV_INT);
			}
			if (i_end == i_final)
			{
				if (i == NDimension - 1)
					return (e_err::NO_ERR);
				else
					return (e_err::BAD_CSV_INT_NUMBER);
			}
			i_begin = i_end + 1;
			i_end = line.find(',', i_begin);
		}
		return (e_err::BAD_CSV_INT_NUMBER);
	}
};

#endif
