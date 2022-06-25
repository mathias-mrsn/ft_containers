/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.functions.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 12:17:31 by mamaurai          #+#    #+#             */
/*   Updated: 2022/06/20 11:06:02 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"
#include <cstring>

#define _TEST_LIST "222343014412222021343201232012321230243021431204312432143123024312044321043021430214"

static void
_launch_functions(NAMESPACE::stack<TESTED_TYPE, NAMESPACE::vector<TESTED_TYPE> > &s, size_t i)
{
	switch(i)
	{
		case 0: {std::cout << s.top() << std::endl; break;}
		case 1: {std::cout << s.empty() << std::endl; break;}
		case 2: {s.push(i); break;}
		case 3: {std::cout << s.size() << std::endl; break;}
		case 4: {s.pop(); break;}
	}
}

int main (void)
{
	NAMESPACE::stack<TESTED_TYPE, NAMESPACE::vector<TESTED_TYPE> > stack;
	
	for (size_t i = 0; i < std::strlen(_TEST_LIST); i++)
		_launch_functions(stack, _TEST_LIST[i] - 48);
	return (0);
}