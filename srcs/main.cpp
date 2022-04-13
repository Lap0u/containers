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
	char x = 'a';
	for (;x != 'f';x++)
		re.add(x, x + '0');
	// re.add('e', 22);
	// re.add('r', 23);
	re.disp();
}