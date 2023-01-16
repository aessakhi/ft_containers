/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_traits.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessakhi <aessakhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 03:03:27 by aessakhi          #+#    #+#             */
/*   Updated: 2023/01/16 16:50:31 by aessakhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPE_TRAITS_HPP
# define TYPE_TRAITS_HPP

	/* In C, an integral type can declare:

	- Integer values, signed or unsigned
	- Boolean values, where 0 is equivalent to false and any nonzero number is equivalent to true
	- Characters, which are automatically converted to an integer value by the compiler
	- Members of an enumerated type, which are interpreted as an integer by the compiler
	- Bit fields */

	/* enable_if allow to enable or disable a candidate of overload resolution */

namespace ft
{
	template <bool Cond, class T = void>
	struct enable_if{};

	template <class T>
	struct enable_if<true, T>
	{
		typedef T	type;
	};

	template <class T, T v>
	struct integral_constant
	{
		static const T	value = v;
	
		typedef T						value_type;
		typedef integral_constant<T, v>	type;

		operator T(){return v;};
	};

	typedef integral_constant<bool, true>	true_type;
	typedef integral_constant<bool, false>	false_type;

	template <class T>
	struct is_integral: public false_type{};

	template <>
	struct is_integral<bool>: public true_type{};

	template <>
	struct is_integral<char>: public true_type{};

/* 	template <>
	struct is_integral<char16_t>: public true_type{};

	template <>
	struct is_integral<char32_t>: public true_type{}; */

	template <>
	struct is_integral<wchar_t>: public true_type{};

	template <>
	struct is_integral<signed char>: public true_type{};

	template <>
	struct is_integral<short int>: public true_type{};

	template <>
	struct is_integral<int>: public true_type{};

	template <>
	struct is_integral<long int>: public true_type{};

	template <>
	struct is_integral<long long int>: public true_type{};

	template <>
	struct is_integral<unsigned char>: public true_type{};

	template <>
	struct is_integral<unsigned short int>: public true_type{};

	template <>
	struct is_integral<unsigned int>: public true_type{};

	template <>
	struct is_integral<unsigned long int>: public true_type{};

	template <>
	struct is_integral<unsigned long long int>: public true_type{};
} // namespace ft


#endif
