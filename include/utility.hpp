/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessakhi <aessakhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 02:19:57 by aessakhi          #+#    #+#             */
/*   Updated: 2023/01/16 21:21:15 by aessakhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILITY_HPP
# define UTILITY_HPP

namespace ft
{
	template <class T1, class T2>
	struct pair
	{
		/* Member types */
		typedef T1	first_type;
		typedef T2	second_type;

		/* Member variables */
		first_type	first;
		second_type	second;

		pair(): first(), second(){};

		template <class U1, class U2>
		pair(const pair<U1, U2>& p): first(p.first), second(p.second){};

		pair(const T1& x, const T2& y): first(x), second(y){};

		pair& operator=(const pair& other)
		{
			first = other.first;
			second = other.second;
			return (*this);
		};
	};

	template <class T1, class T2>
	bool operator==(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs)
	{
		return (lhs.first == rhs.first && lhs.second == rhs.second);
	};

	template <class T1, class T2>
	bool operator!=(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs)
	{
		return !(lhs == rhs);
	};

	template <class T1, class T2>
	bool operator<(const pair <T1, T2>& lhs, const pair<T1, T2>& rhs)
	{
		return (lhs.first < rhs.first || (!(rhs.first < lhs.first) && lhs.second < rhs.second));
	};

	template <class T1, class T2>
	bool operator<=(const pair <T1, T2>& lhs, const pair<T1, T2>& rhs)
	{
		return !(rhs < lhs);
	};

	template <class T1, class T2>
	bool operator>(const pair <T1, T2>& lhs, const pair<T1, T2>& rhs)
	{
		return (rhs < lhs);
	};

	template <class T1, class T2>
	bool operator>=(const pair <T1, T2>& lhs, const pair<T1, T2>& rhs)
	{
		return (!(lhs < rhs));
	};

	template <class T>
	void swap(T& a, T& b)
	{
		T tmp(a);
		a = b;
		b = tmp;
	};

	template <class T1, class T2>
	pair<T1, T2> make_pair(T1 x, T2 y)
	{
		return (pair<T1, T2>(x, y));
	};
} // namespace ft


#endif
