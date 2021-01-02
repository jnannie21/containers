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
		list_iterator(list_iterator const & other);
		~list_iterator();
		list_iterator const & operator=(list_iterator const & rhs);

		bool operator==(list_iterator const &rhs);
		bool operator!=(list_iterator const &rhs);

		T & operator*();
		T const & operator*() const;
		T & operator->();
		T const & operator->() const;

		list_iterator & operator++();
		list_iterator & operator++();
		*a++

	};

}


#endif //LIST_ITERATOR_HPP
