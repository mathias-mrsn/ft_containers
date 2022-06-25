/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 10:55:18 by mamaurai          #+#    #+#             */
/*   Updated: 2022/06/23 10:26:11 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
# define ITERATOR_HPP

#include <iostream>
#include "ft_containers.hpp"

_BEGIN_NAMESPACE_FT

struct input_iterator_tag { };
struct output_iterator_tag { };
struct forward_iterator_tag : public input_iterator_tag { };
struct bidirectional_iterator_tag : public forward_iterator_tag { };
struct random_access_iterator_tag : public bidirectional_iterator_tag { };

template<class Category, class T, class Distance = std::ptrdiff_t, class Pointer = T*, class Reference = T&>
struct iterator {
	typedef Category							iterator_category;
	typedef T									value_type;
	typedef Distance							difference_type;
	typedef Pointer								pointer;
	typedef Reference							reference;
};

template<class Iter>
struct iterator_traits {
	typedef typename Iter::difference_type				difference_type;
	typedef typename Iter::value_type	 				value_type;
	typedef typename Iter::pointer 						pointer;
	typedef typename Iter::reference 					reference;
	typedef typename Iter::iterator_category			iterator_category;
};

template<class T>
struct iterator_traits<T*> {
	typedef std::ptrdiff_t						difference_type;
	typedef T			 						value_type;
	typedef T*									pointer;
	typedef T&				 					reference;
	typedef _IT_TAG::random_access_iterator_tag		iterator_category;
};

template<class T>
struct iterator_traits<const T*> {
	typedef std::ptrdiff_t						difference_type;
	typedef T			 						value_type;
	typedef const T*							pointer;
	typedef const T&							reference;
	typedef _IT_TAG::random_access_iterator_tag		iterator_category;
};
		
_END_NAMESPACE_FT

#endif