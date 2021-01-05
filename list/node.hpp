//
// Created by jnannie on 12/31/20.
//

#ifndef NODE_HPP
#define NODE_HPP

namespace ft {

	template < class T >
	class node {
	public:
		node* _prev;
		node* _next;
		T _value;

		node() : _prev(NULL), _next(NULL), _value() { }
		node(const node& other) { *this = other; }
		node(const T& value) : _prev(NULL), _next(NULL), _value(value) { }
		~node() { }

		const node& operator=(const node& rhs) {
			if (this == &rhs)
				return *this;

			this->_prev = rhs._prev;
			this->_next = rhs._next;
			this->_value = rhs._value;

			return *this;
		}

		node* prev() { return _prev; }
		node* next() { return _next; }

		T& value() { return _value; }

	};

}

#endif //NODE_HPP