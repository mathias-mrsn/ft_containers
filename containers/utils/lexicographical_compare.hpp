/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexicographical_compare.hpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 11:21:41 by mamaurai          #+#    #+#             */
/*   Updated: 2022/11/15 14:36:33 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ft_containers.hpp"

_BEGIN_NAMESPACE_FT

template< class InputIt1, class InputIt2 >
bool equal(InputIt1 first1, InputIt1 last1, InputIt2 first2) {
    for (; first1 != last1; ++first1, ++first2) {
 		if (!(*first1 == *first2))
    		return (false);
    }
    return (true);
}

template< class InputIt1, class InputIt2 >
bool equal(InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2) {
    for (; (first1 != last1 && first2 != last2) ; ++first1, ++first2) {
 		if (!(*first1 == *first2))
    		return (false);
    }
    return ((first1 == last1 && first2 == last2));
}

template< class InputIt1, class InputIt2, class BinaryPredicate >
bool
equal(InputIt1 first1, InputIt1 last1, InputIt2 first2, BinaryPredicate p) {
    for (; first1 != last1; ++first1, ++first2) {
 		if (!p(*first1 == *first2))
    		return (false);
    }
    return (true);
}

template< class InputIt1, class InputIt2 >
bool
lexicographical_compare( InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2) {
    for (; (first1 != last1) && (first2 != last2); ++first1, (void) ++first2 ) {
        if (*first1 < *first2)
			return (true);
        if (*first2 < *first1)
			return (false);
    }
    return ((first1 == last1) && (first2 != last2));
}

template< class InputIt1, class InputIt2, class Compare >
bool
lexicographical_compare(InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2, Compare comp) {
    for (; (first1 != last1) && (first2 != last2); ++first1, (void) ++first2 ) {
        if (comp(*first1, *first2))
			return (true);
        if (comp(*first2, *first1))
			return (false);
    }
    return ((first1 == last1) && (first2 != last2));
}

_END_NAMESPACE_FT
