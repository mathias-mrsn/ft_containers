/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.push_pop.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 14:22:19 by mamaurai          #+#    #+#             */
/*   Updated: 2022/06/20 09:56:58 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"

int main()
{
	std::cout << "ft::vector::push_back function" << std::endl;
	
	srand(time(NULL));

	NAMESPACE::vector<int> c;

	for (int i = 0; i < 100; i++) {c.push_back(i);}

	NAMESPACE::vector<int> v(10);

	for (int i = 0; i < 100; i++) {v.push_back(i);}

	putVector(v);
	putVector(c);
	std::cout << v.size() << std::endl;
	std::cout << c.size() << std::endl;


	std::cout << "ft::vector::pop_back function" << std::endl;
	for (int i = 0; i < 100; i++) {c.pop_back();}
	for (int i = 0; i < 110; i++) {v.pop_back();}

	
	putVector(c);
	putVector(v);
	std::cout << c.size() << std::endl;
	std::cout << v.size() << std::endl;

	for (int i = 0; i < 10; i++) {v.push_back(i);}
	for (int i = 0; i < 10; i++) {c.push_back(i);}

	putVector(c);
	putVector(v);
	std::cout << c.size() << std::endl;
	std::cout << v.size() << std::endl;
}
