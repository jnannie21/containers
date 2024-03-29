//
// Created by jnannie on 1/5/21.
//

#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP

namespace ft {

	template <class Iterator>
	class reverse_iterator {
	public:
		//typedefs
		typedef Iterator iterator_type;
		typedef typename Iterator::iterator_category iterator_category;
		typedef typename Iterator::value_type value_type;
		typedef typename Iterator::difference_type difference_type;
		typedef typename Iterator::pointer pointer;
		typedef typename Iterator::reference reference;

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

		reference operator*() { iterator_type tmp = _base; return *--tmp; }
		pointer operator->() { return &(operator*()); }

		reverse_iterator& operator++() { --_base; return *this; } //prefix increment
		reverse_iterator operator++(int) { //postfix increment
			reverse_iterator temp = *this;
			++(*this);
			return temp;
		}

		reverse_iterator& operator--() { ++_base; return *this; }
		reverse_iterator operator--(int) {
			reverse_iterator temp = *this;
			--(*this);
			return temp;
		}

		iterator_type base() const { return _base; }

		reverse_iterator operator+ (difference_type n) const { return reverse_iterator(_base - n); }
		reverse_iterator& operator+= (difference_type n) { _base -= n; return *this; }

		reverse_iterator operator- (difference_type n) const { return reverse_iterator(_base + n); }
		reverse_iterator& operator-= (difference_type n) { _base += n; return *this; }

		reference operator[] (difference_type n) const { return *(*this + n); }

	};



//	(1)
	template <class Iterator>
	bool operator== (const reverse_iterator<Iterator>& lhs,
					 const reverse_iterator<Iterator>& rhs) {
		return lhs.base() == rhs.base();
	}

//	(2)
	template <class Iterator>
	bool operator!= (const reverse_iterator<Iterator>& lhs,
					 const reverse_iterator<Iterator>& rhs) {
		return lhs.base() != rhs.base();
	}

//	(3)
	template <class Iterator>
	bool operator<  (const reverse_iterator<Iterator>& lhs,
					 const reverse_iterator<Iterator>& rhs) {
		return lhs.base() > rhs.base();
	}

//	(4)
	template <class Iterator>
	bool operator<= (const reverse_iterator<Iterator>& lhs,
					 const reverse_iterator<Iterator>& rhs) {
		return lhs.base() >= rhs.base();
	}

//	(5)
	template <class Iterator>
	bool operator>  (const reverse_iterator<Iterator>& lhs,
					 const reverse_iterator<Iterator>& rhs) {
		return lhs.base() < rhs.base();
	}

//	(6)
	template <class Iterator>
	bool operator>= (const reverse_iterator<Iterator>& lhs,
					 const reverse_iterator<Iterator>& rhs) {
		return lhs.base() <= rhs.base();
	}

	template <class Iterator>
	reverse_iterator<Iterator> operator+ (
			typename reverse_iterator<Iterator>::difference_type n,
			const reverse_iterator<Iterator>& rev_it) {
//		return reverse_iterator<Iterator>(rev_it.base() - n);
		return rev_it + n;
	}

	template <class Iterator>
	typename reverse_iterator<Iterator>::difference_type operator- (
			const reverse_iterator<Iterator>& lhs,
			const reverse_iterator<Iterator>& rhs) {
		return rhs.base() - lhs.base();
	}


} //namespace ft


#endif //LIST_REVERSE_ITERATOR_HPP
