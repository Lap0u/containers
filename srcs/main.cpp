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
	// re['e'] = 22;
	// re['r'] = 23;
	re.add('e', 22);
	re.add('r', 23);
	map<char,int>::iterator ite = re.find('r');
	COUT ite->second ENDL;
	re.disp();
}