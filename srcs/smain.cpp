
#include "../stack.hpp"
#include "../vector.hpp"
#include <vector>
#include <stack>

#include <iostream>

# define COUT std::cout <<
# define ENDL << std::endl
# define NL std::cout << std::endl;
# define DEB COUT "yo" ENDL ENDL;

int main()
{
	using namespace NS;

	vector<int>re (3, 13);
	stack<int, vector<int> >lol (re);
	stack<int, vector<int> >temp = lol;
	
	for (int i = 0; i < 3; i++)
	{
		COUT temp.top() ENDL;
		temp.pop();
	}
	NL

	temp = lol;
	for (int i = 0; i < 3; i++)
	{
		temp.push(15);
		COUT temp.top() ENDL;
	}
	NL
	
	for (int i = 0; i < 6; i++)
	{
		COUT temp.top() ENDL;
		temp.pop();
	}
	return 0;
}