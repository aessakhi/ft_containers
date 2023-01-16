/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RandomAccessIterator.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessakhi <aessakhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 17:51:54 by aessakhi          #+#    #+#             */
/*   Updated: 2023/01/03 19:49:09 by aessakhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RANDOMACCESSITERATOR_HPP
# define RANDOMACCESSITERATOR_HPP

#include "iterator.hpp"

namespace ft
{
	template <class T>
	class RandomAccessIterator: public ft::iterator< ft::random_access_iterator_tag, T >
	{
		public:

		typedef ptrdiff_t							difference_type;
		typedef T									value_type;
		typedef T*									pointer;
		typedef T&									reference;
		typedef ft::random_access_iterator_tag		iterator_category;
		
		RandomAccessIterator(): _ptr(0){};

		RandomAccessIterator(pointer ptr): _ptr(ptr){};

		template <class U>
		RandomAccessIterator(const RandomAccessIterator<U>& other): _ptr(other.base()){};

		~RandomAccessIterator(){};

		pointer base() const {return _ptr;};

		template <class U>
		RandomAccessIterator& operator=(const RandomAccessIterator<U>& other)
		{
			_ptr = other.base();
			return (*this);
		};

		reference operator*() const
		{
			return (*_ptr);
		};

		pointer	operator->() const
		{
			return &(operator*());
		};

		reference operator[](difference_type n) const
		{
			return *(*this + n);
		};

		RandomAccessIterator& operator++()
		{
			++_ptr;
			return (*this);
		};

		RandomAccessIterator& operator--()
		{
			--_ptr;
			return (*this);
		};

		RandomAccessIterator operator++(int)
		{
			RandomAccessIterator _tmp = *this;
			++_ptr;
			return (_tmp);
		};

		RandomAccessIterator operator--(int)
		{
			RandomAccessIterator _tmp = *this;
			--_ptr;
			return (_tmp);
		};

		RandomAccessIterator operator+(difference_type n) const
		{
			return (RandomAccessIterator(_ptr + n));
		};

		RandomAccessIterator operator-(difference_type n) const
		{
			return (RandomAccessIterator(_ptr - n));
		};

		RandomAccessIterator& operator+=(difference_type n)
		{
			_ptr += n;
			return (*this);
		};

		RandomAccessIterator& operator-=(difference_type n)
		{
			_ptr -= n;
			return (*this);
		};

		protected:

			pointer	_ptr;
	};

template <class T1, class T2>
bool operator==(const RandomAccessIterator<T1>& lhs, const RandomAccessIterator<T2>& rhs)
{
	return (lhs.base() == rhs.base());
}

template <class T1, class T2>
bool operator!=(const RandomAccessIterator<T1>& lhs, const RandomAccessIterator<T2>& rhs)
{
	return (lhs.base() != rhs.base());
}

template <class T1, class T2>
bool operator<(const RandomAccessIterator<T1>& lhs, const RandomAccessIterator<T2>& rhs)
{
	return (lhs.base() < rhs.base());
}

template <class T1, class T2>
bool operator<=(const RandomAccessIterator<T1>& lhs, const RandomAccessIterator<T2>& rhs)
{
	return (lhs.base() <= rhs.base());
}

template <class T1, class T2>
bool operator>(const RandomAccessIterator<T1>& lhs, const RandomAccessIterator<T2>& rhs)
{
	return (lhs.base() > rhs.base());
}

template <class T1, class T2>
bool operator>=(const RandomAccessIterator<T1>& lhs, const RandomAccessIterator<T2>& rhs)
{
	return (lhs.base() >= rhs.base());
}

template <class T>
RandomAccessIterator<T> operator+(typename RandomAccessIterator<T>::difference_type n, const RandomAccessIterator<T>& it)
{
	return (it + n);
};

template <class T1, class T2>
typename RandomAccessIterator<T1>::difference_type operator- (const RandomAccessIterator<T1>& lhs, const RandomAccessIterator<T2>& rhs)
{
	return (lhs.base() - rhs.base());
};

} // namespace ft


#endif
