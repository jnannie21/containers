//
// Created by jnannie on 1/15/21.
//

#ifndef VECTORITERATOR_HPP
#define VECTORITERATOR_HPP

namespace ft {
	template <class T>
	class VectorIterator {
	public:
		typedef T value_type;
		typedef ptrdiff_t difference_type;
		typedef T* pointer;
		typedef T& reference;
		typedef std::random_access_iterator_tag iterator_category;

	};
}

#endif //VECTORITERATOR_HPP
