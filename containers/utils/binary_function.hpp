/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_function.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 15:41:58 by mamaurai          #+#    #+#             */
/*   Updated: 2022/06/12 11:56:21 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_HPP
# define TREE_HPP

#include "ft_containers.hpp"

_BEGIN_NAMESPACE_FT

template <	class T1,
			class T2,
			class Result >
struct binary_function {
	typedef T1		first_argument_type;
	typedef T2		second_argument_type;
	typedef Result	result_type;
}; /* binary_function */

template < typename T >
struct equal_to : public binary_function<T, T, bool> {
	bool
	operator()(const T x, const T y) const {
		return (x == y);
	}
}; /* equal_to */

template < typename T >
struct not_equal_to : public binary_function<T, T, bool> {
	bool
	operator()(const T x, const T y) const {
		return (x != y);
	}
}; /* not_equal_to */

template < typename T >
struct greater : public binary_function<T, T, bool> {
	bool
	operator()(const T x, const T y) const {
		return (x > y);
	}
}; /* greater */

template < typename T >
struct less : public binary_function<T, T, bool> {
	bool
	operator()(const T x, const T y) const {
		return (x < y);
	}
}; /* less */

template < typename T >
struct greater_equal : public binary_function<T, T, bool> {
	bool
	operator()(const T x, const T y) const {
		return (x >= y);
	}
}; /* greater_equal */

template < typename T >
struct less_equal : public binary_function<T, T, bool> {
	bool
	operator()(const T x, const T y) const {
		return (x <= y);
	}
}; /* less_equal */

_END_NAMESPACE_FT

#endif /* TREE_HPP */