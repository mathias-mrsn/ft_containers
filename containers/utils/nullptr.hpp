/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nullptr.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 13:59:43 by mamaurai          #+#    #+#             */
/*   Updated: 2022/06/14 15:02:54 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NULLPTR
# define NULLPTR

#include "ft_containers.hpp"

_BEGIN_NAMESPACE_FT

struct nullptr_t
{
    void*	ptr;
	
    struct nat {int b;};
	
    nullptr_t() : ptr(0) {}
    nullptr_t(int nat::*) : ptr(0) {}
    operator int nat::*() const {return 0;}
	
    template <class T>
    operator T* () const {return 0;}
	
    template <class T, class P>
    operator T P::* () const {return 0;}
	
    friend bool operator==(nullptr_t, nullptr_t) {return true;}
    friend bool operator!=(nullptr_t, nullptr_t) {return false;}
};

#define _nullptr	nullptr_t(0)

_END_NAMESPACE_FT

#endif