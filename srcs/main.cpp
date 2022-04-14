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
	map<char,int>::iterator low = re.lower_bound('g');
	map<char,int>::iterator up = re.upper_bound('g');
	COUT low->first << " and " << low->second ENDL;
	COUT up->first << " and " << up->second ENDL;
 

}