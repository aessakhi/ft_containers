/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessakhi <aessakhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 17:58:54 by aessakhi          #+#    #+#             */
/*   Updated: 2023/01/15 20:20:39 by aessakhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP

#include "vector.hpp"

//Pretty easy to do since stack calls on the underlying container

namespace ft
{
	template <class T, class Container = ft::vector<T> >
	class stack
	{
		template<class T1, class Container1>
		friend bool operator==(const stack<T1, Container1>&, const stack<T1, Container1>&);

		template<class T1, class Container1>
		friend bool operator<(const stack<T1, Container1>&, const stack<T1, Container1>&);

	public:

		typedef Container							container_type;
		typedef typename Container::value_type		value_type;
		typedef typename Container::size_type		size_type;
		typedef typename Container::reference		reference;
		typedef typename Container::const_reference	const_reference;

		explicit stack(const container_type& ctnr = container_type()): c(ctnr){};

		/* Capacity */

		bool empty() const
		{
			return (this->c.empty());
		};

		size_type size() const
		{
			return (this->c.size());
		}

		/* Element access */

		reference top()
		{
			return (this->c.back());
		};

		const reference top() const
		{
			return (this->c.back());
		};

		/* Modifiers */

		void push(const value_type& value)
		{
			this->c.push_back(value);
		};

		void pop()
		{
			this->c.pop_back();
		};


	protected:

		Container	c;
	};

	template <class T, class Container>
	bool operator==(const stack<T, Container>& lhs, const stack<T, Container>& rhs)
	{
		return (lhs.c == rhs.c);
	};

	template <class T, class Container>
	bool operator!=(const stack<T, Container>& lhs, const stack<T, Container>& rhs)
	{
		return !(lhs == rhs);
	}

	template <class T, class Container>
	bool operator<(const stack<T, Container>& lhs, const stack<T, Container>& rhs)
	{
		return (lhs.c < rhs.c);
	}

	template <class T, class Container>
	bool operator<=(const stack<T, Container>& lhs, const stack<T, Container>& rhs)
	{
		return !(rhs < lhs);
	}

	template <class T, class Container>
	bool operator>(const stack<T, Container>& lhs, const stack<T, Container>& rhs)
	{
		return (rhs < lhs);
	}

	template <class T, class Container>
	bool operator>=(const stack<T, Container>& lhs, const stack<T, Container>& rhs)
	{
		return !(lhs < rhs);
	};
} // namespace ft


#endif
