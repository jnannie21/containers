//
// Created by jnannie on 1/28/21.
//

#ifndef STACK_HPP
#define STACK_HPP

#include "../list/list.hpp"

namespace ft {

	template <class T, class Container = ft::list<T> >
	class stack {
	public:
		typedef T value_type;
		typedef Container container_type;
		typedef size_t size_type;

	private:
		container_type _c;

	public:
		explicit stack (const container_type& ctnr = container_type()) : _c(ctnr) { }

		bool empty() const {
			return _c.empty();
		}

		size_type size() const {
			return _c.size();
		}

		value_type& top() {
			return _c.back();
		}

		const value_type& top() const {
			return _c.back();
		}

		void push (const value_type& val) {
			_c.push_back(val);
		}

		void pop() {
			_c.pop_back();
		}

		friend bool operator== (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
			return lhs._c == rhs._c;
		}

		friend bool operator!= (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
			return lhs._c != rhs._c;
		}

		friend bool operator<  (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
			return lhs._c < rhs._c;
		}

		friend bool operator<= (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
			return lhs._c <= rhs._c;
		}

		friend bool operator>  (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
			return lhs._c > rhs._c;
		}

		friend bool operator>= (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
			return lhs._c >= rhs._c;
		}

	};


} //namespace ft

#endif //STACK_HPP
