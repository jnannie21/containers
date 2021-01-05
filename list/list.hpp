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
		node *_first;
		node *_last;
		size_type _length;


	public:
		//constructor
		//default (1)
		explicit list (const allocator_type& alloc = allocator_type())
						: _alloc(alloc), _first(NULL), _last(NULL)), length(0) {
			_first = new node<value_type>();
			_last = new node<value_type>();

			_first->next = _last;
			_last->prev = _first;
		}

		//fill (2)
		explicit list (size_type n, const value_type& val = value_type(),
						const allocator_type& alloc = allocator_type())
						: _alloc(alloc), _first(NULL), _last(NULL), _length(0) {
			_first = new node<value_type>();
			_last = new node<value_type>();

			_first->next = _last;
			_last->prev = _first;

			this->assign(n, val);
		}

		//range (3)
		template <class InputIterator>
		list (InputIterator first, InputIterator last,
			  const allocator_type& alloc = allocator_type())
			  : _alloc(alloc), _first(NULL), _last(NULL), _length(0) {
			_first = new node<value_type>();
			_last = new node<value_type>();

			_first->next = _last;
			_last->prev = _first;

			this->assign(first, last);
		}

		//copy (4)
		list (const list& x)
				: _first(NULL), _last(NULL), _length(0) {
			_first = new node<value_type>();
			_last = new node<value_type>();

			*this = x;
		}

		//destructor
		~list() {
			delete _first;
			delete _last;
		}

		//copy
		list& operator= (const list& x) {
			if (this == &x)
				return *this;

			this->_alloc = x._alloc;
			*this->_first = *x._first;
			*this->_last = *x._last;
			this->_length = x._length;

			return *this;
		}

		//iterators
		iterator begin() {
			return iterator(_first->_next);
		}

		const_iterator begin() const {
			return const_iterator(_first->_next);
		}

		iterator end() {
			return iterator(_last->_prev);
		}

		const_iterator end() const {
			return const_iterator(_last->_prev);
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

			temp->_prev = _last->_prev;
			temp->_next = _last;
			_last->_prev->_next = temp;
			_last->_prev = temp;

			_length++;
		}

		void pop_back() {
			if (_length > 0)
			{
				node* temp = _last->_prev;
				_last->_prev = _last->_prev->_prev;
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
