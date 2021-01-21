//
// Created by jnannie on 12/31/20.
//

#ifndef LIST_NODE_HPP
#define LIST_NODE_HPP

namespace ft {

	template < typename T >
	class list_node {
	public:
		list_node* prev;
		list_node* next;
		T value;

	public:
		list_node() : prev(NULL), next(NULL), value() { }
		list_node(const list_node& other) { *this = other; }
		list_node(const T& value) : prev(NULL), next(NULL), value(value) { }
		~list_node() { }

		const list_node& operator=(const list_node& rhs) {
			if (this == &rhs)
				return *this;

			prev = rhs.prev;
			next = rhs.next;
			value = rhs.value;

			return *this;
		}

	};

}

#endif //LIST_NODE_HPP
