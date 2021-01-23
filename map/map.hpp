//
// Created by jnannie on 1/19/21.
//

#ifndef MAP_HPP
#define MAP_HPP

#include "map_iterator.hpp"
#include "../common/utils.hpp"
#include "pair.hpp"
#include "map_node.hpp"
#include "../common/reverse_iterator.hpp"

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

//		template <class Key, class T, class Compare>
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
		};

	private:
		node* _root;
		node* _before_first;
		node* _after_last;
		key_compare _comp;
		value_compare _val_comp;
		size_type _size;

	public:
//		empty (1)
		explicit map (const key_compare& comp = key_compare())
					: _root(NULL), _before_first(NULL), _after_last(NULL), _comp(comp), _val_comp(_comp), _size(0) {
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
			 : _root(NULL), _before_first(NULL), _after_last(NULL), _comp(comp), _val_comp(_comp), _size(0) {
			_before_first = new node();
			_after_last = new node();

			_before_first->right = _after_last;
			_after_last->left = _before_first;

			insert(first, last);
		}

//		copy (3)
		map (const map& x)
			: _root(NULL), _before_first(NULL), _after_last(NULL), _comp(x._comp), _val_comp(_comp), _size(0) {
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

		iterator begin() {
			return ++iterator(_before_first);
		}

		const_iterator begin() const {
			return ++const_iterator(_before_first);
		}

		iterator end() {
			return iterator(_after_last);
		}

		const_iterator end() const {
			return const_iterator(_after_last);
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
				delete new_node;
				return ft::pair<iterator,bool>(find(val.first), false);
			}
			++_size;
			return ft::pair<iterator,bool>(iterator(new_node), true);
		}

//		with hint (2)
		iterator insert (iterator position, const value_type& val) {
			if ((_val_comp(val, *position) && _val_comp(position.prev_node()->value, val))
				|| (_val_comp(*position, val) && _val_comp(val, position.next_node()->value)))
			{
				node new_node = new node(val);
				add_new_node(position._p, new_node);
				++_size;
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

//		(1)
		void erase (iterator position) {
			erase((*position).first);
		}

//		(2)
		size_type erase (const key_type& k) {
			node* n = find_node(_root, k);
			if (n == _after_last)
				return 0;
			_root = delete_node(_root, n->value.first);
			--_size;
			return 1;
		}

//		(3)
		void erase (iterator first, iterator last) {
			iterator temp;
			while (first != last)
			{
				temp = first;
				++first;
				erase(temp);
			}
		}

		void clear() {
			erase(begin(), end());
		}

		iterator find (const key_type& k) {
			return iterator(find_node(_root, k));
		}

		const_iterator find (const key_type& k) const {
			return const_iterator(find_node(_root, k));
		}


	private:
//		friend bool operator< (const key_type & lhs, const key_type & rhs) {
//			return _comp(lhs, rhs);
//		}
//
//		friend bool operator> (const key_type & lhs, const key_type & rhs) {
//			return rhs < lhs;
//		}
//
//		friend bool operator< (const value_type & lhs, const value_type & rhs) {
//			return value_compare(_comp)(lhs, rhs);
//		}
//
//		friend bool operator> (const value_type & lhs, const value_type & rhs) {
//			return rhs < lhs;
//		}

		node* delete_node(node *root, key_type key) {
			if (root == _before_first || root == _after_last)
				return root == _before_first ? _before_first : _after_last;
			if (root == NULL)
				return NULL;
			if (key < root->value.first)
				root->left = delete_node(root->left, key);
			else if (key > root->value.first)
				root->right = delete_node(root->right, key);
			else
			{
				if ((root->left == NULL) || (root->right == NULL))
				{
					node *temp = root->left ? root->left : root->right;
					if (temp == NULL)
					{
						temp = root;
						root = NULL;
					}
					else
					{
						temp->parent = root->parent;
						*root = *temp;
					}
					delete temp;
				}
				else
				{
					node *temp = iterator(root->right).next_node();
					if (temp != _after_last)
					{
						root->value = temp->value;
						root->right = delete_node(root->right, temp->value.first);
					}
					else
					{
						temp = iterator(root->left).prev_node();
						if (temp != _before_first)
						{
							root->value = temp->value;
							root->left = delete_node(root->left, temp->value.first);
						}
						else
						{
							delete root;
							return NULL;
						}
					}
				}
			}

			if (root == NULL)
				return NULL;

			root->height = 1 + ft::max(node_height(root->left), node_height(root->right));
			int balance_factor = node_balance_factor(root);
			if (balance_factor > 1)
			{
				if (node_balance_factor(root->left) >= 0)
				{
					return right_rotate(root);
				}
				else
				{
					root->left = left_rotate(root->left);
					return right_rotate(root);
				}
			}
			if (balance_factor < -1)
			{
				if (node_balance_factor(root->right) <= 0)
				{
					return left_rotate(root);
				}
				else
				{
					root->right = right_rotate(root->right);
					return left_rotate(root);
				}
			}
			return root;
		}

//		node* node_with_minimum_value(node *node) {
//			node *current = node;
//			while (current->left != NULL)
//				current = current->left;
//			return current;
//		}

		node* find_node(const node* n, const key_type& k) {
			if (n == _before_first || n == _after_last)
				return _after_last;
			else if (_comp(k, n->value.first))
				return find_node(n->left, k);
			else if (_comp(n->value.first, k))
				return find_node(n->right, k);
			else
				return n;
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
			else if (_value_comp(new_node->value, cur->value))
			{
				if (cur->left)
				{
					if (!add_new_node(cur->left, new_node))
						return false;
					else
						balance_node(cur, new_node->value.first);
				}
				else
				{
					new_node->parent = cur;
					cur->left = new_node;
				}
			}
			else if (_value_comp(cur->value, new_node->value))
			{
				if (cur->right)
				{
					if (!add_new_node(cur->right, new_node))
						return false;
					else
						balance_node(cur, new_node->value.first);
				}
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

		node* balance_node(node* n, key_type key) {
			n->height = 1 + ft::max<int>(node_height(n->left), node_height(n->right));
			int balance_factor = node_balance_factor(n);
			if (balance_factor > 1)
			{
				if (key < n->left->value.first)
				{
					return right_rotate(n);
				}
				else if (key > n->left->value.first)
				{
					n->left = left_rotate(n->left);
					return right_rotate(n);
				}
			}
			if (balance_factor < -1)
			{
				if (key > n->right->value.first)
				{
					return left_rotate(n);
				}
				else if (key < n->right->value.first)
				{
					n->right = right_rotate(n->right);
					return left_rotate(n);
				}
			}
		}

		int node_balance_factor(node* n) {
			if (n)
				return node_height(n->left) - node_height(n->right);
			return 0;

		}

		int node_height(node* n) {
			if (n)
				return n->height;
			return 0;
		}

		node *right_rotate(node *y) {
			node *x = y->left;
			node *T2 = x->right;
			x->right = y;
			x->parent = y->parent;
			y->left = T2;
			y->parent = x;
			y->height = ft::max(node_height(y->left), node_height(y->right)) + 1;
			x->height = ft::max(node_height(x->left), node_height(x->right)) + 1;
			return x;
		}

		node *left_rotate(node *x) {
			node *y = x->right;
			node *T2 = y->left;
			y->left = x;
			y->parent = x->parent;
			x->right = T2;
			x->parent = y;
			x->height = ft::max(node_height(x->left), node_height(x->right)) + 1;
			y->height = ft::max(node_height(y->left), node_height(y->right)) + 1;
			return y;
		}

	};

}


#endif //MAP_HPP
