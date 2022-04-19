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

	map<char,int>re;

	re.insert(pair<char,int>('r', 23));
	re.insert(pair<char,int>('x', 25));
	re.insert(pair<char,int>('s', 2252));
	re.insert(pair<char,int>('a', 13));
	re.disp();
	re.erase('r');
	re.disp();
}