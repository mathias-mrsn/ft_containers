/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.lookup.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 16:03:17 by mamaurai          #+#    #+#             */
/*   Updated: 2022/06/18 16:09:40 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"

#define _SIZE_MAP 2000

int main (void)
{
	_MAP m;

	m.insert(_MVALUE(4242, 10));
	for (int i = 0; i < _SIZE_MAP; i++)
		m.insert(_MVALUE(rand(), (rand() % 50) + 48));
	m.insert(_MVALUE(52314, 42));
	
	COUT(m.count(4242));
	COUT(m.find(4242)->first);
	COUT(m.lower_bound(4242)->first);
	COUT(m.upper_bound(4242)->first);
	COUT(m.equal_range(4242).first->first);
	COUT(m.equal_range(4242).first->second);
	COUT(m.equal_range(4242).second->first);
	COUT(m.equal_range(4242).second->second);

	COUT(m.count(52314));
	COUT(m.find(52314)->first);
	COUT(m.lower_bound(52314)->first);
	COUT(m.upper_bound(52314)->first);
	COUT(m.equal_range(52314).first->first);
	COUT(m.equal_range(52314).first->second);
	COUT(m.equal_range(52314).second->first);
	COUT(m.equal_range(52314).second->second);

	_MAP empty;

	COUT(empty.count(52314));
	COUT(empty.find(52314)->first);
	COUT(empty.lower_bound(52314)->first);
	COUT(empty.upper_bound(52314)->first);
	COUT(empty.equal_range(52314).first->first);
	COUT(empty.equal_range(52314).first->second);
	COUT(empty.equal_range(52314).second->first);
	COUT(empty.equal_range(52314).second->second);

	return (0);
}