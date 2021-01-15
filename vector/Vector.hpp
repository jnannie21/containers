//
// Created by jnannie on 1/14/21.
//

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include "VectorIterator.hpp"
#include "../common/reverse_iterator.hpp"
#include "../common/utils.hpp"
#include <cstring>

namespace ft {

	template < class T, class Alloc = std::allocator<T> >
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
		typedef ft::reverse_iterator<iterator> reverse_iterator;
		typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;
		typedef typename VectorIterator<value_type>::difference_type difference_type;
		typedef size_t size_type;

	private:
		allocator_type _alloc;
		value_type* _array;
		size_type _size;
		size_type _capacity;

	public:
//		default (1)
		explicit Vector (const allocator_type& alloc = allocator_type())
		: _alloc(alloc), _array(NULL), _size(0), _capacity(0) { }

//		fill (2)
		explicit Vector (size_type n, const value_type& val = value_type(),
		const allocator_type& alloc = allocator_type())
		: _alloc(alloc), _array(NULL), _size(0), _capacity(0) {
//			_array = new value_type[n];
//			for (size_type i = 0; i < n; ++i)
//				_array[i] = val;
//			_size = n;
			assign(n, val);
		}

//		range (3)
		template <class InputIterator>
		Vector (InputIterator first, InputIterator last,
		const allocator_type& alloc = allocator_type(),
		typename enable_if<is_input_iterator<InputIterator>::value>::type* = 0)
		: _alloc(alloc), _array(NULL), _size(0), _capacity(0) {
			assign(first, last);
		}

//		copy (4)
		Vector (const Vector& x)
		: _alloc(), _array(NULL), _size(0), _capacity(0) {
			*this = x;
		}

		~Vector() {
			delete [] _array;
		}

//		copy (1)
		Vector& operator= (const Vector& x) {
			if (this == &x)
				return *this;

			clear();
			assign(x.begin(), x.end());

			return *this;
		}

		iterator begin() {
			return iterator(_array);
		}

		const_iterator begin() const {
			return const_iterator(_array);
		}

		iterator end() {
			return iterator(_array + _size);
		}

		const_iterator end() const {
			return const_iterator(_array + _size);
		}

		reverse_iterator rbegin() {
			return reverse_iterator(end());
		}

		const_reverse_iterator rbegin() const {
			return const_reverse_iterator(end());
		}

		reverse_iterator rend() {
			return reverse_iterator(begin());
		}

		const_reverse_iterator rend() const {
			return const_reverse_iterator(begin());
		}

		size_type size() const {
			return _size;
		}

		size_type max_size() const {
			return ft::min<size_type>(std::numeric_limits<size_type>::max() / (sizeof(value_type)), std::numeric_limits<difference_type>::max());
		}





		size_type capacity() const {
			return _capacity;
		}

		void push_back (const value_type& val) {
			if (_size + 1 > _capacity)
			{
				if (_capacity == 0)
					reserve(1);
				else
					reserve(_capacity * 2);
			}

			_array[_size] = val;
			++_size;
		}

		void clear() {
			delete [] _array;
			_size = 0;
			reserve(_capacity);
		}

		void reserve (size_type n) {
			if (n > _capacity) {
				value_type* temp = new value_type[n];
				std::memcpy(temp, _array, _size * sizeof(value_type));

				delete [] _array;
				_array = temp;
				_capacity = n;
			}
		}

	};
}

#endif //VECTOR_HPP
