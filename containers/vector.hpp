/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 16:44:12 by mamaurai          #+#    #+#             */
/*   Updated: 2022/11/15 14:39:07 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <memory>
#include <sstream>
#include "reverse_iterator.hpp"
#include "random_iterator.hpp"
#include "enable_if.hpp"
#include "is_integral.hpp"
#include "utils.hpp"
#include "lexicographical_compare.hpp"
#include "pair.hpp"
#include "nullptr.hpp"

_BEGIN_NAMESPACE_FT

# define _VECTOR_CAPACITY_MULTIPLIER	2

# ifndef _VECTOR_DEBUG
#  define _VECTOR_DEBUG 0
# endif

template <class T, class Allocator = std::allocator<T> >
class vector {

	public:
		typedef	T						value_type;
		typedef Allocator				allocator_type;
		typedef std::size_t				size_type;
		typedef std::ptrdiff_t			difference_type;
		typedef value_type&			reference;
		typedef typename allocator_type::reference 	const_reference;
		typedef typename Allocator::pointer	pointer;
		typedef typename Allocator::const_pointer const_pointer;
		typedef typename ft::random_iterator<value_type> 		iterator;
		typedef typename ft::random_iterator<const value_type> 	const_iterator;
		typedef typename ft::reverse_iterator<iterator> 		reverse_iterator;
		typedef typename ft::reverse_iterator<const_iterator> 	const_reverse_iterator;		
		
	private:
		size_type		_size;
		size_type		_capacity;
		allocator_type	_allocator;
		pointer			_begin;
		pointer			_end;
		
	public:

		explicit vector (const allocator_type& alloc = allocator_type()) :
			_size(0),
			_capacity(0),
			_allocator(alloc),
			_begin(_nullptr),
			_end(_nullptr)
		{
# if defined(_VECTOR_DEBUG) && (_VECTOR_DEBUG == 1)
			_begin = _allocator.allocate(1);
			_end = _begin;
# endif
		}

		explicit vector (	size_type n,
							const value_type& val = value_type(),
							const allocator_type& alloc = allocator_type()) :
			_size(n),
			_capacity(n),
			_allocator(alloc),
			_begin(_nullptr),
			_end(_nullptr)
		{
# if defined(_VECTOR_DEBUG) && (_VECTOR_DEBUG == 1)
			_begin = _allocator.allocate((_capacity == 0) ? 1 : _capacity);
# else
			_begin = _allocator.allocate(_capacity);
#endif
			_end = _begin;

			for (size_type i = 0; i < n; i++) {
				_allocator.construct(_end, val);
				_end++;
			}
		}

		template <class InputIterator>
    	vector (	InputIterator first, InputIterator last,
					const allocator_type& alloc = allocator_type(),
					typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = _nullptr) :
			_allocator(alloc)
		{
			_size = ft::distance<InputIterator>(first, last);
			_capacity = _size;
# if defined(_VECTOR_DEBUG) && (_VECTOR_DEBUG == 1)
			_begin = _allocator.allocate((_capacity == 0) ? 1 : _capacity);
# else
			_begin = _allocator.allocate(_capacity);
# endif
			_end = _begin;
		
			for (size_type n = 0; n < _size; n++) {
				_allocator.construct(_end, *first);
				first++;
				_end++;
			}
		}
		
		vector (const vector& x) :
			_size(x._size),
			_capacity(x._size),
			_allocator(x._allocator)
		{
# if defined(_VECTOR_DEBUG) && (_VECTOR_DEBUG == 1)
			_begin = _allocator.allocate((_capacity == 0) ? 1 : _capacity);
# else
			_begin = _allocator.allocate(_capacity);
# endif
			_end = _begin;
			
			for (pointer begin_ptr = x._begin; begin_ptr < x._end; ++begin_ptr, ++_end)
				_allocator.construct(_end, *begin_ptr);		
		}

		~vector (void)
		{
			clear();
			if (_begin != _nullptr || _begin == _end)
				_allocator.deallocate(_begin, _capacity);
		}

		vector&
		operator= (const vector& ref) {
			if (&ref == this) {return (*this);}

			clear();
			_allocator.deallocate(_begin, _capacity);
			if (ref._size > _capacity)
				_capacity = ref._size;
			_begin = _allocator.allocate(_capacity);
			_end = _begin;
			_size = ref._size;


			for (pointer begin_ptr = ref._begin; begin_ptr < ref._end; ++begin_ptr, ++_end)
				_allocator.construct(_end, *begin_ptr);

			return (*this);
		}

		iterator
		begin (void) {
			return (iterator(_begin));
		}

		const_iterator
		begin (void) const {
			return (const_iterator(_begin));
		}

		iterator
		end (void) {
			return (iterator(_end));
		}

		const_iterator
		end (void) const {
			return (const_iterator(_end));	
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
		size_type
		size() const {
			return (_size);
		}

		size_type
		max_size (void) const {
			return (_allocator.max_size());
		}

		size_type
		capacity (void) const {
			return (_capacity);
		}

		bool
		empty (void) const {
			return (size() == 0);	
		}

		void
		reserve (size_type n) {
			if (n > max_size())
				throw (std::length_error("vector::reserve"));
			if (n < capacity())
				return;
			
			pointer ptr_to_free = _begin;
			pointer begin_ptr = _begin;

			_begin = _allocator.allocate(n);
			_end = _begin;
			for (size_type i = 0; i < _size; i++) {
				_allocator.construct(_end, *begin_ptr);
				_allocator.destroy(begin_ptr);
				++_end;
				++begin_ptr;
			}
			_allocator.deallocate(ptr_to_free, _capacity);
			_capacity = n;
		}

		void
		resize (size_type n, value_type val = value_type()) {
			if (n > max_size())
				throw (std::length_error("vector::resize"));
			else if (n < size()) {
				for ( ; _size > n; _size--)
					_allocator.destroy(_begin + (_size - 1));
				_end = _begin + _size;
			} else {
				if (n <= _capacity);
				else if (n > _size * _VECTOR_CAPACITY_MULTIPLIER)
					reserve(n);
				else
					reserve(_size * _VECTOR_CAPACITY_MULTIPLIER);
				for (size_type i = _size; i < n; i++, _end++)
					_allocator.construct(_end, val);
				_size = n;
			}
		}

		reference
		operator[] (size_type n) {
			return (*(_begin + n));
		}

		const_reference
		operator[] (size_type n) const {
			return (*(_begin + n));
		}

		reference
		at (size_type n) {
			std::stringstream	error_stream;

			error_stream 	<< "vector::_M_range_check: __n (which is "
							<< n
							<< ") >= this->size() (which is "
							<< _size
							<< ")";

			if (n >= size()) {throw (std::out_of_range(error_stream.str()));}
			return (*(_begin + n));
		}
		
		const_reference
		at (size_type n) const {
			if (n >= size()) {throw (std::out_of_range("vector::at"));}
			return (*(_begin + n));
		}
		
		reference
		front (void) {
			return (*(_begin));
		}

		const_reference
		front (void) const {
			return (*(_begin));
		}

		reference
		back (void) {
			return (*(_end - 1));
		}

		const_reference
		back (void) const {
			return (*(_end - 1));
		}

		pointer
		data (void) {
			return (_begin);
		}

		const_pointer
		data (void) const {
			return (_begin);
		}

		void
		push_back (const value_type& val) {
			if (size() >= _capacity)
				reserve(((_capacity == 0) ? 0.5 : _capacity) * _VECTOR_CAPACITY_MULTIPLIER);
			_allocator.construct(_end++, val);
			_size++;
		}

		void
		pop_back (void) {
			--_size;
			_allocator.destroy(--_end);
		}

		template <class InputIterator>
  		void
		assign (InputIterator first, InputIterator last,
			typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = _nullptr) {
			
			size_type i;

			reserve(ft::distance(first, last));
			for (i = 0; i < _size; i++)
				_allocator.destroy(_begin + i);
			for (i = 0; first != last; ++first, i++)
				_allocator.construct(_begin + i, *first);
			_size = i;
			_end = _begin + _size;
		}

		void
		assign (size_type n, const value_type& val) {
			reserve(n);
			for (size_type i = 0; i < _size; i++)
				_allocator.destroy(_begin + i);
			(void)val;
			for (size_type i = 0; i < n; i++)
				_allocator.construct(_begin + i, val);
			_size = n;
			_end = _begin + n;
		}

		iterator
		insert (iterator position, const value_type& val) {	
			difference_type dist = ft::distance(begin(), position);
			insert(position, 1, val);
			return (iterator(begin() + dist));
		}

		void
		insert (iterator position, size_type n, const value_type& val) {
			difference_type begin_position = ft::distance(begin(), position);
			difference_type position_end = ft::distance(position, end());
			difference_type	begin_end = ft::distance(begin(), end());
			
			if (n == 0)
				return;
			if (n + _size <= _capacity);
			else if (n + _size >= _capacity * _VECTOR_CAPACITY_MULTIPLIER)
				reserve(n + _size);
			else
				reserve(_size * _VECTOR_CAPACITY_MULTIPLIER);
			for (difference_type i = 1; i <= position_end; i++) {
				_allocator.construct(((_begin + begin_end + n) - i), *(_begin + begin_end - i));
				_allocator.destroy(_begin + begin_end - i);
			}
			for (size_type i = 0; i < n; i++) {
				_allocator.construct((_begin + begin_position + (i) ), val);
			}
			_end = _begin + _size + n;
			_size += n;
			position++;
		}

		template <class InputIterator>
    	void
		insert (iterator position, InputIterator first, InputIterator last,
			typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = _nullptr) {
			size_type n = static_cast<size_type>(ft::distance(first, last));
			difference_type begin_position = ft::distance(begin(), position);
			difference_type position_end = ft::distance(position, end());
			difference_type	begin_end = _size;			

			if (n == 0)
				return;
			if (n + _size <= _capacity);
			else if (n + _size > _capacity * _VECTOR_CAPACITY_MULTIPLIER)
				reserve(n + _size);
			else
				reserve(_size * _VECTOR_CAPACITY_MULTIPLIER);
			for (difference_type i = 1; i <= position_end; i++) {
				_allocator.construct(((_begin + begin_end + n) - i), *(_begin + begin_end - i));
				_allocator.destroy(_begin + begin_end - i);
			}
			for (size_type i = 0; i < n; i++) {
				_allocator.construct((_begin + begin_position + i), *(first));
				++first;
			}
			_end = _begin + _size + n;
			_size += n;
		}

		iterator
		erase (iterator position) {
			iterator save = position;
			
			for (; position + 1 != end(); position++) {
				_allocator.destroy(&(*position));
				_allocator.construct(&(*position), *(position + 1));
			}
			_allocator.destroy(&(*position));
			_size--;
			_end--;
			return (save);
		}

		iterator
		erase (iterator first, iterator last) {
			iterator save = first;
			
			for (; first != last; --last)
				erase(first);
			return (save);
		}

		void
		swap (vector& x) {
			pointer tmp_begin = _begin;
			pointer tmp_end = _end;
			size_type tmp_capacity = _capacity;
			allocator_type tmp_allocator = _allocator;
			size_type tmp_size = _size;

			_begin = x._begin;
			_end = x._end;
			_capacity = x._capacity;
			_size = x._size;
			_allocator = x._allocator;

			x._begin = tmp_begin;
			x._end = tmp_end;
			x._capacity = tmp_capacity;
			x._size = tmp_size;
			x._allocator = tmp_allocator;
		}

		void
		clear (void) {
			while (_size--) {
				_allocator.destroy(_begin + _size);
			}
			_end = _begin;
			_size = 0;
		}

		allocator_type
		get_allocator (void) const {
			return (_allocator);
		}

};

template<class T, class Alloc>
bool
operator== (const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs) {
	return (ft::equal(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
}

template<class T, class Alloc>
bool
operator!= (const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs) {
	return (!(lhs == rhs));
}

template<class T, class Alloc>
bool
operator< (const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs) {
	return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
}

template<class T, class Alloc>
bool
operator> (const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs) {
	return (ft::lexicographical_compare(rhs.begin(), rhs.end(), lhs.begin(), lhs.end()));
}

template<class T, class Alloc>
bool
operator<= (const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs) {
	return (!(lhs > rhs));
}

template<class T, class Alloc>
bool
operator>= (const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs) {
	return (!(lhs < rhs));
}

template<class T, class Alloc>
void
swap (ft::vector<T,Alloc>& lhs, ft::vector<T,Alloc>& rhs) {
	lhs.swap(rhs);
}
	
_END_NAMESPACE_FT
