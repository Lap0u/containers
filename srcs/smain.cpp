
#include "../stack.hpp"
#include "../vector.hpp"
#include <vector>
#include <stack>

#include <iostream>

# define COUT std::cout <<
# define ENDL << std::endl
# define NL std::cout << std::endl;
# define SEP COUT "###############################" ENDL ENDL;

int main()
{
	using namespace NS;

	vector<int>re;
	for (int i = 0; i < 5; i++)
		re.push_back(i + 10);
	stack<int, vector<int> >lol (re);
	stack<int, vector<int> >rrr = lol;

	COUT "size is " << lol.size() ENDL ENDL;
	COUT "While empty" ENDL ENDL;
	while (lol.size())
	{
		COUT lol.top() ENDL;
		lol.pop();
		COUT "is empty? : " << lol.empty() ENDL;
	}
	COUT std::endl << rrr.top() ENDL;
	rrr.top() = 121;
	COUT std::endl << rrr.top() ENDL;
	for (size_t i = 0; i < rrr.size(); i++)
		lol.push(i * 10);
	while (lol.size())
	{
		COUT lol.top() ENDL;
		lol.pop();
		COUT "is empty? : " << lol.empty() ENDL;
	}
}