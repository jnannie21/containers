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

	template<class T>
	const T &max(const T &a, const T &b) {
		return (b < a) ? a : b;
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


	template<bool Cond, class T = void> struct enable_if {};
	template<class T> struct enable_if<true, T> { typedef T type; };


	template <class T> struct is_type { typedef void type; };


	template <class InpIter>
	struct is_pointer
	{
		template <class U>
		static char is_ptr(U *);

		static double is_ptr(...);

		static InpIter t;
		enum { value = sizeof(is_ptr(t)) == sizeof(char) };

	};

	template <typename Iter>
	struct is_iterator
	{
		template <typename U>
		static char is_iter(typename ft::is_type<typename U::value_type>::type*,
							typename ft::is_type<typename U::difference_type>::type*,
							typename ft::is_type<typename U::pointer>::type*,
							typename ft::is_type<typename U::reference>::type*,
							typename ft::is_type<typename U::iterator_category>::type*);

		template <typename>
		static double is_iter(...);

		enum { value = (sizeof(is_iter<Iter>(NULL, NULL, NULL, NULL, NULL)) == sizeof(char)
						|| is_pointer<Iter>::value)
		};
	};

	template <typename InpIter>
	struct is_input_iterator
	{
		template <class U>
		static char is_input_iter(typename U::iterator_category*);

		template <typename>
		static double is_input_iter(...);

		static std::output_iterator_tag* output_iterator;

		enum { value = ((is_iterator<InpIter>::value
						&& !(sizeof(is_input_iter<InpIter>(output_iterator)) == sizeof(char))))
		};
	};

	template <class Arg1, class Arg2, class Result>
	struct binary_function {
		typedef Arg1 first_argument_type;
		typedef Arg2 second_argument_type;
		typedef Result result_type;
	};

	template <class T> struct less : binary_function <T,T,bool> {
		bool operator() (const T& x, const T& y) const {return x<y;}
	};


	template< class T > struct remove_const                { typedef T type; };
	template< class T > struct remove_const<const T>       { typedef T type; };


	template<class T> struct is_const { enum { value = false };	};
	template<class T> struct is_const<const T> { enum { value = true };
	};

}

#endif //UTILS_HPP
