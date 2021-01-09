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

//	template <class T, T v>
//	struct integral_constant {
//		static const T value = v;
//		typedef T value_type;
//		typedef integral_constant<T,v> type;
//		operator T() const { return v; }
//	};
//
//	typedef integral_constant<bool,true> true_type;
//	typedef integral_constant<false,true> false_type;


//	struct binary_comparement { };
	struct const_comparement { };

//	template <class T, class Binary>
//	class equality_check { };

	template <class T, class Binary>
	class equality_check {
	public:
		bool operator()(const T& cur, const T& prev) { return cur == prev; }
	};

	template <class T>
	class equality_check<T, const_comparement> {
		equality_check();
		const T _value;

	public:
		equality_check(const T& value) : _value(value) { }

		bool operator()(const T& x) { return _value == x; }
	};



}

#endif //UTILS_HPP
