//
// Created by jnannie on 12/31/20.
//

namespace ft {

	template < class T >
	node<T>::node() : _prev(NULL), _next(NULL), _content() {

	}

	node::node(const node& other) {
		*this = other;
	}

	node::~node() {

	}

	const node& node::operator=(const node& rhs) {
		if (this == &other)
			return *this;

		this->_prev = rhs._prev;
		this->_next = rhs._next;
		this->_content = rhs._content;

		return *this;
	}


	node* node::prev() {
		return _prev;
	}

	node* node::next() {
		return next;
	}


	T& node::content() {
		return content;
	}

	const T& node::content() const {
		return content;
	}


} //namespace ft