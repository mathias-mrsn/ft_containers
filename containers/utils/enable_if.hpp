/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enable_if.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 15:42:33 by mamaurai          #+#    #+#             */
/*   Updated: 2022/05/25 17:48:39 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENABLE_IF_HPP
# define ENABLE_IF_HPP

#include "ft_containers.hpp"

_BEGIN_NAMESPACE_FT

template<bool B, class T = void>
struct enable_if {};
 
template<class T>
struct enable_if<true, T> {typedef T type;};

_END_NAMESPACE_FT

#endif