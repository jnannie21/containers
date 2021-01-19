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

		template <class ,class >
		friend class Vector;

	private:
		value_type* _p;

	public:
		VectorIterator() : _p(NULL) { }
		VectorIterator(const VectorIterator<value_type>& other) : _p(other._p) { }
		VectorIterator(value_type* p) : _p(p) { }
		~VectorIterator() { }

		const VectorIterator& operator=(const VectorIterator& rhs) { _p = rhs._p; return *this; }

		template <class U>
		friend bool operator== (const VectorIterator<U>& lhs, const VectorIterator<U>& rhs) {
			return lhs._p == rhs._p;
		}

		template <class U>
		friend bool operator!= (const VectorIterator<U>& lhs, const VectorIterator<U>& rhs) {
			return !(lhs == rhs);
		}

		reference operator*() const { return *_p; }
		pointer operator->() const { return _p; }

		VectorIterator& operator++() { //prefix increment
			++_p;
			return *this;
		}
		VectorIterator operator++(int) { //postfix increment
			VectorIterator temp = *this;
			++(*this);
			return temp;
		}

		VectorIterator& operator--() {
			--_p;
			return *this;
		}
		VectorIterator operator--(int) {
			VectorIterator temp = *this;
			--(*this);
			return temp;
		}

		VectorIterator& operator+=(difference_type n) {
			_p += n;
			return *this;
		}

		VectorIterator  operator+ (difference_type n) const {
			VectorIterator temp(*this);
			temp += n;
			return temp;
		}

		friend VectorIterator  operator+ (difference_type n, const VectorIterator & it) {
			return it + n;
		}

		VectorIterator& operator-=(difference_type n) {
			*this += -n;
			return *this;
		}

		VectorIterator  operator- (difference_type n) const {
			return *this + (-n);
		}

		template <class U>
		friend typename VectorIterator<U>::difference_type
		operator-(const VectorIterator<U>& it1, const VectorIterator<U>& it2) {
			return it1._p - it2._p;
		}

		reference operator[](difference_type n) const { return *(*this + n); }

		template <class U>
		friend bool operator<(const VectorIterator<U>& lhs, const VectorIterator<U>& rhs)
		{
			return lhs._p < rhs._p;
		}

		template <class U>
		friend bool operator>(const VectorIterator<U>& lhs, const VectorIterator<U>& rhs)
		{
			return rhs._p < lhs._p;
		}

		template <class U>
		friend bool operator>=(const VectorIterator<U>& lhs, const VectorIterator<U>& rhs)
		{
			return !(lhs._p < rhs._p);
		}

		template <class U>
		friend bool operator<=(const VectorIterator<U>& lhs, const VectorIterator<U>& rhs)
		{
			return !(lhs._p > rhs._p);
		}

	};










}

#endif //VECTORITERATOR_HPP
