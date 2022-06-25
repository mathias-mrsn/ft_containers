/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 12:00:38 by mamaurai          #+#    #+#             */
/*   Updated: 2022/06/13 15:01:49 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP

#include "iterator.hpp"
#include "ft_containers.hpp"

_BEGIN_NAMESPACE_FT

/**
 * @brief Return the distance between two iterators
 * 
 * @tparam InputIt 
 * @param first 
 * @param last 
 * @return ft::iterator_traits<InputIt>::difference_type 
 */
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

#endif /* UTILS_HPP */