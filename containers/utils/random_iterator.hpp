/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_iterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 18:14:03 by mamaurai          #+#    #+#             */
/*   Updated: 2022/11/15 14:35:10 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "iterator.hpp"
#include "nullptr.hpp"

_BEGIN_NAMESPACE_FT

template<typename T>
class random_iterator : public ft::iterator<_IT_TAG::random_access_iterator_tag, T> {
	
	public:
		typedef typename ft::iterator<_IT_TAG::random_access_iterator_tag, T>::value_type         value_type;
		typedef typename ft::iterator<_IT_TAG::random_access_iterator_tag, T>::difference_type    difference_type;
		typedef typename ft::iterator<_IT_TAG::random_access_iterator_tag, T>::pointer            pointer;
		typedef typename ft::iterator<_IT_TAG::random_access_iterator_tag, T>::reference          reference;
		typedef typename ft::iterator<_IT_TAG::random_access_iterator_tag, T>::iterator_category  iterator_category;
		
	private:
		pointer	_current;

	public:

		random_iterator(void) : _current(_nullptr)
		{ }

		explicit random_iterator(pointer it) : _current(it)
		{ }

		random_iterator(const random_iterator& ref) : _current(ref.base())
		{ }
		
		virtual ~random_iterator(void)
		{ }

		operator	random_iterator<const value_type>() const {
			return (random_iterator<const value_type>(this->_current));
		};
		
		pointer
		base (void) const {
			return (_current);
		}

		random_iterator&
		operator=(const random_iterator& ref) {
			if (this == &ref) {return (*this);}

			_current = ref._current;
			return (*this);
		}

		reference
		operator*() const {
			return (*_current);
		}

		pointer
		operator->() const {
			return &(operator*());
		}

		reference
		operator[](difference_type n) const {
			return *(*this + n);
		}
		
		random_iterator&
		operator++() {
			++_current;
			return (*this);
		}
		
		random_iterator&
		operator--() {
			--_current;
			return (*this);
		}

		random_iterator
		operator++(_INT_UNUSED) {
			random_iterator tmp = *this;
			++_current;
			return (tmp);
		}

		random_iterator
		operator--(_INT_UNUSED) {
			random_iterator tmp = *this;
			--_current;
			return (tmp);
		}
		

		random_iterator&
		operator+=( difference_type n ) {
			_current += n;
			return (*this);
		}
		
		random_iterator&
		operator-=( difference_type n ) {	
			_current -= n;
			return (*this);
		}

		random_iterator
		operator+( difference_type n ) const {
			return (random_iterator(_current + n));
		}
		
		random_iterator
		operator-( difference_type n ) const {
			return (random_iterator(_current - n));
		}
		
		friend	difference_type
		operator-(const ft::random_iterator<value_type>& lhs, const ft::random_iterator<value_type>&rhs) {
			return (lhs.base() - rhs.base());
		}

		friend	ft::random_iterator<value_type>
		operator+(const ft::random_iterator<value_type>& lhs, const ft::random_iterator<value_type>&rhs) {
			return random_iterator<value_type>(lhs.base() - rhs);
		}

		friend	difference_type
		operator-(const difference_type n, const ft::random_iterator<value_type>& lhs) {
			return (lhs.base() - n);
		}

		friend	ft::random_iterator<value_type>
		operator+(const difference_type n, const ft::random_iterator<value_type>& lhs) {
			return random_iterator<value_type>(lhs.base() + n);
		}		
};


template< class Iterator1, class Iterator2 >
bool
operator==(	const ft::random_iterator<Iterator1>& lhs, 
			const ft::random_iterator<Iterator2>& rhs ) {
	return (lhs.base() == rhs.base());
}

template< class Iterator1, class Iterator2 >
bool
operator!=(	const ft::random_iterator<Iterator1>& lhs,
			const ft::random_iterator<Iterator2>& rhs ) {
	return (lhs.base() != rhs.base());
}

template< class Iterator1, class Iterator2 >
bool
operator<(	const ft::random_iterator<Iterator1>& lhs,
			const ft::random_iterator<Iterator2>& rhs ) {
	return (lhs.base() < rhs.base());
}

template< class Iterator1, class Iterator2 >
bool
operator<=(	const ft::random_iterator<Iterator1>& lhs,
			const ft::random_iterator<Iterator2>& rhs ) {
	return (lhs.base() <= rhs.base());
}

template< class Iterator1, class Iterator2 >
bool
operator>(	const ft::random_iterator<Iterator1>& lhs,
			const ft::random_iterator<Iterator2>& rhs ) {
	return (lhs.base() > rhs.base());
}

template< class Iterator1, class Iterator2 >
bool
operator>=(	const ft::random_iterator<Iterator1>& lhs,
			const ft::random_iterator<Iterator2>& rhs ) {
	return (lhs.base() >= rhs.base());
}

_END_NAMESPACE_FT
