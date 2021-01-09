//
// Created by jnannie on 1/8/21.
//

#ifndef UTILS_HPP
#define UTILS_HPP

namespace ft {

	template<class T>
	const T &min(const T &a, const T &b) {
		return !(b < a) ? a : b;
	}

	template <class T> void swap ( T& a, T& b )
	{
		T c(a); a=b; b=c;
	}

	template <class T>
	class equality_check
	{
		const T _value;

	public:
		equality_check(const T& value) : _value(value) { }

		bool operator()(const T& x) { return _value == x; }
	};

}

#endif //UTILS_HPP
