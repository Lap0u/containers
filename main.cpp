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
	// size_t x = 4;
	vector<int> re(4, 12);
	re[0] = 25;
	re[1] = 100;
	vector<int>::iterator s = re.begin();
	vector<int>::iterator t = re.begin() + 2;
	vector<int> yo(s, t);
	COUT yo[0] ENDL;
	COUT yo[1] ENDL ENDL;
	
#if 1 //basic_test
	COUT re.size() ENDL;
	COUT re.capacity() ENDL ENDL;
	// re[0] = 2;
	// re[1] = 4;
	// re[2] = 6;
	// re[3] = 8;
	COUT re[0] ENDL;
	COUT re[1] ENDL;
	COUT re[2] ENDL;
	COUT re[3] ENDL ENDL;
	// re.assign(8, 12);
	// COUT re[0] ENDL;
	// COUT re[1] ENDL;
	// COUT re.size() ENDL;
	// COUT re.capacity() ENDL;
#endif
#if 0 //iterators
	vector<int>::iterator it = re.begin();
	vector<int>::iterator it2 = re.end();
	re[3] = 111;
	COUT *(it2 - 1) ENDL;
	// COUT *(it2 - 1) ENDL ENDL;
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
	it += 3;
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