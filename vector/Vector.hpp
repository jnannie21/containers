//
// Created by jnannie on 1/14/21.
//

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include "VectorIterator.hpp"
#include "../common/reverse_iterator.hpp"

namespace ft {
	template < class T, class Alloc = allocator<T> >
	class Vector {
	public:
		//typedefs
		typedef T value_type;
		typedef Alloc allocator_type;
		typedef typename allocator_type::reference reference;
		typedef typename allocator_type::const_reference const_reference;
		typedef typename allocator_type::pointer pointer;
		typedef typename allocator_type::const_pointer const_pointer;
		typedef VectorIterator<value_type> iterator;
		typedef VectorIterator<const value_type> const_iterator;
		typedef reverse_iterator<iterator> reverse_iterator;
		typedef reverse_iterator<const_iterator> const_reverse_iterator;
		typedef typename VectorIterator<value_type>::difference_type difference_type;
		typedef size_t size_type;

	private:
		allocator_type _alloc;
		value_type* _array;
		size_type _length;
		size_type _capacity;

	public:
//		default (1)
		explicit vector (const allocator_type& alloc = allocator_type())
		: _alloc(alloc), _array(NULL), _length(0), _capacity(0) { }

//		fill (2)
		explicit vector (size_type n, const value_type& val = value_type(),
		const allocator_type& alloc = allocator_type()) {
			array = new value_type[n];
		}

//		range (3)
		template <class InputIterator>
		vector (InputIterator first, InputIterator last,
		const allocator_type& alloc = allocator_type()) {

		}
//		copy (4)
		vector (const vector& x) {

		}

	};
}

#endif //VECTOR_HPP
