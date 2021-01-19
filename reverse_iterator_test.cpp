//
// Created by jnannie on 1/15/21.
//

#include <vector>
#include <iterator>
#include <iostream>
#include "vector/vector.hpp"

int reverse_iterator_test () {
	std::cout << std::endl << "------------- constructor" << std::endl;
	std::cout << "------------- std" << std::endl;
	{
		std::vector<int> myvector;
		for (int i=0; i<10; i++) myvector.push_back(i);

		typedef std::vector<int>::iterator iter_type;
		// ? 0 1 2 3 4 5 6 7 8 9 ?
		iter_type from (myvector.begin());                     //   ^
		//         ------>
		iter_type until (myvector.end());                      //                       ^
		//
		std::reverse_iterator<iter_type> rev_until (from);     // ^
		//         <------
		std::reverse_iterator<iter_type> rev_from (until);     //                     ^

		std::cout << "myvector:";
		while (rev_from != rev_until)
			std::cout << ' ' << *rev_from++;
		std::cout << '\n';
	}

	std::cout << "------------- my" << std::endl;
	{
		ft::vector<int> myvector;
		for (int i=0; i<10; i++) myvector.push_back(i);

		typedef ft::vector<int>::iterator iter_type;
		// ? 0 1 2 3 4 5 6 7 8 9 ?
		iter_type from (myvector.begin());                     //   ^
		//         ------>
		iter_type until (myvector.end());                      //                       ^
		//
		ft::reverse_iterator<iter_type> rev_until (from);     // ^
		//         <------
		ft::reverse_iterator<iter_type> rev_from (until);     //                     ^

		std::cout << "myvector:";
		while (rev_from != rev_until)
			std::cout << ' ' << *rev_from++;
		std::cout << '\n';
	}


	std::cout << std::endl << "------------- base" << std::endl;
	std::cout << "------------- std" << std::endl;
	{
		std::vector<int> myvector;
		for (int i=0; i<10; i++) myvector.push_back(i);

		typedef std::vector<int>::iterator iter_type;

		std::reverse_iterator<iter_type> rev_end (myvector.begin());
		std::reverse_iterator<iter_type> rev_begin (myvector.end());

		std::cout << "myvector:";
		for (iter_type it = rev_end.base(); it != rev_begin.base(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';
	}

	std::cout << "------------- my" << std::endl;
	{
		ft::vector<int> myvector;
		for (int i=0; i<10; i++) myvector.push_back(i);

		typedef ft::vector<int>::iterator iter_type;

		ft::reverse_iterator<iter_type> rev_end (myvector.begin());
		ft::reverse_iterator<iter_type> rev_begin (myvector.end());

		std::cout << "myvector:";
		for (iter_type it = rev_end.base(); it != rev_begin.base(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';
	}


	std::cout << std::endl << "------------- operator*" << std::endl;
	std::cout << "------------- std" << std::endl;
	{
		std::vector<int> myvector;
		for (int i=0; i<10; i++) myvector.push_back(i);

		typedef std::vector<int>::iterator iter_type;
		// ? 9 8 7 6 5 4 3 2 1 0 ?
		iter_type from (myvector.begin());                     //   ^
		//         ------>
		iter_type until (myvector.end());                      //                       ^
		//
		std::reverse_iterator<iter_type> rev_until (from);     // ^
		//         <------
		std::reverse_iterator<iter_type> rev_from (until);     //                     ^

		std::cout << "myvector:";
		while (rev_from != rev_until)
			std::cout << ' ' << *rev_from++;
		std::cout << '\n';
	}

	std::cout << "------------- my" << std::endl;
	{
		ft::vector<int> myvector;
		for (int i=0; i<10; i++) myvector.push_back(i);

		typedef ft::vector<int>::iterator iter_type;
		// ? 9 8 7 6 5 4 3 2 1 0 ?
		iter_type from (myvector.begin());                     //   ^
		//         ------>
		iter_type until (myvector.end());                      //                       ^
		//
		ft::reverse_iterator<iter_type> rev_until (from);     // ^
		//         <------
		ft::reverse_iterator<iter_type> rev_from (until);     //                     ^

		std::cout << "myvector:";
		while (rev_from != rev_until)
			std::cout << ' ' << *rev_from++;
		std::cout << '\n';
	}


	std::cout << std::endl << "------------- operator+" << std::endl;
	std::cout << "------------- std" << std::endl;
	{
		std::vector<int> myvector;
		for (int i=0; i<10; i++) myvector.push_back(i);	// myvector: 0 1 2 3 4 5 6 7 8 9

		typedef std::vector<int>::iterator iter_type;

		std::reverse_iterator<iter_type> rev_it;

		rev_it = myvector.rbegin() +3;

		std::cout << "The fourth element from the end is: " << *rev_it << '\n';
	}

	std::cout << "------------- my" << std::endl;
	{
		ft::vector<int> myvector;
		for (int i=0; i<10; i++) myvector.push_back(i);	// myvector: 0 1 2 3 4 5 6 7 8 9

		typedef ft::vector<int>::iterator iter_type;

		ft::reverse_iterator<iter_type> rev_it;

		rev_it = myvector.rbegin() +3;

		std::cout << "The fourth element from the end is: " << *rev_it << '\n';
	}


	std::cout << std::endl << "------------- operator++" << std::endl;
	std::cout << "------------- std" << std::endl;
	{
		std::vector<int> myvector;
		for (int i=0; i<10; i++) myvector.push_back(i);

		typedef std::vector<int>::iterator iter_type;
		// ? 9 8 7 6 5 4 3 2 1 0 ?
		iter_type from (myvector.begin());                     //   ^
		//         ------>
		iter_type until (myvector.end());                      //                       ^
		//
		std::reverse_iterator<iter_type> rev_until (from);     // ^
		//         <------
		std::reverse_iterator<iter_type> rev_from (until);     //                     ^

		std::cout << "myvector:";
		while (rev_from != rev_until) {
			std::cout << ' ' << *rev_from;
			++rev_from;
		}
		std::cout << '\n';
	}

	std::cout << "------------- my" << std::endl;
	{
		ft::vector<int> myvector;
		for (int i=0; i<10; i++) myvector.push_back(i);

		typedef ft::vector<int>::iterator iter_type;
		// ? 9 8 7 6 5 4 3 2 1 0 ?
		iter_type from (myvector.begin());                     //   ^
		//         ------>
		iter_type until (myvector.end());                      //                       ^
		//
		ft::reverse_iterator<iter_type> rev_until (from);     // ^
		//         <------
		ft::reverse_iterator<iter_type> rev_from (until);     //                     ^

		std::cout << "myvector:";
		while (rev_from != rev_until) {
			std::cout << ' ' << *rev_from;
			++rev_from;
		}
		std::cout << '\n';
	}


	std::cout << std::endl << "------------- operator+=" << std::endl;
	std::cout << "------------- std" << std::endl;
	{
		std::vector<int> myvector;
		for (int i=0; i<10; i++) myvector.push_back(i);	// myvector: 0 1 2 3 4 5 6 7 8 9

		typedef std::vector<int>::iterator iter_type;

		std::reverse_iterator<iter_type> rev_iterator = myvector.rbegin();

		rev_iterator += 2;

		std::cout << "The third element from the end is: " << *rev_iterator << '\n';
	}

	std::cout << "------------- my" << std::endl;
	{
		ft::vector<int> myvector;
		for (int i=0; i<10; i++) myvector.push_back(i);	// myvector: 0 1 2 3 4 5 6 7 8 9

		typedef ft::vector<int>::iterator iter_type;

		ft::reverse_iterator<iter_type> rev_iterator = myvector.rbegin();

		rev_iterator += 2;

		std::cout << "The third element from the end is: " << *rev_iterator << '\n';
	}


	std::cout << std::endl << "------------- operator-" << std::endl;
	std::cout << "------------- std" << std::endl;
	{
		std::vector<int> myvector;
		for (int i=0; i<10; i++) myvector.push_back(i);	// myvector: 0 1 2 3 4 5 6 7 8 9

		typedef std::vector<int>::iterator iter_type;

		std::reverse_iterator<iter_type> rev_iterator;

		rev_iterator = myvector.rend() - 3;

		std::cout << "myvector.rend()-3 points to: " << *rev_iterator << '\n';
	}

	std::cout << "------------- my" << std::endl;
	{
		ft::vector<int> myvector;
		for (int i=0; i<10; i++) myvector.push_back(i);	// myvector: 0 1 2 3 4 5 6 7 8 9

		typedef ft::vector<int>::iterator iter_type;

		ft::reverse_iterator<iter_type> rev_iterator;

		rev_iterator = myvector.rend() - 3;

		std::cout << "myvector.rend()-3 points to: " << *rev_iterator << '\n';
	}


	std::cout << std::endl << "------------- operator--" << std::endl;
	std::cout << "------------- std" << std::endl;
	{
		std::vector<int> myvector;
		for (int i=0; i<10; i++) myvector.push_back(i);

		typedef std::vector<int>::iterator iter_type;

		std::reverse_iterator<iter_type> rev_begin (myvector.end());
		std::reverse_iterator<iter_type> rev_end (myvector.begin());

		std::reverse_iterator<iter_type> rev_iterator = rev_begin;
		while ( rev_iterator != rev_end )
			std::cout << *rev_iterator++ << ' ';
		std::cout << '\n';

		while ( rev_iterator != rev_begin )
			std::cout << *(--rev_iterator) << ' ';
		std::cout << '\n';
	}

	std::cout << "------------- my" << std::endl;
	{
		ft::vector<int> myvector;
		for (int i=0; i<10; i++) myvector.push_back(i);

		typedef ft::vector<int>::iterator iter_type;

		ft::reverse_iterator<iter_type> rev_begin (myvector.end());
		ft::reverse_iterator<iter_type> rev_end (myvector.begin());

		ft::reverse_iterator<iter_type> rev_iterator = rev_begin;
		while ( rev_iterator != rev_end )
			std::cout << *rev_iterator++ << ' ';
		std::cout << '\n';

		while ( rev_iterator != rev_begin )
			std::cout << *(--rev_iterator) << ' ';
		std::cout << '\n';
	}


	std::cout << std::endl << "------------- operator-=" << std::endl;
	std::cout << "------------- std" << std::endl;
	{
		std::vector<int> myvector;
		for (int i=0; i<10; i++) myvector.push_back(i);	// myvector: 0 1 2 3 4 5 6 7 8 9

		typedef std::vector<int>::iterator iter_type;

		std::reverse_iterator<iter_type> rev_iterator = myvector.rend();

		rev_iterator -= 4;

		std::cout << "rev_iterator now points to: " << *rev_iterator << '\n';
	}

	std::cout << "------------- my" << std::endl;
	{
		ft::vector<int> myvector;
		for (int i=0; i<10; i++) myvector.push_back(i);	// myvector: 0 1 2 3 4 5 6 7 8 9

		typedef ft::vector<int>::iterator iter_type;

		ft::reverse_iterator<iter_type> rev_iterator = myvector.rend();

		rev_iterator -= 4;

		std::cout << "rev_iterator now points to: " << *rev_iterator << '\n';
	}


//	std::cout << std::endl << "------------- operator->" << std::endl;
//	std::cout << "------------- std" << std::endl;
//	{
//		std::map<int,std::string> numbers;
//		numbers.insert (std::make_pair(1,"one"));
//		numbers.insert (std::make_pair(2,"two"));
//		numbers.insert (std::make_pair(3,"three"));
//
//		typedef std::map<int,std::string>::iterator map_iter;
//
//		std::reverse_iterator<map_iter> rev_end (numbers.begin());
//
//		std::reverse_iterator<map_iter> rev_iterator (numbers.end());
//
//		for ( ; rev_iterator != rev_end ; ++rev_iterator )
//			std::cout << rev_iterator->first << ' ' << rev_iterator->second << '\n';
//	}
//
//	std::cout << "------------- my" << std::endl;
//	{
//		std::map<int,std::string> numbers;
//		numbers.insert (std::make_pair(1,"one"));
//		numbers.insert (std::make_pair(2,"two"));
//		numbers.insert (std::make_pair(3,"three"));
//
//		typedef std::map<int,std::string>::iterator map_iter;
//
//		std::reverse_iterator<map_iter> rev_end (numbers.begin());
//
//		std::reverse_iterator<map_iter> rev_iterator (numbers.end());
//
//		for ( ; rev_iterator != rev_end ; ++rev_iterator )
//			std::cout << rev_iterator->first << ' ' << rev_iterator->second << '\n';
//	}


	std::cout << std::endl << "------------- operator[]" << std::endl;
	std::cout << "------------- std" << std::endl;
	{
		std::vector<int> myvector;
		for (int i=0; i<10; i++) myvector.push_back(i);  // myvector: 0 1 2 3 4 5 6 7 8 9

		typedef std::vector<int>::iterator iter_type;

		std::reverse_iterator<iter_type> rev_iterator = myvector.rbegin();

		std::cout << "The fourth element from the end is: " << rev_iterator[3] << '\n';
	}

	std::cout << "------------- my" << std::endl;
	{
		ft::vector<int> myvector;
		for (int i=0; i<10; i++) myvector.push_back(i);  // myvector: 0 1 2 3 4 5 6 7 8 9

		typedef ft::vector<int>::iterator iter_type;

		ft::reverse_iterator<iter_type> rev_iterator = myvector.rbegin();

		std::cout << "The fourth element from the end is: " << rev_iterator[3] << '\n';
	}


	std::cout << std::endl << "------------- relational operators" << std::endl;
	std::cout << "------------- std" << std::endl;
	{
		std::vector<int> myvector;
		for (int i=0; i<10; i++) myvector.push_back(i);

		typedef std::vector<int>::iterator iter_type;
		// ? 9 8 7 6 5 4 3 2 1 0 ?
		iter_type from (myvector.begin());                     //   ^
		//         ------>
		iter_type until (myvector.end());                      //                       ^
		//
		std::reverse_iterator<iter_type> rev_until (from);     // ^
		//         <------
		std::reverse_iterator<iter_type> rev_from (until);     //                     ^

		std::cout << "myvector:";
		while (rev_from != rev_until)
			std::cout << ' ' << *rev_from++;
		std::cout << '\n';
	}

	std::cout << "------------- my" << std::endl;
	{
		ft::vector<int> myvector;
		for (int i=0; i<10; i++) myvector.push_back(i);

		typedef ft::vector<int>::iterator iter_type;
		// ? 9 8 7 6 5 4 3 2 1 0 ?
		iter_type from (myvector.begin());                     //   ^
		//         ------>
		iter_type until (myvector.end());                      //                       ^
		//
		ft::reverse_iterator<iter_type> rev_until (from);     // ^
		//         <------
		ft::reverse_iterator<iter_type> rev_from (until);     //                     ^

		std::cout << "myvector:";
		while (rev_from != rev_until)
			std::cout << ' ' << *rev_from++;
		std::cout << '\n';
	}


	std::cout << std::endl << "------------- Non-member operator+" << std::endl;
	std::cout << "------------- std" << std::endl;
	{
		std::vector<int> myvector;
		for (int i=0; i<10; i++) myvector.push_back(i);	// myvector: 0 1 2 3 4 5 6 7 8 9

		typedef std::vector<int>::iterator iter_type;

		std::reverse_iterator<iter_type> rev_it;

		rev_it = 3 + myvector.rbegin();

		std::cout << "The fourth element from the end is: " << *rev_it << '\n';
	}

	std::cout << "------------- my" << std::endl;
	{
		ft::vector<int> myvector;
		for (int i=0; i<10; i++) myvector.push_back(i);	// myvector: 0 1 2 3 4 5 6 7 8 9

		typedef ft::vector<int>::iterator iter_type;

		ft::reverse_iterator<iter_type> rev_it;

		rev_it = 3 + myvector.rbegin();

		std::cout << "The fourth element from the end is: " << *rev_it << '\n';
	}


	std::cout << std::endl << "------------- Non-member operator-" << std::endl;
	std::cout << "------------- std" << std::endl;
	{
		std::vector<int> myvector;
		for (int i=0; i<10; i++) myvector.push_back(i);

		std::reverse_iterator<std::vector<int>::iterator> from,until;

		from = myvector.rbegin();
		until = myvector.rend();

		std::cout << "myvector has " << (until-from) << " elements.\n";
	}

	std::cout << "------------- my" << std::endl;
	{
		ft::vector<int> myvector;
		for (int i=0; i<10; i++) myvector.push_back(i);

		ft::reverse_iterator<ft::vector<int>::iterator> from,until;

		from = myvector.rbegin();
		until = myvector.rend();

		std::cout << "myvector has " << (until-from) << " elements.\n";
	}

	return 0;
}