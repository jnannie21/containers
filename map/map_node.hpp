//
// Created by jnannie on 12/31/20.
//

#ifndef MAP_NODE_HPP
#define MAP_NODE_HPP

namespace ft {

	template < typename T >
	class map_node {
	public:
		map_node* parent;
		map_node* prev;
		map_node* next;
		T value;

	public:
		map_node() : prev(NULL), next(NULL), value() { }
		map_node(const map_node& other) { *this = other; }
		map_node(const T& value) : prev(NULL), next(NULL), value(value) { }
		~node() { }

		const map_node& operator=(const map_node& rhs) {
			if (this == &rhs)
				return *this;

			parent = rhs.parent;
			prev = rhs.prev;
			next = rhs.next;
			value = rhs.value;

			return *this;
		}

	};

}

#endif //MAP_NODE_HPP
