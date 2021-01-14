//
// Created by jnannie on 1/2/21.
//

#ifndef LIST_ITERATOR_HPP
#define LIST_ITERATOR_HPP

#include "node.hpp"

namespace ft {

	template <class T>
	class list_iterator {
	public:
		typedef T value_type;
		typedef ptrdiff_t difference_type;
		typedef T* pointer;
		typedef T& reference;
		typedef std::bidirectional_iterator_tag iterator_category;

	private:
		node<value_type>* _p;

	public:
		list_iterator() : _p(NULL) { }
		list_iterator(const list_iterator<value_type>& other) : _p(other._p) { }
		list_iterator(node<value_type>* p) : _p(p) { }
		~list_iterator() { }

		const list_iterator& operator=(const list_iterator& rhs) { _p = rhs._p; return *this; }

		template <class T1>
		friend bool operator== (const list_iterator<T1>& lhs, const list_iterator<T1>& rhs);
		template <class T1>
		friend bool operator!= (const list_iterator<T1>& lhs, const list_iterator<T1>& rhs);

		reference operator*() const { return _p->_value; }
		pointer operator->() const { return &_p->_value; }

		list_iterator& operator++() { //prefix increment
			_p = _p->_next;
			return *this;
		}

		list_iterator operator++(int) { //postfix increment
			list_iterator temp = *this;
			++(*this);
			return temp;
		}

		list_iterator& operator--() {
			_p = _p->_prev;
			return *this;
		}

		list_iterator& operator--(int) {
			list_iterator temp = *this;
			--(*this);
			return temp;
		}

		node<value_type>* get_p() const { return _p; }

	};

	template <class T1>
	bool operator== (const list_iterator<T1>& lhs, const list_iterator<T1>& rhs) {
		return lhs._p == rhs._p;
	}

	template <class T1>
	bool operator!= (const list_iterator<T1>& lhs, const list_iterator<T1>& rhs) {
		return !(lhs == rhs);
	}


} //namespace ft


#endif //LIST_ITERATOR_HPP
