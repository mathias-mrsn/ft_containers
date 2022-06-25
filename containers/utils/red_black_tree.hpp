/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_black_tree.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 12:31:34 by mamaurai          #+#    #+#             */
/*   Updated: 2022/06/22 14:30:13 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RED_BLACK_TREE_HPP
# define RED_BLACK_TREE_HPP

#include "ft_containers.hpp"
#include "binary_function.hpp"
#include "node_iterator.hpp"
#include "node.hpp"
#include "pair.hpp"
#include "is_integral.hpp"
#include "nullptr.hpp"

#include <limits>

#include <iostream>
#include <typeinfo>

/*	source : https://www.programiz.com/dsa/red-black-tree */

// TODO balanced functions

_BEGIN_NAMESPACE_FT

template < 	class T,
			class Compare,
			class Node = ft::Node<T>,
			class Allocator = std::allocator<Node> >
class RBT {
	
	public:
		typedef T			 						value_type;
		typedef typename Allocator::pointer			pointer;
		typedef typename Allocator::reference		reference;
		typedef Node								node_type;
		typedef typename std::size_t				size_type;
		typedef typename std::ptrdiff_t				difference_type;
		typedef Compare								value_compare;
		typedef Allocator							allocator_type;
		typedef typename Node::color_type			color_type;
		typedef RBT									self;

	private:
		pointer			_root;
		pointer			_end;
		value_compare	_cmp;
		allocator_type	_allocator;
		size_type		_size;

	public:
		
		RBT (const value_compare& cmp = value_compare()) :
			_cmp(cmp),
			_allocator(allocator_type()),
			_size(0)
		{
			_end = _allocator.allocate(1);
			_allocator.construct(_end, Node(value_type(), RED_NODE));
			_root = _end;
		}

		~RBT (void) {
			if (_root != _end)
				destroy_tree();
			_allocator.deallocate(_end, 1);
		}

		bool
		empty (void) const {
			return (_size == 0);
		}

		pointer
		get_root (void) const {
			return (_root);
		}

		pointer
		get_end (void) const {
			return (_end);
		}

		pointer
		get_begin (void) const {
			return (__min(_root));
		}
		
		size_type
		get_size (void) const {
			return (_size);
		}

		size_type
		max_size (void) const {
			return (static_cast<unsigned long>(std::numeric_limits<difference_type>::max() / sizeof(ft::Node<value_type>)));
		}

		void
		swap (self& x) {
			pointer tmp_root = _root;
			pointer tmp_end = _end;
			value_compare tmp_cmp = _cmp;
			allocator_type tmp_allocator = _allocator;
			size_type tmp_size = _size;

			_root = x._root;
			_end = x._end;
			_cmp = x._cmp;
			_allocator = x._allocator;
			_size = x._size;

			x._root = tmp_root;
			x._end = tmp_end;
			x._cmp = tmp_cmp;
			x._allocator = tmp_allocator;
			x._size = tmp_size;
		}
				
		pointer 	insert (const value_type& val) {return (__insert(_root, val));}
		pointer 	insert (value_type& val_hint, const value_type& val) {return (__insert(find(val_hint), val));}
		bool		deletion (const value_type& val) {return (__deletion(_root, val));}
		pointer 	min (void) const {return __min(_root);}
		pointer 	max (void) const {return __max(_root);}
		pointer 	find (const value_type& val) const {return __find(val, _root);}
		size_type	size (void) const {return (_size);}
		void 		destroy_tree (void) {__destroy_tree(_root); _size = 0; _root = _end;}
		pointer		lower_bound (const value_type& val) const {return __lower_bound(val, _root);}
		pointer		upper_bound (const value_type& val) const {return __upper_bound(val, _root);}

	private:
	
		void
		_destroy_node (pointer ntd) {
			_allocator.destroy(ntd);
			_allocator.deallocate(ntd, 1);
		}

		void
		_move_node (pointer x, pointer y) {
			if (x->parent == _end)
				_root = y;
			else if (x == x->parent->left)
				x->parent->left = y;
			else
				x->parent->right = y;
			y->parent = x->parent;
		}

		pointer
		__min (pointer node) const {
			if (!node || node == _end)
				return (_end);
			else {
				for (; node->left != _end; node = node->left);
				return (node);
			}
		}

		pointer
		__max (pointer node) const {
			if (!node || node == _end)
				return (_end);
			else {
				for (; node->right != _end; node = node->right);
				return (node);
			}
		}

		void
		__destroy_tree (pointer node) {
			if (node == _end)
				return;
			__destroy_tree(node->left);
			__destroy_tree(node->right);
			_destroy_node(node);
		}

		bool
		__deletion (pointer node, const value_type& val) {
			pointer node_to_del = __find(val, node);
			pointer node_to_switch;
			pointer node_to_fix;

		    if (node_to_del == _nullptr)
				return (false);
				
			node_to_switch = node_to_del;
			int node_to_switch_original_color = node_to_switch->color;
			if (node_to_del->left == _end) {
				node_to_fix = node_to_del->right;
				_move_node(node_to_del, node_to_del->right);
			} else if (node_to_del->right == _end) {
				node_to_fix = node_to_del->left;
				_move_node(node_to_del, node_to_del->left);
			} else {
				node_to_switch = __min(node_to_del->right);
				node_to_switch_original_color = node_to_switch->color;
				node_to_fix = node_to_switch->right;
				if (node_to_switch->parent == node_to_del)
					node_to_fix->parent = node_to_switch;
				else {
					_move_node(node_to_switch, node_to_switch->right);
					node_to_switch->right = node_to_del->right;
					node_to_switch->right->parent = node_to_switch;
				}
				_move_node(node_to_del, node_to_switch);
				node_to_switch->left = node_to_del->left;
				node_to_switch->left->parent = node_to_switch;
				node_to_switch->color = node_to_del->color;
	    	}
		    _destroy_node(node_to_del);
			_size -= 1;
		    if (node_to_switch_original_color == RED_NODE)
				_delete_fix(node_to_fix);
			return (true);	
		}

		void _delete_fix(pointer node) {
		    pointer save;
		    while (node != _root && node->color == RED_NODE) {
				if (node == node->parent->left) {
					save = node->parent->right;
					if (save->color == BLACK_NODE) {
						save->color = RED_NODE;
						node->parent->color = BLACK_NODE;
						_left_rotate(node->parent);
						save = node->parent->right;
					}
					if (save->left->color == RED_NODE && save->right->color == RED_NODE) {
						save->color = BLACK_NODE;
						node = node->parent;
					} else {
						if (save->right->color == RED_NODE) {
							save->left->color = RED_NODE;
							save->color = BLACK_NODE;
							_right_rotate(save);
							save = node->parent->right;
						}
						save->color = node->parent->color;
						node->parent->color = RED_NODE;
						save->right->color = RED_NODE;
						_left_rotate(node->parent);
						node = _root;
					}
				} else {
					save = node->parent->left;
					if (save->color == BLACK_NODE) {
						save->color = RED_NODE;
						node->parent->color = BLACK_NODE;
						_right_rotate(node->parent);
						save = node->parent->left;
					}
					if (save->right->color == RED_NODE && save->right->color == RED_NODE) {
						save->color = BLACK_NODE;
						node = node->parent;
					} else {
						if (save->left->color == RED_NODE) {
							save->right->color = RED_NODE;
							save->color = BLACK_NODE;
							_left_rotate(save);
							save = node->parent->left;
						}
						save->color = node->parent->color;
						node->parent->color = RED_NODE;
						save->left->color = RED_NODE;
						_right_rotate(node->parent);
						node = _root;
					}
				}
			}
			node->color = RED_NODE;
		}

		pointer
		__insert (pointer node, const value_type& val) {
			pointer n = _allocator.allocate(1);
			_allocator.construct(n, Node(val, BLACK_NODE, _nullptr, _end, _end));

			pointer n_parent = node;

			if (_root == _end) {
				_root = n;
				_root->color = BLACK_NODE;
				_root->parent = _end;
				_size += 1;
				return (_root);
			}
			while(n_parent != _end) {
				if (_cmp(val, n_parent->value)) {
					if (n_parent->left == _end) {break;}
					n_parent = n_parent->left;
				} else if (_cmp(n_parent->value, val)) {
					if (n_parent->right == _end) {break;}
					n_parent = n_parent->right;
				} else {
					_allocator.destroy(n);
					_allocator.deallocate(n, 1);
					return (_nullptr);
				}
			}

			n->parent = n_parent;
			if (_cmp(val, n_parent->value))
				n_parent->left = n;
			else
				n_parent->right = n;

			_size += 1	;
			if (n->parent == _end) {
				n->color = RED_NODE;
				return (n);
			}
			if (n->parent->parent == _end)
				return (n);
			
			n->parent = n_parent;
			_insert_fix(n);
			return (n);
		}

		void _insert_fix(pointer node) {
			pointer p;
			while (node->parent->color == BLACK_NODE) {
				if (node->parent == node->parent->parent->right) {
					p = node->parent->parent->left;
					if (p->color == BLACK_NODE) {
						p->color = RED_NODE;
						node->parent->color = RED_NODE;
						node->parent->parent->color = BLACK_NODE;
						node = node->parent->parent;
					} else {
						if (node == node->parent->left) {
							node = node->parent;
							_right_rotate(node);
						}
						node->parent->color = RED_NODE;
						node->parent->parent->color = BLACK_NODE;
						_left_rotate(node->parent->parent);
					}
				} else {
					p = node->parent->parent->right;
					if (p->color == BLACK_NODE) {
						p->color = RED_NODE;
						node->parent->color = RED_NODE;
						node->parent->parent->color = BLACK_NODE;
						node = node->parent->parent;
					} else {
						if (node == node->parent->right) {
							node = node->parent;
							_left_rotate(node);
						}
						node->parent->color = RED_NODE;
						node->parent->parent->color = BLACK_NODE;
						_right_rotate(node->parent->parent);
					}
				}
				if (node == _root) {
					break;
				}
			}
			_root->color = RED_NODE;
		}

		pointer
		__find (const value_type& val, const pointer current) const {
			if (current == _end)
				return (_nullptr);
			else if (_cmp(current->value, val))
				return (__find(val, current->right));
			else if (_cmp(val, current->value))
				return (__find(val, current->left));
			else
				return (current);
		}

		pointer
		__lower_bound (const value_type& val, const pointer current) const {
			pointer tmp = current;
			pointer save = _end;

			while (tmp != _end) {
				if (!_cmp(tmp->value, val)) {
					save = tmp;
					tmp = tmp->left;
				} else {
					tmp = tmp->right;
				}
			}
			return (save);
		}

		pointer
		__upper_bound (const value_type& val, const pointer current) const {
			pointer tmp = current;
			pointer save = _end;

			while (tmp != _end) {
				if (_cmp(val, tmp->value)) {
					save = tmp;
					tmp = tmp->left;
				} else {
					tmp = tmp->right;
				}
			}
			return (save);
		}

		void
		_right_rotate (pointer node) {
			pointer node_left = node->left;
			node->left = node_left->right;
			if (node_left->right != _end)
				node_left->right->parent = node;
			node_left->parent = node->parent;
			if (node->parent == _end)
				_root = node_left;
			else if (node == node->parent->right)
				node->parent->right = node_left;
			else
				node->parent->left = node_left;
			node_left->right = node;
			node->parent = node_left;
		}
		
		void
		_left_rotate (pointer node) {
			pointer node_right = node->right;
			node->right = node_right->left;
			if (node_right->left != _end)
				node_right->left->parent = node;
			node_right->parent = node->parent;
			if (node->parent == _end)
				_root = node_right;
			else if (node == node->parent->left)
				node->parent->left = node_right;
			else
				node->parent->right = node_right;
			node_right->left = node;
			node->parent = node_right;
		}
		
		pointer
		_successor (pointer node) {
			if (node->right != _end)
				return __min(node->right);
			pointer save = node->parent;
			for(;(save != _end && node == save->right); node = save, save = save->parent);
			return (save); 
		}

		pointer
		_predecessor (pointer node) {
			if (node->left != _end)
				return __max(node->left);
			pointer save = node->parent;
			for(;(save != _end && node == save->left); node = save, save = save->parent);
			return (save);
		}
};

_END_NAMESPACE_FT

#endif