/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.comp.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 15:39:56 by mamaurai          #+#    #+#             */
/*   Updated: 2022/06/20 15:40:58 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"

#define _SIZE_SET 2000

static void
cmp (const _SET &x, const _SET &y)
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
	_SET m;
	_SET m2;
	_SET m3;
	_SET m4;

	for (int i = 0; i < _SIZE_SET; i++)
		m.insert((rand(), (rand() % 50) + 48));
	for (int i = 0; i < _SIZE_SET; i++)
		m2.insert((rand(), (rand() % 50) + 48));
	for (int i = 0; i < _SIZE_SET; i++)
		m3.insert((rand(), (rand() % 50) + 48));
	for (int i = 0; i < _SIZE_SET; i++)
		m4.insert((rand(), (rand() % 50) + 48));

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