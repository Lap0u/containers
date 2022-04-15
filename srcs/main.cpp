#define CIN >> std::cin
#define COUT std::cout <<
#define ENDL << std::endl
#define NL COUT std::endl;

#include <utility>
#include <map>
#include <list>
#include "../map.hpp"
#include "../headers/RBT.hpp"

int main()
{
	using namespace ft;


	std::list<pair<char,int> >lol;

	for (int i = 0; i < 10; i++)
		lol.push_back(pair<char,int>(i + '0', i));
	map<char,int>re2(lol.begin(), lol.end());

	re2.disp();

}