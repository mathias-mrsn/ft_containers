/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_iterator.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 14:27:13 by mamaurai          #+#    #+#             */
/*   Updated: 2022/06/23 10:28:49 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NODE_ITERATORS_HPP
# define NODE_ITERATORS_HPP

#include "ft_containers.hpp"
#include "node.hpp"
#include "iterator.hpp"
#include "nullptr.hpp"

_BEGIN_NAMESPACE_FT

template <	class T,
			class Node>
class node_iterator : public ft::iterator<std::bidirectional_iterator_tag, T> {
	
	public:
	
		typedef typename ft::iterator<_IT_TAG::bidirectional_iterator_tag, T>::value_type         value_type;
		typedef typename ft::iterator<_IT_TAG::bidirectional_iterator_tag, T>::difference_type    difference_type;
		typedef typename ft::iterator<_IT_TAG::bidirectional_iterator_tag, T>::pointer            pointer;
		typedef typename ft::iterator<_IT_TAG::bidirectional_iterator_tag, T>::reference          reference;
		typedef typename ft::iterator<_IT_TAG::bidirectional_iterator_tag, T>::iterator_category  iterator_category;
		typedef Node								node_type;
		typedef Node*								node_pointer;
		typedef Node&								node_reference;

	private:
		node_pointer _current;
		node_pointer _root;
		node_pointer _end;
		
	public:

		node_iterator (void) :
			_current(),
			_root(),
			_end()
		{ }

		node_iterator (const node_pointer& val, const node_pointer& root, const node_pointer& end) :
			_current((val == _nullptr) ? end : val),
			_root(root),
			_end(end)
		{ }

		node_iterator (const node_iterator& other) :
			_current(other._current),
			_root(other._root),
			_end(other._end)
		{ }

		operator node_iterator<const T, Node> (void) {
			return (node_iterator<const T, Node>(_current, _root, _end));
		}

		node_iterator&
		operator=(const node_iterator& other) {
			if (this == &other) {return (*this);}

			_current = other._current;
			_end = other._end;
			_root = other._root;

			return (*this);
		}

		reference
		operator* (void) const {
			return (_current->value);
		}

		pointer
		operator-> (void) const {
			return (&operator*());
		}

		node_iterator&
		operator++ (void) {
			if (_current == _end)
				_current = _min(_root);
			else
				_current = _successor();
			return (*this);
		}

		node_iterator
		operator++ (_INT_UNUSED) {
			node_iterator tmp = *this;
			if (_current == _end)
				_current = _min(_root);
			else
				_current = _successor();
			return (tmp);
		}

		node_iterator&
		operator-- (void) {
			if (_current == _end)
				_current = _max(_root);
			else
				_current = _predecessor();
			return (*this);
		}

		node_iterator
		operator-- (_INT_UNUSED) {
			node_iterator tmp = *this;
			if (_current == _end)
				_current = _max(_root);
			else
				_current = _predecessor();
			return (tmp);
		}

		friend bool
		operator== (const node_iterator<value_type, node_type> lhs, const node_iterator<value_type, node_type> rhs) {
			return (lhs._current == rhs._current);
		}

		friend bool
		operator!= (const node_iterator<value_type, node_type> lhs, const node_iterator<value_type, node_type> rhs) {
			return (!(lhs == rhs));
		}

	private:
		
		node_pointer
		_successor (void) {
			if (_current->right != _end)
				return (_min(_current->right));
			node_pointer save = _current->parent;
			for(;(save != _end && _current == save->right); _current = save, save = save->parent);
			return (save);
		}

		node_pointer
		_predecessor (void) {
			if (_current->left != _end)
				return (_max(_current->left));
			node_pointer save = _current->parent;
			for(;(save != _end && _current == save->left); _current = save, save = save->parent);
			return (save);
		}

		node_pointer
		_min (node_pointer node) const {
			if (!node || node == _end)
				return (_end);
			else {
				for (; node->left != _end; node = node->left);
				return (node);
			}
		}

		node_pointer
		_max (node_pointer node) const {
			if (!node || node == _end)
				return (_end);
			else {
				for (; node->right != _end; node = node->right);
				return (node);
			}
		}
};

_END_NAMESPACE_FT

#endif /* NODE_ITERATORS_HPP */