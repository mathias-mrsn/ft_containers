/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.ope_cmp.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 12:17:53 by mamaurai          #+#    #+#             */
/*   Updated: 2022/06/04 12:23:34 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"

static void
cmp (NAMESPACE::stack<TESTED_TYPE, NAMESPACE::vector<TESTED_TYPE> > &lhs,
	NAMESPACE::stack<TESTED_TYPE, NAMESPACE::vector<TESTED_TYPE> > &rhs)
{
	std::cout << "lhs == rhs : " << (lhs == rhs) << std::endl;
	std::cout << "lhs != rhs : " << (lhs != rhs) << std::endl;
	std::cout << "lhs < rhs : " << (lhs < rhs) << std::endl;
	std::cout << "lhs > rhs : " << (lhs > rhs) << std::endl;
	std::cout << "lhs <= rhs : " << (lhs <= rhs) << std::endl;
	std::cout << "lhs >= rhs : " << (lhs >= rhs) << std::endl;
}

int	main (void)
{
	NAMESPACE::stack<TESTED_TYPE, NAMESPACE::vector<TESTED_TYPE> > s1;
	NAMESPACE::stack<TESTED_TYPE, NAMESPACE::vector<TESTED_TYPE> > s2;

	cmp(s1, s2);
	cmp(s2, s1);
	s1.push(4);

	cmp(s1, s2);
	cmp(s2, s1);
	s2.push(4);

	cmp(s1, s2);
	cmp(s2, s1);
	s1.pop();

	cmp(s1, s2);
	cmp(s2, s1);
	s1.push(4);

	return (0);
}