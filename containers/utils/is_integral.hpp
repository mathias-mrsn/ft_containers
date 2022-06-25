/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_integral.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 09:55:37 by mamaurai          #+#    #+#             */
/*   Updated: 2022/06/12 11:56:34 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IS_INTEGRAL_HPP
# define IS_INTEGRAL_HPP

#include "ft_containers.hpp"

_BEGIN_NAMESPACE_FT

template<typename T, T v>
struct integral_const {
	typedef T	value_type;
	typedef integral_const<T, v> type;
	
	static const value_type 	value = v;
	
	operator value_type() {return (v);}
};

typedef integral_const<bool, true> true_type;
typedef integral_const<bool, false> false_type;

template<typename T> struct is_integral				: public false_type {};
template<>	struct is_integral<bool>				: public true_type {};
template<>	struct is_integral<char>				: public true_type {};
template<>	struct is_integral<signed char>			: public true_type {};
template<>	struct is_integral<unsigned char>		: public true_type {};
template<>	struct is_integral<wchar_t>				: public true_type {};
template<>	struct is_integral<short>				: public true_type {};
template<>	struct is_integral<unsigned short>		: public true_type {};
template<>	struct is_integral<int>					: public true_type {};
template<>	struct is_integral<unsigned int>		: public true_type {};
template<>	struct is_integral<long>				: public true_type {};
template<>	struct is_integral<long long>			: public true_type {};
template<>	struct is_integral<unsigned long>		: public true_type {};
template<>	struct is_integral<unsigned long long>	: public true_type {};

_END_NAMESPACE_FT

#endif /* IS_INTEGRAL_HPP */