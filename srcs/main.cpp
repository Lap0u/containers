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
	using namespace std;

	map<char,int>re;
	pair<char,int>pp('r', 10);
	re['e'] = 22;
	// re.add('e', 22);
	map<char,int>::iterator ite = re.begin();
	*ite = 21;

}