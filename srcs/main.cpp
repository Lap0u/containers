#define CIN >> std::cin
#define COUT std::cout <<
#define ENDL << std::endl
#define NL COUT std::endl;

#include <time.h>
#include <stdlib.h>


#include <utility>
#include <map>
#include <vector>
#include <list>
#include "../map.hpp"
#include "../headers/RBT.hpp"
#include "../vector.hpp"

int main()
{
	using namespace ft;

	map<int,std::string>re;

	re[42] = "lol";

	re[50] = "mdr";
	re[25] = "funny";

	re[46] = "bunny";
	re[21] = "fizz";
	re[30] = "buzz";
	re[55] = "fuzzy";

	re[18] = "bee";
	re[23] = "coconut";
	re[28] = "diary";
	re[35] = "fiesta";
	re[44] = "hello";
	re[48] = "world";
	re[53] = "this is a test";
	re[80] = "hey";

	re[12] = "no";
	re[20] = "idea";
	re[22] = "123";
	re[24] = "345";
	re[27] = "27";
	re[29] = "29";
	re[33] = "33";
	re[38] = "38";

	re[43] = "1";
	re[45] = "2";
	re[47] = "3";
	re[49] = "4";
	re[51] = "5";
	re[54] = "6";
	re[60] = "7";
	re[90] = "8";
	re.erase(25);
	re.erase(55);
	re.erase(24);
	re.disp();

	re.erase(54);
	re.disp();
	for (map<int,std::string>::iterator it = re.begin(); it != re.end();it++)
		COUT it->first << " - " << it->second ENDL;
	// map<int,std::string>::iterator it = re.find(51);
	// COUT it.get_node()->parent->mypair.first ENDL;
	// it++;
	// COUT it.get_node()->mypair.first ENDL;

}