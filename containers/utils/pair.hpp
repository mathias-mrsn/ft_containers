/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 11:23:20 by mamaurai          #+#    #+#             */
/*   Updated: 2022/06/13 11:11:40 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAIR_HPP
# define PAIR_HPP

#include "ft_containers.hpp"

_BEGIN_NAMESPACE_FT

template <class T1, class T2>
struct pair {
	
	typedef T1 	first_type;
	typedef T2	second_type;
	
	first_type 	first;
	second_type second;	

	pair (void) :
	first(), second()
	{ }

	pair (const first_type& a, const second_type& b) :
	first(a), second(b)
	{ }

	template<class U, class V>
	pair (const pair<U,V>& pr) :
	first(pr.first), second(pr.second)
	{ }

	~pair (void)
	{ }

	pair&
	operator= (const pair& pr) {
		if (this == &pr) {return (*this);}
		
		first = pr.first;
		second = pr.second;

		return (*this);
	}	
};

template <class T1, class T2>
bool operator==(const pair< T1, T2 >& lhs, const pair< T1, T2 >& rhs) {
	return (lhs.first == rhs.first && lhs.second == rhs.second);
}

template <class T1, class T2>
bool operator!=(const pair< T1, T2 >& lhs, const pair< T1, T2 >& rhs) {
	return !(lhs == rhs);
}

template <class T1, class T2>
bool operator<(const pair< T1, T2 >& lhs, const pair< T1, T2 >& rhs) {
	return (lhs.first < rhs.first || (!(rhs.first < lhs.first) && lhs.second < rhs.second));
}

template <class T1, class T2>
bool operator<=(const pair< T1, T2 >& lhs, const pair< T1, T2 >& rhs) {
	return !(rhs < lhs);
}

template <class T1, class T2>
bool operator>(const pair< T1, T2 >& lhs, const pair< T1, T2 >& rhs) {
	return (rhs < lhs);
}

template <class T1, class T2>
bool operator>=(const pair< T1, T2 >& lhs, const pair< T1, T2 >& rhs) {
	return !(lhs < rhs);
}

template <class T1,class T2>
pair< T1, T2 > make_pair (T1 x, T2 y) {
	return (pair< T1, T2 >(x, y));
}

_END_NAMESPACE_FT

#endif /* PAIR_HPP */