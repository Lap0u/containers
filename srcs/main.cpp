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
	COUT ite->first ENDL; //fonction
	COUT ite->second ENDL;

	(void)ite;
}