/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 11:44:10 by mamaurai          #+#    #+#             */
/*   Updated: 2022/06/16 14:55:17 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

#include "iterator.hpp"
#include "enable_if.hpp"
#include "is_integral.hpp"

_BEGIN_NAMESPACE_FT

template<typename T>
class reverse_iterator : public ft::iterator<	
										typename iterator_traits<T>::iterator_category,
										typename iterator_traits<T>::value_type,
										typename iterator_traits<T>::difference_type,
										typename iterator_traits<T>::pointer,
										typename iterator_traits<T>::reference
										> {
									
	public:
		typedef T														iterator_type;
		typedef typename ft::iterator_traits<T>::iterator_category 		iterator_category;
		typedef typename ft::iterator_traits<T>::value_type 			value_type;
		typedef typename ft::iterator_traits<T>::difference_type 		difference_type;
		typedef typename ft::iterator_traits<T>::pointer				pointer;
		typedef typename ft::iterator_traits<T>::reference				reference;
	
	protected:
		iterator_type		_current;
	
	public:

		reverse_iterator() : _current()
		{ }

		explicit reverse_iterator (iterator_type it) : _current(it)
		{ }

		template <class Iter>
		reverse_iterator (const reverse_iterator<Iter>& rev_it) :
			_current(rev_it.base())
		{ }

		iterator_type
		base (void) const {
			return (_current);
		}

		operator reverse_iterator<const iterator_type>() const {
			return (reverse_iterator<const iterator_type>(_current));
		}

		template<class U>
		reverse_iterator&
		operator=(const reverse_iterator<U>& ref) {
			if (*this == ref) {return (*this);}

			_current = ref.base();
			return (*this);
		}

		reference
		operator*() const {
			iterator_type tmp = _current;
			return (*--tmp);
		}

		pointer
		operator->() const {
			return &(operator*());
		}

		reference
		operator[](difference_type n) const {
			return *(*this + n);
		}

		reverse_iterator&
		operator++() {
			--_current;
			return (*this);
		}
		
		reverse_iterator&
		operator--() {
			++_current;
			return (*this);
		}

		reverse_iterator
		operator++(_INT_UNUSED) {
			reverse_iterator tmp = *this;
			--_current;
			return (tmp);
		}

		reverse_iterator
		operator--(_INT_UNUSED) {
			reverse_iterator tmp = *this;
			++_current;
			return (tmp);
		}

		reverse_iterator& operator+=( difference_type n ) {
			_current -= n;
			return (*this);
		}
		
		reverse_iterator& operator-=( difference_type n ) {
			_current += n;
			return (*this);
		}
		
		reverse_iterator
		operator+( difference_type n ) const {
			return (reverse_iterator(base() - n));
		}
		

		reverse_iterator
		operator-( difference_type n ) const {
			return (reverse_iterator(base() + n));
		}
};

template< class Iterator1, class Iterator2 >
bool
operator==(	const ft::reverse_iterator<Iterator1>& lhs, 
			const ft::reverse_iterator<Iterator2>& rhs ) {
	return (lhs.base() == rhs.base());
}

template< class Iterator1, class Iterator2 >
bool
operator!=(	const ft::reverse_iterator<Iterator1>& lhs,
			const ft::reverse_iterator<Iterator2>& rhs ) {
	return (lhs.base() != rhs.base());
}

template< class Iterator1, class Iterator2 >
bool
operator<(	const ft::reverse_iterator<Iterator1>& lhs,
			const ft::reverse_iterator<Iterator2>& rhs ) {
	return (lhs.base() > rhs.base());
}

template< class Iterator1, class Iterator2 >
bool
operator<=(	const ft::reverse_iterator<Iterator1>& lhs,
			const ft::reverse_iterator<Iterator2>& rhs ) {
	return (lhs.base() >= rhs.base());
}

template< class Iterator1, class Iterator2 >
bool
operator>(	const ft::reverse_iterator<Iterator1>& lhs,
			const ft::reverse_iterator<Iterator2>& rhs ) {
	return (lhs.base() < rhs.base());
}

template< class Iterator1, class Iterator2 >
bool
operator>=(	const ft::reverse_iterator<Iterator1>& lhs,
			const ft::reverse_iterator<Iterator2>& rhs ) {
	return (lhs.base() <= rhs.base());
}

template< class Iter > 
typename ft::reverse_iterator<Iter> 
operator+(	typename reverse_iterator<Iter>::difference_type n,
			const reverse_iterator<Iter>& it ) {
	return (reverse_iterator<Iter>(it.base() - n));
}


template<class Ite1, class Ite2>
typename ft::reverse_iterator<Ite1>::difference_type
operator-(const reverse_iterator<Ite1>& lhs, const reverse_iterator<Ite2>& rhs) {
	return (rhs.base() - lhs.base());
}

template <class Iterator>
bool
operator==(	const reverse_iterator<Iterator>& lhs,
			const reverse_iterator<Iterator>& rhs) {
	return (lhs.base() == rhs.base());
}

template <class Iterator>
bool
operator!=(	const reverse_iterator<Iterator>& lhs,
			const reverse_iterator<Iterator>& rhs) {
	return (lhs.base() != rhs.base());
}

template <class Iterator>
bool
operator<(	const reverse_iterator<Iterator>& lhs,
			const reverse_iterator<Iterator>& rhs) {
	return (lhs.base() > rhs.base());
}

template <class Iterator>
bool
operator<=(	const reverse_iterator<Iterator>& lhs,
			const reverse_iterator<Iterator>& rhs) {
	return (lhs.base() >= rhs.base());
}

template <class Iterator>
bool
operator>(	const reverse_iterator<Iterator>& lhs,
			const reverse_iterator<Iterator>& rhs) {
	return (lhs.base() < rhs.base());
}

template <class Iterator>
bool
operator>=(	const reverse_iterator<Iterator>& lhs,
			const reverse_iterator<Iterator>& rhs) {
	return (lhs.base() <= rhs.base());
}

_END_NAMESPACE_FT

#endif /* REVERSE_ITERATOR_HPP */