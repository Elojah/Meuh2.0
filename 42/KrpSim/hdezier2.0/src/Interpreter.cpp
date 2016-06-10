/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Interpreter.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/14 16:50:10 by leeios            #+#    #+#             */
/*   Updated: 2016/06/10 02:48:16 by leeios           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Interpreter.h"
#include "JobShopManager.h"

#include <iostream>
#include <tuple>
#include <utility>

template<class T>
Interpreter<T>::Interpreter(T &job_shop_manager)
	: m_job_shop_manager(job_shop_manager)
{
}

template<class T>
e_err		Interpreter<T>::read_line(const std::string &line, const bool quickExit)
{
	(void)quickExit;
	const auto	commentDelim(line.find_first_of(COMMENT_DELIM));
	if (commentDelim != std::string::npos)
		return (_read_resource_name(line.substr(0, commentDelim)));
	else
		return (_read_resource_name(line));
}

template<class T>
e_err		Interpreter<T>::_read_resource_name(const std::string &line)
{
	if (line.empty())
		return (e_err::NONE);
	const auto	firstDelim(line.find_first_of(FIRST_DELIM));
	if (firstDelim == std::string::npos)
		return (e_err::RESOURCE_NAME_NOT_FOUND);
	const auto resource_name = line.substr(0, firstDelim);
	if (resource_name.compare("optimize") == 0)
	{
		m_job_shop_manager.print_tasks();
		return (e_err::TODO);
	}
	return (_read_resource_attributes(resource_name, line.substr(firstDelim + 1)));
}

template<class T>
e_err	Interpreter<T>::_read_resource_attributes(const std::string &resource_name, const std::string &line)
{
	// Initial resource
	auto	isNumber(line.find_first_not_of(DIGITS) == std::string::npos);
	if (isNumber)
		return (m_job_shop_manager.set_initial_resources(resource_name
			, std::stoull(line.substr().c_str())));

	// Needs for task
	auto	openParenthesisNeed = line.find_first_of('(');
	auto	closeParenthesisNeed = line.find_first_of(')');
	if (line.at(0) == CURRENT_DELIM)
	{
		openParenthesisNeed = 0;
		closeParenthesisNeed = 0;
	}
	else if (openParenthesisNeed == std::string::npos
		|| openParenthesisNeed != 0
		|| closeParenthesisNeed == std::string::npos
		|| closeParenthesisNeed == line.size() - 1
		|| closeParenthesisNeed < openParenthesisNeed
		|| line.at(closeParenthesisNeed + 1) != CURRENT_DELIM)
		return (e_err::TASK_DEFINITION_SYNTAX_NEED);

	// Products for task
	auto		openParenthesisProduct = line.find_first_of('(', closeParenthesisNeed + 1);
	auto		closeParenthesisProduct = line.find_first_of(')', closeParenthesisNeed + 1);
	if (line.at(closeParenthesisNeed + 2) == CURRENT_DELIM
		|| (openParenthesisNeed == closeParenthesisNeed
			&& line.at(closeParenthesisNeed + 1) == CURRENT_DELIM))
	{
		openParenthesisProduct = closeParenthesisNeed + 1;
		closeParenthesisProduct = closeParenthesisNeed + 1;
	}
	else if (openParenthesisProduct == std::string::npos
		|| closeParenthesisProduct == std::string::npos
		|| closeParenthesisProduct == line.size() - 1
		|| closeParenthesisProduct < openParenthesisProduct
		|| line.at(closeParenthesisProduct + 1) != CURRENT_DELIM)
		return (e_err::TASK_DEFINITION_SYNTAX_PRODUCT);

	// Time for task
	isNumber = (line.find_first_not_of(DIGITS, closeParenthesisProduct + 2) == std::string::npos);
	if (!isNumber)
		return (e_err::TASK_DEFINITION_SYNTAX_TIME);

	auto		needs = _str_to_resource(openParenthesisNeed == closeParenthesisNeed ? "" :
		line.substr(openParenthesisNeed + 1, closeParenthesisNeed - openParenthesisNeed - 1));
	auto		products = _str_to_resource(openParenthesisProduct == closeParenthesisProduct ? "" :
		line.substr(openParenthesisProduct + 1, closeParenthesisProduct - openParenthesisProduct - 1));

	if (std::get<0>(needs) != e_err::NONE)
		return (std::get<0>(needs));
	if (std::get<0>(products) != e_err::NONE)
		return (std::get<0>(products));

	return (m_job_shop_manager.add_task(resource_name
		, std::get<1>(needs)
		, std::get<1>(products)
		, std::stoll(line.substr(closeParenthesisProduct + 2))
		));
}

template<class T>
const std::tuple<e_err, t_resource_pack_token>	Interpreter<T>::_str_to_resource(const std::string &s) const
{
	std::vector<t_resource_number>	result;

	if (s.empty())
		return(std::make_tuple(e_err::NONE, result));
	size_t	startRes(0);
	auto	endRes(s.find_first_of(RES_SEPARATOR));
	while (startRes != std::string::npos)
	{
		const auto resource_def = _set_resource_number(s.substr(startRes
			, endRes != std::string::npos ? endRes - startRes : s.size()));
		if (std::get<0>(resource_def) != e_err::NONE)
			return (std::make_tuple(std::get<0>(resource_def), result));
		result.push_back(std::get<1>(resource_def));
		if (endRes == std::string::npos)
			startRes = std::string::npos;
		else
		{
			startRes = endRes + 1;
			endRes = s.find_first_of(RES_SEPARATOR, endRes + 1);
		}
	}

	return(std::make_tuple(e_err::NONE, result));
}

template<class T>
const std::tuple<e_err, t_resource_number>	Interpreter<T>::_set_resource_number(const std::string &s) const
{
	const auto	separator(s.find_first_of(CURRENT_DELIM));

	if (separator == std::string::npos
		|| s.find_first_not_of(DIGITS, separator + 1) != std::string::npos)
		return (std::make_tuple(
						e_err::RESOURCE_DEFINITION,
						std::make_tuple("", 0)
					)
				);
	return (std::make_tuple(
					e_err::NONE,
					std::make_tuple(s.substr(0, separator), std::stoull(s.substr(separator + 1)))
				)
			);
}

template class Interpreter<JobShopManager>;
