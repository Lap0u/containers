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
	int i = 0;
	using namespace ft;

	map<char,int>re;
	char x = 'a';
	for (;x != 'f';x++)
		re.add(x, x + '0');
	re.insert(pair<char,int>('r', 23));
	re.insert(pair<char,int>('1', 20));
	re.insert(pair<char,int>('4', 19));

	for (map<char,int>::iterator ite = re.begin(); ite != re.end() && i < 4; ite++)
	{
		COUT ite->first << " and " << ite->second ENDL;
		i++;
	}
	re.disp();
}