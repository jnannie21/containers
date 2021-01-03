//
// Created by jnannie on 12/31/20.
//

#include "list/node.hpp"
#include <iostream>

int main() {
	node<int> n();

	std::cout << n.content() << std::endl;

	return 0;
}
