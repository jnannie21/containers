//
// Created by jnannie on 1/28/21.
//

#ifndef SET_NODE_HPP
#define SET_NODE_HPP

namespace ft {

	template<typename T>
	class set_node {
	public:
		set_node *parent;
		set_node *left;
		set_node *right;
		int height;
		T value;

	public:
		set_node() : parent(NULL), left(NULL), right(NULL), height(1), value() {}

		set_node(const set_node &other) : parent(NULL), left(NULL), right(NULL), height(1), value() { *this = other; }

		set_node(const T &value) : parent(NULL), left(NULL), right(NULL), height(1), value(value) {}

		~set_node() {}

		const set_node &operator=(const set_node &rhs) {
			if (this == &rhs)
				return *this;

			parent = rhs.parent;
			left = rhs.left;
			right = rhs.right;
			height = rhs.height;
			value = rhs.value;
			return *this;
		}

	};

}

#endif //SET_NODE_HPP
