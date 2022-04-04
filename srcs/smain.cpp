
#include "../stack.hpp"
#include "../vector.hpp"
#include <vector>
#include <stack>
#include <deque>
#include <list>

#include <iostream>

# define COUT std::cout <<
# define ENDL << std::endl
# define NL std::cout << std::endl;
# define SEP COUT "###############################" ENDL ENDL;

int main()
{
	using namespace NS;
	{
		COUT "vector tests" ENDL;

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
		NL SEP
	}
	{
		COUT "Default test (myvector)" ENDL;

		ft::vector<int>re;

		for (int i = 0; i < 5; i++)
			re.push_back(i + 10);
		ft::stack<int>lol (re);
		ft::stack<int>rrr = lol;

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
		NL SEP
	}
	{
		COUT "deque tests" ENDL;

		std::deque<std::string>re;
		
		for (int i = 0; i < 5; i++)
			re.push_back("hello");
		stack<std::string, std::deque<std::string> >lol (re);
		stack<std::string, std::deque<std::string> >rrr = lol;

		COUT "size is " << lol.size() ENDL ENDL;
		COUT "While empty" ENDL ENDL;
		while (lol.size())
		{
			COUT lol.top() ENDL;
			lol.pop();
			COUT "is empty? : " << lol.empty() ENDL;
		}
		COUT std::endl << rrr.top() ENDL;
		rrr.top() = "hawai";
		COUT std::endl << rrr.top() ENDL;
		for (size_t i = 0; i < rrr.size(); i++)
			lol.push("calor");
		while (lol.size())
		{
			COUT lol.top() ENDL;
			lol.pop();
			COUT "is empty? : " << lol.empty() ENDL;
		}
		NL SEP
	}
	{
		COUT "list tests" ENDL;

		std::list<int>re;
		
		for (int i = 0; i < 5; i++)
			re.push_back(i + 10);
		stack<int, std::list<int> >lol (re);
		stack<int, std::list<int> >rrr = lol;

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
		NL SEP
	}
}