// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   MutantStack.hpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/15 13:35:33 by erobert           #+#    #+#             //
//   Updated: 2015/01/15 19:27:35 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef MUTANT_STACK_HPP
# define MUTANT_STACK_HPP

# include <iterator>
# include <list>
# include <stack>

template<typename T>
class MutantStack: public std::stack<T, std::list<T> >
{
private:
//	std::stack<T, std::list<T> >	*_s;
//	size_t							_size;
//	std::list
/*public:
	MutantStack(void)
	{
		_s = this;
		_size = this->size();
	}
	MutantStack(MutantStack const &mS)
	{
		*this = mS;
	}
	~MutantStack(void) {}
*/
//	MutantStack		&operator=(MutantStack const &mS);
/*	bool			&operator==(MutantStack const &rhs);
	bool			&operator!=(MutantStack const &rhs);
	bool			&operator<(MutantStack const &rhs);
	bool			&operator<=(MutantStack const &rhs);
	bool			&operator>(MutantStack const &rhs);
	bool			&operator>=(MutantStack const &rhs);

	std::stack<T, std::list<T> >		&getS(void) const;

	bool				empty(void) const;
	size_t				size(void) const;
	T					&top(void);
	T const				&top(void) const;
	void				push(T const &val);
	void				pop(void);*/
public:
	class iterator//:
	//		public std::iterator<std::input_iterator_tag, std::list<T> >
	{
	private:
		MutantStack	*_ptr;
	public:
		iterator(void) {}
		iterator(iterator const &i)
		{
			*this = i;
		}
		iterator(MutantStack *ptr):
			_ptr(ptr)
		{
			std::cout << ptr << std::endl;
		}
		~iterator(void) {}

		iterator		operator++(void)
		{
			iterator	i(*this);

//			_ptr->pop();
			_ptr++;
			return (i);
		}
		iterator		operator--(void)
		{
			iterator	i(*this);

			_ptr--;
			return (i);
		}
		T				&operator*(void)
//		int		operator*(void)
		{
//			return (1);
			return (_ptr->top());
		}
		bool			operator==(const iterator &rhs)
		{
			return (_ptr == rhs._ptr);
		}
		bool			operator!=(const iterator &rhs) 
		{
			return (_ptr != rhs._ptr);
		}
	};

	iterator						begin()
	{
		MutantStack<T>::iterator	i(this);

		return (i);
	}
	iterator						end()
	{
		MutantStack<T>::iterator	i(this + this->size());

		return (i);
	}
};

#endif
