//
// Created by jnannie on 1/2/21.
//

#ifndef LIST_ITERATOR_HPP
#define LIST_ITERATOR_HPP

namespace ft {

	template <class Category, class T, class Distance = ptrdiff_t,
			class Pointer = T*, class Reference = T&>
	struct iterator {
		typedef T         value_type;
		typedef Distance  difference_type;
		typedef Pointer   pointer;
		typedef Reference reference;
		typedef Category  iterator_category;
	};

	template <class T>
	class list_iterator : public ft::iterator<std::bidirectional_iterator_tag, T> {
		list_iterator();
		list_iterator(const list_iterator& other);
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

#include "list_iterator.tpp"

} //namespace ft


#endif //LIST_ITERATOR_HPP
