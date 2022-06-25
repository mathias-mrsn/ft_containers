/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.insert.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 15:36:12 by mamaurai          #+#    #+#             */
/*   Updated: 2022/06/20 15:39:09 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"

#define _SIZE_SET 2000

int main (void)
{
	_SET m;

	for (int i = 0; i < _SIZE_SET; i++)
		m.insert((rand(), (rand() % 50) + 48));

	putSet(m);
	m.insert(m.begin(), m.end());
	putSet(m);

	NAMESPACE::pair<_SET::iterator, bool> p = m.insert(42);

	COUT(*(p.first));

	p = m.insert(42);

	COUT(*(p.first));

	_SET::iterator it = m.insert(m.begin(), 42);

	COUT(*it);

	return (0);
}