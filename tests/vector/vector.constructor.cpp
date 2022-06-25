/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.constructor.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 17:21:24 by mamaurai          #+#    #+#             */
/*   Updated: 2022/05/31 17:26:58 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"

int		main(void)
{
	NAMESPACE::vector<TESTED_TYPE> v1;
	NAMESPACE::vector<TESTED_TYPE> v2(v1);
	NAMESPACE::vector<TESTED_TYPE> v3(4);
	NAMESPACE::vector<TESTED_TYPE> v4(4, 7);
	NAMESPACE::vector<TESTED_TYPE> v5(v3.begin() + 1, v3.begin() + 2);

	std::cout << "ft::vector constructors" << std::endl;

	putVector(v1);
	putVector(v2);
	putVector(v3);
	putVector(v4);
	putVector(v5);

	int myints[] = {16,2,77,29};
	NAMESPACE::vector<TESTED_TYPE> v6 (myints, myints + sizeof(myints) / sizeof(int) );

	putVector(v6);

	return 0;
}