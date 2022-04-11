#define CIN >> std::cin
#define COUT std::cout <<
#define ENDL << std::endl
#define NL COUT std::endl;

#include <map>
#include "../map.hpp"
#include "../headers/RBT.hpp"

int main()
{
	using namespace ft;

	map<char,int>re;
	// re['e'] = 22;
	re.add('e', 22);
	map<char,int>::iterator ite = re.begin();
	map<char,int>::iterator ite2 = re.begin();
	COUT ite->first ENDL;
	COUT ite->second ENDL;
	COUT (ite == ite2) ENDL;
	COUT (ite != ite2) ENDL;

}