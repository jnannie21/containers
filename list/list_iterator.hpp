//
// Created by jnannie on 1/2/21.
//

#ifndef LIST_ITERATOR_HPP
#define LIST_ITERATOR_HPP

#include "list_node.hpp"
#include "../common/utils.hpp"
#include <cstddef>

namespace ft {

	template <class T>
	class list_iterator {
	public:
		typedef T value_type;
		typedef std::ptrdiff_t difference_type;
		typedef T* pointer;
		typedef T& reference;
		typedef ft::bidirectional_iterator_tag iterator_category;
		typedef list_node<typename ft::remove_const<T>::type> node;

		template <class >
		friend class list;

		template <class >
		friend class list_iterator;

	private:
		node* _p;

	public:
		list_iterator() : _p(NULL) { }
		list_iterator(const list_iterator<value_type>& other) : _p(other._p) { }
		template <class U>
		list_iterator(list_iterator<U> const& other, typename ft::enable_if<!ft::is_const<U>::value>::type* = NULL) : _p(other._p) { }
		list_iterator(node* p) : _p(p) { }
		~list_iterator() { }

		const list_iterator& operator=(const list_iterator& rhs) { _p = rhs._p; return *this; }

		template <class U>
		friend bool operator== (const list_iterator<U>& lhs, const list_iterator<U>& rhs) {
			return lhs._p == rhs._p;
		}

		reference operator*() const { return _p->value; }
		pointer operator->() const { return &_p->value; }

		list_iterator& operator++() { //prefix increment
			_p = _p->next;
			return *this;
		}
		list_iterator operator++(int) { //postfix increment
			list_iterator temp = *this;
			++(*this);
			return temp;
		}

		list_iterator& operator--() {
			_p = _p->prev;
			return *this;
		}
		list_iterator operator--(int) {
			list_iterator temp = *this;
			--(*this);
			return temp;
		}

	};


	template <class U>
	bool operator!= (const list_iterator<U>& lhs, const list_iterator<U>& rhs) {
		return !(lhs == rhs);
	}

} //namespace ft


#endif //LIST_ITERATOR_HPP
