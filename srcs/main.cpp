#define CIN >> std::cin
#define COUT std::cout <<
#define ENDL << std::endl
#define NL COUT std::endl;

#include <time.h>
#include <stdlib.h>


#include <utility>
#include <map>
#include <vector>
#include <list>
#include "../map.hpp"
#include "../headers/RBT.hpp"
#include "../vector.hpp"

int main()
{
	using namespace ft;

	vector<int>lol(8, 12);

	lol.reserve(10);
	for (vector<int>::iterator re = lol.begin(); re != lol.end(); re++)
		COUT *re ENDL;
	lol.insert(lol.begin() + 5, 3);
	COUT std::endl;
	for (vector<int>::iterator re = lol.begin(); re != lol.end(); re++)
		COUT *re ENDL;
	lol.insert(lol.begin() + 5, 32);
	for (vector<int>::iterator re = lol.begin(); re != lol.end(); re++)
		COUT *re ENDL;
}