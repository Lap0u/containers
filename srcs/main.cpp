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
	re.add('g', 22);
	re.add('y', 22);
	re.add('x', 22);

	map<char,int>::iterator ite = re.begin();
	COUT ite->first << " and " << ite->second ENDL;

	re.find('g');
	re.find('e');
	re.find('y');
	re.find('x');
	re.find('s');

}