/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.constructor.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 13:04:09 by mamaurai          #+#    #+#             */
/*   Updated: 2022/06/20 13:06:59 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"

# define _MAP_SIZE	2000

int main (void)
{
	_MAP m;

	for (int i = 0; i < _MAP_SIZE; i++)
		m.insert(_MVALUE(rand(), (rand() % 50) + 48));
	putMap(m);

	_MAP m2(m);
	putMap(m2);

	_MAP m3((m2.begin()), (m2.end()));
	putMap(m3);

	m3 = m;
	putMap(m3);

	return (0);
}