//
// Created by jnannie on 1/26/21.
//

#include <map>
#include <iostream>
#include "map/map.hpp"

int map_test() {
	int i;
	ft::map<int,int> mymap;

	std::cout << "max size: " << mymap.max_size() << std::endl;
	if (mymap.max_size()>1000)
	{
		for (i=0; i<4; i++)
		{
			mymap[i]=0;
		}
		mymap.print();
		mymap[i]=0;
		mymap.print();
	}

	return 0;
}