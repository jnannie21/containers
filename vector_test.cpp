//
// Created by jnannie on 1/15/21.
//

#include <vector>
#include <iostream>
#include "vector/Vector.hpp"

int vector_test () {
	std::cout << std::endl << "------------- constructors" << std::endl;
	std::cout << "------------- std" << std::endl;
	{
		// constructors used in the same order as described above:
		std::vector<int> first;                                // empty vector of ints
		std::vector<int> second (4,100);                       // four ints with value 100
		std::vector<int> third (second.begin(),second.end());  // iterating through second
		std::vector<int> fourth (third);                       // a copy of third

		// the iterator constructor can also be used to construct from arrays:
		int myints[] = {16,2,77,29};
		std::vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );

		std::cout << "The contents of fifth are:";
		for (std::vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';
	}

	std::cout << "------------- my" << std::endl;
	{
		// constructors used in the same order as described above:
		ft::Vector<int> first;                                // empty vector of ints
		ft::Vector<int> second (4,100);                       // four ints with value 100
		ft::Vector<int> third (second.begin(),second.end());  // iterating through second
		ft::Vector<int> fourth (third);                       // a copy of third

		// the iterator constructor can also be used to construct from arrays:
		int myints[] = {16,2,77,29};
		ft::Vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );

		std::cout << "The contents of fifth are:";
		for (ft::Vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';
	}

	return 0;
}

