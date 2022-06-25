/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_copy_op.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 11:42:45 by mamaurai          #+#    #+#             */
/*   Updated: 2022/06/04 11:45:52 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"

int	main(void)
{
	NAMESPACE::stack<TESTED_TYPE> s1;

	s1.push(32);
	s1.push(35);
	s1.push(832);

	std::cout << s1.size() << std::endl;
	
	NAMESPACE::stack<TESTED_TYPE> s2;
	s2 = s1;

	std::cout << s2.size() << std::endl;
	std::cout << (s1 == s2) << std::endl;

	NAMESPACE::stack<TESTED_TYPE> s3;

	std::cout << s3.size() << std::endl;

	NAMESPACE::stack<TESTED_TYPE> s4 = s3;

	std::cout << s4.size() << std::endl;
	std::cout << (s3 == s4) << std::endl;
	
	return (0);
}