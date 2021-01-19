//
// Created by jnannie on 1/19/21.
//

#ifndef MAP_HPP
#define MAP_HPP

namespace ft {

	template < class Key,                                     // map::key_type
			class T,                                       // map::mapped_type
			class Compare = less<Key>                      // map::key_compare
	> class map {
	public:
		//typedefs
		typedef T value_type;
		typedef T& reference;
		typedef const T& const_reference;
		typedef T* pointer;
		typedef const T* const_pointer;
		typedef vector_iterator<value_type> iterator;
		typedef vector_iterator<const value_type> const_iterator;
		typedef ft::reverse_iterator<iterator> reverse_iterator;
		typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;
		typedef typename vector_iterator<value_type>::difference_type difference_type;
		typedef size_t size_type;

	};

}


#endif //MAP_HPP
