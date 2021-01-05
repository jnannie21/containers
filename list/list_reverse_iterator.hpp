//
// Created by jnannie on 1/5/21.
//

#ifndef LIST_REVERSE_ITERATOR_HPP
#define LIST_REVERSE_ITERATOR_HPP

#include "node.hpp"
#include "iterator.hpp"

namespace ft {

	template <class Iterator>
	class list_reverse_iterator {
	private:
		Iterator _it;
	public:
		list_reverse_iterator();
		list_reverse_iterator(const list_reverse_iterator& other);
		list_reverse_iterator(node<Iterator::value_type>* p) : Iterator(p) { }
		~list_reverse_iterator();
		const list_reverse_iterator& operator=(const list_reverse_iterator& rhs);

		bool operator==(const list_reverse_iterator& rhs);
		bool operator!=(const list_reverse_iterator& rhs);

		reference operator*();
		pointer operator->();

		list_reverse_iterator& operator++(); //prefix increment
		list_reverse_iterator& operator++(int); //postfix increment

		list_reverse_iterator& operator--();
		list_reverse_iterator& operator--(int);

	};

} //namespace ft


#endif //LIST_REVERSE_ITERATOR_HPP
