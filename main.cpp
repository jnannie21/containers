//
// Created by jnannie on 12/31/20.
//

#include "list/node.hpp"
#include <iostream>
#include <iterator>

int main() {
	iterator_traits<int *> it;

	node<int> n();

	std::cout << n.content() << std::endl;

	return 0;
}
