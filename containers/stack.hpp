/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 15:35:10 by mamaurai          #+#    #+#             */
/*   Updated: 2022/11/15 14:39:04 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "vector.hpp"
#include "ft_containers.hpp"

_BEGIN_NAMESPACE_FT

template <class T, class Container = ft::vector<T> >
class stack {
	
	public:
		typedef Container								container_type;
		typedef typename Container::value_type 			value_type;
		typedef typename Container::size_type 			size_type;
		typedef typename Container::reference 			reference;
		typedef typename Container::const_reference 	const_reference;

	protected:
		container_type c;

	public:

		explicit stack (const Container& cont = Container())
		: c(cont)
		{ }

		stack (const stack& other) {
			*this = other;
		}

		~stack (void)
		{ }

		stack&
		operator= (const stack& ref) {
			c = ref.c;
			return (*this);
		}

		reference
		top (void) {
			return (c.back());
		}

		const_reference
		top (void) const {
			return (c.back());
		}

		bool
		empty (void) const {
			return (c.size() == 0);
		}

		size_type
		size (void) const {
			return (c.size());
		}

		void
		push (const value_type& value) {
			c.push_back(value);
		}

		void
		pop (void) {
			c.pop_back();
		}

		friend bool
		operator== (const ft::stack<T, Container>& lhs, const ft::stack<T, Container>& rhs) {
			return (lhs.c == rhs.c);
		}

		friend bool
		operator!= (const ft::stack<T, Container>& lhs, const ft::stack<T, Container>& rhs) {
			return (lhs.c != rhs.c);
		}

		friend bool
		operator< (const ft::stack<T, Container>& lhs, const ft::stack<T, Container>& rhs) {
			return (lhs.c < rhs.c);
		}

		friend bool
		operator> (const ft::stack<T, Container>& lhs, const ft::stack<T, Container>& rhs) {
			return (lhs.c > rhs.c);
		}

		friend bool
		operator<= (const ft::stack<T, Container>& lhs, const ft::stack<T, Container>& rhs) {
			return (lhs.c <= rhs.c);
		}

		friend bool
		operator>= (const ft::stack<T, Container>& lhs, const ft::stack<T, Container>& rhs) {
			return (lhs.c >= rhs.c);
		}
		
};

_END_NAMESPACE_FT
