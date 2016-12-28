/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/17 14:05:52 by leeios            #+#    #+#             */
/*   Updated: 2016/12/28 13:26:56 by leeios           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

#include <iostream>


namespace Feature
{
	class	Test
	{
	public:
		inline explicit Test(int value) {std::cerr << "Constructed with value " << value << std::endl;m_value = value;};
		inline Test(void) : m_value(-1) {std::cerr << "Constructed" << std::endl;};
		inline Test(Test &&rhs) {m_value = std::move(rhs.m_value);std::cerr << "Copy by rvalue" << std::endl;};
		inline Test(const Test &&rhs) {m_value = std::move(rhs.m_value);std::cerr << "Copy by const rvalue" << std::endl;};
		inline Test(Test &rhs) {m_value = rhs.m_value;std::cerr << "Copy by reference" << std::endl;};
		inline Test(const Test &rhs) {m_value = rhs.m_value;std::cerr << "Copy by const reference" << std::endl;};
		inline ~Test(void) {std::cerr << "Destructed" << std::endl;};

		inline Test&	operator=(const Test &rhs)
		{
			m_value = rhs.get();
			return (*this);
		};
		// inline Test&	operator=(Test &&rhs)
		// {
		// 	m_value = rhs.get();
		// 	return (*this);
		// };
		inline Test		operator+(const Test &rhs) const {std::cerr << m_value << " + " << rhs.get() << std::endl;return (Test(m_value + rhs.get()));};
		inline Test		operator-(const Test &rhs) const {std::cerr << m_value << " - " << rhs.get() << std::endl;return (Test(m_value - rhs.get()));};
		inline Test		operator*(const Test &rhs) const {std::cerr << m_value << " * " << rhs.get() << std::endl;return (Test(m_value * rhs.get()));};
		inline bool		operator==(const int &rhs) const {return (m_value == rhs);};
		inline bool		operator==(const Test &rhs) const {return (m_value == rhs.m_value);};
		inline operator	float(void) {return (m_value);};
		// inline int		operator*(const Test &rhs) const {return (m_value * rhs.get());};

		inline int	get(void) const {return (m_value);};
		// inline void	set(int value) {m_value = value;};
	private:
		int		m_value;
	};
};
inline std::ostream& operator<<(std::ostream& stream, const Feature::Test& test) {stream << test.get(); return (stream);};


// int i0, double d0
// *
// int i1, int i2
// double d1, double d2
// =
// i0 * i1 + d0 * d1, i0 * i2 + d0 * d2

#endif
