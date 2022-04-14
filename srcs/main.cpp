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

	map<char,int>re2;

	re2.add('r', 32);
	re2.add('x', 32);

	re2.disp();
	map<char,int>::iterator ite = re2.end();
	ite--;
	COUT ite->first ENDL;
	COUT ite->second ENDL;
}