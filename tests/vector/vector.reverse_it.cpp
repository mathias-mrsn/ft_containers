/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.reverse_it.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 13:05:44 by mamaurai          #+#    #+#             */
/*   Updated: 2022/06/18 12:59:46 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"

int		main(void)
{
	_VECTOR v (5, 99);

	_VECTOR::reverse_iterator rit = v.rbegin();

	for (int i = 0; rit!= v.rend(); ++rit)
		*rit = ++i;

	putVector(v);

	return 0;
}
