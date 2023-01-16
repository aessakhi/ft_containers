/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessakhi <aessakhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 14:52:18 by aessakhi          #+#    #+#             */
/*   Updated: 2023/01/03 15:36:08 by aessakhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
# define ITERATOR_HPP

#include <cstddef>

namespace ft
{
	struct input_iterator_tag{};

	struct output_iterator_tag{};

	struct forward_iterator_tag: public input_iterator_tag{};

	struct bidirectional_iterator_tag: public forward_iterator_tag{};

	struct random_access_iterator_tag: public bidirectional_iterator_tag{}; 


	/* 	This is a base class template that can be used to derive iterator classes from it. It is not an iterator class and does not provide any of the functionality an iterator is expected to have.

	This base class only provides some member types, which in fact are not required to be present in any iterator type (iterator types have no specific member requirements), but they might be useful,
	since they define the members needed for the default iterator_traits class template to generate the appropriate instantiation automatically (and such instantiation is required to be valid for all iterator types). 
	*/
	template <class Category, class T, class Distance = ptrdiff_t, class Pointer = T*, class Reference = T&>
	struct iterator
	{
		typedef T			value_type;
		typedef Distance	difference_type;
		typedef Pointer		pointer;
		typedef Reference	reference;
		typedef Category	iterator_category;
	};

	template <class Iterator>
	struct iterator_traits
	{
		typedef typename Iterator::difference_type		difference_type;
		typedef typename Iterator::value_type			value_type;
		typedef typename Iterator::pointer				pointer;
		typedef typename Iterator::reference			reference;
		typedef typename Iterator::iterator_category	iterator_category;
	};

	template <class T>
	struct iterator_traits<T*>
	{
		typedef ptrdiff_t						difference_type;
		typedef T								value_type;
		typedef T*								pointer;
		typedef T&								reference;
		typedef random_access_iterator_tag		iterator_category;
	};

	template <class T>
	struct iterator_traits<const T*>
	{
		typedef ptrdiff_t					difference_type;
		typedef T							value_type;
		typedef const T*					pointer;
		typedef const T&					reference;
		typedef random_access_iterator_tag	iterator_category;
	};
}

#endif
