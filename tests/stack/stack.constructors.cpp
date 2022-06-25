/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.constructors.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 11:31:29 by mamaurai          #+#    #+#             */
/*   Updated: 2022/06/04 11:40:46 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"

int		main(void)
{
	NAMESPACE::stack<TESTED_TYPE> s1;

	s1.push(32);
	s1.push(35);
	s1.push(832);

	std::cout << s1.size() << std::endl;
	
	NAMESPACE::stack<TESTED_TYPE> s2(s1);
	
	std::cout << s2.size() << std::endl;
	std::cout << (s1 == s2) << std::endl;

	NAMESPACE::vector<TESTED_TYPE>	v(5, 10);

	NAMESPACE::stack<TESTED_TYPE, NAMESPACE::vector<TESTED_TYPE> > s3;

	std::cout << s3.size() << std::endl;

	return (0);
}