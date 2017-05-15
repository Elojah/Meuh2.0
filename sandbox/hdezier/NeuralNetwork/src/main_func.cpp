/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_func.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 16:09:31 by leeios            #+#    #+#             */
/*   Updated: 2017/05/08 17:13:26 by leeios           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "func.h"
#include <vector>
#include <tuple>

struct add_one
{
	template<typename Tparam>
	const auto operator()(const Tparam &&n) {return (n + 1);}
};

struct inf_4
{
	template<typename Tparam>
	const bool operator()(const Tparam &&n) {return (n < 4);}
};

int		main(void)
{
	std::vector<int> vec_test = {
		1, 2, 3, 4, 5, 6
	};
	const auto lazy_test = Lazy<
		Map, add_one,
		Filter, inf_4
	>::eval(std::move(vec_test));
	return (0);
}
