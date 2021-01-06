//
// Created by jnannie on 12/31/20.
//

#ifndef LIST_HPP
#define LIST_HPP

#include "node.hpp"
#include "list_iterator.hpp"

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
		typedef list_itetator<T> iterator;
		typedef list_iterator<const T> const_iterator;
		typedef list_reverse_iterator<iterator> reverse_iterator;
		typedef list_reverse_iterator<const_iterator> const_reverse_iterator;
		typedef list_iterator::difference_type difference_type;
		typedef size_t size_type;

	private:
		allocator_type _alloc;
		node *_before_before_first;
		node *_after_last;
		size_type _length;

	public:
		//constructor
		//default (1)
		explicit list (const allocator_type& alloc = allocator_type())
						: _alloc(alloc), _before_before_first(NULL), _after_last(NULL)), length(0) {
			_before_before_first = new node<value_type>();
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

			this->assign(n, val);
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

			this->assign(first, last);
		}

		//copy (4)
		list (const list& x)
				: _before_first(NULL), _after_last(NULL), _length(0) {
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

		reverse_iterator rbegin();
		const_reverse_iterator rbegin() const;

		reverse_iterator rend();
		const_reverse_iterator rend() const;

		//capacity
		bool empty() const;
		size_type size() const;
		size_type max_size() const;

		//element access
		reference front();
		const_reference front() const;

		reference back();
		const_reference back() const;

		//modifiers
		//range (1)
		template <class InputIterator>
		void assign (InputIterator first, InputIterator last) {
			this->clear();
			_length = 0;

			while (first != last)
			{
				this->push_back(*first);
				first++;
				_length++;
			}
		}

		//fill (2)
		void assign (size_type n, const value_type& val);

		void push_front (const value_type& val);

		void pop_front();

		void push_back (const value_type& val) {
			node* temp = new node(val);

			if (_before_first == _after_last)
				_before_first = _temp;

			temp->_prev = _after_last->_prev;
			temp->_next = _after_last;
			_after_last->_prev = temp;

			if (temp->_prev)
				temp->_prev->_next = temp;

			_length++;
		}

		void pop_back() {
			if (_length > 0 && _after_last->_prev)
			{
				node* temp = _after_last->_prev;
				_after_last->_prev = _after_last->_prev->_prev;
				_after_last->_prev->_next = _after_last;
				delete temp;
				_length--;
			}
		}

		//single element (1)
		iterator insert (iterator position, const value_type& val);
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
				this->pop_back();
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
