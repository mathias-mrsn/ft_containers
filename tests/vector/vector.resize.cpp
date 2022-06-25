/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.resize.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 19:19:44 by mamaurai          #+#    #+#             */
/*   Updated: 2022/06/17 19:22:20 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"

int	main()
{
	NAMESPACE::vector<TESTED_TYPE> v;

	v.resize(15);
	putVector(v);
	v.resize(v.size() - 10);
	putVector(v);
	v.resize(0);
	putVector(v);
	v.resize(100, 42);
	putVector(v);
	v.resize(110, 84);
	putVector(v);
	v.resize(10, 21);
	putVector(v);
	v.resize(25, 54);
	putVector(v);

	return (0);
}