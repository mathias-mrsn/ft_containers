/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.swap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 15:58:47 by mamaurai          #+#    #+#             */
/*   Updated: 2022/06/18 15:59:51 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"

#define _SIZE_MAP 2000

int main (void)
{
	_MAP m;
	_MAP m2;

	for (int i = 0; i < _SIZE_MAP; i++)
		m.insert(_MVALUE(rand(), (rand() % 50) + 48));
	for (int i = 0; i < _SIZE_MAP; i++)
		m2.insert(_MVALUE(rand(), (rand() % 50) + 48));

	putMap(m);
	putMap(m2);

	m.swap(m2);

	putMap(m);
	putMap(m2);

	swap(m, m2);

	putMap(m);
	putMap(m2);
	
	return (0);
}