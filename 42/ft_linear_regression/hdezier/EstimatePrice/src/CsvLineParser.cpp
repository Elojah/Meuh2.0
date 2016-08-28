/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CsvLineParser.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/10 18:47:47 by hdezier           #+#    #+#             */
/*   Updated: 2016/08/14 12:19:46 by leeios           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CsvLineParser.h"

template<uint8_t NDimension>
e_err		CsvLineParser<NDimension>::read_csv_line(const std::string &line, local_csv_params &result)
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

template class CsvLineParser<2>;
