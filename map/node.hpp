//
// Created by jnannie on 12/31/20.
//

#ifndef NODE_HPP
#define NODE_HPP

namespace ft {

	template < typename T >
	class node {
	public:
		node* parent;
		node* prev;
		node* next;
		T value;

	public:
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

	};

}

#endif //NODE_HPP
