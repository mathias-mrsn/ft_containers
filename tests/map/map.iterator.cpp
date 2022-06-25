/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.iterator.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 15:43:08 by mamaurai          #+#    #+#             */
/*   Updated: 2022/06/20 15:43:09 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"

#define _SIZE_MAP 2000

int main (void)
{
	_MAP m;

	for (int i = 0; i < _SIZE_MAP; i++)
		m.insert(_MVALUE(rand(), (rand() % 50) + 48));

	for (_MAP::iterator it = m.begin(); it != m.end(); it++)
		COUT(it->second);

	for (_MAP::reverse_iterator rit = m.rbegin(); rit != m.rend(); rit++)
		COUT(rit->second);

	return (0);
}