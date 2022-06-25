/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.clear.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 11:26:11 by mamaurai          #+#    #+#             */
/*   Updated: 2022/06/18 12:55:39 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"

#define TESTED_TYPE int

int
main ()
{
	_VECTOR v(10, 27);
	_VECTOR v2(v.begin(), v.end());
	_VECTOR v3(v2);
	_VECTOR v4;

	v4 = v2;
	v.clear();
	putVector(v);
	putVector(v2);
	v2.clear();
	putVector(v2);
	putVector(v3);
	v3.clear();
	putVector(v3);
	putVector(v4);
	v4.clear();
	putVector(v4);
	v.push_back(42);
	putVector(v);

	return (0);
}