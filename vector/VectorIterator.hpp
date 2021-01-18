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

		value_type* getP() { return _p; }

	public:
		VectorIterator() : _p(NULL) { }
		VectorIterator(const VectorIterator<value_type>& other) : _p(other._p) { }
		VectorIterator(value_type* p) : _p(p) { }
		~VectorIterator() { }

		const VectorIterator& operator=(const VectorIterator& rhs) { _p = rhs._p; return *this; }

		template <class T1>
		friend bool operator== (const VectorIterator<T1>& lhs, const VectorIterator<T1>& rhs);
		template <class T1>
		friend bool operator!= (const VectorIterator<T1>& lhs, const VectorIterator<T1>& rhs);

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

		friend VectorIterator  operator+ (difference_type n, const VectorIterator & it) const {
			return it + n;
		}

		VectorIterator& operator-=(difference_type n) {
			*this += -n;
			return *this;
		}

		VectorIterator  operator- (difference_type n) const {
			return *this + (-n);
		}

		template <class Iter1, class Iter2>
		friend typename VectorIterator<Iter1>::difference_type
		operator-(const VectorIterator<Iter1>& it1, const VectorIterator<Iter2>& it2);

		reference operator[](difference_type n) const { return *(*this + n); }

	};


	template <class Iter1, class Iter2>
	typename VectorIterator<Iter1>::difference_type
	operator-(const VectorIterator<Iter1>& it1, const VectorIterator<Iter2>& it2) {
		return it1._p - it2._p;
	}

	template <class T1>
	bool operator== (const VectorIterator<T1>& lhs, const VectorIterator<T1>& rhs) {
		return lhs._p == rhs._p;
	}

	template <class T1>
	bool operator!= (const VectorIterator<T1>& lhs, const VectorIterator<T1>& rhs) {
		return !(lhs == rhs);
	}

	template <class Iter1, class Iter2>
	bool operator<(const VectorIterator<Iter1>& lhs, const VectorIterator<Iter2>& rhs)
	{
		return lhs._p > rhs._p;
	}

}

#endif //VECTORITERATOR_HPP
