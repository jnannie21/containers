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
		~map_node() { }

		const map_node& operator=(const map_node& rhs) {
			if (this == &rhs)
				return *this;

			parent = rhs.parent;
			left = rhs.left;
			right = rhs.right;
			value = rhs.value;
			return *this;
		}

		map_node* prev() {
			map_node* temp = this;

//			if (this == _before_first)
//				return _before_first;

			if (temp->left)
			{
				temp = temp->left;
				while (temp->right)
					temp = temp->right;
			}
			else
			{
				while (temp && temp != _before_first && temp->value >= this->value)
					temp = temp->parent;
			}
			return (temp);
		}

		map_node* next() {

		}

	};

}

#endif //MAP_NODE_HPP
