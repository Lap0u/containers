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
	vector<int> re(3);
	re[0] = 10;re[1] = 11; re[2] = 12;
	COUT "cap" << re.capacity() ENDL;
	COUT &re[1] ENDL;
	re.erase(re.begin() + 1);
	// re.clear();
	COUT &re[2] ENDL;
	COUT re[0] ENDL << re[1] ENDL;
	COUT "size" << re.size() ENDL;
	COUT "cap" << re.capacity() ENDL;
	COUT re[2] ENDL;

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