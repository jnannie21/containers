//
// Created by jnannie on 1/28/21.
//

#ifndef SET_ITERATOR_HPP
#define SET_ITERATOR_HPP

#include "set_node.hpp"
#include "../common/utils.hpp"
#include <iterator>
#include <cstddef>

namespace ft {

	template<class T, class Compare = ft::less<T> >
	class set_iterator {
	public:
		typedef T value_type;
		typedef std::ptrdiff_t difference_type;
		typedef const T* pointer;
		typedef const T& reference;
		typedef std::bidirectional_iterator_tag iterator_category;
		typedef set_node<typename ft::remove_const<T>::type> node;

		template<class, class>
		friend class set;

		template<class, class>
		friend class set_iterator;

	private:
		node* _p;
		Compare _comp;

	public:
		set_iterator() : _p(NULL), _comp() { }
		set_iterator(const set_iterator& other)
				: _p(other._p), _comp(other._comp) { }
		template <class U>
		set_iterator(set_iterator<U> const& other, typename ft::enable_if<!ft::is_const<U>::value>::type* = NULL)
				: _p(other._p), _comp(other._comp) { }
		set_iterator(node* p) : _p(p), _comp() { }
		~set_iterator() { }

		const set_iterator& operator=(const set_iterator& rhs) { _p = rhs._p; return *this; }

		template <class U>
		friend bool operator== (const set_iterator<U, Compare>& lhs, const set_iterator<U, Compare>& rhs) {
			return lhs._p == rhs._p;
		}

		reference operator*() const { return _p->value; }
		pointer operator->() const { return &_p->value; }

		set_iterator& operator++() { //prefix increment
			_p = next_node();
			return *this;
		}
		set_iterator operator++(int) { //postfix increment
			set_iterator temp = *this;
			++(*this);
			return temp;
		}

		set_iterator& operator--() {
			_p = prev_node();
			return *this;
		}
		set_iterator operator--(int) {
			set_iterator temp = *this;
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
				while (!_comp(temp->value, _p->value))
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
				while (!_comp(_p->value, temp->value))
					temp = temp->parent;
			}
			return (temp);
		}

	};

	template <class U, class Compare>
	bool operator!= (const set_iterator<U, Compare>& lhs, const set_iterator<U, Compare>& rhs) {
		return !(lhs == rhs);
	}

}

#endif //SET_ITERATOR_HPP
