/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.erase.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 15:55:55 by mamaurai          #+#    #+#             */
/*   Updated: 2022/06/18 15:58:15 by mamaurai         ###   ########.fr       */
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

	_MAP::iterator it = m.insert(m.begin(), _MVALUE(42, 10));

	COUT(it->first);
	COUT(it->second);

	m.erase(it);
	m.insert(m.begin(), _MVALUE(42, 10));
	m.erase(42);

	putMap(m);

	m.erase(m.begin(), m.end());

	putMap(m);

	m.insert(_MVALUE(rand(), (rand() % 50) + 48));
	
	putMap(m);

	return (0);
}