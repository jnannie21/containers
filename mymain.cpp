//
// Created by jnannie on 12/31/20.
//

#include <iostream>
#include <list>
#include "list/list.hpp"
#include <algorithm>

struct sss {
	void *str1;
	void *str2;
	int i;
	int i2;
	int i3;
};

int main () {
	{
		std::cout << "------------ real list" << std::endl;
		int arr1[3] = {10, 20, 30};
		std::list<int> a(arr1, arr1 + 3);
		int arr3[4] = {10, 20, 30, 0};
		std::list<int> b(arr3, arr3 + 3);
		int arr2[3] = {30, 20, 10};
		std::list<int> c(arr2, arr2 + 2);

		if (a == b) std::cout << "a and b are equal\n";
		if (a != b) std::cout << "a and b are not equal\n";
		if (b != c) std::cout << "b and c are not equal\n";
		if (b < c) std::cout << "b is less than c\n";
		if (c > b) std::cout << "c is greater than b\n";
		if (a <= b) std::cout << "a is less than or equal to b\n";
		if (a >= b) std::cout << "a is greater than or equal to b\n";

		std::list <sss> d;
		std::cout << "a max_size: " << d.max_size() << "\n";

		std::reverse_iterator <std::list<int>::iterator> rit1 = a.rbegin();

		std::cout << *rit1++ << "\n";
		std::cout << *rit1 << "\n";

		std::cout << std::count(a.begin(), a.end(), 10) << "\n";

		--rit1;
		std::reverse_iterator <std::list<int>::iterator> rit2 = b.rbegin();
		std::cout << "(rit1 == rit2): " << ((rit1 == rit2) ? "true" : "false") << "\n";
		std::reverse_iterator <std::list<int>::iterator> rit3 = a.rbegin();
		std::cout << "(rit1 == rit3): " << ((rit1 == rit3) ? "true" : "false") << "\n";

		std::list<int>::iterator it1 = a.begin();

		std::cout << *it1++ << "\n";
		std::cout << *it1 << "\n";

	}

	{
		std::cout << "------------ my list" << std::endl;
		int arr1[3] = {10, 20, 30};
		ft::list<int> a(arr1, arr1 + 3);
		int arr2[4] = {10, 20, 30, 0};
		ft::list<int> b(arr2, arr2 + 3);
		int arr3[3] = {30, 20, 10};
		ft::list<int> c(arr3, arr3 + 2);

		if (a == b) std::cout << "a and b are equal\n";
		if (a != b) std::cout << "a and b are not equal\n";
		if (b != c) std::cout << "b and c are not equal\n";
		if (b < c) std::cout << "b is less than c\n";
		if (c > b) std::cout << "c is greater than b\n";
		if (a <= b) std::cout << "a is less than or equal to b\n";
		if (a >= b) std::cout << "a is greater than or equal to b\n";

		ft::list<sss> d;
		std::cout << "a max_size: " << d.max_size() << "\n";

		ft::list<int>::reverse_iterator rit1 = a.rbegin();

		std::cout << *rit1++ << "\n";
		std::cout << *rit1 << "\n";

		std::cout << std::count(a.begin(), a.end(), 10) << "\n";

		--rit1;
		ft::list<int>::reverse_iterator rit2 = b.rbegin();
		std::cout << "(rit1 == rit2): " << ((rit1 == rit2) ? "true" : "false") << "\n";
		ft::list<int>::reverse_iterator rit3 = a.rbegin();
		std::cout << "(rit1 == rit3): " << ((rit1 == rit3) ? "true" : "false") << "\n";

		ft::list<int>::iterator it1 = a.begin();

		std::cout << *it1++ << "\n";
		std::cout << *it1 << "\n";

		{
			std::cout << "------------ my list" << std::endl;
			int arr1[3] = {10, 20, 30};
			ft::list<int> a(arr1, arr1 + 3);
			int arr2[4] = {10, 20, 30, 0};
			ft::list<int> b(arr2, arr2 + 4);
			std::cout << (a == b) << std::endl;
		}

	}
}