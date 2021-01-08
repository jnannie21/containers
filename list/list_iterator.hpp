//
// Created by jnannie on 1/2/21.
//

#ifndef LIST_ITERATOR_HPP
#define LIST_ITERATOR_HPP

#include "node.hpp"
#include "iterator.hpp"

namespace ft {

	template <class T>
	class list_iterator : public iterator<std::bidirectional_iterator_tag, T> {
	private:
		node<value_type>* _p;

	public:
		list_iterator() : _p(NULL) { }
		list_iterator(const list_iterator& other) : _p(other._p) { }
		list_iterator(node<value_type>* p) : _p(p) { }
		~list_iterator() { }

		const list_iterator& operator=(const list_iterator& rhs) { _p = rhs._p; }

//		bool operator==(const list_iterator& rhs) const { return _p == rhs._p;}
//		bool operator!=(const list_iterator& rhs) const { return _p != rhs._p;}

		friend bool operator== (const list_iterator& lhs, const list_iterator& rhs);
		friend bool operator!= (const list_iterator& lhs, const list_iterator& rhs);

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

		node<value_type>* get_p() { return _p; }

	};

	template <class T>
	bool operator== (const list_iterator<T>& lhs, const list_iterator<T>& rhs) {
		return lhs._p == rhs._p;
	}

	template <class T>
	bool operator!= (const list_iterator<T>& lhs, const list_iterator<T>& rhs) {
		return !(lhs == rhs);
	}

} //namespace ft


#endif //LIST_ITERATOR_HPP
