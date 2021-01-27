//
// Created by jnannie on 1/28/21.
//

#include <stack>
#include <vector>
#include <list>
#include <deque>
#include <iostream>
#include "stack/stack.hpp"
#include "list/list.hpp"

int stack_test () {

	std::cout << "------------- constructors" << std::endl;
	std::cout << "------------- std" << std::endl;
	{
		std::deque<int> mydeque (3,100);          // deque with 3 elements
		std::vector<int> myvector (2,200);        // vector with 2 elements

		std::stack<int> first;                    // empty stack
		std::stack<int> second (mydeque);         // stack initialized to copy of deque

		std::stack<int,std::vector<int> > third;  // empty stack using vector
		std::stack<int,std::vector<int> > fourth (myvector);

		std::cout << "size of first: " << first.size() << '\n';
		std::cout << "size of second: " << second.size() << '\n';
		std::cout << "size of third: " << third.size() << '\n';
		std::cout << "size of fourth: " << fourth.size() << '\n';
	}

	std::cout << "------------- my" << std::endl;
	{
		ft::list<int> mylist (3,100);          // deque with 3 elements
		std::vector<int> myvector (2,200);        // vector with 2 elements

		ft::stack<int> first;                    // empty stack
		ft::stack<int> second (mylist);         // stack initialized to copy of deque

		ft::stack<int,std::vector<int> > third;  // empty stack using vector
		ft::stack<int,std::vector<int> > fourth (myvector);

		std::cout << "size of first: " << first.size() << '\n';
		std::cout << "size of second: " << second.size() << '\n';
		std::cout << "size of third: " << third.size() << '\n';
		std::cout << "size of fourth: " << fourth.size() << '\n';
	}


	std::cout << "------------- empty" << std::endl;
	std::cout << "------------- std" << std::endl;
	{
		std::stack<int> mystack;
		int sum (0);

		for (int i=1;i<=10;i++) mystack.push(i);

		while (!mystack.empty())
		{
			sum += mystack.top();
			mystack.pop();
		}

		std::cout << "total: " << sum << '\n';
	}

	std::cout << "------------- my" << std::endl;
	{
		ft::stack<int> mystack;
		int sum (0);

		for (int i=1;i<=10;i++) mystack.push(i);

		while (!mystack.empty())
		{
			sum += mystack.top();
			mystack.pop();
		}

		std::cout << "total: " << sum << '\n';
	}


	std::cout << "------------- size" << std::endl;
	std::cout << "------------- std" << std::endl;
	{
		std::stack<int> myints;
		std::cout << "0. size: " << myints.size() << '\n';

		for (int i=0; i<5; i++) myints.push(i);
		std::cout << "1. size: " << myints.size() << '\n';

		myints.pop();
		std::cout << "2. size: " << myints.size() << '\n';
	}

	std::cout << "------------- my" << std::endl;
	{
		ft::stack<int> myints;
		std::cout << "0. size: " << myints.size() << '\n';

		for (int i=0; i<5; i++) myints.push(i);
		std::cout << "1. size: " << myints.size() << '\n';

		myints.pop();
		std::cout << "2. size: " << myints.size() << '\n';
	}


	std::cout << "------------- top" << std::endl;
	std::cout << "------------- std" << std::endl;
	{
		std::stack<int> mystack;

		mystack.push(10);
		mystack.push(20);

		mystack.top() -= 5;

		std::cout << "mystack.top() is now " << mystack.top() << '\n';
	}

	std::cout << "------------- my" << std::endl;
	{
		ft::stack<int> mystack;

		mystack.push(10);
		mystack.push(20);

		mystack.top() -= 5;

		std::cout << "mystack.top() is now " << mystack.top() << '\n';
	}


	std::cout << "------------- push/pop" << std::endl;
	std::cout << "------------- std" << std::endl;
	{
		std::stack<int> mystack;

		for (int i=0; i<5; ++i) mystack.push(i);

		std::cout << "Popping out elements...";
		while (!mystack.empty())
		{
			std::cout << ' ' << mystack.top();
			mystack.pop();
		}
		std::cout << '\n';
	}

	std::cout << "------------- my" << std::endl;
	{
		ft::stack<int> mystack;

		for (int i=0; i<5; ++i) mystack.push(i);

		std::cout << "Popping out elements...";
		while (!mystack.empty())
		{
			std::cout << ' ' << mystack.top();
			mystack.pop();
		}
		std::cout << '\n';
	}


	std::cout << "------------- relational operators" << std::endl;
	std::cout << "------------- std" << std::endl;
	{
		int arr1[3] = {10, 20, 30};
		std::list<int> l1(arr1, arr1 + 3);
		std::list<int> l2(arr1, arr1 + 3);
		int arr2[3] = {30, 20, 10};
		std::list<int> l3(arr2, arr2 + 3);

		std::stack<int, std::list<int> > a(l1);
		std::stack<int, std::list<int> > b(l2);
		std::stack<int, std::list<int> > c(l3);

		if (a==b) std::cout << "a and b are equal\n";
		if (b!=c) std::cout << "b and c are not equal\n";
		if (b<c) std::cout << "b is less than c\n";
		if (c>b) std::cout << "c is greater than b\n";
		if (a<=b) std::cout << "a is less than or equal to b\n";
		if (a>=b) std::cout << "a is greater than or equal to b\n";
	}

	std::cout << "------------- my" << std::endl;
	{
		int arr1[3] = {10, 20, 30};
		ft::list<int> l1(arr1, arr1 + 3);
		ft::list<int> l2(arr1, arr1 + 3);
		int arr2[3] = {30, 20, 10};
		ft::list<int> l3(arr2, arr2 + 3);

		ft::stack<int, ft::list<int> > a(l1);
		ft::stack<int, ft::list<int> > b(l2);
		ft::stack<int, ft::list<int> > c(l3);

		if (a==b) std::cout << "a and b are equal\n";
		if (b!=c) std::cout << "b and c are not equal\n";
		if (b<c) std::cout << "b is less than c\n";
		if (c>b) std::cout << "c is greater than b\n";
		if (a<=b) std::cout << "a is less than or equal to b\n";
		if (a>=b) std::cout << "a is greater than or equal to b\n";
	}

	return 0;
}
