/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.size.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 15:55:08 by mamaurai          #+#    #+#             */
/*   Updated: 2022/06/20 15:57:53 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"

static void
put_size (_SET m)
{
	COUT(m.size());
	COUT(m.max_size());
	COUT(m.empty());
	COUT("");
}

int main ()
{
	_SET m;
	
	put_size(m);

	m.insert(1);
	m.insert(2);
	m.insert(3);
	m.insert(4);
	m.insert(5);
	
	put_size(m);
	_MERASE(m, 5, 5);
	put_size(m);

	m.insert(5);
	m.insert(6);
	m.insert(0);

	_MERASE(m, 0, 6);
	put_size(m);

	m.insert(8);
	
	put_size(m);
}