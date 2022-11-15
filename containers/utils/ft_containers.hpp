/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_containers.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 11:46:16 by mamaurai          #+#    #+#             */
/*   Updated: 2022/11/15 14:36:52 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# define _BEGIN_NAMESPACE_FT 		namespace ft {
# define _END_NAMESPACE_FT 			};
# define _IT_TAG	 				std

# define BLACK_NODE 0
# define RED_NODE 1

# define _INT_UNUSED				__attribute__((unused)) int _
# define _UNUSED					__attribute__((unused))

# define ROOT_						_t.get_root()
# define END_						_t.get_end()
# define BEGIN_						_t.get_begin()
# define _KEY(k)					value_type(k, mapped_type())

# define COUT(x)					std::cout << x << std::endl;
