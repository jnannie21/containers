//
// Created by jnannie on 1/15/21.
//

#ifndef VECTOR_ITERATOR_HPP
#define VECTOR_ITERATOR_HPP

#include "../common/utils.hpp"

namespace ft {
	template <class T>
	class vector_iterator {
	public:
		typedef T value_type;
		typedef ptrdiff_t difference_type;
		typedef T* pointer;
		typedef T& reference;
		typedef std::random_access_iterator_tag iterator_category;

		template <class >
		friend class vector;
		template <typename U>
		friend class vector_iterator;

	private:
		value_type* _p;

	public:
		vector_iterator() : _p(NULL) { }
		vector_iterator(const vector_iterator<value_type>& other) : _p(other._p) { }
		template <typename U>
		vector_iterator(vector_iterator<U> const& other, typename ft::enable_if<!ft::is_const<U>::value>::type* = NULL) : _p(other._p) { }
		vector_iterator(value_type* p) : _p(p) { }
		~vector_iterator() { }

		const vector_iterator& operator=(const vector_iterator& rhs) {
			_p = rhs._p;
			return *this;
		}

		reference operator*() const { return *_p; }
		pointer operator->() const { return _p; }

		vector_iterator& operator++() { //prefix increment
			++_p;
			return *this;
		}
		vector_iterator operator++(int) { //postfix increment
			vector_iterator temp = *this;
			++(*this);
			return temp;
		}

		vector_iterator& operator--() {
			--_p;
			return *this;
		}
		vector_iterator operator--(int) {
			vector_iterator temp = *this;
			--(*this);
			return temp;
		}

		vector_iterator& operator+=(difference_type n) {
			_p += n;
			return *this;
		}

		vector_iterator  operator+ (difference_type n) const {
			vector_iterator temp(*this);
			temp += n;
			return temp;
		}

		template <class U>
		friend vector_iterator<U> operator+ (typename vector_iterator<U>::difference_type n, const vector_iterator<U> & it) {
			return it + n;
		}

		vector_iterator& operator-=(difference_type n) {
			*this += (-n);
			return *this;
		}

		vector_iterator  operator- (difference_type n) const {
			return *this + (-n);
		}

		template <class U>
		friend typename vector_iterator<U>::difference_type
		operator-(const vector_iterator<U>& it1, const vector_iterator<U>& it2) {
			return it1._p - it2._p;
		}

		reference operator[](difference_type n) const { return *(*this + n); }

		template <class U>
		friend bool operator== (const vector_iterator<U>& lhs, const vector_iterator<U>& rhs) {
			return lhs._p == rhs._p;
		}

		template <class U>
		friend bool operator!= (const vector_iterator<U>& lhs, const vector_iterator<U>& rhs) {
			return !(lhs == rhs);
		}

		template <class U>
		friend bool operator<(const vector_iterator<U>& lhs, const vector_iterator<U>& rhs) {
			return lhs._p < rhs._p;
		}

		template <class U>
		friend bool operator>(const vector_iterator<U>& lhs, const vector_iterator<U>& rhs) {
			return rhs < lhs;
		}

		template <class U>
		friend bool operator>=(const vector_iterator<U>& lhs, const vector_iterator<U>& rhs) {
			return !(lhs < rhs);
		}

		template <class U>
		friend bool operator<=(const vector_iterator<U>& lhs, const vector_iterator<U>& rhs) {
			return !(lhs > rhs);
		}

	};

}

#endif //VECTOR_ITERATOR_HPP
