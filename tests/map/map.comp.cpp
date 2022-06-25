/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.comp.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 16:10:23 by mamaurai          #+#    #+#             */
/*   Updated: 2022/06/18 16:13:57 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"

#define _SIZE_MAP 2000

static void
cmp (const _MAP &x, const _MAP &y)
{
	COUT((x == y));
	COUT((x != y));
	COUT((x < y));
	COUT((x > y));
	COUT((x <= y));
	COUT((x >= y));
}

int main (void)
{
	_MAP m;
	_MAP m2;
	_MAP m3;
	_MAP m4;

	for (int i = 0; i < _SIZE_MAP; i++)
		m.insert(_MVALUE(rand(), (rand() % 50) + 48));
	for (int i = 0; i < _SIZE_MAP; i++)
		m2.insert(_MVALUE(rand(), (rand() % 50) + 48));
	for (int i = 0; i < _SIZE_MAP; i++)
		m3.insert(_MVALUE(rand(), (rand() % 50) + 48));
	for (int i = 0; i < _SIZE_MAP; i++)
		m4.insert(_MVALUE(rand(), (rand() % 50) + 48));

	cmp(m, m2);
	cmp(m, m3);
	cmp(m, m4);
	cmp(m2, m3);
	cmp(m2, m4);
	cmp(m3, m3);
	cmp(m3, m4);
	cmp(m, m);

	return (0);
}