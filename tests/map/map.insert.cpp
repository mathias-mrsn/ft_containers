/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.insert.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 15:55:43 by mamaurai          #+#    #+#             */
/*   Updated: 2022/06/18 15:55:44 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"

#define _SIZE_MAP 2000

int main (void)
{
	_MAP m;

	for (int i = 0; i < _SIZE_MAP; i++)
		m.insert(_MVALUE(rand(), (rand() % 50) + 48));

	putMap(m);
	m.insert(m.begin(), m.end());
	putMap(m);

	NAMESPACE::pair<_MAP::iterator, bool> p = m.insert(_MVALUE(42, 10));

	COUT(p.first->first);
	COUT(p.first->second);
	COUT(p.second);

	p = m.insert(_MVALUE(42, 10));

	COUT(p.first->first);
	COUT(p.first->second);
	COUT(p.second);

	_MAP::iterator it = m.insert(m.begin(), _MVALUE(42, 10));

	COUT(it->first);
	COUT(it->second);

	return (0);
}