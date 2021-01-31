//
// Created by jnannie on 12/31/20.
//

#include <iostream>
#include "list/list.hpp"

int reverse_iterator_test();
int list_test();
int vector_test();
int map_test();
int stack_test();
int queue_test();
int set_test();

int main() {
	std::cout << std::endl << "------------- \033[1;32m reverse_iterator tests\033[0m" << std::endl;
	reverse_iterator_test();
	std::cout << std::endl << "------------- \033[1;32m list tests\033[0m" << std::endl;
	list_test();
	std::cout << std::endl << "------------- \033[1;32m vector tests\033[0m" << std::endl;
	vector_test();
	std::cout << std::endl << "------------- \033[1;32m map tests\033[0m" << std::endl;
	map_test();
	std::cout << std::endl << "------------- \033[1;32m stack tests\033[0m" << std::endl;
	stack_test();
	std::cout << std::endl << "------------- \033[1;32m queue tests\033[0m" << std::endl;
	queue_test();
	std::cout << std::endl << "------------- \033[1;32m set tests\033[0m" << std::endl;
	set_test();

	return 0;
}
