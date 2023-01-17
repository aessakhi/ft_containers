/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessakhi <aessakhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 19:07:54 by aessakhi          #+#    #+#             */
/*   Updated: 2023/01/17 14:29:27 by aessakhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

#include <iostream>
#include "iterator.hpp"

namespace ft
{
	template <class Iterator>
	class reverse_iterator
	{
		public:

		typedef Iterator													iterator_type;
		typedef typename ft::iterator_traits<Iterator>::iterator_category	iterator_category;
		typedef typename ft::iterator_traits<Iterator>::value_type			value_type;
		typedef typename ft::iterator_traits<Iterator>::difference_type		difference_type;
		typedef typename ft::iterator_traits<Iterator>::pointer				pointer;
		typedef typename ft::iterator_traits<Iterator>::reference			reference;

		reverse_iterator(): _current(){};

		reverse_iterator(iterator_type x): _current(x){};

		template <class U>
		reverse_iterator(const reverse_iterator<U>& other): _current(other.base()){};

		~reverse_iterator(){};

		iterator_type base() const {return _current;};

		template<class U>
		reverse_iterator& operator=(const reverse_iterator<U>& other)
		{
			_current = other.base();
			return (*this);
		}

		reference operator*() const
		{
			Iterator _tmp = _current;
			return (*--_tmp);
		};

		pointer operator->() const
		{
			return &(operator*());
		};

		reference operator[](difference_type n) const
		{
			return *(*this + n);
		}

		reverse_iterator& operator++()
		{
			--_current;
			return (*this);
		};

		reverse_iterator& operator--()
		{
			++_current;
			return (*this);
		}

		reverse_iterator operator++(int)
		{
			reverse_iterator _tmp = *this;
			--_current;
			return (_tmp);
		};

		reverse_iterator operator--(int)
		{
			reverse_iterator _tmp = *this;
			++_current;
			return (_tmp);
		};

		reverse_iterator operator+(difference_type n) const
		{
			return (reverse_iterator(_current - n));
		};

		reverse_iterator operator-(difference_type n) const
		{
			return (reverse_iterator(_current + n));
		};

		reverse_iterator& operator+=(difference_type n)
		{
			_current -= n;
			return (*this);
		};

		reverse_iterator& operator-=(difference_type n)
		{
			_current += n;
			return (*this);
		};

	protected:
		iterator_type	_current;
	};

	template <class Iterator1, class Iterator2>
	bool operator==(const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs)
	{
		return (lhs.base() == rhs.base()); 
	};

	template <class Iterator1, class Iterator2>
	bool operator!=(const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs)
	{
		return (lhs.base() != rhs.base());
	};

	template <class Iterator1, class Iterator2>
	bool operator<(const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs)
	{
		return (lhs.base() > rhs.base());
	};

	template <class Iterator1, class Iterator2>
	bool operator<=(const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs)
	{
		return (lhs.base() >= rhs.base());
	};

	template <class Iterator1, class Iterator2>
	bool operator>(const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs)
	{
		return (lhs.base() < rhs.base());
	};

	template <class Iterator1, class Iterator2>
	bool operator>=(const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs)
	{
		return (lhs.base() <= rhs.base());
	};

	template<class Iterator>
	reverse_iterator<Iterator> operator+(typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator>& rev_it)
	{
		return (rev_it + n);
	};

	template<class Iterator1, class Iterator2>
	typename reverse_iterator<Iterator1>::difference_type operator-(const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs)
	{
		return (rhs.base() - lhs.base());
	};

	template<class Iterator>
	typename reverse_iterator<Iterator>::difference_type operator-(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
	{
		return (rhs.base() - lhs.base());
	};
} // namespace ft

#endif
