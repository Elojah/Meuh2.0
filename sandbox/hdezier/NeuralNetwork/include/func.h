/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 15:40:07 by leeios            #+#    #+#             */
/*   Updated: 2017/05/08 17:57:25 by leeios           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNC_H
# define FUNC_H

#include <iostream>
#include <utility>

// FFinal = (fn, type) + (fn, type) + ...

struct	Map {};
struct	Reduce {};
struct	Filter {};
struct	First {};
struct	Takewhile {};
template<unsigned int N>
struct	Take {};
struct	Dropwhile {};
template<unsigned int N>
struct	Drop {};

template<typename...TFns>
class Lazy
{

private:
	// Functor wrapper return -> _Break || _Continue || _Reduced || Value
	enum e_loop_action {
		_Break,
		_Continue,
		_Reduced
	};

public:
	~Lazy() = default;

	template<typename TParam, typename FAcc>
	inline static const auto		eval(const TParam &&p)
	{
		for (const auto &&val : p)
		{
			const auto evaluated_val = Lazy<TFns...>::apply(val);
			switch (evaluated_val)
			{
				case (Lazy::_Break): return (evaluated_val);
				case (Lazy::_Continue): continue;
				default: break ;
			}
		}
	};

	template<typename TResult, typename FunctorType, typename Functor, typename...Ts>
	inline static const TResult		apply(const auto &&acc, const auto &&val) {return (0);};

private:
	explicit Lazy() = default;

	// template<typename TContainer, typename TResult>
	// inline const TResult	eval(TContainer const &&ct) const
	// {
	// 	switch (std::get(1)(TFns[0]))
	// 	{
	// 		case (Map): return TFns[0]()
	// 		case (Reduce)
	// 		case (Filter)
	// 		case (First)
	// 		case (Takewhile)
	// 		case (Dropwhile)
	// 	}
	// }
};

#endif
