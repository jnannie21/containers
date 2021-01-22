//
// Created by jnannie on 1/22/21.
//

#ifndef MAP_ITERATOR_HPP
#define MAP_ITERATOR_HPP

#include "map_node.hpp"

namespace ft {

	template<class T>
	class map_iterator {
	public:
		typedef T value_type;
		typedef ptrdiff_t difference_type;
		typedef T *pointer;
		typedef T &reference;
		typedef std::bidirectional_iterator_tag iterator_category;
		typedef map_node<typename ft::remove_const<T>::type> node;

		template<class>
		friend
		class map;

		template<typename U>
		friend
		class map_iterator;

	private:
		node *_p;

	public:
		map_iterator() : _p(NULL) { }
		map_iterator(const map_iterator<value_type>& other) : _p(other._p) { }
		template <typename U>
		map_iterator(map_iterator<U> const& other, typename ft::enable_if<!ft::is_const<U>::value>::type* = NULL) : _p(other._p) { }
		map_iterator(node* p) : _p(p) { }
		~map_iterator() { }

		const map_iterator& operator=(const map_iterator& rhs) { _p = rhs._p; return *this; }

		template <class U>
		friend bool operator== (const map_iterator<U>& lhs, const map_iterator<U>& rhs) {
			return lhs._p == rhs._p;
		}

		template <class U>
		friend bool operator!= (const map_iterator<U>& lhs, const map_iterator<U>& rhs) {
			return !(lhs == rhs);
		}

		reference operator*() const { return _p->value; }
		pointer operator->() const { return &_p->value; }

		map_iterator& operator++() { //prefix increment
			_p = _p->next();
			return *this;
		}
		map_iterator operator++(int) { //postfix increment
			map_iterator temp = *this;
			++(*this);
			return temp;
		}

		map_iterator& operator--() {
			_p = _p->prev();
			return *this;
		}
		map_iterator operator--(int) {
			map_iterator temp = *this;
			--(*this);
			return temp;
		}

	}

}

#endif //MAP_ITERATOR_HPP
