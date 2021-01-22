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
		map_node* left;
		map_node* right;
		T value;

	public:
		map_node() : parent(NULL), left(NULL), right(NULL), value() { }
		map_node(const map_node& other) : parent(NULL), left(NULL), right(NULL), value() { *this = other; }
		map_node(const T& value) : parent(NULL), left(NULL), right(NULL), value(value) { }
		~node() { }

		const map_node& operator=(const map_node& rhs) {
			if (this == &rhs)
				return *this;

			parent = rhs.parent;
			left = rhs.left;
			right = rhs.right;
			value = rhs.value;
			return *this;
		}

	};

}

#endif //MAP_NODE_HPP
