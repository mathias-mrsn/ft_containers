/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 11:25:31 by mamaurai          #+#    #+#             */
/*   Updated: 2022/06/20 13:08:47 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_HPP
# define TEST_HPP

#include "iterator.hpp"
#include "vector.hpp"
#include "stack.hpp"
#include <vector>
#include <stack>
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include "is_integral.hpp"
#include "enable_if.hpp"
#include "map.hpp"
#include "pair.hpp"
#include "nullptr.hpp"
#include <map>
#include <set>
#include "set.hpp"

# define TESTED_TYPE 	int
# define _VECTOR 		NAMESPACE::vector<TESTED_TYPE>

# define T1 int
# define T2 char

# define _MAP 					NAMESPACE::map<T1, T2>
# define _MVALUE(y, z) 			NAMESPACE::make_pair<T1, T2>(y, z)
# define _MERASE(x, y, z)		x.erase(x.lower_bound(y), x.upper_bound(z));

# define _SET	 				NAMESPACE::set<T1>

template <typename T>
void
putVector (NAMESPACE::vector<T> const &v)
{
	typename NAMESPACE::vector<T>::const_iterator ite = v.end();
	typename NAMESPACE::vector<T>::const_iterator it = v.begin();

	for (; it != ite; it++)
	{
		std::cout << *it << " ";
	}
	COUT("");
	COUT(v.size());
	COUT(v.max_size());
	COUT(v.capacity());
	COUT(v.empty());
	
	std::cout << std::endl;
}

template <typename T, typename C>
void
putMap (NAMESPACE::map<T, C> const &m)
{
	typename NAMESPACE::map<T, C>::const_iterator ite = m.end();
	typename NAMESPACE::map<T, C>::const_iterator it = m.begin();

	for (; it != ite; it++)
	{
		std::cout << it->first << " " << it->second << std::endl;
	}
	COUT("");
	COUT(m.size());
	
# if !defined (__APPLE__) && !defined (__MACH__)
	COUT(m.max_size());
# endif

	COUT(m.empty());
	
	std::cout << std::endl;
}

template <typename T>
void
putSet (NAMESPACE::set<T> const &m)
{
	typename NAMESPACE::set<T>::const_iterator ite = m.end();
	typename NAMESPACE::set<T>::const_iterator it = m.begin();

	for (; it != ite; it++)
	{
		std::cout << *it << std::endl;
	}
	COUT("");
	COUT(m.size());
	
# if !defined (__APPLE__) && !defined (__MACH__)
	COUT(m.max_size());
# endif

	COUT(m.empty());
	
	std::cout << std::endl;
}

#endif