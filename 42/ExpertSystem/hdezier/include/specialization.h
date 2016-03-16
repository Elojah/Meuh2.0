/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specialization.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/13 22:30:24 by leeios            #+#    #+#             */
/*   Updated: 2016/03/16 09:55:26 by leeios           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPECIALIZATION_H
# define SPECIALIZATION_H

#define DECL_INIT(n, name, type)\
	typedef std::integral_constant<int, n>	name;\
	template <typename TypeSpe, typename = int>\
	struct spe_check : name {};\
	static const spe_check<type>	_specialization;\

/**
 * @param n specialization ID
 * @param name type to use for spe
 * @param fn function name to test
 */
#define DECL_SPE(n, name, fn)\
	typedef std::integral_constant<int, n>	name;\
	template <typename TypeSpe>\
	struct spe_check <TypeSpe, decltype((void) TypeSpe::fn, 0)> : name {};\

#endif
