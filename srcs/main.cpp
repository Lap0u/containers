#define CIN >> std::cin
#define COUT std::cout <<
#define ENDL << std::endl
#define NL COUT std::endl;

#include <time.h>
#include <stdlib.h>


#include <utility>
#include <map>
#include <list>
#include "../map.hpp"
#include "../headers/RBT.hpp"

int main()
{
	using namespace ft;

	// map<int,int>re;

	// re.insert(pair<int,int>(12, 15));
	// re.insert(pair<int,int>(12, 14));
	srand(time(NULL));
	std::list<pair<int,int> >lol;

	for (int i = 0; i < 7; i++)
	{
		// srand(time(NULL));
		lol.push_back(pair<int,int>(rand() % 1000, i));
	}
	map<int,int>re2(lol.begin(), lol.end());
	// map<int,int>re;

	// re.add(947,0);
	// re.add(367,1);
	// re.add(532,2);
	// re.add(659,3);
	// re.add(168,4);
	// re.add(976,5);
	// re.add(480,6);

	map<int,int>::iterator it = re2.begin();
	map<int,int>::iterator ite = re2.end();

	re2.disp();
	while (it != ite)
	{
		COUT it->first << " and " << it->second ENDL;
		it++;
	}
	// re.disp();
}