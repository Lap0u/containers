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
	vector<int> re(4);
	re.reserve(6);
	COUT re.size() ENDL;
	COUT re.capacity() ENDL ENDL;
	re[0] = 2;
	re[1] = 4;
	re[2] = 6;
	re[3] = 8;
	COUT re[0] ENDL;
	COUT re[1] ENDL;
	COUT re[2] ENDL;
	COUT re[3] ENDL ENDL;
	re.insert(re.begin() + 2, 2, 4);
	COUT re[0] ENDL;
	COUT re[1] ENDL;
	COUT re[2] ENDL;
	COUT re[3] ENDL;
	COUT re[4] ENDL;
	COUT re[5] ENDL ENDL;
	COUT re.size() ENDL;
	COUT re.capacity() ENDL;

#if 0 //iterators
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