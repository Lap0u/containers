#define CIN >> std::cin
#define COUT std::cout <<
#define ENDL << std::endl
#define NL COUT std::endl;

#include <time.h>
#include <stdlib.h>


#include <utility>
#include <map>
#include <list>
#include "../map.hpp"
#include "../headers/RBT.hpp"

int main()
{
	using namespace ft;

	map<char,int>lol2;

	lol2.insert(pair<char,int>('x', 122));
	lol2.insert(pair<char,int>('y', 123));
	lol2.clear();
	lol2.insert(pair<char,int>('x', 122));
}