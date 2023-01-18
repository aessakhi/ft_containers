/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBTree.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessakhi <aessakhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 19:41:55 by aessakhi          #+#    #+#             */
/*   Updated: 2023/01/18 20:41:17 by aessakhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBTREE_HPP
# define RBTREE_HPP

#include <memory>
#include "algorithm.hpp"
#include "iterator.hpp"
#include "reverse_iterator.hpp"
#include "utility.hpp"

namespace ft
{
	//Recheck this one afterwards
	//Might need to be bool
	enum color {BLACK, RED};

	struct RBTree_node_base
	{
		typedef RBTree_node_base*	Base_ptr;
		typedef const RBTree_node_base* const_Base_ptr;

		color		_color;
		//Pointers to the different nodes this node is connected to
		Base_ptr	_parent;
		Base_ptr	_left;
		Base_ptr	_right;

		static Base_ptr _s_minimum(Base_ptr x)
		{
			while (x->_left != 0)
				x = x->_left;
			return (x);
		}

		static const_Base_ptr _s_minimum(const_Base_ptr x)
		{
			while (x->_left != 0)
				x = x->_left;
			return (x);
		}

		static Base_ptr _s_maximum(Base_ptr x)
		{
			while (x->_right != 0)
				x = x->_right;
			return (x);
		}

		static const_Base_ptr _s_maximum(const_Base_ptr x)
		{
			while (x->_right != 0)
				x = x->_right;
			return (x);
		}
	};

	template <typename T>
	struct RBTree_node: public RBTree_node_base
	{
		typedef RBTree_node<T>*	Link_type;

		T	value;

		RBTree_node(const T& val): value(val){};

		T*			valptr(){return &value;};
		const T*	valptr() const {return &value;};
	};

	//The increment operation either takes you to your right child and then all the way to left, or to your first non-right parent.
	RBTree_node_base*	RBTree_increment(RBTree_node_base* x)
	{
		if (x->_right)
		{
			x = x->_right;
			while (x->_left)
				x = x->_left;
		}
		else
		{
			RBTree_node_base *y = x->_parent;
			while (x == y->_right)
			{
				x = y;
				y = y->_parent;
			}
			if (x->_right != y)
				x = y;
		}
		return (x);
	};

	const RBTree_node_base*	RBTree_increment(const RBTree_node_base* x)
	{
		return RBTree_increment(const_cast<RBTree_node_base*>(x));
	};

	RBTree_node_base*	RBTree_decrement(RBTree_node_base* x)
	{
		if (x->_color == RED && x->_parent->_parent == x)
			x = x->_right;
		else if (x->_left)
		{
			RBTree_node_base* y = x->_left;
			while (y->_right)
				y = y->_right;
			x = y;
		}
		else
		{
			RBTree_node_base *y = x->_parent;
			while (x == y->_left)
			{
				x = y;
				y = y->_parent;
			}
			x = y;
		}
		return (x);
	};

	const RBTree_node_base*	RBTree_decrement(const RBTree_node_base* x)
	{
		return (RBTree_decrement(const_cast<RBTree_node_base*>(x)));
	};

	template <typename T>
	struct RBTree_iterator
	{
		typedef T	value_type;
		typedef T&	reference;
		typedef T*	pointer;

		typedef std::bidirectional_iterator_tag	iterator_category;
		typedef std::ptrdiff_t					difference_type;

		typedef RBTree_iterator<T>			Self;
		typedef RBTree_node_base::Base_ptr	Base_ptr;
		typedef RBTree_node<T>*				Link_type;

		RBTree_iterator(): _node(){};

		explicit RBTree_iterator(Base_ptr x): _node(x){};

		reference operator*() const
		{
			return *static_cast<Link_type>(_node)->valptr();
		};

		pointer operator->() const
		{
			return static_cast<Link_type>(_node)->valptr();
		};

		Self &operator++()
		{
			_node = RBTree_increment(_node);
			return (*this);
		}

		Self operator++(int)
		{
			Self tmp = *this;
			_node = RBTree_increment(_node);
			return (tmp);
		}

		Self &operator--()
		{
			_node = RBTree_decrement(_node);
			return (*this);
		}

		Self operator--(int)
		{
			Self tmp = *this;
			_node = RBTree_decrement(_node);
			return (tmp);
		}

		friend bool operator==(const Self& x, const Self& y)
		{
			return x._node == y._node;
		};

		friend bool operator!=(const Self& x, const Self& y)
		{
			return (x._node != y._node);
		};

		Base_ptr	_node;
	};

	template <typename T>
	struct RBTree_const_iterator
	{
		typedef T			value_type;
		typedef const T&	reference;
		typedef const T*	pointer;

		typedef RBTree_iterator<T> iterator;

		typedef std::bidirectional_iterator_tag	iterator_category;
		typedef std::ptrdiff_t					difference_type;

		typedef RBTree_const_iterator<T>			Self;
		typedef RBTree_node_base::const_Base_ptr	Base_ptr;
		typedef const RBTree_node<T>*				Link_type;

		RBTree_const_iterator(): _node(){};

		explicit RBTree_const_iterator(Base_ptr x): _node(x){};

		RBTree_const_iterator(const iterator& it): _node(it._node){};

		iterator _const_cast() const
		{
			return iterator(const_cast<typename iterator::Base_ptr>(_node));
		};

		reference operator*() const
		{
			return (*static_cast<Link_type>(_node)->valptr());
		};

		pointer operator->() const
		{
			return (static_cast<Link_type>(_node)->valptr());
		};

		Self& operator++()
		{
			_node = RBTree_increment(_node);
			return (*this);
		};

		Self operator++(int)
		{
			Self tmp = *this;
			_node = RBTree_increment(_node);
			return tmp;
		}

		Self &operator--()
		{
			_node = RBTree_decrement(_node);
			return (*this);
		}

		Self operator--(int)
		{
			Self tmp = *this;
			_node = RBTree_decrement(_node);
			return tmp;
		};

		friend bool operator==(const Self& x, const Self& y)
		{
			return (x._node == y._node);
		};

		friend bool operator!=(const Self& x, const Self& y)
		{
			return (x._node != y._node);
		};

		Base_ptr	_node;
	};

	//Helper struct to manage initialization of the tree and node count
	struct RBTree_header
	{
		RBTree_header()
		{
			_header._color = RED;
			reset();
		}

		void move_data(RBTree_header &other)
		{
			_header._color = other._header._color;
			_header._parent = other._header._parent;
			_header._left = other._header._left;
			_header._right = other._header._right;
			_header._parent->_parent = &_header;
			_node_count = other._node_count;

			other.reset();
		}

		void reset()
		{
			_header._parent = 0;
			_header._left = &_header;
			_header._right = &_header;
			_node_count = 0;
		};

		RBTree_node_base	_header;
		size_t				_node_count;
	};


	//Use the visualizer during the correction because it's a pain to explain otherwise
	void	RBTree_rotate_left(RBTree_node_base* const x, RBTree_node_base*& root)
	{
		RBTree_node_base* const y = x->_right;
		
		x->_right = y->_left; //X right subtree turns into y left subtree
		//If y has a left subtree assign x as the parent of the left subtree of y
		if (y->_left)
			y->_left->_parent = x;
		y->_parent = x->_parent; //y "takes over" x position so needs to have its parent
		if (x == root) //If the parent of x is null (top of the tree), y becomes the root
			root = y;
		else if (x == x->_parent->_left) //If x is the left child of its parent, y becomes the left child instead
			x->_parent->_left = y;
		else //Same but if x is the right child instead
			x->_parent->_right = y;
		y->_left = x;
		x->_parent = y;
	}

	void	RBTree_rotate_right(RBTree_node_base* const x, RBTree_node_base*& root)
	{
		RBTree_node_base* const y = x->_left;

		x->_left = y->_right; //X left subtree turns into y right subtree
		//If y has a right subtree assign x as the parent of the right subtree of y
		if (y->_right)
			y->_right->_parent = x;
		y->_parent = x->_parent; //y "takes over" x position so needs to have its parent
		if (x == root) //If the parent of x is null (top of the tree), y becomes the root
			root = y;
		else if (x == x->_parent->_right) // If x is the right child of its parent, y becomes the right child instead
			x->_parent->_right = y;
		else //Same but if x is the left child instead
			x->_parent->_left = y;
		y->_right = x;
		x->_parent = y;
	};

	//Need to add the rotate functions somewhere
	template <typename Key, typename T, typename KeyOfValue, typename Compare, typename Alloc = std::allocator<T> >
	class RBTree
	{
		public:

			typedef Key					key_type;
			typedef T					value_type;
			typedef value_type*			pointer;
			typedef const value_type*	const_pointer;
			typedef value_type&			reference;
			typedef const value_type&	const_reference;
			typedef size_t				size_type;
			typedef std::ptrdiff_t		difference_type;
			typedef Alloc				allocator_type;

			typedef RBTree_iterator<value_type>				iterator;
			typedef RBTree_const_iterator<value_type>		const_iterator;
			typedef ft::reverse_iterator<iterator>			reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>	const_reverse_iterator;

			//The Alloc template is used to obtains objects of some type
			//Since the RBTree uses nodes to stock the values, the nodes need their own allocation mecanism
			//Weird syntax, can be found in other containers too, like std::list
			//See: https://stackoverflow.com/questions/14148756/what-does-template-rebind-do
			typedef typename Alloc::template rebind<RBTree_node<T> >::other node_allocator;

			typedef RBTree_node_base*		Base_ptr;
			typedef const RBTree_node_base*	const_Base_ptr;
			typedef RBTree_node<T>*			Link_type;
			typedef const RBTree_node<T>*	const_Link_type;

			RBTree(){};

			RBTree(const Compare& comp, const allocator_type& alloc = allocator_type()): _key_compare(comp), _node_alloc(alloc){};

			//Add once I made copy();
			RBTree(const RBTree& other): _key_compare(other._key_compare), _start(other._start)
			{
				if (other._start._header._parent)
					this->_start._header._parent = copy(other);
				this->_node_alloc = other._node_alloc;
			};

			RBTree& operator=(const RBTree& other)
			{
				if (this != &other)
				{
					clear();
					this->_key_compare = other._key_compare;
					if (other.root())
						this->_start._header._parent = copy(other);
				}
				return (*this);
			}

			~RBTree()
			{
				erase_no_rebalance(static_cast<Link_type>(_start._header._parent));
			};

			/* Accessors */

			Compare key_comp() const
			{
				return (this->_key_compare);
			};

			iterator begin()
			{
				return (iterator(this->_start._header._left));
			};

			const_iterator begin() const
			{
				return (const_iterator(this->_start._header._left));
			};

			iterator end()
			{
				return (iterator(&this->_start._header));
			};

			const_iterator end() const
			{
				return (const_iterator(&this->_start._header));
			};

			reverse_iterator rbegin()
			{
				return (reverse_iterator(end()));
			};

			const_reverse_iterator rbegin() const
			{
				return (const_reverse_iterator(end()));
			};

			reverse_iterator rend()
			{
				return (reverse_iterator(begin()));
			};

			const_reverse_iterator rend() const
			{
				return (const_reverse_iterator(begin()));
			};

			bool empty() const
			{
				return (_start._node_count == 0);
			};

			size_type size() const
			{
				return (_start._node_count);
			};

			//Directly use alloc::max_size() just like for vector
			size_type max_size() const
			{
				return (this->_node_alloc.max_size());
			};

			allocator_type get_allocator() const
			{
				return (this->_node_alloc);
			};

			iterator lower_bound(const Key& k)
			{
				return _lower_bound(static_cast<Link_type>(_start._header._parent) , &_start._header, k);
			};

			const_iterator lower_bound(const Key& k) const
			{
				return _lower_bound(static_cast<const_Link_type>(_start._header._parent), &_start._header, k);
			};
			

			iterator upper_bound(const Key& k)
			{
				return _upper_bound(static_cast<Link_type>(_start._header._parent), &_start._header, k);
			};

			const_iterator upper_bound(const Key& k) const
			{
				return _upper_bound(static_cast<const_Link_type>(_start._header._parent), &_start._header, k);
			};

			ft::pair<iterator, iterator> equal_range(const Key& k)
			{
				return (ft::make_pair<iterator, iterator>(lower_bound(k), upper_bound(k)));
			};

			ft::pair<const_iterator, const_iterator> equal_range(const Key& k) const
			{
				return (ft::make_pair<const_iterator, const_iterator>(lower_bound(k), upper_bound(k)));
			};

			iterator find(const Key& k)
			{
				iterator result = _lower_bound(static_cast<Link_type>(_start._header._parent), &_start._header, k);
				if (_key_compare(k, _key(result._node)))
					return end();
				else
					return (result);
			};

			const_iterator find(const Key& k) const
			{
				const_iterator result = _lower_bound(static_cast<const_Link_type>(_start._header._parent), &_start._header, k);
				if (_key_compare(k, _key(result._node)))
					return end();
				else
					return (result);
			};

			/* Insert */

			//Will use this one for map
			ft::pair<iterator, bool> insert_unique(const value_type &value)
			{
				return (insert_unique_aux(value));
			};

			//Don't need it
/* 			iterator insert(iterator position, const value_type& val)
			{
				
			}; */

			template <typename InputIt>
			void insert_it(InputIt first, InputIt last)
			{
				while (first != last)
				{
					insert_unique_aux(*first);
					++first;
				}
			};

			/* Erase */

			//Erase but no rebalancing, will be used in the destructor
			void erase_no_rebalance(Link_type x)
			{
				while (x)
				{
					erase_no_rebalance(right(x));
					Link_type y = left(x);
					_node_alloc.destroy(x);
					_node_alloc.deallocate(x, 1);
					x = y;
				}
			};

			void erase(iterator position)
			{
				if (position != end())
					erase_aux(position);
			};

			void erase(const_iterator position)
			{
				if (position != end())
					erase_aux(position);
			};

			void erase(iterator first, iterator last)
			{
				erase_aux(first, last);
			};

			void erase(const_iterator first, const_iterator last)
			{
				erase_aux(first, last);
			};

			size_type erase_return_nodes_deleted(const Key& k)
			{
				ft::pair<iterator, iterator> result = equal_range(k);
				const size_type tmp_size = size();
				erase_aux(result.first, result.second);
				return (tmp_size - size());
			};

			Link_type copy(const RBTree& other)
			{
				Link_type copy = copy_node(static_cast<Link_type>(other._start._header._parent), &_start._header);
				_start._node_count = other._start._node_count;
				_start._header._left = RBTree_node_base::_s_minimum(copy);
				_start._header._right = RBTree_node_base::_s_maximum(copy);
				return (copy);
			};

			void clear()
			{
				erase_no_rebalance(static_cast<Link_type>(_start._header._parent));
				this->_start.reset();
			};

			//TBD after doing the rest of the functions.
			void	swap(RBTree& other)
			{
				if (this == &other)
					return ;
				if (root() == 0)
				{
					if (other.root())
					{
						_start._header._color = other._start._header._color;
						_start._header._parent = other._start._header._parent;
						_start._header._left = other._start._header._left;
						_start._header._right = other._start._header._right;
						_start._header._parent->_parent = &_start._header;
						_start._node_count = other._start._node_count;
						other._start._header._parent = 0;
						other._start._header._left = &other._start._header;
						other._start._header._right = &other._start._header;
						other._start._node_count = 0;
					}
				}
				else if (other.root() == 0)
				{
					other._start._header._color = _start._header._color;
					other._start._header._parent = _start._header._parent;
					other._start._header._left = _start._header._left;
					other._start._header._right = _start._header._right;
					other._start._header._parent->_parent = &other._start._header;
					other._start._node_count = _start._node_count;
					_start._header._parent = 0;
					_start._header._left = &_start._header;
					_start._header._right = &_start._header;
					_start._node_count = 0;
				}
				else
				{
					
					ft::swap(root(), other.root());
					ft::swap(_start._header._left, other._start._header._left);
					ft::swap(_start._header._right, other._start._header._right);
					root()->_parent = &_start._header;
					other.root()->_parent = &other._start._header;
					ft::swap(_start._node_count, other._start._node_count);
				}
				node_allocator tmp = _node_alloc;

				ft::swap(_key_compare, other._key_compare);
				_node_alloc = other._node_alloc;
				other._node_alloc = tmp;
			};

		private:
		
			Compare			_key_compare;
			node_allocator	_node_alloc;
			RBTree_header	_start;

		//Need all the auxiliary functions so it's easier to navigate

			Base_ptr&	root()
			{
				return (this->_start._header._parent);
			};

			const_Base_ptr	root() const
			{
				return (this->_start._header._parent);
			};

			static const Key& _key(const_Link_type x)
			{
				return (KeyOfValue()(*x->valptr()));
			};

			static const Key& _key(const_Base_ptr x)
			{
				return _key(static_cast<const_Link_type>(x));
			};

			static Link_type left(Base_ptr x)
			{
				return (static_cast<Link_type>(x->_left));
			};

			static const_Link_type left(const_Base_ptr x)
			{
				return (static_cast<const_Link_type>(x->_left));
			};

			static Link_type right(Base_ptr x)
			{
				return (static_cast<Link_type>(x->_right));
			};

			static const_Link_type right(const_Base_ptr x)
			{
				return (static_cast<const_Link_type>(x->_right));
			};

			static Base_ptr minimum(Base_ptr x)
			{
				return (RBTree_node_base::_s_minimum(x));
			};

			static const_Base_ptr minimum(const_Base_ptr x)
			{
				return (RBTree_node_base::_s_minimum(x));
			};

			static Base_ptr maximum(Base_ptr x)
			{
				return (RBTree_node_base::_s_maximum(x));
			};

			static const_Base_ptr maximum(const_Base_ptr x)
			{
				return (RBTree_node_base::_s_maximum(x));
			};

			iterator _lower_bound(Link_type x, Base_ptr y, const Key& k)
			{
				while (x)
				{
					if (_key_compare(_key(x), k))
						x = right(x);
					else
					{
						y = x;
						x = left(x);
					}
				}
				return iterator(y);
			};

			const_iterator _lower_bound(const_Link_type x, const_Base_ptr y, const Key& k) const
			{
				while (x)
				{
					if (_key_compare(_key(x), k))
						x = right(x);
					else
					{
						y = x;
						x = left(x);
					}
				}
				return const_iterator(y);
			};

			iterator _upper_bound(Link_type x, Base_ptr y, const Key& k)
			{
				while (x)
				{
					if (!_key_compare(k, _key(x)))
						x = right(x);
					else
					{
						y = x;
						x = left(x);
					}
				}
				return iterator(y);
			};

			const_iterator _upper_bound(const_Link_type x, const_Base_ptr y, const Key& k) const
			{
				while (x)
				{
					if (!_key_compare(k, _key(x)))
						x = right(x);
					else
					{
						y = x;
						x = left(x);
					}
				}
				return const_iterator(y);
			};

			//Used by insert unique to find the right pos to insert the node
			ft::pair<Base_ptr, Base_ptr> insert_pos(const Key& k)
			{
				Link_type x = static_cast<Link_type>(_start._header._parent);
				Link_type y = static_cast<Link_type>(&_start._header);
				bool comp = true;
				while (x)
				{
					y = x;
					comp = _key_compare(k, _key(x));
					if (comp)
						x = left(x);
					else
						x = right(x);
				}
				iterator j(y);
				if (comp)
				{
					if (j == begin())
						return (ft::pair<Base_ptr, Base_ptr>(x, y));
					else
						j--;
				}
				if (_key_compare(_key(j._node), k))
					return (ft::pair<Base_ptr, Base_ptr>(x, y));
				return (ft::pair<Base_ptr, Base_ptr>(j._node, 0));
			};

			ft::pair<iterator, bool> insert_unique_aux(const value_type &value)
			{
				ft::pair<Base_ptr, Base_ptr> result = insert_pos(KeyOfValue()(value));
				if (result.second)
						return (ft::pair<iterator, bool>(insert_aux(result.first, result.second, value), true));
				return ft::pair<iterator, bool>(iterator(result.first), false);
			}

			iterator insert_aux(Base_ptr x, Base_ptr parent, const value_type &value)
			{
				(void)x; // Not used here
				Link_type new_node = _node_alloc.allocate(1);
				_node_alloc.construct(new_node, value);

				insert_rebalance(new_node, parent);
				++this->_start._node_count;
				return (iterator(new_node));
			};

			// See https://www.geeksforgeeks.org/insertion-in-red-black-tree/
			void insert_rebalance(Base_ptr new_node, Base_ptr parent)
			{
				RBTree_node_base *&tmp_root = root();

				// Init new node here
				new_node->_parent = parent;
				new_node->_left = NULL;
				new_node->_right = NULL;
				new_node->_color = RED; // Easier to recolor and fix if the node is first colored in red

				bool leftinsert = (parent == &_start._header) || !(_key_compare(_key(parent), _key(new_node)));
				// Insert start
				if (leftinsert)
				{
						parent->_left = new_node;
						if (parent == &_start._header)
						{
							_start._header._parent = new_node;
							_start._header._right = new_node;
						}
						else if (parent == _start._header._left)
							_start._header._left = new_node;
				}
				else
				{
						parent->_right = new_node;
						if (parent == _start._header._right)
							_start._header._right = new_node;
				}
				// Fix / Rebalance
				while (new_node != tmp_root && new_node->_parent->_color == RED) //Do the following until the parent of new_node is REd
				{
						RBTree_node_base *const grandpa = new_node->_parent->_parent;
						if (new_node->_parent == grandpa->_left) //If parent is the left child of grandpa of new_node
						{
							RBTree_node_base *const y = grandpa->_right;
							if (y && y->_color == RED) //Case 1: If the color of the right of grandpa is RED, set the color of both the children of grandpa as BLACK and the color of grandpa as RED
							{
								new_node->_parent->_color = BLACK;
								y->_color = BLACK;
								grandpa->_color = RED;
								new_node = grandpa; //Assign grandpa to new_node
							}
							else
							{
								if (new_node == new_node->_parent->_right) //If new_node is the right child of parent
								{
									new_node = new_node->_parent; //Assign parent to new_node
									RBTree_rotate_left(new_node, tmp_root); //Left rotate new_node
								}
								new_node->_parent->_color = BLACK; //Set color of parent as black
								grandpa->_color = RED; //Set color of grandpa as RED
								RBTree_rotate_right(grandpa, tmp_root); //Right rotate grandpa
							}
						}
						else //Else do the following
						{
							RBTree_node_base *const y = grandpa->_left;
							if (y && y->_color == RED) //If the color of the left child of the grandparent of new_node is RED, set the color of both the children of grandpa as BLACK and the color of grandpa as RED
							{
								new_node->_parent->_color = BLACK;
								y->_color = BLACK;
								grandpa->_color = RED;
								new_node = grandpa; //Assign grandpa to new_node
							}
							else
							{
								if (new_node == new_node->_parent->_left) //Else if new_node is the left child of parent
								{
									new_node = new_node->_parent; //Assign parent to new_node
									RBTree_rotate_right(new_node, tmp_root); //Right rotate new_node
								}
								new_node->_parent->_color = BLACK; //Set color of parent as BLACK
								grandpa->_color = RED; //Set color of grandpa as RED
								RBTree_rotate_left(grandpa, tmp_root); //Left rotate grandpa
							}
						}
				}
				tmp_root->_color = BLACK; //Set the root of the tree as BLACK
			};

			void erase_aux(const_iterator position)
			{
				Link_type node;

				node = static_cast<Link_type>(erase_rebalance(const_cast<Base_ptr>(position._node)));
				_node_alloc.destroy(node);
				_node_alloc.deallocate(node, 1);
				--_start._node_count;
			};

			void erase_aux(const_iterator first, const_iterator last)
			{
				if (first == begin() && last == end())
					clear();
				else
					while (first != last)
						erase_aux(first++);
			};

			RBTree_node_base* erase_rebalance(RBTree_node_base* const node)
			{
				RBTree_node_base* y = node;
				RBTree_node_base* x = 0;
				RBTree_node_base* x_parent = 0;
				color original_color = node->_color; //Save the color of the node to be deleted

				//Deletion part BST Deletion
				if (y->_left == 0) //If the left child of the node to be deleted is null
					x = y->_right; //Assign the right child of node to be deleted to x;
				else
					if (y->_right == 0) //Else if the right child of node to be deleted is null
						x = y->_left; //Assign the left child of node to be deleted into x
					else
					{
						y = y->_right; //Assign the minimum of the the right subtree of the node to be deleted into y
						while (y->_left != 0)
							y = y->_left; //Minimum here
						x = y->_right; //Assign the right child of y into x
					}
				if (y != node) //If the right child of the node to be deleted isn't null this condition wouldn't be respected
				{
					node->_left->_parent = y;
					y->_left = node->_left;
					if (y != node->_right) //Transplant y with the right child of y (here x) if y isn't a child of node to be deleted
					{
						x_parent = y->_parent;
						if (x)
							x->_parent = y->_parent;
						y->_parent->_left = x;
						y->_right = node->_right;
						node->_right->_parent = y;
					}
					else
						x_parent = y; //If y is a child of the node to be deleted set the parent of x as y
					if (_start._header._parent == node)
						_start._header._parent = y;
					else if (node->_parent->_left == node)
						node->_parent->_left = y;
					else
						node->_parent->_right = y;
					y->_parent = node->_parent;
					node->_color = y->_color;
					y->_color = original_color; //Set the color of y with original color
					y = node; //y points to the node that will be deleted, will be returned by the function so it can be destroyed/deallocated
				}
				else //Transplant node to be deleted with x
				{
					x_parent = y->_parent;
					if (x)
						x->_parent = y->_parent;
					if (_start._header._parent == node) //This part is used to maintain the root, left and right pointers for the header
						_start._header._parent = x;
					else
						if (node->_parent->_left == node)
							node->_parent->_left = x;
						else
							node->_parent->_right = x;
					if (_start._header._left == node)
					{
						if (node->_right == 0)
							_start._header._left = node->_parent;
						else
							_start._header._left = RBTree_node_base::_s_minimum(x);
					}
					if (_start._header._right == node)
					{
						if (node->_left == 0)
							_start._header._right = node->_parent;
						else
							_start._header._right = RBTree_node_base::_s_maximum(x);
					}
				}
				//This part is used to rebalance the tree after deletion
				//Meaning after a Black node is deleted, violating the black depth property of the RBTree
				if (y->_color != RED)
				{
					while (x != _start._header._parent && (x == 0 || x->_color == BLACK)) //Must do the following until the x is not the root of the tree and the color of x is black
						if (x == x_parent->_left)
						{
							RBTree_node_base* sibling = x_parent->_right;
							if (sibling->_color == RED) //CASE 1 
							{
								sibling->_color = BLACK; //Set the color of the right child of the parent of x as BLACK
								x_parent->_color = RED; //Set the color of the parent of x as RED
								RBTree_rotate_left(x_parent, _start._header._parent); //Left Rotate the parent of X
								sibling = x_parent->_right; //Assign the right child of the parent of x to the sibling
							}
							if ((sibling->_left == 0 || sibling->_left->_color == BLACK) && (sibling->_right == 0 || sibling->_right->_color == BLACK)) // CASE 2 If the color of both the right and the left child of the sibling is BLACK
							{
								sibling->_color = RED; //Set the color of the sibling as RED
								x = x_parent; //Assign the parent of x to x
								x_parent = x_parent->_parent;
							}
							else
							{
								if (sibling->_right == 0 || sibling->_right->_color == BLACK) //CASE 3 If the color of the right child of the sibling is BLACK
								{
									sibling->_left->_color = BLACK; //Set the color of the left child of the sibling as BLACK
									sibling->_color = RED; //Set the color of the sibling as RED
									RBTree_rotate_right(sibling, _start._header._parent); //Right rotate the sibling
									sibling = x_parent->_right; //Assign the right child of the parent of x to the sibling
								}
								sibling->_color = x_parent->_color; //CASE 4 Set the color of the sibling as the color of the parent of x
								x_parent->_color = BLACK; //Set the color of the grandparent of x as BLACK
								if (sibling->_right) //Set the color of the right child of the sibling as BLACK if it exists
									sibling->_right->_color = BLACK;
								RBTree_rotate_left(x_parent, _start._header._parent); //Left rotate the parent of x
								break;
							}
						}
						else //Same as above but with right changed to left and vice versa
						{
							RBTree_node_base* sibling = x_parent->_left;
							if (sibling->_color == RED)
							{
								sibling->_color = BLACK;
								x_parent->_color = RED;
								RBTree_rotate_right(x_parent, _start._header._parent);
								sibling = x_parent->_left;
							}
							if ((sibling->_right == 0 || sibling->_right->_color == BLACK) && (sibling->_left == 0 || sibling->_left->_color == BLACK))
							{
								sibling->_color = RED;
								x = x_parent;
								x_parent = x_parent->_parent;
							}
							else
							{
								if (sibling->_left == 0 || sibling->_left->_color == BLACK)
								{
									sibling->_right->_color = BLACK;
									sibling->_color = RED;
									RBTree_rotate_left(sibling, _start._header._parent);
									sibling = x_parent->_left;
								}
								sibling->_color = x_parent->_color;
								x_parent->_color = BLACK;
								if (sibling->_left)
									sibling->_left->_color = BLACK;
								RBTree_rotate_right(x_parent, _start._header._parent);
								break;
							}
						}
					if (x)
						x->_color = BLACK; //Set the color of x as BLACK
				}
				return (y);
			};

			Link_type copy_node(const_Link_type copied, Base_ptr parent)
			{
				if (copied == NULL)
					return (NULL);
				Link_type cpy = _node_alloc.allocate(1);
				_node_alloc.construct(cpy, copied->value);

				cpy->_parent = parent;
				cpy->_left = copy_node(left(copied), cpy);
				cpy->_right = copy_node(right(copied), cpy);
				cpy->_color = copied->_color;
				return (cpy);
			};

		};

		template <typename Key, typename T, typename KeyOfValue, typename Compare, typename Alloc>
		bool operator==(const RBTree<Key, T, KeyOfValue, Compare, Alloc>& lhs, const RBTree<Key, T, KeyOfValue, Compare, Alloc>& rhs)
		{
			return (lhs.size() == rhs.size() && ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
		};

		template <typename Key, typename T, typename KeyOfValue, typename Compare, typename Alloc>
		bool operator<(const RBTree<Key, T, KeyOfValue, Compare, Alloc>& lhs, const RBTree<Key, T, KeyOfValue, Compare, Alloc>& rhs)
		{
			return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
		};

		template <typename Key, typename T, typename KeyOfValue, typename Compare, typename Alloc>
		void swap(RBTree<Key, T, KeyOfValue, Compare, Alloc>& lhs, RBTree<Key, T, KeyOfValue, Compare, Alloc>& rhs)
		{
			lhs.swap(rhs);
		};

} // namespace ft

#endif
