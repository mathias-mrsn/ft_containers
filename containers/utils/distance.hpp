/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 14:54:25 by mamaurai          #+#    #+#             */
/*   Updated: 2022/11/15 14:54:28 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "iterator.hpp"
#include "ft_containers.hpp"

_BEGIN_NAMESPACE_FT

template<class InputIt>
typename ft::iterator_traits<InputIt>::difference_type
distance(InputIt first, InputIt last) {
	typename ft::iterator_traits<InputIt>::difference_type size = 0;

	for (; first != last; ++first) {
		size++;
	}
	return (size);
}

_END_NAMESPACE_FT
