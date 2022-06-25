/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.swap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 12:52:00 by mamaurai          #+#    #+#             */
/*   Updated: 2022/06/18 12:53:34 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"

int main (void)
{
	_VECTOR v1(10, 42);
	_VECTOR v2(32, 55);

	putVector(v1);
	putVector(v2);

	v1.swap(v2);

	putVector(v1);
	putVector(v2);

	v2.swap(v1);

	putVector(v1);
	putVector(v2);

	return (0);
}