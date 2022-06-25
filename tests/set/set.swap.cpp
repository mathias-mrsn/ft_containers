/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.swap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 15:58:37 by mamaurai          #+#    #+#             */
/*   Updated: 2022/06/20 15:59:02 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"

#define _SIZE_SET 2000

int main (void)
{
	_SET m;
	_SET m2;

	for (int i = 0; i < _SIZE_SET; i++)
		m.insert((rand(), (rand() % 50) + 48));
	for (int i = 0; i < _SIZE_SET; i++)
		m2.insert((rand(), (rand() % 50) + 48));

	putSet(m);
	putSet(m2);

	m.swap(m2);

	putSet(m);
	putSet(m2);

	swap(m, m2);

	putSet(m);
	putSet(m2);
	
	return (0);
}