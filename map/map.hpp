//
// Created by jnannie on 1/19/21.
//

#ifndef MAP_HPP
#define MAP_HPP

#include "common/utils.hpp"
#include "pair.hpp"

namespace ft {

	template < class Key,                                     // map::key_type
			class T,                                       // map::mapped_type
			class Compare = ft::less<Key>                      // map::key_compare
	> class map {
	public:
		//typedefs
		typedef Key key_type;
		typedef T mapped_type;
		typedef ft::pair<const key_type, mapped_type> value_type;
		typedef Compare key_compare;
		typedef value_type& reference;
		typedef const value_type& const_reference;
		typedef value_type* pointer;
		typedef const value_type* const_pointer;
		typedef map_iterator<value_type> iterator;
		typedef map_iterator<const value_type> const_iterator;
		typedef ft::reverse_iterator<iterator> reverse_iterator;
		typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;
		typedef ptrdiff_t difference_type;
		typedef size_t size_type;

		template <class Key, class T, class Compare>
		class value_compare {   // in C++98, it is required to inherit binary_function<value_type,value_type,bool>
			friend class map;
		protected:
			Compare comp;
			value_compare (Compare c) : comp(c) {}  // constructed with map's comparison object
		public:
			typedef bool result_type;
			typedef value_type first_argument_type;
			typedef value_type second_argument_type;
			result_type operator() (const first_argument_type& x, const second_argument_type& y) const
			{
				return comp(x.first, y.first);
			}
		}

	private:
		node<T> _root;
		key_compare _comp;
		size_type _size;

	public:
//		empty (1)
		explicit map (const key_compare& comp = key_compare())
					: _root(), _comp(comp), _size() { }

//		range (2)
		template <class InputIterator>
		map (InputIterator first, InputIterator last,
			 const key_compare& comp = key_compare())
			 : _root(), _comp(comp), _size() {

		}

//		copy (3)
		map (const map& x)
			: _root(), _comp(comp), _size() { }

	};

}


#endif //MAP_HPP
