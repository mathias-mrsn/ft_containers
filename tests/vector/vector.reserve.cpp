/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.reserve.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 17:54:01 by mamaurai          #+#    #+#             */
/*   Updated: 2022/06/17 19:19:31 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"

#define TESTED_TYPE int

int		main(void)
{
	NAMESPACE::vector<int> v(7);

	for (int i = 0; i < 7; i++) {v.push_back(i);}
	v.reserve(15);
	for (int i = 7; i < 15; i++) {v.push_back(i);}

	putVector(v);

	v.reserve(10);
	v.reserve(v.capacity() - 1);
	putVector(v);
	v.reserve(v.capacity() + 1);
	putVector(v);
	v.reserve(v.capacity() * 2);
	putVector(v);
	v.reserve(0);
	putVector(v);
		
	return (0);
}