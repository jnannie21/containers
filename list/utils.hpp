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
	class equal_const_pred {
		const T _value;

		equal_const_pred();

	public:
		equal_const_pred(const T& value) : _value(value) { }

		bool operator()(const T& x) { return _value == x; }
	};

	template <class T>
	class equal_binary_pred {
	public:
		bool operator()(const T& val1, const T& val2) { return val1 == val2; }
	};

	template <class T>
	class less_than_binary_pred {
	public:
		bool operator()(const T& val1, const T& val2) { return val1 < val2; }
	};

}

#endif //UTILS_HPP
