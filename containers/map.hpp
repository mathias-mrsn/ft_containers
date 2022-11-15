/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 12:36:01 by mamaurai          #+#    #+#             */
/*   Updated: 2022/11/15 14:38:59 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ft_containers.hpp"
#include "pair.hpp"
#include "binary_function.hpp"
#include "reverse_iterator.hpp"
#include "node_iterator.hpp"
#include "red_black_tree.hpp"
#include "lexicographical_compare.hpp"


_BEGIN_NAMESPACE_FT

template<	class Key,
			class T,
			class Compare = ft::less<Key>,
			class Allocator = std::allocator<ft::pair<const Key, T> > >
class map {
	
	public:
	
		typedef map													self;
		typedef typename ft::pair<const Key, T>						value_type;
		typedef Compare												key_compare;
	
		class value_compare : public binary_function<value_type, value_type, bool> {
			
			friend class map;
			
			protected:
				key_compare	comp;
			
				value_compare (key_compare k) : comp(k)
				{ }
			
			public:
				bool
				operator()(const value_type& lhs, const value_type& rhs) const {
					return (comp(lhs.first, rhs.first));
				}

		};
		
		typedef Key													key_type;
		typedef T													mapped_type;
		typedef typename std::size_t								size_type;
		typedef typename std::ptrdiff_t								difference_type;
		typedef Allocator											allocator_type;
		typedef value_type&											reference;
		typedef const value_type&									const_reference;
		typedef typename ft::RBT<value_type, value_compare> 		underlying_tree;
		typedef typename allocator_type::pointer					pointer;
		typedef typename ft::Node<value_type>						node_type;
		typedef typename allocator_type::const_pointer				const_pointer;
		typedef typename ft::node_iterator<value_type, node_type>				iterator;
		typedef typename ft::node_iterator<const value_type, node_type>		const_iterator;
		typedef typename ft::reverse_iterator<iterator>				reverse_iterator;
		typedef typename ft::reverse_iterator<const_iterator>		const_reverse_iterator;

		
	private:
		value_compare		_compare;
		allocator_type 		_allocator;
		underlying_tree		_t;
		
	public:

		explicit map (	const Compare& comp = Compare(),
						const Allocator& alloc = Allocator()) :
			_compare(value_compare(comp)),
			_allocator(alloc),
			_t(_compare)
		{ }

		template<class InputIt>
		map (	InputIt first,
				InputIt last,
				const Compare& comp = Compare(),
				const Allocator& alloc = Allocator()) :
			_compare(value_compare(comp)),
			_allocator(alloc),
			_t(_compare)
		{
			insert(first, last);
		}

		map (const self& other) :
			_compare(other._compare),
			_allocator(other._allocator),
			_t(_compare)
		{
			*this = other;
		}

		~map (void)
		{ }
		
		self&
		operator= (const self& other) {
			if (this == &other) {return (*this);}
			
			_compare = other._compare;
			_allocator = other._allocator;
			_t.destroy_tree();
			insert(other.begin(), other.end());

			return (*this);
		}
		
		allocator_type
		get_allocator (void) const {
			return (_allocator);
		}

		mapped_type&
		operator[] (const key_type& k) {
			iterator it = iterator(_t.find(_KEY(k)), ROOT_, END_);
			if (it == end()) {
				iterator node_inserted = iterator(_t.insert(_KEY(k)), ROOT_, END_);
				return (node_inserted->second);
			}
			return (it->second);
		}

		iterator
		begin (void) {
			return (iterator(BEGIN_, ROOT_, END_));
		}

		const_iterator
		begin (void) const {
			return (const_iterator(BEGIN_, ROOT_, END_));
		}

		iterator
		end (void) {
			return (iterator(END_, ROOT_, END_));
		}

		const_iterator
		end (void) const {
			return (const_iterator(END_, ROOT_, END_));
		}

		reverse_iterator
		rbegin (void) {
			return (reverse_iterator(end()));
		}

		const_reverse_iterator
		rbegin (void) const {
			return (const_reverse_iterator(end()));
		}

		reverse_iterator
		rend (void) {
			return (reverse_iterator(begin()));
		}

		const_reverse_iterator
		rend (void) const {
			return (const_reverse_iterator(begin()));
		}

		bool
		empty (void) const {
			return (_t.empty());
		}

		size_type
		size (void) const {
			return (_t.size());
		}

		size_type
		max_size (void) const {
			return (_t.max_size());
		}
		
		ft::pair<iterator, bool>
		insert (const value_type& value) {
			const bool b = static_cast<bool>(!!(_t.insert(value)));
			return (ft::make_pair(iterator(_t.find(value), ROOT_, END_), b));
		}

		iterator
		insert (_UNUSED iterator hint, const value_type& value) {
			_t.insert(value);
			return (iterator(_t.find(value), ROOT_, END_));
		}

		template <class InputIterator>
		void insert (InputIterator first, InputIterator last) {
			for ( ;first != last; ++first)
				_t.insert(*first);
		}

		void
		erase (iterator position) {
			_t.deletion(*position);
		}

		size_type
		erase (const key_type& k) {
			return (_t.deletion(_KEY(k)));
		}

		void
		erase (iterator first, iterator last) {
			while (first != last)
				_t.deletion(*(first++));
		}

		void
		swap (self& x) {
			_t.swap(x._t);
		}

		void
		clear (void) {
			_t.destroy_tree();
		}

		key_compare
		key_comp (void) const {
			return (key_compare());
		}

		value_compare
		value_comp (void) const {
			return (_compare);
		}

		size_type
		count (const key_type& k) const {
			return (!(_t.find(_KEY(k)) == _nullptr));
		}
		
		iterator
		find (const key_type& k) {
			return (iterator(_t.find(_KEY(k)), ROOT_, END_));
		}
		
		const_iterator
		find (const key_type& k) const {
			return (const_iterator(_t.find(_KEY(k)), ROOT_, END_));
		}

		iterator
		lower_bound (const key_type& k) {
			return (iterator(_t.lower_bound(_KEY(k)), ROOT_, END_));
		}

		const_iterator
		lower_bound (const key_type& k) const {
			return (const_iterator(_t.lower_bound(_KEY(k)), ROOT_, END_));
		}

		iterator
		upper_bound (const key_type& k) {
			return (iterator(_t.upper_bound(_KEY(k)), ROOT_, END_));
		}

		const_iterator
		upper_bound (const key_type& k) const {
			return (iterator(_t.upper_bound(_KEY(k)), ROOT_, END_));
		}

		ft::pair<iterator, iterator>
		equal_range (const key_type& k) {
			return (ft::make_pair(lower_bound(k), upper_bound(k)));
		}

		ft::pair<const_iterator, const_iterator>
		equal_range (const key_type& k) const {
			return (ft::make_pair(lower_bound(k), upper_bound(k)));
		}

};

template< class Key, class T, class Compare, class Alloc >
bool operator== (const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs) {
	return (ft::equal(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
}

template< class Key, class T, class Compare, class Alloc >
bool operator!= (const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs) {
	return (!(lhs == rhs));
}

template< class Key, class T, class Compare, class Alloc >
bool operator< (const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs) {
	return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
}

template< class Key, class T, class Compare, class Alloc >
bool operator> (const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs) {
	return (ft::lexicographical_compare(rhs.begin(), rhs.end(), lhs.begin(), lhs.end()));
}

template< class Key, class T, class Compare, class Alloc >
bool operator<= (const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs) {
	return (!(lhs > rhs));
}

template< class Key, class T, class Compare, class Alloc >
bool operator>= (const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs) {
	return (!(lhs < rhs));
}

template< class Key, class T, class Compare, class Alloc >
void swap (ft::map<Key,T,Compare,Alloc>& lhs, ft::map<Key,T,Compare,Alloc>& rhs) {
	lhs.swap(rhs);
}

_END_NAMESPACE_FT
