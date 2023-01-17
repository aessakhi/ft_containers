/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessakhi <aessakhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 19:36:01 by aessakhi          #+#    #+#             */
/*   Updated: 2023/01/17 21:50:20 by aessakhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

#include "RBTree.hpp"
#include <functional>

//For RBTree I will need erase, clear, insert_unique, find, key_comp, upper_bound, lower_bound, insert
namespace ft
{
	template <class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<ft::pair<const Key, T> > >
	class map
	{
		public:
		
			typedef Key									key_type;
			typedef T									mapped_type;
			typedef pair<const key_type, mapped_type>	value_type;
			typedef Compare								key_compare;
			//Value compare Nested function class to compare elements

			typedef Alloc										allocator_type;
			typedef typename allocator_type::reference			reference;
			typedef typename allocator_type::const_reference	const_reference;

			typedef RBTree<key_type, value_type, std::_Select1st<value_type>, key_compare, allocator_type>	tree;

			//Not really sure about pointer and const pointer will see the results;
			typedef typename tree::pointer					pointer;
			typedef typename tree::const_pointer			const_pointer;
			typedef typename tree::iterator					iterator;
			typedef typename tree::const_iterator			const_iterator;
			typedef typename tree::reverse_iterator			reverse_iterator;
			typedef typename tree::const_reverse_iterator	const_reverse_iterator;
			typedef typename tree::size_type				size_type;
			typedef typename tree::difference_type			difference_type;

			//Nested class that uses the internal comparison object to generate the appropriate comparison functional class
			//Will be used by value_comp() to compare two elements to get whether the key of the first one goes before the second.
			class value_compare
			{
				friend class map;

				protected:

					Compare _comp;

					value_compare(Compare c): _comp(c){};

				public:

					typedef bool	result_type;
					typedef value_type	first_argument_type;
					typedef value_type	second_argument_type;

					bool operator()(const value_type& x, const value_type& y) const
					{
						return _comp(x.first, y.first);
					};
			};

			/* Constructors */

			explicit map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()): _rbtree(comp, alloc){};

			//Need insert for this one
			template<class InputIterator>
			map(InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()): _rbtree(comp, alloc)
			{
				insert(first, last);
			};

			map(const map& other): _rbtree(other._rbtree){};

			//Calls the destructor of rbtree so no need to do anything special here;
			~map(){};

			map& operator=(const map& other)
			{
				if (this != &other)
					_rbtree = other._rbtree;
				return (*this);
			};

			/* Iterators */

			iterator begin()
			{
				return (this->_rbtree.begin());
			};

			const_iterator begin() const
			{
				return (this->_rbtree.begin());
			};

			iterator end()
			{
				return (this->_rbtree.end());
			};

			const_iterator end() const
			{
				return (this->_rbtree.end());
			};

			reverse_iterator rbegin()
			{
				return (this->_rbtree.rbegin());
			};

			const_reverse_iterator rbegin() const
			{
				return (this->_rbtree.rbegin());
			};

			reverse_iterator rend()
			{
				return (this->_rbtree.rend());
			};

			const_reverse_iterator rend() const
			{
				return (this->_rbtree.rend());
			};


			/* Capacity */

			bool empty() const
			{
				return (this->_rbtree.empty());
			};

			size_type size() const
			{
				return (this->_rbtree.size());
			};

			size_type max_size() const
			{
				return (this->_rbtree.max_size());
			};

			/* Element access */

			//If k matches the key of an element in the container, the function returns a reference to its mapped value
			mapped_type& operator[](const key_type& k)
			{
				return (*((this->insert(value_type(k,mapped_type()))).first)).second;
			};

			/* Modifiers */

			//Careful use insert_unique() since element keys in a map are unique
			//DONE
			ft::pair<iterator, bool> insert(const value_type& val)
			{
				ft::pair<typename tree::iterator, bool> result = _rbtree.insert_unique(val);
				return pair<typename tree::iterator, bool>(result.first, result.second);
			};

			iterator insert(iterator position, const value_type& val)
			{
				(void)position;
				ft::pair<typename tree::iterator, bool> result = _rbtree.insert_unique(val);
				return (result.first);
			};

			template<class InputIterator>
			void insert(InputIterator first, InputIterator last)
			{
				this->_rbtree.insert_it(first, last);
			};

			void erase(iterator position)
			{
				this->_rbtree.erase(position);
			};

			//Returns the number of elements erased;
			size_type erase(const key_type& k)
			{
				return (this->_rbtree.erase_return_nodes_deleted(k));
			};

			void erase(iterator first, iterator last)
			{
				this->_rbtree.erase(first, last);
			};

			void swap(map& other)
			{
				this->_rbtree.swap(other._rbtree);
			};

			void clear()
			{
				this->_rbtree.clear();
			};

			/* Observers */

			key_compare key_comp() const
			{
				return (this->_rbtree.key_comp());
			};

			value_compare value_comp() const
			{
				return value_compare(this->_rbtree.key_comp());
			};

			/* Operations */

			//Searches the container for an element with a key equivalent to k and returns an iterator to it if found
			iterator find(const key_type& k)
			{
				return (this->_rbtree.find(k));
			};

			const_iterator find (const key_type& k) const
			{
				return (this->_rbtree.find(k));
			};

			//Searches the container for elements with a key equivalent to k and returns the number of matches
			//Because all elements in a map container are unique, it can only return 1 or 0
			size_type count(const key_type& k) const
			{
				if (this->_rbtree.find(k) != this->_rbtree.end())
					return (1);
				else
					return (0);
			};

			//Returns an iterator pointing to the first element in the container whose key is not considered to go before k
			//Example: the keys are a, b, c, d, e and f. If I do lower_bound('b') it will return an iterator pointing to 'b'
			iterator lower_bound(const key_type& k)
			{
				return (this->_rbtree.lower_bound(k));
			};

			const_iterator lower_bound(const key_type& k) const
			{
				return (this->_rbtree.lower_bound(k));
			};

			//Returns an iterator pointing to the first element in the container whose key is considered to go after k
			//In the example above if I do upper_bound('d') it will point to 'e';
			iterator upper_bound(const key_type& k)
			{
				return (this->_rbtree.upper_bound(k));
			};

			const_iterator upper_bound(const key_type& k) const
			{
				return (this->_rbtree.upper_bound(k));
			};

			//Returns the bounds of a range that includes all the elements in the container which have a key equivalent to k
			//Since key are uniques in a map, it will return 1 element AT MOST
			pair<const_iterator, const_iterator>
			equal_range(const key_type& k) const
			{
				return (this->_rbtree.equal_range(k));
			};

			pair<iterator, iterator>
			equal_range(const key_type& k)
			{
				return (this->_rbtree.equal_range(k));
			};

			//Allocator

			allocator_type get_allocator() const
			{
				return (this->_rbtree.get_allocator());
			};

			template <class Key1, class T1, class Compare1, class Alloc1>
			friend bool operator==(const map<Key1, T1, Compare1, Alloc1>&, const map<Key1, T1, Compare1, Alloc1>&);

			template <class Key1, class T1, class Compare1, class Alloc1>
			friend bool operator<(const map<Key1, T1, Compare1, Alloc1>&, const map<Key1, T1, Compare1, Alloc1>&);

			private:

				tree _rbtree;
	};


	//Need to add friend function in the main class for == and < just like for stack
	template <class Key, class T, class Compare, class Alloc>
	bool operator==(const map<Key, T, Compare, Alloc>& lhs, const map<Key, T, Compare, Alloc>& rhs)
	{
		return (lhs._rbtree == rhs._rbtree);
	};

	template <class Key, class T, class Compare, class Alloc>
	bool operator!=(const map<Key, T, Compare, Alloc>& lhs, const map<Key, T, Compare, Alloc>& rhs)
	{
		return !(lhs == rhs);
	};

	template <class Key, class T, class Compare, class Alloc>
	bool operator<(const map<Key, T, Compare, Alloc>& lhs, const map<Key, T, Compare, Alloc>& rhs)
	{
		return (lhs._rbtree < rhs._rbtree);
	};

	template <class Key, class T, class Compare, class Alloc>
	bool operator<=(const map<Key, T, Compare, Alloc>& lhs, const map<Key, T, Compare, Alloc>& rhs)
	{
		return !(rhs < lhs);
	};

	template <class Key, class T, class Compare, class Alloc>
	bool operator>(const map<Key, T, Compare, Alloc>& lhs, const map<Key, T, Compare, Alloc>& rhs)
	{
		return (rhs < lhs);
	};

	template <class Key, class T, class Compare, class Alloc>
	bool operator>=(const map<Key, T, Compare, Alloc>& lhs, const map<Key, T, Compare, Alloc>& rhs)
	{
		return !(lhs < rhs);
	};

	template <class Key, class T, class Compare, class Alloc>
	void swap(map<Key, T, Compare, Alloc>& lhs, map<Key, T, Compare, Alloc>& rhs)
	{
		lhs.swap(rhs);
	};

} // namespace ft

#endif
