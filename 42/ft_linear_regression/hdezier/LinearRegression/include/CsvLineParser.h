/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CsvLineParser.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/10 18:47:39 by hdezier           #+#    #+#             */
/*   Updated: 2016/08/27 18:51:47 by hdezier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CSV_LINE_PARSER_H
# define CSV_LINE_PARSER_H

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

	static e_err		read_csv_line(const std::string &line, local_csv_params &result);
};

#endif
