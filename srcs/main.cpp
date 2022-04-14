#define CIN >> std::cin
#define COUT std::cout <<
#define ENDL << std::endl
#define NL COUT std::endl;

#include <utility>
#include <map>
#include "../map.hpp"
#include "../headers/RBT.hpp"

int main()
{
	using namespace ft;

	map<char,int>re;
	map<char,int>re2;

	for (char x = 'g';x < 'x';x++)
		re2[x] = x + '0';
	for (char x = 'a'; x < 'r';x++)
		re2[x] = x + '0';

	re.disp();
	re2.disp();

}