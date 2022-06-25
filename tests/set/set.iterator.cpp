/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.iterator.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 15:43:07 by mamaurai          #+#    #+#             */
/*   Updated: 2022/06/20 15:43:35 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"

#define _SIZE_SET 2000

int main (void)
{
	_SET m;

	for (int i = 0; i < _SIZE_SET; i++)
		m.insert((rand(), (rand() % 50) + 48));

	for (_SET::iterator it = m.begin(); it != m.end(); it++)
		COUT(*it);

	for (_SET::reverse_iterator rit = m.rbegin(); rit != m.rend(); rit++)
		COUT(*rit);

	return (0);
}