//
// Created by jnannie on 1/14/21.
//

#ifndef VECTOR_HPP
#define VECTOR_HPP

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
		typedef ReverseIterator<iterator> reverse_iterator;
		typedef ReverseIterator<const_iterator> const_reverse_iterator;
		typedef typename VectorIterator<value_type>::difference_type difference_type;
		typedef size_t size_type;

	private:
		allocator_type _alloc;
		value_type* _before_first;
		value_type* _after_last;
		size_type _length;

	};
}

#endif //VECTOR_HPP
