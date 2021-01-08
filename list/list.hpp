//
// Created by jnannie on 12/31/20.
//

#ifndef LIST_HPP
#define LIST_HPP

#include "node.hpp"
#include "list_iterator.hpp"
#include "utils.hpp"
#include <memory>

namespace ft {

	template < class T, class Alloc = allocator<T> >
	class list {
	public:
		//typedefs
		typedef T value_type;
		typedef Alloc allocator_type;
		typedef allocator_type::reference reference;
		typedef allocator_type::const_reference const_reference;
		typedef allocator_type::pointer pointer;
		typedef allocator_type::const_pointer const_pointer;
		typedef list_itetator<value_type> iterator;
		typedef list_iterator<value_type> const_iterator;
		typedef list_reverse_iterator<iterator> reverse_iterator;
		typedef list_reverse_iterator<const_iterator> const_reverse_iterator;
		typedef list_iterator::difference_type difference_type;
		typedef size_t size_type;

	private:
		allocator_type _alloc;
		node<T> *_before_first;
		node<T> *_after_last;
		size_type _length;

	public:
		//constructor
		//default (1)
		explicit list (const allocator_type& alloc = allocator_type())
						: _alloc(alloc), _before_first(NULL), _after_last(NULL)), length(0) {
			_before_first = new node<value_type>();
			_after_last = new node<value_type>();

			_before_first->_next = _after_last;
			_after_last->_prev = _before_first;
	}

		//fill (2)
		explicit list (size_type n, const value_type& val = value_type(),
						const allocator_type& alloc = allocator_type())
						: _alloc(alloc), _before_first(NULL), _after_last(NULL), _length(0) {
			_before_first = new node<value_type>();
			_after_last = new node<value_type>();

			_before_first->_next = _after_last;
			_after_last->_prev = _before_first;

			assign(n, val);
		}

		//range (3)
		template <class InputIterator>
		list (InputIterator first, InputIterator last,
			  const allocator_type& alloc = allocator_type())
			  : _alloc(alloc), _before_first(NULL), _after_last(NULL), _length(0) {
			_before_first = new node<value_type>();
			_after_last = new node<value_type>();

			_before_first->_next = _after_last;
			_after_last->_prev = _before_first;

			assign(first, last);
		}

		//copy (4)
		list (const list& x)
			: _alloc(), _before_first(NULL), _after_last(NULL), _length(0) {
			_before_first = new node<value_type>();
			_after_last = new node<value_type>();

			*this = x;
		}

		//destructor
		~list() {
			delete _before_first;
			delete _after_last;
		}

		//copy
		list& operator= (const list& x) {
			if (this == &x)
				return *this;

			_alloc = x._alloc;
			*_before_first = *x._before_first;
			*_after_last = *x._after_last;
			_length = x._length;

			return *this;
		}

		//iterators
		iterator begin() {
			return iterator(_before_first->_next);
		}

		const_iterator begin() const {
			return const_iterator(_before_first->_next);
		}

		iterator end() {
			return iterator(_after_last);
		}

		const_iterator end() const {
			return const_iterator(_after_last);
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

		//capacity
		bool empty() const {
			return (begin() == end());
		}

		size_type size() const {
			return _length;
		}

		size_type max_size() const {
			return ft::min<size_type>(_alloc.max_size(), std::numeric_limits<difference_type>::max());
//			return min<size_type>(std::numeric_limits<size_type>::max() / (sizeof(value_type)), std::numeric_limits<difference_type>::max());
		}

		//element access
		reference front() {
			return _before_first->_next->_value;
//			return *begin();
		}

		const_reference front() const {
			return _before_first->_next->_value;
//			return *begin();
		}

		reference back() {
			return _after_last->_prev->_value;
		}

		const_reference back() const {
			return _after_last->_prev->_value;
		}

		//modifiers
		//range (1)
		template <class InputIterator>
		void assign (InputIterator first, InputIterator last) {
			clear();
			_length = 0;

			while (first != last)
			{
				push_back(*first);
				first++;
			}
		}

		//fill (2)
		void assign (size_type n, const value_type& val) {
			clear();
			_length = 0;

			while (n--)
				push_back(val);
		}

		void push_front (const value_type& val) {
			node* temp = new node(val);

			temp->_prev = _before_first;
			temp->_next = _before_first->_next;
			_before_first->_next = temp;
			temp->_next->_prev = temp;

			_length++;
		}

		void pop_front() {
			if (_length > 0)
			{
				node* temp = _before_first->_next;
				_before_first->_next = _before_first->_next->_next;
				_before_first->_next->_prev = _before_first;
				delete temp;
				_length--;
			}
		}

		void push_back (const value_type& val) {
			node* temp = new node(val);

			temp->_prev = _after_last->_prev;
			temp->_next = _after_last;
			_after_last->_prev = temp;
			temp->_prev->_next = temp;

			_length++;
		}

		void pop_back() {
			if (_length > 0)
			{
				node* temp = _after_last->_prev;
				_after_last->_prev = _after_last->_prev->_prev;
				_after_last->_prev->_next = _after_last;
				delete temp;
				_length--;
			}
		}

		//single element (1)
		iterator insert (iterator position, const value_type& val) {
			node* temp = new node(val);

			temp->_prev = _after_last->_prev;
			temp->_next = _after_last;
			_after_last->_prev = temp;
			temp->_prev->_next = temp;

			_length++;
		}
		//fill (2)
		void insert (iterator position, size_type n, const value_type& val);
		//range (3)
		template <class InputIterator>
		void insert (iterator position, InputIterator first, InputIterator last);

		iterator erase (iterator position);
		iterator erase (iterator first, iterator last);

		void swap (list& x);

		void resize (size_type n, value_type val = value_type());

		void clear() {
			while (_length--)
				pop_back();
		}

		//operations
		//entire list (1)
		void splice (iterator position, list& x);
		//single element (2)
		void splice (iterator position, list& x, iterator i);
		//element range (3)
		void splice (iterator position, list& x, iterator first, iterator last);

		void remove (const value_type& val);

		template <class Predicate>
		void remove_if (Predicate pred);

		//(1)
		void unique();
		//(2)
		template <class BinaryPredicate>
		void unique (BinaryPredicate binary_pred);

		//(1)
		void merge (list& x);
		//(2)
		template <class Compare>
		void merge (list& x, Compare comp);

		//(1)
		void sort();
		//(2)
		template <class Compare>
		void sort (Compare comp);

		void reverse();

	};


	//non-member function overloads
//(1)
	template <class T, class Alloc>
	bool operator== (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs);
//(2)
	template <class T, class Alloc>
	bool operator!= (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs);
//(3)
	template <class T, class Alloc>
	bool operator<  (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs);
//(4)
	template <class T, class Alloc>
	bool operator<= (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs);
//(5)
	template <class T, class Alloc>
	bool operator>  (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs);
//(6)
	template <class T, class Alloc>
	bool operator>= (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs);


	template <class T, class Alloc>
	void swap (list<T,Alloc>& x, list<T,Alloc>& y);


} //namespace ft


#endif //LIST_HPP
