//
// Created by jnannie on 1/19/21.
//

#ifndef MAP_HPP
#define MAP_HPP

#include "common/utils.hpp"
#include "pair.hpp"
#include "map_node.hpp"

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
		typedef map_node<typename ft::remove_const<value_type>::type> node;

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
		node* _root;
		node* _before_first;
		node* _after_last;
		key_compare _comp;
		size_type _size;

	public:
//		empty (1)
		explicit map (const key_compare& comp = key_compare())
					: _root(NULL), _before_first(NULL), _after_last(NULL), _comp(comp), _size(0) {
			_before_first = new node();
			_after_last = new node();

			_before_first->right = _after_last;
			_after_last->left = _before_first;
//			_after_last->parent = _before_first;
//			_before_first->parent = _after_last;
		}

//		range (2)
		template <class InputIterator>
		map (InputIterator first, InputIterator last,
			 const key_compare& comp = key_compare())
			 : _root(NULL), _before_first(NULL), _after_last(NULL), _comp(comp), _size(0) {
			_before_first = new node();
			_after_last = new node();

			_before_first->right = _after_last;
			_after_last->left = _before_first;

			insert(first, last);
		}

//		copy (3)
		map (const map& x)
			: _root(NULL), _before_first(NULL), _after_last(NULL), _comp(x.comp), _size(0) {
			_before_first = new node();
			_after_last = new node();

			_before_first->right = _after_last;
			_after_last->left = _before_first;

			*this = x;
		}

		~map() {
			clear();
			delete _before_first;
			delete _after_last;
		}

//		copy (1)
		map& operator= (const map& x) {
			if (this == &x)
				return *this;

			clear();
			insert(x.begin(), x.end());
			return *this;
		}

//		single element (1)
		ft::pair<iterator,bool> insert (const value_type& val) {
			node new_node = new node(val);
			if (!_root)
			{
				_root = new_node;
				_root->left = _before_first;
				_root->right = _after_last;
				_before_first->right = NULL;
				_after_last->left = NULL;
			}
			else if (!add_new_node(_root, new_node))
			{
				free new_node;
				return ft::pair<iterator,bool>(find(val.first), false);
			}
			++_size;
			return ft::pair<iterator,bool>(iterator(new_node), true);
		}

//		with hint (2)
		iterator insert (iterator position, const value_type& val) {
			if ((val.first < (*position).first && val.first > position._p->prev()->value.first)
				|| (val.first > (*position).first && val.first < position._p->next()->value.first))
			{
				node new_node = new node(val);
				add_new_node(position._p, new_node);
				++size;
				return new_node;
			}
			else
				return insert(val).first;
		}

//		range (3)
		template <class InputIterator>
		void insert (InputIterator first, InputIterator last) {
			while (first != last)
			{
				insert(*first);
				first++;
			}
		}

		iterator find (const key_type& k) {
			return iterator(find_node(_root, k));
		}

		const_iterator find (const key_type& k) const {
			return const_iterator(find_node(_root, k));
		}


	private:
		node* find_node(const node* n, const key_type& k) {
			if (n == _before_first || n == _after_last || k == n->value.first)
				return n;
			else if (k < n->value.first)
				return find_node(n->left, k);
			else
				return find_node(n->right, k);
		}

		bool add_new_node(const node* cur, const node* new_node) {
			if (cur == _before_first)
			{
				new_node->parent = _before_first->parent;
				new_node->left = _before_first;
			}
			else if (cur == _after_last)
			{
				new_node->parent = _after_last->parent;
				new_node->right = _after_last;
			}
			else if (new_node->value.first < cur->value.first)
			{
				if (cur->left)
					return add_new_node(cur->left, new_node);
				else
				{
					new_node->parent = cur;
					cur->left = new_node;
				}
			}
			else if (new_node->value.first < cur->value.first)
			{
				if (cur->right)
					return add_new_node(cur->right, new_node);
				else
				{
					new_node->parent = cur;
					cur->right = new_node;
				}
			}
			else
				return false;
			return true;
		}

	};

}


#endif //MAP_HPP
