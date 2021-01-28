//
// Created by jnannie on 1/28/21.
//

#include <queue>
#include <vector>
#include <list>
#include <deque>
#include <iostream>
#include "queue/queue.hpp"
#include "list/list.hpp"

int queue_test () {

	std::cout << "------------- constructors" << std::endl;
	std::cout << "------------- std" << std::endl;
	{
		std::deque<int> mydeck (3,100);        // deque with 3 elements
		std::list<int> mylist (2,200);         // list with 2 elements

		std::queue<int> first;                 // empty queue
		std::queue<int> second (mydeck);       // queue initialized to copy of deque

		std::queue<int,std::list<int> > third; // empty queue with list as underlying container
		std::queue<int,std::list<int> > fourth (mylist);

		std::cout << "size of first: " << first.size() << '\n';
		std::cout << "size of second: " << second.size() << '\n';
		std::cout << "size of third: " << third.size() << '\n';
		std::cout << "size of fourth: " << fourth.size() << '\n';
	}

	std::cout << "------------- my" << std::endl;
	{
		ft::list<int> mylist (3,100);          // deque with 3 elements
		std::vector<int> myvector (2,200);        // vector with 2 elements

		ft::queue<int> first;                    // empty stack
		ft::queue<int> second (mylist);         // stack initialized to copy of deque

		ft::queue<int,std::vector<int> > third;  // empty stack using vector
		ft::queue<int,std::vector<int> > fourth (myvector);

		std::cout << "size of first: " << first.size() << '\n';
		std::cout << "size of second: " << second.size() << '\n';
		std::cout << "size of third: " << third.size() << '\n';
		std::cout << "size of fourth: " << fourth.size() << '\n';
	}


	std::cout << "------------- empty" << std::endl;
	std::cout << "------------- std" << std::endl;
	{
		std::queue<int> myqueue;
		int sum (0);

		for (int i=1;i<=10;i++) myqueue.push(i);

		while (!myqueue.empty())
		{
			sum += myqueue.front();
			myqueue.pop();
		}

		std::cout << "total: " << sum << '\n';
	}

	std::cout << "------------- my" << std::endl;
	{
		ft::queue<int> myqueue;
		int sum (0);

		for (int i=1;i<=10;i++) myqueue.push(i);

		while (!myqueue.empty())
		{
			sum += myqueue.front();
			myqueue.pop();
		}

		std::cout << "total: " << sum << '\n';
	}


	std::cout << "------------- size" << std::endl;
	std::cout << "------------- std" << std::endl;
	{
		std::queue<int> myints;
		std::cout << "0. size: " << myints.size() << '\n';

		for (int i=0; i<5; i++) myints.push(i);
		std::cout << "1. size: " << myints.size() << '\n';

		myints.pop();
		std::cout << "2. size: " << myints.size() << '\n';
	}

	std::cout << "------------- my" << std::endl;
	{
		ft::queue<int> myints;
		std::cout << "0. size: " << myints.size() << '\n';

		for (int i=0; i<5; i++) myints.push(i);
		std::cout << "1. size: " << myints.size() << '\n';

		myints.pop();
		std::cout << "2. size: " << myints.size() << '\n';
	}


	std::cout << "------------- front" << std::endl;
	std::cout << "------------- std" << std::endl;
	{
		std::queue<int> myqueue;

		myqueue.push(77);
		myqueue.push(16);

		myqueue.front() -= myqueue.back();    // 77-16=61

		std::cout << "myqueue.front() is now " << myqueue.front() << '\n';
	}

	std::cout << "------------- my" << std::endl;
	{
		ft::queue<int> myqueue;

		myqueue.push(77);
		myqueue.push(16);

		myqueue.front() -= myqueue.back();    // 77-16=61

		std::cout << "myqueue.front() is now " << myqueue.front() << '\n';
	}


	std::cout << "------------- back" << std::endl;
	std::cout << "------------- std" << std::endl;
	{
		std::queue<int> myqueue;

		myqueue.push(12);
		myqueue.push(75);   // this is now the back

		myqueue.back() -= myqueue.front();

		std::cout << "myqueue.back() is now " << myqueue.back() << '\n';
	}

	std::cout << "------------- my" << std::endl;
	{
		ft::queue<int> myqueue;

		myqueue.push(12);
		myqueue.push(75);   // this is now the back

		myqueue.back() -= myqueue.front();

		std::cout << "myqueue.back() is now " << myqueue.back() << '\n';
	}


	std::cout << "------------- push/pop" << std::endl;
	std::cout << "------------- std" << std::endl;
	{
		std::queue<int> myqueue;

		myqueue.push (3);
		myqueue.push (6);
		myqueue.push (0);

		std::cout << "myqueue contains: ";
		while (!myqueue.empty())
		{
			std::cout << ' ' << myqueue.front();
			myqueue.pop();
		}
		std::cout << '\n';
	}

	std::cout << "------------- my" << std::endl;
	{
		ft::queue<int> myqueue;

		myqueue.push (3);
		myqueue.push (6);
		myqueue.push (0);

		std::cout << "myqueue contains: ";
		while (!myqueue.empty())
		{
			std::cout << ' ' << myqueue.front();
			myqueue.pop();
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

		std::queue<int, std::list<int> > a(l1);
		std::queue<int, std::list<int> > b(l2);
		std::queue<int, std::list<int> > c(l3);

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
		std::list<int> l1(arr1, arr1 + 3);
		std::list<int> l2(arr1, arr1 + 3);
		int arr2[3] = {30, 20, 10};
		std::list<int> l3(arr2, arr2 + 3);

		ft::queue<int, std::list<int> > a(l1);
		ft::queue<int, std::list<int> > b(l2);
		ft::queue<int, std::list<int> > c(l3);

		if (a==b) std::cout << "a and b are equal\n";
		if (b!=c) std::cout << "b and c are not equal\n";
		if (b<c) std::cout << "b is less than c\n";
		if (c>b) std::cout << "c is greater than b\n";
		if (a<=b) std::cout << "a is less than or equal to b\n";
		if (a>=b) std::cout << "a is greater than or equal to b\n";
	}

	return 0;
}