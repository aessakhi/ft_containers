/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessakhi <aessakhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 13:57:49 by aessakhi          #+#    #+#             */
/*   Updated: 2023/01/16 23:36:41 by aessakhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <memory>
#include <stdexcept>
#include "RandomAccessIterator.hpp"
#include "reverse_iterator.hpp"
#include "algorithm.hpp"
#include "type_traits.hpp"
#include "utility.hpp"

namespace ft
{
	template < class T, class Allocator = std::allocator<T> >
	class vector
	{
	public:

		/* Member types */

		typedef T											value_type;
		//Type of the elements inside the vector container
		//If the vector is ft::vector<ft::vector<int> >, then value_type of the given vector will be ft::vector<int>

		typedef Allocator									allocator_type;
		//Member type allocator_type is the internal allocator type used by the container, defined in vector as an alias of its second template parameter (Allocator).

		typedef typename std::size_t								size_type;
		typedef typename std::ptrdiff_t								difference_type;
		typedef typename allocator_type::reference					reference;
		typedef typename allocator_type::const_reference			const_reference;
		typedef typename allocator_type::pointer					pointer;
		typedef typename allocator_type::const_pointer				const_pointer;
		typedef typename ft::RandomAccessIterator<value_type>		iterator;
		typedef typename ft::RandomAccessIterator<const value_type>	const_iterator;
		typedef typename ft::reverse_iterator<iterator>				reverse_iterator;
		typedef typename ft::reverse_iterator<const_iterator>		const_reverse_iterator;

		/* Constructors and Destructors */

		//Default constructor. Constructs an empty container with a default-constructed allocator.
		vector(): _alloc(), _start(0), _finish(0), _end_of_storage(0){};

		//Constructs an empty container with the given allocator alloc.
		explicit vector(const Allocator& alloc): _alloc(alloc), _start(0), _finish(0), _end_of_storage(0){};

		//Constructs the container with count copies of elements with value value.
		explicit vector(size_type count, const T& value = T(), const Allocator& alloc = Allocator()): _alloc(alloc)
		{
			this->_start = this->_alloc.allocate(count);
			this->_finish = this->_start;
			this->_end_of_storage = this->_start + count;
			for (size_t i = 0; i < count; i++)
				this->_alloc.construct(this->_finish++, value);
		};

		//Constructs the container with the contents of the range [first, last).
		template<class InputIt>
		vector(InputIt first, InputIt last, const Allocator& alloc = Allocator(),
		typename ft::enable_if<!ft::is_integral<InputIt>::value>::type* = 0): _alloc(alloc)
		{
			size_type count = last - first;
			this->_start = this->_alloc.allocate(count);
			this->_finish = this->_start;
			while (&(*first) != &(*last))
			{
				this->_alloc.construct(this->_finish++, *first);
				first++;
			}
			this->_end_of_storage = this->_start + count;
		};

		// Copy constructor. Constructs the container with the copy of the contents of other.
		vector(const vector& other)
		{
			size_type count = other.size();

			_alloc = other.get_allocator();
			this->_start = this->_alloc.allocate(count);
			this->_end_of_storage = this->_start + count;
			this->_finish = this->_start;

			pointer	result = other._start;
			for (size_t i = 0; i < count; i++)
				this->_alloc.construct(this->_finish++, *result++);
		};

		//Destructs the vector. The destructors of the elements are called (Use clear()) and the used storage is deallocated. 
		//Note, that if the elements are pointers, the pointed-to objects are not destroyed.
		~vector()
		{
			this->clear();
			this->_alloc.deallocate(this->_start, this->capacity());
		};

		/* Member functions */

		//Copy all the elements from other into the container
		//The container preserves its current allocator, which is used to allocate storage in case of reallocation
		//Return *this
		vector& operator=(const vector& other)
		{
			if (this == &other)
				return (*this);
			this->clear();
			this->insert(this->_start, other.begin(), other.end());
			return (*this);
		};

		allocator_type get_allocator() const
		{
			return (this->_alloc);
		};

		//Replace the content by count copies of value value
		//Any elements held in the container before the call are destroyed and replaced by newly constructed elements
		//This causes an automatic reallocation of the allocated storage space if and only if the new vector size surpasses the current vector capacity
		void assign(size_type count, const T& value)
		{
			this->clear();
			//Need a case when capacity >= count and else
			if (this->capacity() >= count)
				for (size_type i = 0; i < count; i++)
					this->_alloc.construct(this->_finish++, value);
			else
			{
				//Add deallocate else leaks
				this->_alloc.deallocate(this->_start, this->capacity());
				this->_start = this->_alloc.allocate(count);
				this->_finish = this->_start;
				this->_end_of_storage = this->_start + count;
				for (size_type i = 0; i < count; i++)
					this->_alloc.construct(this->_finish++, value);
			}
		};

		template<class InputIt>
		void assign(InputIt first, InputIt last,
		typename ft::enable_if<!ft::is_integral<InputIt>::value>::type* = 0)
		{
			size_type count = last - first;
			if (count > this->max_size())
				throw std::length_error("ft::vector::assign: Length error");
			this->clear();
			if (this->capacity() >= count)
				for (size_type i = 0; i < count; i++)
				{
					this->_alloc.construct(this->_finish++, *first);
					first++;
				}
			else
			{
				this->_alloc.deallocate(this->_start, this->capacity());
				this->_start = this->_alloc.allocate(count);
				this->_finish = this->_start;
				this->_end_of_storage = this->_start + count;
				for (size_type i = 0; i < count; i++)
				{
					this->_alloc.construct(this->_finish++, *first);
					first++;
				}
			}
		};

		/* Element access */

		//Throws an std::out_of_range exception if (pos > size())
		reference at(size_type pos)
		{
			if (pos > size())
				throw std::out_of_range("ft::vector::at Value out of range");
			return (this->_start[pos]);
		};

		const_reference at(size_type pos) const
		{
			if (pos > size())
				throw std::out_of_range("ft::vector::at: Value out of range");
			return (this->_start[pos]);
		};

		reference operator[]( size_type pos )
		{
			return (this->_start[pos]);
		};

		const_reference operator[]( size_type pos ) const
		{
			return (this->_start[pos]);
		};

		reference front()
		{
			return (*this->_start);
		};

		const_reference front() const
		{
			return (*this->_start);
		};

		reference back()
		{
			return *(this->_finish - 1);
		};

		const_reference back() const
		{
			return *(this->_finish - 1);
		};

		/* Iterators */

		iterator	begin()
		{
			return (this->_start);
		};

		const_iterator	begin() const
		{
			return (this->_start);
		};

		iterator	end()
		{
			return (this->_finish);
		};

		const_iterator	end() const
		{
			return (this->_finish);
		};

		reverse_iterator rbegin()
		{
			return (this->end());
		};

		reverse_iterator rend()
		{
			return (this->begin());
		};

		/* Capacity */
		bool empty() const
		{
			return (size() == 0);
		};

		size_type size() const
		{
			return (this->_finish - this->_start);
		};

		size_type max_size() const
		{
			return (this->_alloc.max_size());
		};

		//Request that the vector capacity be at least enough to contain n elements.
		//If new_cap is greater than the current vector capacity, the function causes the container to reallocate its storage increasing its capacity to new_cap
		//In all other cases, the function call does not cause a reallocation and the vector capacity is unaffected.
		//Throws a std::length_error if new_cap is greater than the max size of the allocator
		//If new_cap is greater than capacity(), all iterators, including the past-the-end iterator, and all referecences to the elements are invalidated
		void reserve(size_type new_cap)
		{
			if (new_cap > this->max_size())
				throw std::length_error("vector::reserve");
			if (this->capacity() >= new_cap)
				return ;
		
			pointer tmp_start = this->_alloc.allocate(new_cap);
			pointer tmp_finish = tmp_start;
			for (pointer current = this->_start; current != this->_finish; current++)
				this->_alloc.construct(tmp_finish++, *current);
			//Need to destroy previous elements + deallocate previous allocated memory
			while (this->_finish != this->_start)
			{
				this->_finish--;
				this->_alloc.destroy(this->_finish);
			}
			this->_alloc.deallocate(this->_start, this->_end_of_storage - this->_start);

			this->_start = tmp_start;
			this->_finish = tmp_finish;
			this->_end_of_storage = this->_start + new_cap;
		};

		size_type capacity() const
		{
			return ((size_type)(this->_end_of_storage - this->_start));
		};

		/* Modifiers */

		//Erase all elements from the container. 
		//After this call, size() returns 0.
		//Use allocator destroy, calls the destructor of the object pointed to by p
		void clear()
		{
			while (this->_finish != this->_start)
			{
				this->_finish--;
				this->_alloc.destroy(this->_finish);
			}
		};

		//Vector is extended by inserting new elements before the element at the specified position, increasing the container size by the number of elements inserted.
		//Causes an automatic reallocation of the allocated storage space if and only if the new vector size surpasses the current vector capacity.
		//
		iterator insert(iterator pos, const T& value)
		{
			size_type position = pos - this->begin();
			this->insert(pos, 1, value);
			return (this->_start + position);
		};

		void insert(iterator pos, size_type count, const T& value)
		{
			if (count == 0)
				return ;
			size_type position = pos - this->begin();
			if (this->capacity() >= count + this->size())
			{
				for (size_type i = 0; i < this->size() - position; i++)
					this->_alloc.construct(this->_finish - i + (count - 1), *(this->_finish - i - 1));
				this->_finish += count;
				while (count)
				{
					this->_alloc.construct(this->_start + position + (count - 1), value);
					count--;
				}
			}
			else
			{
				//A RECHECK
					pointer new_start = pointer();
					pointer new_end = pointer();
					pointer new_end_capacity = pointer();
					
					int next_capacity = (this->capacity() > 0) ? (int)(this->size() * 2) : 1;
					new_start = _alloc.allocate(next_capacity);
					new_end_capacity = new_start + next_capacity;

					if (size_type(new_end_capacity - new_start) < this->size() + count)
					{
						if (new_start)
							_alloc.deallocate(new_start, new_start - new_end_capacity);
						next_capacity = this->size() + count;
						new_start = _alloc.allocate(next_capacity);
						new_end = new_start + this->size() + count;
						new_end_capacity = new_start + next_capacity;
					}

					new_end = new_start + this->size() + count;

					for (size_type i = 0; i < position; i++)
						_alloc.construct(new_start + i, *(_start + i));
					for (size_type k = 0; k < count; k++)
						_alloc.construct(new_start + position + k, value);
					for (size_type j = 0; j < (this->size() - position); j++)
						_alloc.construct(new_end - j - 1, *(_finish - j - 1));

					for (size_type u = 0; u < this->size(); u++)
						_alloc.destroy(_start + u);
					_alloc.deallocate(_start, this->capacity());

					_start = new_start;
					_finish = new_end;
					_end_of_storage = new_end_capacity;
			}
		};

		//Same as above but the difference between first and last will serve as count
		template< class InputIt >
		void insert(iterator pos, InputIt first, InputIt last,
		typename ft::enable_if<!ft::is_integral<InputIt>::value>::type* = 0)
		{
			size_type count = last - first;
			if (count == 0)
				return ;
			if (count > this->max_size())
				throw std::length_error("ft::vector::insert: length error");
			size_type position = pos - this->begin();
			if (this->capacity() >= count + this->size())
			{
				for (size_type i = 0; i < this->size() - position; i++)
					this->_alloc.construct(this->_finish - i + (count - 1), *(this->_finish - i - 1));
				this->_finish += count;
				while (count)
				{
					last--;
					this->_alloc.construct(this->_start + position + (count - 1), *last);
					count--;
				}
			}
			else
			{
				size_type length = this->size() + std::max(size(), count);
				pointer tmp_start = this->_alloc.allocate(length);
				pointer tmp_finish = tmp_start + this->size() + count;
				pointer tmp_end_of_storage = tmp_start + length;

				for (size_type i = 0; i < position; i++) //Cpy before the first element to be inserted
					this->_alloc.construct(tmp_start + i, *(this->_start + i));
				for (size_type j = 0; &(*first) != &(*last); first++, j++) //Cpy the [first, last) range
					this->_alloc.construct(tmp_start + position + j, *first);
				for (size_type k = 0; k < this->size() - position; k++) //Cpy after
					this->_alloc.construct(tmp_start + position + count + k, *(this->_start + (position + k)));
				for (size_type l = 0; l < this->size(); l++)
					this->_alloc.destroy(this->_start + l);
				this->_alloc.deallocate(this->_start, this->capacity());

				this->_start = tmp_start;
				this->_finish = tmp_finish;
				this->_end_of_storage = tmp_end_of_storage;
			}
		};

		//Removes the element at given position and thus shorten the vector by one
		//Return an iterator pointing to the next element or (end())
		iterator erase(iterator pos)
		{
			if (pos + 1 != this->end())
			{
				iterator cpy = pos;
				for (; cpy + 1 != this->end(); (void)++cpy)
					*cpy = *(cpy + 1);
			}
			--this->_finish;
			this->_alloc.destroy(this->_finish);
			return (pos);
		};

		//Removes the element in the range [first, last)
		//Need to check the difference between the two iterators
		iterator erase(iterator first, iterator last)
		{
			size_type count = last - first;
			if (count > this->max_size())
				throw std::length_error("ft::vector::erase: length error");
			if (first != last)
			{
				//Copy the elements after last to first
				iterator cpy_first = first;
				iterator cpy_last = last;
				if (last != end())
					for (; cpy_last != this->end(); (void)++cpy_last)
					{
						*cpy_first = *cpy_last;
						cpy_first++;
					}
				pointer p = first.base() + (this->end() - last);
				size_type count = this->_finish - p;
				pointer it = p + count;
				if (count)
				{
					while(it != p)
						this->_alloc.destroy(--it);
					this->_finish = p;
				}
			}
			return first;
		};

		//Appends the given element value to the end of the container.
		void push_back(const T& value)
		{
			this->insert(this->end(), value);
		};

		void pop_back()
		{
			if (this->size() == 0)
				return ;
			this->_alloc.destroy(--this->_finish);
		};

		//Resizes the container to contain count elements
		//If the current size is greater than count, the container is reduced to its first count elements
		//If the current size is less than count - Additional default-inserted elements are appended - Additional copies of value are appended
		void resize(size_type count, T value = T())
		{
			if (this->size() > count)
			{
				size_type cpy_size = this->size();
				while (cpy_size > count)
				{
					--this->_finish;
					this->_alloc.destroy(this->_finish);
					cpy_size--;
				}
			}
			else if (count > this->size())
				this->insert(this->_finish, count - this->size(), value);
		};

		void swap(vector& other)
		{
			if (this == &other)
				return ;
			ft::swap(this->_start, other._start);
			ft::swap(this->_finish, other._finish);
			ft::swap(this->_end_of_storage, other._end_of_storage);
			ft::swap(this->_alloc, other._alloc);
		};

	private:
		Allocator	_alloc;
		pointer		_start;
		pointer		_finish;
		pointer		_end_of_storage;
	};

	/* Non-member functions */

	template< class T, class Alloc >
	bool operator==(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return (lhs.size() == rhs.size() && std::equal(lhs.begin(), lhs.end(), rhs.begin()));
	};

	template< class T, class Alloc >
	bool operator!=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return (!(lhs == rhs));
	};

	template< class T, class Alloc >
	bool operator<(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	};

	template< class T, class Alloc >
	bool operator<=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return !(rhs < lhs);
	};

	template< class T, class Alloc >
	bool operator>(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return (rhs < lhs);
	};

	template< class T, class Alloc >
	bool operator>=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return !(lhs < rhs);
	};

	template< class T, class Alloc >
	void swap(vector<T,Alloc>& lhs, vector<T,Alloc>& rhs)
	{
		lhs.swap(rhs);
	};

} // namespace ft

#endif
