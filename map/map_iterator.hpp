//
// Created by jnannie on 1/22/21.
//

#ifndef MAP_ITERATOR_HPP
#define MAP_ITERATOR_HPP

#include "map_node.hpp"
#include "../common/utils.hpp"

namespace ft {

	template<class T>
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

		template<class>
		friend class map_iterator;

	private:
		node* _p;
		node* _before_first;
		node* _after_last;

	public:
		map_iterator() : _p(NULL), _before_first(NULL), _after_last(NULL) { }
		map_iterator(const map_iterator<value_type>& other)
				: _p(other._p), _before_first(other._before_first), _after_last(other._after_last) { }
		template <typename U>
		map_iterator(map_iterator<U> const& other, typename ft::enable_if<!ft::is_const<U>::value>::type* = NULL)
				: _p(other._p), _before_first(other._before_first), _after_last(other._after_last) { }
		map_iterator(node* p) : _p(p), _before_first(find_before_first()), _after_last(find_after_last()) { }
		~map_iterator() { }

		const map_iterator& operator=(const map_iterator& rhs) { _p = rhs._p; return *this; }

		template <class U>
		friend bool operator== (const map_iterator<U>& lhs, const map_iterator<U>& rhs) {
			return lhs._p == rhs._p;
		}

		template <class U>
		friend bool operator!= (const map_iterator<U>& lhs, const map_iterator<U>& rhs) {
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

			if (temp == _after_last)
			{
				if (_after_last->parent)
					return _after_last->parent;
				else
					return _after_last->left;
			}
			else if (temp->left)
			{
				temp = temp->left;
				while (temp->right)
					temp = temp->right;
			}
			else
			{
				if (temp != _before_first)
					while (temp->value >= _p->value)
						temp = temp->parent;
			}
			return (temp);
		}

		node* next_node() {
			node* temp = _p;

			if (temp == _before_first)
			{
				if (_before_first->parent)
					return _before_first->parent;
				else
					return _before_first->right;
			}
			else if (temp->right)
			{
				temp = temp->right;
				while (temp->left)
					temp = temp->left;
			}
			else
			{
				if (temp != _after_last)
					while (temp->value <= _p->value)
						temp = temp->parent;
			}
			return (temp);
		}

		node* find_before_first() {
			node* temp = _p;

			while (temp->parent)
				temp = temp->parent;
			while (temp->left)
				temp = temp->left;
			return temp;
		}

		node* find_after_last() {
			node* temp = _p;

			while (temp->parent)
				temp = temp->parent;
			while (temp->right)
				temp = temp->right;
			return temp;
		}

	};

}

#endif //MAP_ITERATOR_HPP
