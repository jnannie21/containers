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
			link_pseudo();
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

			link_pseudo();

			insert(first, last);
		}

//		copy (3)
		map (const map& x)
			: _root(NULL), _before_first(NULL), _after_last(NULL), _comp(x._comp), _val_comp(_comp), _size(0) {
			_before_first = new node();
			_after_last = new node();

			link_pseudo();

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

		reverse_iterator rbegin() {
			return reverse_iterator(end());
		}

		const_reverse_iterator rbegin() const {
			return const_reverse_iterator(end());
		}

		reverse_iterator rend() {
			return reverse_iterator(begin());
		}

		const_reverse_iterator rend() const {
			return const_reverse_iterator(begin());
		}

		bool empty() const {
			return (!_size);
		}

		size_type size() const {
			return _size;
		}

		size_type max_size() const {
			return ft::min<size_type>(std::numeric_limits<size_type>::max() / (sizeof(node)), std::numeric_limits<difference_type>::max());
		}

		mapped_type& operator[] (const key_type& k) {
			value_type val(k, mapped_type());
			iterator it = insert(val).first;
			return (*it).second;
		}









//		single element (1)
		ft::pair<iterator,bool> insert (const value_type& val) {
			node* new_node = new node(val);
			if (!_root)
			{
				_root = new_node;
				_root->height = 2;
				_root->left = _before_first;
				_root->right = _after_last;
				_before_first->right = NULL;
				_after_last->left = NULL;
				_before_first->parent = _root;
				_after_last->parent = _root;
			}
			else
			{
				node* n = add_new_node(_root, new_node);
				if (n != new_node)
				{
					delete new_node;
					return ft::pair<iterator,bool>(n, false);
				}
				_root = find_root(_root);
			}
			++_size;
			return ft::pair<iterator,bool>(iterator(new_node), true);
		}

//		with hint (2)
		iterator insert (iterator position, const value_type& val) {
			if (position._p != _after_last && position._p != _before_first
				&& ((_val_comp(val, *position) && _val_comp(position.prev_node()->value, val))
				|| (_val_comp(*position, val) && _val_comp(val, position.next_node()->value))))
			{
				node new_node = new node(val);
				unlink_pseudo();
				node* n = add_new_node(position._p, new_node);
				link_pseudo();
				if (n != new_node)
				{
					delete new_node;
					return iterator(n);
				}
				_root = find_root(_root);
				++_size;
				return iterator(new_node);
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
				++first;
			}
		}

//		(1)
		void erase (iterator position) {
			erase((*position).first);
		}

//		(2)
		size_type erase (const key_type& k) {
			unlink_pseudo();
			node* found = find_node(_root, k);
			if (found == NULL)
			{
				link_pseudo();
				return 0;
			}
			_root = delete_node(_root, k);
			link_pseudo();
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
			node* found = find_node(_root, k);
			if (!found)
				found = _after_last;
			return iterator(found);
		}

		const_iterator find (const key_type& k) const {
			node* found = find_node(_root, k);
			if (!found)
				found = _after_last;
			return const_iterator(found);
		}


	private:
		void unlink_pseudo() {
			if (_root)
			{
				_before_first->parent->left = NULL;
				_after_last->parent->right = NULL;
				_before_first->parent = NULL;
				_after_last->parent = NULL;
				_before_first->right = _after_last;
				_after_last->left = _before_first;
			}
		}

		void link_pseudo() {
			if (!_root)
			{
				_before_first->right = _after_last;
				_after_last->left = _before_first;
				_before_first->parent = NULL;
				_after_last->parent = NULL;
			}
			else
			{
				node* temp = _root;
				while (temp->left)
					temp = temp->left;
				_before_first->parent = temp;
				_before_first->right = NULL;
				temp->left = _before_first;
				temp = _root;
				while (temp->right)
					temp = temp->right;
				_after_last->parent = temp;
				_after_last->left = NULL;
				temp->right = _after_last;
			}
		}

		node* find_root(node* cur) {
			while (cur->parent)
				cur = cur->parent;
			return cur;
		}

		node* delete_node(node *n, const key_type& k) {
			if (n == NULL)
				return n;
			if (_comp(k, n->value.first))
				n->left = delete_node(n->left, k);
			else if (_comp(n->value.first, k))
				n->right = delete_node(n->right, k);
			else if ((n->left == NULL) || (n->right == NULL))
			{
				node* temp = NULL;
				if (n->left)
					temp = n->left;
				else if (n->right)
					temp = n->right;
				else
				{
					delete n;
					return NULL;
				}
				temp->parent = n->parent;
				*n = *temp;
				delete temp;
			}
			else
			{
				node* temp = get_next_node(n->right);
				n->value = temp->value;
				n->right = delete_node(n->right, temp->value.first);
			}
			if (n != NULL)
				n = balance_node(n);
			return n;
		}

		node* get_next_node(node* n) {
			while (n->left != NULL)
				n = n->left;
			return n;
		}

		node* find_node(node* n, const key_type& k) {
			if (n == NULL)
				return NULL;
			else if (_comp(k, n->value.first))
				return find_node(n->left, k);
			else if (_comp(n->value.first, k))
				return find_node(n->right, k);
			else
				return n;
		}

		node* add_new_node(node* cur, node* new_node) {
			if (_val_comp(new_node->value, cur->value))
			{
				if (cur->left)
					new_node = add_new_node(cur->left, new_node);
				else
				{
					new_node->parent = cur;
					cur->left = new_node;
				}
			}
			else if (_val_comp(cur->value, new_node->value))
			{
				if (cur->right)
					new_node = add_new_node(cur->right, new_node);
				else
				{
					new_node->parent = cur;
					cur->right = new_node;
				}
			}
			else
				return cur;
			balance_node(cur);
			return new_node;
		}

		node* balance_node(node* n) {
			n->height = 1 + ft::max<int>(node_height(n->left), node_height(n->right));
			int balance_factor = node_balance_factor(n);
			if (balance_factor > 1)
			{
				if (node_balance_factor(n->left) >= 0)
					return right_rotate(n);
				else
				{
					n->left = left_rotate(n->left);
					return right_rotate(n);
				}
			}
			else if (balance_factor < -1)
			{
				if (node_balance_factor(n->right) <= 0)
					return left_rotate(n);
				else
				{
					n->right = right_rotate(n->right);
					return left_rotate(n);
				}
			}
			return n;
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

		node *right_rotate(node *r) {
			node *l = r->left;
			node *r2 = l->right;
			l->right = r;
			l->parent = r->parent;
			r->left = r2;
			r->parent = l;
			r->height = ft::max(node_height(r->left), node_height(r->right)) + 1;
			l->height = ft::max(node_height(l->left), node_height(l->right)) + 1;
			return l;
		}

		node *left_rotate(node *l) {
			node *r = l->right;
			node *l2 = r->left;
			r->left = l;
			r->parent = l->parent;
			l->right = l2;
			l->parent = r;
			l->height = ft::max(node_height(l->left), node_height(l->right)) + 1;
			r->height = ft::max(node_height(r->left), node_height(r->right)) + 1;
			return r;
		}

	};

}


#endif //MAP_HPP
