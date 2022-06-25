/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.erase.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 15:32:51 by mamaurai          #+#    #+#             */
/*   Updated: 2022/06/20 15:35:42 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"

#define _SIZE_SET 2000

int main (void)
{
	_SET s;

	for (int i = 0; i < _SIZE_SET; i++)
		s.insert((rand(), (rand() % 50) + 48));

	putSet(s);
	s.insert(s.begin(), s.end());
	putSet(s);

	_SET::iterator it = s.insert(s.begin(), (42));

	COUT(*it);

	s.erase(it);
	s.insert(s.begin(), (42));
	s.erase(42);

	putSet(s);

	s.erase(s.begin(), s.end());

	putSet(s);

	s.insert((rand(), (rand() % 50) + 48));
	
	putSet(s);

	return (0);
}