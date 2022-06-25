/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.empty.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 17:09:12 by mamaurai          #+#    #+#             */
/*   Updated: 2022/05/30 17:11:50 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"

int
main (void)
{
	NAMESPACE::vector<TESTED_TYPE> v1;
	NAMESPACE::vector<TESTED_TYPE> v2(10, 100);
	NAMESPACE::vector<TESTED_TYPE> v3(v2.begin(), v2.end() - 5);

	std::cout << "ft::vector::size_max" << std::endl;

	std::cout << v1.empty() << std::endl;
	std::cout << v2.empty() << std::endl;
	std::cout << v3.empty() << std::endl;

	v1.push_back(1);

	std::cout << v1.empty() << std::endl;
	std::cout << v2.empty() << std::endl;
	std::cout << v3.empty() << std::endl;

	for(int i = 0; i < 10; i++)
		v2.pop_back();

	std::cout << v1.empty() << std::endl;
	std::cout << v2.empty() << std::endl;
	std::cout << v3.empty() << std::endl;
	
	return (0);
}