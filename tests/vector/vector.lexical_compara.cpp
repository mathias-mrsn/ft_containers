/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.lexical_compara.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 18:09:25 by mamaurai          #+#    #+#             */
/*   Updated: 2022/06/03 09:24:26 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"

template <class T>
void	cmp(const NAMESPACE::vector<T> &lhs, const NAMESPACE::vector<T> &rhs)
{
	std::cout << "lhs == rhs : " << (lhs == rhs) << std::endl;
	std::cout << "lhs != rhs : " << (lhs != rhs) << std::endl;
	std::cout << "lhs < rhs : " << (lhs < rhs) << std::endl;
	std::cout << "lhs > rhs : " << (lhs > rhs) << std::endl;
	std::cout << "lhs <= rhs : " << (lhs <= rhs) << std::endl;
	std::cout << "lhs >= rhs : " << (lhs >= rhs) << std::endl;
}


int main(void)
{
	NAMESPACE::vector<TESTED_TYPE> v1(10, 4);
	NAMESPACE::vector<TESTED_TYPE> v2(10, 4);

	cmp(v1, v2);
	cmp(v2, v1);
	v2.insert(v2.begin() + 2, 4);
	putVector(v1);
	putVector(v2);

	cmp(v1, v2);
	cmp(v2, v1);
	v1.insert(v1.begin() + 1, 6);
	putVector(v1);
	putVector(v2);


	cmp(v1, v2);
	cmp(v2, v1);
	v2[2] = 4;
	putVector(v1);
	putVector(v2);


	cmp(v1, v2);
	cmp(v2, v1);
	v1[1] = 4;
	putVector(v1);
	putVector(v2);


	cmp(v1, v2);
	cmp(v2, v1);

	return (0);
}