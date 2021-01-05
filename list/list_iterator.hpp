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
		node<T>* _p;

	public:
		list_iterator();
		list_iterator(const list_iterator& other);
		list_iterator(node<T>* p) : _p(p) { }
		~list_iterator();
		const list_iterator& operator=(const list_iterator& rhs);

		bool operator==(const list_iterator& rhs);
		bool operator!=(const list_iterator& rhs);

		reference operator*();
		pointer operator->();

		list_iterator& operator++(); //prefix increment
		list_iterator& operator++(int); //postfix increment

		list_iterator& operator--();
		list_iterator& operator--(int);

	};

} //namespace ft


#endif //LIST_ITERATOR_HPP
