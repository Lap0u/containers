#include <vector>
#include <stack>
#include <map>
#include <iostream>
#include "vector.hpp"

#define CIN >> std::cin
#define COUT std::cout <<
#define ENDL << std::endl

int main()
{
	using namespace ft;
	vector<int> re(12);
#if 1 //iterators
	vector<int>::iterator it = re.begin();
	COUT *it ENDL;
	*it = 12;
	COUT *it ENDL;
	it++;
	COUT *it ENDL;
	it--;
	COUT *it ENDL;
	++it;
	COUT *it ENDL;
	--it;
	COUT *it ENDL;
	it[3] = 24;
	COUT *(it + 3) ENDL;
	it = &(it[3]);
	COUT *it ENDL;
	it -= 3;
	COUT *it ENDL;
	it[2] = 48;
	it += 2;
	COUT "comparison" << "  " << *it << "  " << it[1] ENDL;
	COUT (*it < it[1]) ENDL;
	COUT (*it <= it[1]) ENDL;
	COUT (*it > it[1]) ENDL;
	COUT (*it >= it[1]) ENDL;
	COUT (*it == it[1]) ENDL;
	COUT (*it != it[1]) ENDL ENDL;

	*it = it[1];
	COUT "now equal" << "  " << *it << "  " << it[1] ENDL;
	COUT (*it < it[1]) ENDL;
	COUT (*it <= it[1]) ENDL;
	COUT (*it > it[1]) ENDL;
	COUT (*it >= it[1]) ENDL;
	COUT (*it == it[1]) ENDL;
	COUT (*it != it[1]) ENDL;

#endif
    return 0;
}