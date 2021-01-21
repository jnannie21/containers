//
// Created by jnannie on 12/31/20.
//

#ifndef LIST_HPP
#define LIST_HPP

#include "list_node.hpp"
#include "list_iterator.hpp"
#include "../common/reverse_iterator.hpp"
#include "../common/utils.hpp"

namespace ft {

	template < class T >
	class list {
	public:
		//typedefs
		typedef T value_type;
		typedef T& reference;
		typedef const T& const_reference;
		typedef T* pointer;
		typedef const T* const_pointer;
		typedef list_iterator<value_type> iterator;
		typedef list_iterator<const value_type> const_iterator;
		typedef ft::reverse_iterator<iterator> reverse_iterator;
		typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;
		typedef ptrdiff_t difference_type;
		typedef size_t size_type;
		typedef list_node<typename ft::remove_const<value_type>::type> node;

	private:
		node* _before_first;
		node* _after_last;
		size_type _length;

	public:
		//constructor
		//default (1)
		explicit list ()
						: _before_first(NULL), _after_last(NULL), _length(0) {
			_before_first = new node();
			_after_last = new node();

			_before_first->next = _after_last;
			_after_last->prev = _before_first;
	}

		//fill (2)
		explicit list (size_type n, const value_type& val = value_type())
						: _before_first(NULL), _after_last(NULL), _length(0) {
			_before_first = new node();
			_after_last = new node();

			_before_first->next = _after_last;
			_after_last->prev = _before_first;

			assign(n, val);
		}

		//range (3)
		template <class InputIterator>
		list (InputIterator first, InputIterator last,
			  typename enable_if<is_input_iterator<InputIterator>::value>::type* = 0) //is_pointer<InputIterator>::value ||
			  : _before_first(NULL), _after_last(NULL), _length(0) {
			_before_first = new node();
			_after_last = new node();

			_before_first->next = _after_last;
			_after_last->prev = _before_first;

			assign(first, last);
		}

		//copy (4)
		list (const list& x)
			: _before_first(NULL), _after_last(NULL), _length(0) {
			_before_first = new node();
			_after_last = new node();

			_before_first->next = _after_last;
			_after_last->prev = _before_first;

			*this = x;
		}

		//destructor
		~list() {
			clear();
			delete _before_first;
			delete _after_last;
		}

		//copy
		list& operator= (const list& x) {
			if (this == &x)
				return *this;

			clear();
			assign(x.begin(), x.end());

			return *this;
		}

		//iterators
		iterator begin() {
			return iterator(_before_first->next);
		}

		const_iterator begin() const {
			return const_iterator(_before_first->next);
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
			return (!_length);
		}

		size_type size() const {
			return _length;
		}

		size_type max_size() const {
			return ft::min<size_type>(std::numeric_limits<size_type>::max() / (sizeof(node)), std::numeric_limits<difference_type>::max());
//			return ft::min<size_type>(_alloc.max_size(), std::numeric_limits<difference_type>::max());
		}

		//element access
		reference front() {
			return _before_first->next->value;
//			return *begin();
		}

		const_reference front() const {
			return _before_first->next->value;
//			return *begin();
		}

		reference back() {
			return _after_last->prev->value;
		}

		const_reference back() const {
			return _after_last->prev->value;
		}

		//modifiers
		//range (1)
		template <class InputIterator>
		void assign (InputIterator first, InputIterator last,
					 typename enable_if<is_input_iterator<InputIterator>::value>::type* = 0) {
			clear();
//			_length = 0;

			while (first != last)
			{
				push_back(*first);
				first++;
			}
		}

		//fill (2)
		void assign (size_type n, const value_type& val) {
			clear();
//			_length = 0;

			while (n--)
				push_back(val);
		}

		void push_front (const value_type& val) {
			node* temp = new node(val);

			temp->prev = _before_first;
			temp->next = _before_first->next;
			temp->next->prev = temp;
			_before_first->next = temp;

			_length++;
		}

		void pop_front() {
			if (_length == 0)
				return ;

			node* temp = _before_first->next;
			_before_first->next = _before_first->next->next;
			_before_first->next->prev = _before_first;
			delete temp;
			_length--;
		}

		void push_back (const value_type& val) {
			node* temp = new node(val);

			temp->prev = _after_last->prev;
			temp->next = _after_last;
			temp->prev->next = temp;
			_after_last->prev = temp;

			_length++;
		}

		void pop_back() {
			if (_length > 0)
			{
				node* temp = _after_last->prev;
				_after_last->prev = _after_last->prev->prev;
				_after_last->prev->next = _after_last;
				delete temp;
				--_length;
			}
		}

		//single element (1)
		iterator insert (iterator position, const value_type& val) {
			node* p = position._p;

			node* temp = new node(val);

			temp->prev = p->prev;
			temp->next = p;
			temp->prev->next = temp;
			p->prev = temp;

			_length++;
			return temp;
		}

		//fill (2)
		void insert (iterator position, size_type n, const value_type& val) {
			while (n--)
				insert(position, val);
		}

		//range (3)
		template <class InputIterator>
		void insert (iterator position, InputIterator first, InputIterator last,
					 typename enable_if<is_input_iterator<InputIterator>::value>::type* = 0) {
			while (first != last)
			{
				insert(position, *first);
				first++;
			}
		}

		iterator erase (iterator position) {
//			if (position == end())
//				return position;

			node* p = position._p;
			p->prev->next = p->next;
			p->next->prev = p->prev;

			++position;
			delete p;
			--_length;
			return position;
		}

		iterator erase (iterator first, iterator last) {
			while (first != last)
				first = erase(first);

			return last;
		}

		void swap (list& x) {
			ft::swap(_before_first->next, x._before_first->next);
			ft::swap(_before_first->next->prev, x._before_first->next->prev);

			ft::swap(_after_last->prev, x._after_last->prev);
			ft::swap(_after_last->prev->next, x._after_last->prev->next);

			ft::swap(_length, x._length);
		}

		void resize (size_type n, value_type val = value_type()) {
			while (_length > n)
				pop_back();
			while (_length < n)
				push_back(val);
		}

		void clear() {
			while (_length)
				pop_back();
		}

		//operations
		//entire list (1)
		void splice (iterator position, list& x) {
			splice(position, x, x.begin(), x.end());
		}

		//single element (2)
		void splice (iterator position, list& x, iterator i) {
			iterator next(i);

			++next;
			splice(position, x, i, next);
		}

		//element range (3)
		void splice (iterator position, list& x, iterator first, iterator last) {
			if (first == last)
				return ;

			node* p = position._p;
			node* f = first._p;
			node* l = last._p;

			node* before_f = f->prev;

			f->prev = p->prev;
			f->prev->next = f;

			p->prev = l->prev;
			p->prev->next = p;

			before_f->next = l;
			l->prev = before_f;

			while (f != p)
			{
				--x._length;
				++_length;
				f = f->next;
			}
		}

		void remove (const value_type& val) {
			remove_if(ft::equal_const_pred<value_type>(val));
		}

		template <class Predicate>
		void remove_if (Predicate pred) {
			for (iterator i = begin(); i != end(); )
			{
				if (pred(*i))
				{
					iterator temp = i;
					++i;
					erase(temp);
				}
				else
					++i;
			}
		}

		//(1)
		void unique() {
			unique(ft::equal_binary_pred<value_type>());
		}

		//(2)
		template <class BinaryPredicate>
		void unique (BinaryPredicate binary_pred) {
			if (empty())
				return ;

			for (iterator prev = begin(), next = ++begin(); next != end(); )
			{
				if (binary_pred(*next, *prev))
				{
					iterator temp = next;
					++next;
					erase(temp);
				}
				else
				{
					++prev;
					++next;
				}
			}
		}

		//(1)
		void merge (list& x) {
			merge(x, ft::less_than_binary_pred<value_type>());
		}

		//(2)
		template <class Compare>
		void merge (list& x, Compare comp) {
			if (this == &x)
				return ;

			iterator it = begin(), xit = x.begin();
			while (it != end() && xit != x.end())
			{
				if (comp(*xit, *it))
				{
					iterator temp = xit;
					++xit;
					splice(it, x, temp);
				}
				else
					++it;
			}
			splice(it, x, xit, x.end());
		}

		//(1)
		void sort() {
			sort(ft::less_than_binary_pred<value_type>());
		}

		//(2)
		template <class Compare>
		void sort (Compare comp) {
			if (empty())
				return ;

			iterator prev = begin(), next = ++begin();

			while (next != end())
			{
				while (comp(*next, *prev) && next != begin())
				{
					splice(prev, *this, next);
					ft::swap(prev, next);
					--prev;
					--next;
				}
				++next;
				++prev;
			}
		}

		void reverse() {
			if (empty())
				return;

			iterator to = end();
			iterator cur = begin();
			iterator next = ++begin();

			while (next != to) {
				while (next != to) {
					splice(cur, *this, next);
					ft::swap(cur, next);
					++cur;
					++next;
				}
				--to;
				cur = begin();
				next = ++begin();
			}
		}

	};


	//non-member function overloads
//(1)
	template <class T>
	bool operator== (const list<T>& lhs, const list<T>& rhs) {
		if (lhs.size() != rhs.size())
			return false;

		for (typename list<T>::const_iterator lit = lhs.begin(), rit = rhs.begin(); lit != lhs.end(); ++lit, ++rit)
		{
			if (!(*lit == *rit))
				return false;
		}
		return true;
	}

//(2)
	template <class T>
	bool operator!= (const list<T>& lhs, const list<T>& rhs) {
		return !(lhs == rhs);
	}

//(3)
	template <class T>
	bool operator<  (const list<T>& lhs, const list<T>& rhs) {
		typename list<T>::const_iterator lit = lhs.begin(), rit = rhs.begin();

		for ( ; lit != lhs.end() && rit != rhs.end(); ++lit, ++rit)
		{
			if (*lit < *rit)
				return true;
			else if (*rit < *lit)
				return false;
		}
		return (rit != rhs.end());
	}

//(4)
	template <class T>
	bool operator<= (const list<T>& lhs, const list<T>& rhs) {
		return !(rhs < lhs);
	}

//(5)
	template <class T>
	bool operator>  (const list<T>& lhs, const list<T>& rhs) {
		return (rhs < lhs);
	}

//(6)
	template <class T>
	bool operator>= (const list<T>& lhs, const list<T>& rhs) {
		return !(lhs < rhs);
	}


	template <class T>
	void swap (list<T>& x, list<T>& y) {
		x.swap(y);
	}


} //namespace ft


#endif //LIST_HPP
