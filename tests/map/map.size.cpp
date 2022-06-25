/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.size.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 11:19:04 by mamaurai          #+#    #+#             */
/*   Updated: 2022/06/13 11:39:01 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"

static void
put_size (_MAP m)
{
	COUT(m.size());
	COUT(m.max_size());
	COUT(m.empty());
	COUT("");
}

int main ()
{
	_MAP m;
	
	put_size(m);

	m[1] = 'a';
	m[2] = 'b';
	m[3] = 'c';
	m[4] = 'd';
	m[5] = 'e';
	
	put_size(m);
	_MERASE(m, 5, 5);
	put_size(m);

	m[5] = 'r';
	m[6] = 'q';
	m[0] = 'x';

	_MERASE(m, 0, 6);
	put_size(m);

	m[8] = 'e';
	
	put_size(m);
}