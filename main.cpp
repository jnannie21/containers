//
// Created by jnannie on 12/31/20.
//

#include "list/node.hpp"
#include <iostream>
#include <iterator>
#include <list>

int main() {
	list<int> l;

	iterator_traits<int *> it;

	node<int> n();

	std::cout << n.content() << std::endl;

	return 0;
}
