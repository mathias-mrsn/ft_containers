/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 13:29:36 by mamaurai          #+#    #+#             */
/*   Updated: 2022/06/14 15:00:56 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NODE_HPP
# define NODE_HPP

#include "ft_containers.hpp"
#include "nullptr.hpp"

_BEGIN_NAMESPACE_FT

template < class T >
struct Node {
	
	typedef T		value_type;
	typedef Node	self;

# if defined(__APPLE__) && defined(__MACH__)
	typedef bool	color_type;
# else
	typedef size_t	color_type;
# endif

	Node (void) :
		value(),
		color(BLACK_NODE),
		parent(_nullptr),
		left(_nullptr),
		right(_nullptr)
	{ }

	Node (	const value_type& val,
			const color_type c = BLACK_NODE,
			Node* p = _nullptr,
			Node* l = _nullptr,
			Node* r = _nullptr) :
		value(val),
		color(c),
		parent(p),
		left(l),
		right(r)
	{ }

	Node (const Node& other) :
		value(other.value),
		color(other.color),
		parent(other.parent),
		left(other.left),
		right(other.right)
	{ }

	~Node (void)
	{ }
	
	self&
	operator=(const self& other) {
		if (this == &other) {return (*this);}
		
		value = other.value;
		color = other.color;
		parent = other.parent;
		left = other.left;
		right = other.right;
		
		return (*this);
	}

	T				value;
	color_type		color;
	Node*			parent;
	Node*			left;
	Node*			right;
};

_END_NAMESPACE_FT

#endif /* NODE_HPP */