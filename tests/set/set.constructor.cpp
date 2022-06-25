/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.constructor.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 13:04:16 by mamaurai          #+#    #+#             */
/*   Updated: 2022/06/20 13:07:07 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"

# define _SET_SIZE	2000

int main (void)
{
	_SET s;

	for (int i = 0; i < _SET_SIZE; i++)
		s.insert((rand(), (rand() % 50) + 48));
	putSet(s);

	_SET s2(s);
	putSet(s2);

	_SET s3((s2.begin()), (s2.end()));
	putSet(s3);

	s3 = s;
	putSet(s3);

	return (0);
}