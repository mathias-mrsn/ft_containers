/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_function.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 15:41:58 by mamaurai          #+#    #+#             */
/*   Updated: 2022/11/15 14:37:24 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ft_containers.hpp"

_BEGIN_NAMESPACE_FT

template <	class T1,
			class T2,
			class Result >
struct binary_function {
	typedef T1		first_argument_type;
	typedef T2		second_argument_type;
	typedef Result	result_type;
};

template < typename T >
struct equal_to : public binary_function<T, T, bool> {
	bool
	operator()(const T x, const T y) const {
		return (x == y);
	}
};

template < typename T >
struct not_equal_to : public binary_function<T, T, bool> {
	bool
	operator()(const T x, const T y) const {
		return (x != y);
	}
};

template < typename T >
struct greater : public binary_function<T, T, bool> {
	bool
	operator()(const T x, const T y) const {
		return (x > y);
	}
};

template < typename T >
struct less : public binary_function<T, T, bool> {
	bool
	operator()(const T x, const T y) const {
		return (x < y);
	}
};

template < typename T >
struct greater_equal : public binary_function<T, T, bool> {
	bool
	operator()(const T x, const T y) const {
		return (x >= y);
	}
};

template < typename T >
struct less_equal : public binary_function<T, T, bool> {
	bool
	operator()(const T x, const T y) const {
		return (x <= y);
	}
};

_END_NAMESPACE_FT
