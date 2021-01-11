//
// Created by jnannie on 12/31/20.
//

#include <iostream>
#include <list>
#include "list/list.hpp"

int main ()
{
	{
		std::cout << "real list" << std::endl;
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
	}


	{
		std::cout << "my list" << std::endl;
		int arr1[3] = {10, 20, 30};
		ft::list<int> a(arr1, arr1 + 3);
		int arr3[4] = {10, 20, 30, 0};
		ft::list<int> b(arr3, arr3 + 3);
		int arr2[3] = {30, 20, 10};
		ft::list<int> c(arr2, arr2 + 2);

		if (a == b) std::cout << "a and b are equal\n";
		if (a != b) std::cout << "a and b are not equal\n";
		if (b != c) std::cout << "b and c are not equal\n";
		if (b < c) std::cout << "b is less than c\n";
		if (c > b) std::cout << "c is greater than b\n";
		if (a <= b) std::cout << "a is less than or equal to b\n";
		if (a >= b) std::cout << "a is greater than or equal to b\n";
	}

	return 0;
}