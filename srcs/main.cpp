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
	re.add('e', 22);
	re.add('g', 26);
	re.add('y', 24);
	re.add('x', 21);

	re.disp();
	pair<map<char,int>::iterator, map<char,int>::iterator> up = re.equal_range('e');
	COUT up.first->first << " and " << up.first->second ENDL;
 

}