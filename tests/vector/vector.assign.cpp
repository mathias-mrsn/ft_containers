/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.assign.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 15:21:19 by mamaurai          #+#    #+#             */
/*   Updated: 2022/06/18 12:46:28 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"

#define TESTED_TYPE int

int		main(void)
{
	_VECTOR v;

	v.assign(42, 100);
	putVector(v);

	_VECTOR v2(v);
	v2.assign(v.begin(), v.end());
	putVector(v2);
	v2.assign(v.begin(), v.begin());
	putVector(v2);
	
	int tab[] = {1, 3, 5, 7, 9};
	v2.assign(tab + 1, tab + 4);
	putVector(v);

	return (0);
}
