#include <vector>
#include <stack>
#include <map>
#include <iostream>
#include "../vector.hpp"

#define CIN >> std::cin
#define COUT std::cout <<
#define ENDL << std::endl
#define NL COUT std::endl;

using namespace ft;

void	printVec(const vector<int> & vec)
{
	COUT "vec is empty = " << vec.empty() ENDL;
	if (vec.empty())
		return ;
	COUT "capacity is " << vec.capacity() << " and size is " << vec.size() ENDL;
	for (vector<int>::const_iterator beg = vec.begin(); beg != vec.end(); beg++)
		COUT *beg ENDL;
	NL
}
int main()
{
	vector<int>test (3,125);
	vector<int>lol;

	lol.reserve(20);
	COUT lol.capacity() ENDL;
	lol = test;
	COUT lol.capacity() ENDL;
	// vector<int>::iterator it = lol.begin();
	// it++;

	// COUT *it ENDL;
	// COUT test.capacity() ENDL;
	// COUT lol.capacity() ENDL;

	// lol = test;
	// COUT *it ENDL;
	// COUT lol.capacity() ENDL;

    return 0;
}
