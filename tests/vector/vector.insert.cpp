/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.insert.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 09:33:18 by mamaurai          #+#    #+#             */
/*   Updated: 2022/06/18 12:51:11 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"

#define _LIMIT 10

int
main (void)
{
	_VECTOR v1(50, 7);
	putVector(v1);
	v1.insert(v1.end(), 4, 9);
	putVector(v1);
	std::cout << v1.size() << std::endl;
	std::cout << std::endl << std::endl;
	
	_VECTOR v2(55, 10);
	putVector(v2);
	std::cout << "insert" << std::endl;
	v2.insert(v2.end() - 10, v1.rbegin(), v1.rend());
	putVector(v2);
	std::cout << *(v2.insert(v2.begin() + 2, 42)) << std::endl;
	putVector(v2);

	_VECTOR vct(10);
	_VECTOR vct2;

	for (unsigned long int i = 0; i < vct.size(); ++i)
		vct[i] = (vct.size() - i) * 3;
	putVector(vct);
	vct2.insert(vct2.end(), 42);
	vct2.insert(vct2.begin(), 2, 21);
	putVector(vct2);
	vct2.insert(vct2.end() - 3, 42);
	putVector(vct2);
	vct2.insert(vct2.end(), 32, 84);
	putVector(vct2);
	vct2.resize(4);
	putVector(vct2);
	vct2.insert(vct2.begin() + 2, vct.begin(), vct.end());
	vct.clear();
	putVector(vct2);
	putVector(vct);

	return (0);
}