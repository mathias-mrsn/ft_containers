/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.size.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 16:54:04 by mamaurai          #+#    #+#             */
/*   Updated: 2022/06/20 10:58:20 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"

void	is_empty(NAMESPACE::vector<TESTED_TYPE> const &vct)
{
	std::cout << "is_empty: " << vct.empty() << std::endl;
}

int main()
{
	std::cout << "ft::vector::size function" << std::endl;
	
	NAMESPACE::vector<int> c(2);

	c.push_back(5);
	c.push_back(7321);
	c.push_back(12);
	c.push_back(351);

	std::cout << c.size() << std::endl;

	c.pop_back();
	c.pop_back();

	std::cout << c.size() << std::endl;	

	NAMESPACE::vector<long>				long_;
	NAMESPACE::vector<std::string>		strs(3, "string");

	long_.push_back(true);
	long_.push_back(false);
	long_.push_back(true);

	putVector(long_);
	putVector(c);
	putVector(strs);

	std::cout << std::endl;	
	const int start_size = 7;
	NAMESPACE::vector<TESTED_TYPE> vct(start_size, 20);
	NAMESPACE::vector<TESTED_TYPE> vct2;
	NAMESPACE::vector<TESTED_TYPE>::iterator it = vct.begin();

	for (int i = 2; i < start_size; ++i)
		it[i] = (start_size - i) * 3;
	putVector(vct);

	vct.resize(10, 42);
	putVector(vct);

	vct.resize(18, 43);
	putVector(vct);
	vct.resize(10);
	putVector(vct);
	vct.resize(23, 44);
	putVector(vct);
	vct.resize(5);
	putVector(vct);
	vct.reserve(5);
	vct.reserve(3);
	putVector(vct);
	vct.resize(87);
	vct.resize(5);
	putVector(vct);

	is_empty(vct2);
	vct2 = vct;
	is_empty(vct2);
	vct.reserve(vct.capacity() + 1);
	putVector(vct);

	COUT("here");

	putVector(vct2);

	vct2.resize(0);
	is_empty(vct2);
	putVector(vct2);
	return 0;
}


