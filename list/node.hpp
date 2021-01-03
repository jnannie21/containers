//
// Created by jnannie on 12/31/20.
//

#ifndef NODE_HPP
#define NODE_HPP

namespace ft {

	template < class T >
	class node {
		node(const T& content = T());
		node(const node& other);
		~node();
		const node& operator=(const node& rhs);

		node* prev();
		node* next();

		T& content();
		const T& content() const;

	private:
		node* _prev;
		node* _next;
		T _content;

	};

}

#include "node.tpp"

#endif //NODE_HPP