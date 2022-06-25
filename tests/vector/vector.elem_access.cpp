/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.elem_access.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 11:38:10 by mamaurai          #+#    #+#             */
/*   Updated: 2022/06/20 09:58:10 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"

#define _SIZE_VECTOR 1000

int main (void)
{
	NAMESPACE::vector<TESTED_TYPE> v(_SIZE_VECTOR);
	NAMESPACE::vector<TESTED_TYPE> v1(v);
	NAMESPACE::vector<TESTED_TYPE> v2(v.begin() + 50, v.end() - 30);
	NAMESPACE::vector<TESTED_TYPE> v3(156, 42);
	NAMESPACE::vector<TESTED_TYPE> empty;

	int i = 20;
	for (NAMESPACE::vector<TESTED_TYPE>::iterator it = v.begin(); it != v.end(); it++) {
		*it = i++;
	}

	COUT("operator [] and at");

	putVector(v);
	for(int i = 0; i < _SIZE_VECTOR; i++) {
		COUT(v[i]);
		COUT(v.at(i));
	}

	COUT("at exception test")

	try {
		COUT(v.at(v.size() + 1));
	} catch(const std::exception &e)
	{
		COUT(e.what());
	}

	COUT("front");
	
	COUT(v.front());
	COUT(v1.front());
	COUT(v2.front());
	COUT(v3.front());
	// COUT(empty.front()); // BOOM

	COUT("back");

	COUT(v.back());
	COUT(v1.back());
	COUT(v2.back());
	COUT(v3.back());
	// COUT(empty.back()); // BOOM
 
	return (0);
}