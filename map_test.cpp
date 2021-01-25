//
// Created by jnannie on 1/23/21.
//

#include <map>
#include <iostream>
#include "map/map.hpp"

bool fncomp (char lhs, char rhs) {return lhs<rhs;}

struct classcomp {
	bool operator() (const char& lhs, const char& rhs) const
	{return lhs<rhs;}
};

int map_test () {
	std::cout << "------------- constructors" << std::endl;
	std::cout << "------------- std" << std::endl;
	{
		std::map<char,int> first;

		first['a']=10;
		first['b']=30;
		first['c']=50;
		first['d']=70;

		std::map<char,int> second (first.begin(),first.end());

		std::map<char,int> third (second);

		std::map<char,int,classcomp> fourth;                 // class as Compare

		bool(*fn_pt)(char,char) = fncomp;
		std::map<char,int,bool(*)(char,char)> fifth (fn_pt); // function pointer as Compare

	}

	std::cout << "------------- my" << std::endl;
	{
		ft::map<char,int> first;

		first['a']=10;
//		std::cout << first['a'] << std::endl;
		first['b']=30;
//		std::cout << first['a'] << std::endl;
		first['c']=50;

		std::cout << first['a'] << " " << first['b'] << " " << first['c'] << std::endl;
		first['d']=70;
//		ft::map<char,int> second (first.begin(),first.end());
//
//		ft::map<char,int> third (second);
//
//		ft::map<char,int,classcomp> fourth;                 // class as Compare
//
//		bool(*fn_pt)(char,char) = fncomp;
//		ft::map<char,int,bool(*)(char,char)> fifth (fn_pt); // function pointer as Compare
//
//		ft::map<char,int> one_more = ft::map<char,int>();

	}
	return 0;
}