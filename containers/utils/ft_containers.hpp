/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_containers.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 11:46:16 by mamaurai          #+#    #+#             */
/*   Updated: 2022/06/23 10:36:40 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CONTAINERS_HPP
# define FT_CONTAINERS_HPP

// TODO clean every files (indentation, newline...)

# define _BEGIN_NAMESPACE_FT 		namespace ft {
# define _END_NAMESPACE_FT 			};
# define _IT_TAG	 				std

# define BLACK_NODE 0
# define RED_NODE 1

# define _INT_UNUSED				__attribute__((unused)) int _
# define _UNUSED					__attribute__((unused))

// * define only for map and set * //

# define ROOT_						_t.get_root()
# define END_						_t.get_end()
# define BEGIN_						_t.get_begin()
# define _KEY(k)					value_type(k, mapped_type())

// * print define * //

# define COUT(x)					std::cout << x << std::endl;

#endif /* FT_CONTAINERS_HPP */