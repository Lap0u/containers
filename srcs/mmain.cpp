#include <iostream>
#include <map>
#include <list>
#include <vector>
#include <string>
#include <locale>

# define COUT std::cout <<
# define ENDL << std::endl
# define NL std::cout << std::endl;
# define SEP COUT "###############################" ENDL ENDL;

using namespace std;

void	printMap(const std::map<std::string, int> & map)
{
	if (map.empty())
	{
		COUT "Container is empty" ENDL;
		return ;
	}
	for (std::map<std::string, int>::const_iterator beg = map.begin(); beg != map.end(); beg++)
		COUT beg->first << "   " << beg->second ENDL;
	NL
}

int main ()
{

#if 1 //string/int tests 
	{
	#if 1
		COUT "Constructors" ENDL ENDL;

		map<std::string, int>temp_construct;
		temp_construct["A"] = 0;
		temp_construct["B"] = 1;
		temp_construct["C"] = 2;
		temp_construct["D"] = 3;
		map<std::string, int>emp;
		map<std::string, int>range(temp_construct.begin(), temp_construct.end());
		map<std::string, int>copy(range);
		printMap(emp);
		printMap(range);
		printMap(copy);
		range.at("B") = 20;
		printMap(range);
		printMap(copy);
		SEP
	#endif
	#if 1
		COUT "Clear" ENDL ENDL;

		map<std::string, int>t_emp = emp;
		map<std::string, int>t_range = range;
		map<std::string, int>t_copy = copy;
		t_emp.clear();
		t_range.clear();
		t_copy.clear();
		printMap(t_emp);
		printMap(t_range);
		printMap(t_copy);
		SEP
	#endif
	#if 1
		COUT "Count" ENDL ENDL;
		
		emp["E"] = 12;
		COUT "is e part of a emp? " << emp.count("E") ENDL;
		COUT "is e part of a range? " << range.count("E") ENDL;
		COUT "is e part of a copy? " << copy.count("E") ENDL;
		COUT "Adding E to range and removing it from emp" ENDL;
		emp.erase("E");
		range["E"];
		COUT "is e part of a emp? " << emp.count("E") ENDL;
		COUT "is e part of a range? " << range.count("E") ENDL;
		COUT "is e part of a copy? " << copy.count("E") ENDL;
		SEP
	#endif
	#if 1
		COUT "Equal_range" ENDL ENDL;
		
		pair<std::map<std::string,int>::iterator,std::map<std::string,int>::iterator> ret;
		ret = range.equal_range("E");
		COUT "We looked for E in range" ENDL;
		COUT "lower bound points to: ";
  		COUT ret.first->first << " => " << ret.first->second << '\n';

 		// COUT "upper bound points to: "; E is last so this would crash
 		// COUT ret.second->first << " => " << ret.second->second << '\n';

		ret = emp.equal_range("E");
		COUT "We looked for E in emp(doesn't exist so it would crash)" ENDL;
		// COUT "lower bound points to: "; (this will crash)
  		// COUT ret.first->first << " => " << ret.first->second << '\n';

 		// COUT "upper bound points to: ";
 		// COUT ret.second->first << " => " << ret.second->second << '\n';

		ret = copy.equal_range("C");
		COUT "We looked for C in copy" ENDL;
		COUT "lower bound points to: ";
  		COUT ret.first->first << " => " << ret.first->second << '\n';

 		COUT "upper bound points to: ";
 		COUT ret.second->first << " => " << ret.second->second << '\n';
	#endif

	}
#endif
}