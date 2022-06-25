/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.lookup.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 15:44:13 by mamaurai          #+#    #+#             */
/*   Updated: 2022/06/20 15:54:32 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"

#define _SIZE_SET 2000

int main (void)
{
	_SET m;

	m.insert(10);
	for (int i = 0; i < _SIZE_SET; i++)
		m.insert(rand());
	m.insert(52314);
	
	COUT(m.count(4242));
	// COUT(*(m.find(4242)));
	COUT(*m.lower_bound(4242));
	COUT(*m.upper_bound(4242));
	COUT(*(m.equal_range(4242).first));
	COUT(*(m.equal_range(4242).second));

	COUT(m.count(52314));
	COUT(*m.find(52314));
	COUT(*m.lower_bound(52314));
	COUT(*m.upper_bound(52314));
	COUT(*(m.equal_range(52314).first));
	COUT(*(m.equal_range(52314).second));

	_SET empty;

	COUT(empty.count(52314));
	COUT(*empty.find(52314));
	COUT(*empty.lower_bound(52314));
	COUT(*empty.upper_bound(52314));
	COUT(*(empty.equal_range(52314).first));
	COUT(*(empty.equal_range(52314).second));

	return (0);
}