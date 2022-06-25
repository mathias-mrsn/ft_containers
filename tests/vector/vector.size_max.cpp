/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.size_max.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 16:58:32 by mamaurai          #+#    #+#             */
/*   Updated: 2022/05/30 17:07:32 by mamaurai         ###   ########.fr       */
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

	std::cout << v1.max_size() << std::endl;
	std::cout << v3.max_size() << std::endl;
	std::cout << v2.max_size() << std::endl;
	
	return (0);
}