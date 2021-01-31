//
// Created by jnannie on 1/28/21.
//

#ifndef QUEUE_HPP
#define QUEUE_HPP

#include "../list/list.hpp"
#include <cstddef>

namespace ft {

	template <class T, class Container = ft::list<T> >
	class queue {
	public:
		typedef T value_type;
		typedef Container container_type;
		typedef std::size_t size_type;

	private:
		container_type _c;

	public:
		explicit queue (const container_type& ctnr = container_type()) : _c(ctnr) { }

		bool empty() const {
			return _c.empty();
		}

		size_type size() const {
			return _c.size();
		}

		value_type& front() {
			return _c.front();
		}

		const value_type& front() const {
			return _c.front();
		}

		value_type& back() {
			return _c.back();
		}

		const value_type& back() const {
			return _c.back();
		}

		void push (const value_type& val) {
			_c.push_back(val);
		}

		void pop() {
			_c.pop_front();
		}

		friend bool operator== (const queue<T,Container>& lhs, const queue<T,Container>& rhs) {
			return lhs._c == rhs._c;
		}

		friend bool operator!= (const queue<T,Container>& lhs, const queue<T,Container>& rhs) {
			return lhs._c != rhs._c;
		}

		friend bool operator<  (const queue<T,Container>& lhs, const queue<T,Container>& rhs) {
			return lhs._c < rhs._c;
		}

		friend bool operator<= (const queue<T,Container>& lhs, const queue<T,Container>& rhs) {
			return lhs._c <= rhs._c;
		}

		friend bool operator>  (const queue<T,Container>& lhs, const queue<T,Container>& rhs) {
			return lhs._c > rhs._c;
		}

		friend bool operator>= (const queue<T,Container>& lhs, const queue<T,Container>& rhs) {
			return lhs._c >= rhs._c;
		}

	};

} //namespace ft



#endif //QUEUE_HPP
