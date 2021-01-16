//
// Created by jnannie on 1/14/21.
//

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include "VectorIterator.hpp"
#include "../common/reverse_iterator.hpp"
#include "../common/utils.hpp"
#include <cstring>
#include <stdexcept>

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
		: _alloc(x._alloc), _array(NULL), _size(0), _capacity(0) {
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

		void resize (size_type n, value_type val = value_type()) {
			if (n > _capacity)
			{
				if (n > _capacity * 2)
					reserve(n);
				else
					reserve(_capacity * 2);
			}
			while (n < _size)
				pop_back();
			while (n > _size)
				push_back(val);
		}

		size_type capacity() const {
			return _capacity;
		}

		bool empty() const {
			return (!_size);
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

		reference operator[] (size_type n) {
			return _array[n];
		}

		const_reference operator[] (size_type n) const {
			return _array[n];
		}

		reference at (size_type n) {
			if (n >= _size)
				throw std::out_of_range("out of bounds");
			return _array[n];
		}

		const_reference at (size_type n) const {
			if (n >= _size)
				throw std::out_of_range("out of bounds");
			return _array[n];
		}

		reference front() {
			return *_array;
		}

		const_reference front() const {
			return *_array;
		}

		reference back() {
			return *(_array + (_size - 1));
		}

		const_reference back() const {
			return *(_array + (_size - 1));
		}

//		range (1)
		template <class InputIterator>
		void assign (InputIterator first, InputIterator last,
					 typename enable_if<is_input_iterator<InputIterator>::value>::type* = 0) {
			clear();

			size_type n = 0;
			for (InputIterator temp = first; temp != last; ++temp)
				++n;
			reserve(n);

			for (InputIterator temp = first; temp != last; ++temp)
				push_back(*temp);
		}

//		fill (2)
		void assign (size_type n, const value_type& val) {
			clear();
			reserve(n);

			while (n--)
				push_back(val);
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

		void pop_back() {
			if (_size > 0)
				--_size;
		}

//		single element (1)
		iterator insert (iterator position, const value_type& val) {
			insert(position, 1, val);
		}

//		fill (2)
		void insert (iterator position, size_type n, const value_type& val) {
			size_type i = 0;
			for (iterator it = begin(); it != position; ++it)
				++i;

			if (_size + n > _capacity)
			{
				if (_size + n > _capacity * 2)
					reserve(_size + n);
				else
					reserve(_capacity * 2);
				position = iterator(_array + i);
			}

			std::memmove(position._p + n, position._p, (_size - i) * sizeof(value_type));

			_size += n;
			while (n--)
			{
				*position = val;
				++position;
			}
		}

//		range (3)
		template <class InputIterator>
		void insert (iterator position, InputIterator first, InputIterator last,
					 typename enable_if<is_input_iterator<InputIterator>::value>::type* = 0) {
			size_type n = 0;
			for (InputIterator it = first; it != last; ++it)
				++n;

			size_type i = 0;
			for (iterator it = begin(); it != position; ++it)
				++i;

			if (_size + n > _capacity)
			{
				if (_size + n > _capacity * 2)
					reserve(_size + n);
				else
					reserve(_capacity * 2);
				position = iterator(_array + i);
			}

			std::memmove(position._p + n, position._p, (_size - i) * sizeof(value_type));

			_size += n;

			while (first != last)
			{
				*position = *first;
				++position;
				first++;
			}
		}

		iterator erase (iterator position) {
			return erase(position, position + 1);
		}

		iterator erase (iterator first, iterator last) {
			for (; last != end(); ++first, ++last)
				*first = *last;

			for (iterator it = first; it != last; ++it)
				--_size;

			return first; // points to initial last
		}

		void swap (Vector& x) {
			ft::swap(_array, x._array);
			ft::swap(_size, x._size);
			ft::swap(_capacity, x._capacity);
		}

		void clear() {
			delete [] _array;
			_size = 0;
			reserve(_capacity);
		}
	};

//	(1)
	template <class T, class Alloc>
	bool operator== (const Vector<T,Alloc>& lhs, const Vector<T,Alloc>& rhs) {
		if (lhs.size() != rhs.size())
			return false;

		for (typename Vector<T,Alloc>::const_iterator lit = lhs.begin(), rit = rhs.begin(); lit != lhs.end(); ++lit, ++rit)
		{
			if (!(*lit == *rit))
				return false;
		}
		return true;
	}

//	(2)
	template <class T, class Alloc>
	bool operator!= (const Vector<T,Alloc>& lhs, const Vector<T,Alloc>& rhs) {
		return !(lhs == rhs);
	}

//	(3)
	template <class T, class Alloc>
	bool operator<  (const Vector<T,Alloc>& lhs, const Vector<T,Alloc>& rhs) {
		typename Vector<T,Alloc>::const_iterator lit = lhs.begin(), rit = rhs.begin();

		for ( ; lit != lhs.end() && rit != rhs.end(); ++lit, ++rit)
		{
			if (*lit < *rit)
				return true;
			else if (*rit < *lit)
				return false;
		}
		return (rit != rhs.end());
	}
	(4)
	template <class T, class Alloc>
	bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
	(5)
	template <class T, class Alloc>
	bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
	(6)
	template <class T, class Alloc>
	bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
}

#endif //VECTOR_HPP
