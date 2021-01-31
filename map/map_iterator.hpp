//
// Created by jnannie on 1/22/21.
//

#ifndef MAP_ITERATOR_HPP
#define MAP_ITERATOR_HPP

#include "map_node.hpp"
#include "../common/utils.hpp"
#include <iterator>
#include <cstddef>

namespace ft {

	template<class T, class Compare = ft::less<typename T::first_type> >
	class map_iterator {
	public:
		typedef T value_type;
		typedef ptrdiff_t difference_type;
		typedef T *pointer;
		typedef T &reference;
		typedef std::bidirectional_iterator_tag iterator_category;
		typedef map_node<typename ft::remove_const<T>::type> node;

		template<class, class, class>
		friend class map;

		template<class, class>
		friend class map_iterator;

	private:
		node* _p;
		Compare _comp;

	public:
		map_iterator() : _p(NULL), _comp() { }
		map_iterator(const map_iterator& other)
				: _p(other._p), _comp(other._comp) { }
		template <class U>
		map_iterator(map_iterator<U> const& other, typename ft::enable_if<!ft::is_const<U>::value>::type* = NULL)
				: _p(other._p), _comp(other._comp) { }
		map_iterator(node* p) : _p(p), _comp() { }
		~map_iterator() { }

		const map_iterator& operator=(const map_iterator& rhs) { _p = rhs._p; return *this; }

		template <class U>
		friend bool operator== (const map_iterator<U, Compare>& lhs, const map_iterator<U, Compare>& rhs) {
			return lhs._p == rhs._p;
		}

		template <class U>
		friend bool operator!= (const map_iterator<U, Compare>& lhs, const map_iterator<U, Compare>& rhs) {
			return !(lhs == rhs);
		}

		reference operator*() const { return _p->value; }
		pointer operator->() const { return &_p->value; }

		map_iterator& operator++() { //prefix increment
			_p = next_node();
			return *this;
		}
		map_iterator operator++(int) { //postfix increment
			map_iterator temp = *this;
			++(*this);
			return temp;
		}

		map_iterator& operator--() {
			_p = prev_node();
			return *this;
		}
		map_iterator operator--(int) {
			map_iterator temp = *this;
			--(*this);
			return temp;
		}

	private:
		node* prev_node() {
			node* temp = _p;

			if (temp->height == 0)
			{
				if (temp->parent->left == temp)
					return temp;
				return temp->parent;
			}
			else if (temp->left)
			{
				temp = temp->left;
				while (temp->right)
					temp = temp->right;
			}
			else
			{
				while (!_comp(temp->value.first, _p->value.first))
					temp = temp->parent;
			}
			return (temp);
		}

		node* next_node() {
			node* temp = _p;

			if (temp->height == 0)
			{
				if (temp->parent->right == temp)
					return temp;
				return temp->parent;
			}
			else if (temp->right)
			{
				temp = temp->right;
				while (temp->left)
					temp = temp->left;
			}
			else
			{
				while (!_comp(_p->value.first, temp->value.first))
					temp = temp->parent;
			}
			return (temp);
		}

	};

}

#endif //MAP_ITERATOR_HPP
