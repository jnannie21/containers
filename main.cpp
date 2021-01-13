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

int main ()
{
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

		std::list<sss> d;
		std::cout << "a max_size: " << d.max_size() << "\n";

		std::reverse_iterator<std::list<int>::iterator> rit1 = a.rbegin();

		std::cout << *rit1++ << "\n";
		std::cout << *rit1 << "\n";

		std::cout << std::count (a.begin(), a.end(), 10) << "\n";

		--rit1;
		std::reverse_iterator<std::list<int>::iterator> rit2 = b.rbegin();
		std::cout << "(rit1 == rit2): " << ((rit1 == rit2) ? "true" : "false") << "\n";
		std::reverse_iterator<std::list<int>::iterator> rit3 = a.rbegin();
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

		std::cout << std::count (a.begin(), a.end(), 10) << "\n";

		--rit1;
		ft::list<int>::reverse_iterator rit2 = b.rbegin();
		std::cout << "(rit1 == rit2): " << ((rit1 == rit2) ? "true" : "false") << "\n";
		ft::list<int>::reverse_iterator rit3 = a.rbegin();
		std::cout << "(rit1 == rit3): " << ((rit1 == rit3) ? "true" : "false") << "\n";

		ft::list<int>::iterator it1 = a.begin();

		std::cout << *it1++ << "\n";
		std::cout << *it1 << "\n";

	}

	std::cout << "------------- constructors test" << std::endl;
	std::cout << "------------- std" << std::endl;

	{
		// constructors used in the same order as described above:
		std::list<int> first;                                // empty list of ints
		std::list<int> second (4,100);                       // four ints with value 100
		std::list<int> third (second.begin(),second.end());  // iterating through second
		std::list<int> fourth (third);                       // a copy of third

		// the iterator constructor can also be used to construct from arrays:
		int myints[] = {16,2,77,29};
		std::list<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );

		std::cout << "The contents of fifth are: ";
		for (std::list<int>::iterator it = fifth.begin(); it != fifth.end(); it++)
			std::cout << *it << ' ';

		std::cout << '\n';
	}

	std::cout << "------------- my" << std::endl;

	{
		// constructors used in the same order as described above:
		ft::list<int> first;                                // empty list of ints
		ft::list<int> second (4,100);                       // four ints with value 100
		ft::list<int> third (second.begin(),second.end());  // iterating through second
		ft::list<int> fourth (third);                       // a copy of third

		// the iterator constructor can also be used to construct from arrays:
		int myints[] = {16,2,77,29};
		ft::list<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );

		std::cout << "The contents of fifth are: ";
		for (ft::list<int>::iterator it = fifth.begin(); it != fifth.end(); it++)
			std::cout << *it << ' ';

		std::cout << '\n';
	}

	std::cout << "------------- swap test" << std::endl;
	std::cout << "------------- std" << std::endl;

	{
		std::list<int> first (3,100);   // three ints with a value of 100
		std::list<int> second (5,200);  // five ints with a value of 200
		std::list<int>::iterator eit=first.end();

		first.swap(second);

		std::cout << "first contains:";
		for (std::list<int>::iterator it=first.begin(); it!=eit; it++)
			std::cout << ' ' << *it;
		std::cout << '\n';

		std::cout << "second contains:";
		for (std::list<int>::iterator it=second.begin(); it!=second.end(); it++)
			std::cout << ' ' << *it;
		std::cout << '\n';
	}

	std::cout << "------------- my" << std::endl;

	{
		ft::list<int> first (3,100);   // three ints with a value of 100
		ft::list<int> second (5,200);  // five ints with a value of 200
		ft::list<int>::iterator eit=first.end();

		first.swap(second);

		std::cout << "first contains:";
		for (ft::list<int>::iterator it=first.begin(); it!=eit; it++)
			std::cout << ' ' << *it;
		std::cout << '\n';

		std::cout << "second contains:";
		for (ft::list<int>::iterator it=second.begin(); it!=second.end(); it++)
			std::cout << ' ' << *it;
		std::cout << '\n';
	}

	return 0;
}