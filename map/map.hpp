//
// Created by jnannie on 1/19/21.
//

#ifndef MAP_HPP
#define MAP_HPP

#include "map_iterator.hpp"
#include "../common/utils.hpp"
#include "../common/pair.hpp"
#include "map_node.hpp"
#include "../common/reverse_iterator.hpp"
#include <cstddef>
#include <limits>

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
		typedef map_iterator<value_type, key_compare> iterator;
		typedef map_iterator<const value_type, key_compare> const_iterator;
		typedef ft::reverse_iterator<iterator> reverse_iterator;
		typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;
		typedef std::ptrdiff_t difference_type;
		typedef std::size_t size_type;
		typedef map_node<typename ft::remove_const<value_type>::type> node;

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
			_before_first->height = 0;
			_after_last->height = 0;

			link_pseudo();
		}

//		range (2)
		template <class InputIterator>
		map (InputIterator first, InputIterator last,
			 const key_compare& comp = key_compare())
			 : _root(NULL), _before_first(NULL), _after_last(NULL), _comp(comp), _val_comp(_comp), _size(0) {
			_before_first = new node();
			_after_last = new node();
			_before_first->height = 0;
			_after_last->height = 0;

			link_pseudo();

			insert(first, last);
		}

//		copy (3)
		map (const map& x)
			: _root(NULL), _before_first(NULL), _after_last(NULL), _comp(x._comp), _val_comp(_comp), _size(0) {
			_before_first = new node();
			_after_last = new node();
			_before_first->height = 0;
			_after_last->height = 0;

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
			node* n = add_new_node(_root, new_node);
			if (n != new_node)
			{
				delete new_node;
				return ft::pair<iterator,bool>(n, false);
			}
			++_size;
			return ft::pair<iterator,bool>(iterator(new_node), true);
		}

//		with hint (2)
		iterator insert (iterator position, const value_type& val) {
			if (position._p != _after_last && position._p != _before_first
				&& ((_val_comp(val, position.next_node()->value) && _val_comp(position.prev_node()->value, val))))
			{
				node* new_node = new node(val);
				node* n = add_new_node(position._p, new_node);
				if (n != new_node)
				{
					delete new_node;
					return iterator(n);
				}
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
			delete_exact_node(position._p);
			--_size;
		}

//		(2)
		size_type erase (const key_type& k) {
			if (delete_node(k))
			{
				--_size;
				return 1;
			}
			else
				return 0;
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

		void swap (map& x) {
			ft::swap(_root, x._root);

			ft::swap(_before_first->parent, x._before_first->parent);
			ft::swap(_before_first->parent->left, x._before_first->parent->left);

			ft::swap(_after_last->parent, x._after_last->parent);
			ft::swap(_after_last->parent->right, x._after_last->parent->right);

			ft::swap(_size, x._size);
		}

		void clear() {
			erase(begin(), end());
		}

		key_compare key_comp() const {
			return _comp;
		}

		value_compare value_comp() const {
			return _val_comp;
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

		size_type count (const key_type& k) const {
			return !(find(k) == end());
		}

		iterator lower_bound (const key_type& k) {
			unlink_pseudo();
			node* n = finding_near_node(_root, k);
			link_pseudo();
			if (_comp(k, n->value.first))
				return ++iterator(n);
			return iterator(n);
		}

		const_iterator lower_bound (const key_type& k) const {
			unlink_pseudo();
			node* n = finding_near_node(_root, k);
			link_pseudo();
			if (_comp(k, n->value.first))
				return ++const_iterator(n);
			else if (_comp(n->value.first, k))
				return --const_iterator(n);
			return const_iterator(n);
		}

		iterator upper_bound (const key_type& k) {
			iterator it = lower_bound(k);
			if (!_comp(k, (*it).first))
				++it;
			return it;
		}

		const_iterator upper_bound (const key_type& k) const {
			iterator it = lower_bound(k);
			if (!_comp(k, (*it).first))
				++it;
			return const_iterator(it);
		}

		ft::pair<const_iterator,const_iterator> equal_range (const key_type& k) const {
			return ft::pair<const_iterator, const_iterator>(lower_bound(k), upper_bound(k));
		}

		ft::pair<iterator,iterator>             equal_range (const key_type& k) {
			return ft::pair<iterator, iterator>(lower_bound(k), upper_bound(k));
		}

//		void print() {
//			print_tree(_root, "", true);
//		}

	private:
		node* finding_near_node(node* n, const key_type& k) const {
			if (n == NULL)
				return NULL;
			else if (_comp(k, n->value.first))
			{
				node* temp = finding_near_node(n->left, k);
				if (temp)
					return temp;
			}
			else if (_comp(n->value.first, k))
			{
				node* temp = finding_near_node(n->right, k);
				if (temp)
					return temp;
			}
			return n;
		}

		void unlink_pseudo() const {
			if (_root)
			{
				_before_first->parent->left = NULL;
				_after_last->parent->right = NULL;
				_before_first->parent = _after_last;
				_after_last->parent = _before_first;
			}
		}

		void link_pseudo() const {
			if (!_root)
			{
				_before_first->parent = _after_last;
				_after_last->parent = _before_first;
			}
			else
			{
				node* temp = _root;
				while (temp->left && temp->left != _before_first)
					temp = temp->left;
				_before_first->parent = temp;
				temp->left = _before_first;
				temp = _root;
				while (temp->right && temp->right != _after_last)
					temp = temp->right;
				_after_last->parent = temp;
				temp->right = _after_last;
			}
		}

		node* find_root(node* cur) {
			while (cur->parent)
				cur = cur->parent;
			return cur;
		}

		void delete_exact_node(node* n) {
			unlink_pseudo();
			node* parent = n->parent;
			if (parent)
			{
				if (parent->left == n)
					parent->left = deleting(n, n->value.first).first;
				else
					parent->right = deleting(n, n->value.first).first;
				while (parent->parent)
				{
					balance_node(parent);
					parent = parent->parent;
				}
				_root = balance_node(parent);
			}
			else
				_root = deleting(n, n->value.first).first;
			link_pseudo();
		}

		bool delete_node(const key_type& k) {
			unlink_pseudo();
			ft::pair<node*, bool> res;
			res = deleting(_root, k);
			_root = res.first;
			link_pseudo();
			return res.second;
		}

		ft::pair<node*, bool> deleting(node *n, const key_type& k) {
			ft::pair<node*, bool> ret(NULL, false);
			if (n == NULL)
				return ret;
			else if (_comp(k, n->value.first))
			{
				ret = deleting(n->left, k);
				n->left = ret.first;
			}
			else if (_comp(n->value.first, k))
			{
				ret = deleting(n->right, k);
				n->right = ret.first;
			}
			else if ((n->left == NULL) || (n->right == NULL))
			{
				node* temp = NULL;
				if (n->left)
					temp = n->left;
				else if (n->right)
					temp = n->right;
				if (temp)
				{
					temp->parent = n->parent;
					if (temp->parent)
					{
						if (temp->parent->left == n)
							temp->parent->left = temp;
						else
							temp->parent->right = temp;
					}
				}
				delete n;
				n = temp;
				ret.second = true;
			}
			else
			{
				node* next = n->right;
				while (next->left != NULL)
					next = next->left;
				swap_node(n, next);
				ret = deleting(next->right, n->value.first);
				next->right = ret.first;
				n = next;
			}
			if (n)
				n = balance_node(n);
			ret.first = n;
			return ret;
		}

		void swap_node(node*& n, node*& next) {		//swap pointers but not values
			ft::swap(next->left, n->left);
			ft::swap(next->right, n->right);
			ft::swap(next->parent, n->parent);
			if (n->parent == n)
			{
				n->parent = next;
				next->right = n;
			}

			next->left->parent = next;
			next->right->parent = next;
			if (next->parent)
			{
				if (next->parent->right == n)
					next->parent->right = next;
				else
					next->parent->left = next;
			}

			if (n->left)
				n->left->parent = n;
			if (n->right)
				n->right->parent = n;
			if (n->parent != next)
			{
				if (n->parent->right == next)
					n->parent->right = n;
				else
					n->parent->left = n;
			}
		}

		node* find_node(node* n, const key_type& k) const {
			unlink_pseudo();
			n = finding(n, k);
			link_pseudo();
			return n;
		}

		node* finding(node* n, const key_type& k) const {
			if (n == NULL)
				return NULL;
			else if (_comp(k, n->value.first))
				return finding(n->left, k);
			else if (_comp(n->value.first, k))
				return finding(n->right, k);
			else
				return n;
		}

		node* add_new_node(node* cur, node* new_node) {
			unlink_pseudo();
			if (!_root)
				_root = new_node;
			else
			{
				new_node = adding(cur, new_node);
				_root = find_root(_root);
			}
			link_pseudo();
			return new_node;
		}

		node* adding(node* cur, node* new_node) {
			if (_val_comp(new_node->value, cur->value))
			{
				if (cur->left)
					new_node = adding(cur->left, new_node);
				else
				{
					new_node->parent = cur;
					cur->left = new_node;
				}
			}
			else if (_val_comp(cur->value, new_node->value))
			{
				if (cur->right)
					new_node = adding(cur->right, new_node);
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
			if (l->parent)
			{
				if (l->parent->left == r)
					l->parent->left = l;
				else
					l->parent->right = l;
			}
			r->left = r2;
			if (r2)
				r2->parent = r;
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
			if (r->parent)
			{
				if (r->parent->left == l)
					r->parent->left = r;
				else
					r->parent->right = r;
			}
			l->right = l2;
			if (l2)
				l2->parent = l;
			l->parent = r;
			l->height = ft::max(node_height(l->left), node_height(l->right)) + 1;
			r->height = ft::max(node_height(r->left), node_height(r->right)) + 1;
			return r;
		}

//		void print_tree(node *n, std::string indent, bool right) {
//			if (n != NULL)
//			{
//				std::cout << indent;
//				if (right)
//				{
//					std::cout << "R---- ";
//					indent += "   ";
//				}
//				else
//				{
//					std::cout << "L---- ";
//					indent += "|  ";
//				}
//				std::cout << n->value.first << " " << n->value.second << std::endl;
//				print_tree(n->left, indent, false);
//				print_tree(n->right, indent, true);
//			}
//		}

	};

}


#endif //MAP_HPP
