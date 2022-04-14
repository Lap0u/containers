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

	map<char,int>::iterator ite = re.begin();
	COUT ite->first << " and " << ite->second ENDL;

	COUT re.find('g')->second ENDL;
	COUT re.find('e')->second ENDL;
	COUT re.find('y')->second ENDL;
	COUT re.find('x')->second ENDL;
	re.disp();

}