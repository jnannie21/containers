//
// Created by jnannie on 1/5/21.
//

#ifndef LIST_REVERSE_ITERATOR_HPP
#define LIST_REVERSE_ITERATOR_HPP

#include "node.hpp"
#include "iterator.hpp"

namespace ft {

	template <class Iterator>
	class reverse_iterator {
	public:
		//typedefs
		typedef Iterator iterator_type;
		typedef Iterator::iterator_category iterator_category;
		typedef Iterator::value_type value_type;
		typedef Iterator::difference_type difference_type;
		typedef Iterator::pointer pointer;
		typedef Iterator::reference reference;

	private:
		iterator_type _base;

	public:
		//default (1)
		reverse_iterator() : _base() { }

		//initialization (2)
		explicit reverse_iterator (iterator_type it) : _base(it) { }

		//copy (3)
		template <class Iter>
		reverse_iterator (const reverse_iterator<Iter>& rev_it) { _base = rev_it._base; }

//		bool operator==(const reverse_iterator& rhs);
//		bool operator!=(const reverse_iterator& rhs);

		friend bool operator== (const reverse_iterator& lhs, const reverse_iterator& rhs);
		friend bool operator!= (const reverse_iterator& lhs, const reverse_iterator& rhs);

		reference operator*() { iterator_type tmp = _base; return *--tmp; }
		pointer operator->() { return &(operator*()); }

		reverse_iterator& operator++() { --_base; return *this; } //prefix increment
		reverse_iterator operator++(int) { //postfix increment
			reverse_iterator temp = *this;
			++(*this);
			return temp;
		}

		reverse_iterator& operator--() { ++_base; return *this; }
		reverse_iterator& operator--(int) {
			reverse_iterator temp = *this;
			--(*this);
			return temp;
		}

	};


	template <class T>
	bool operator== (const reverse_iterator<T>& lhs, const reverse_iterator<T>& rhs) {
		return lhs._p == rhs._p;
	}

	template <class T>
	bool operator!= (const reverse_iterator<T>& lhs, const reverse_iterator<T>& rhs) {
		return !(lhs == rhs);
	}


} //namespace ft


#endif //LIST_REVERSE_ITERATOR_HPP