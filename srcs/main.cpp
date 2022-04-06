#include <vector>
#include <stack>
#include <map>
#include <iostream>
#include "../vector.hpp"
#include "../stack.hpp"

#define CIN >> std::cin
#define COUT std::cout <<
#define ENDL << std::endl
#define NL COUT std::endl;

using namespace ft;

int main()
{
	vector<vector<int> >	erase_in_me;
	for (int i = 0; i < 15; i++)
	{
		vector<int>	j(1, 1);
		erase_in_me.push_back(j);
	}
	// for (size_t i = 0; i < erase_in_me.size(); i++)
	// 	cout << erase_in_me.at(i).front() << ' ';
	// cout << '\n';

	erase_in_me.erase(erase_in_me.begin() + 7);

    return 0;
}

