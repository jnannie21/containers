//
// Created by jnannie on 12/31/20.
//

#include <iostream>

int list_test();
int vector_test();
int reverse_iterator_test();

int main() {
	std::cout << std::endl << "------------- \033[1;32m reverse_iterator tests\033[0m" << std::endl;
	reverse_iterator_test();
	std::cout << std::endl << "------------- \033[1;32m list tests\033[0m" << std::endl;
	list_test();
	std::cout << std::endl << "------------- \033[1;32m vector tests\033[0m" << std::endl;
	vector_test();

	return 0;
}