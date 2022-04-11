#define CIN >> std::cin
#define COUT std::cout <<
#define ENDL << std::endl
#define NL COUT std::endl;

#include "../map.hpp"
#include "../headers/RBT.hpp"

int main()
{
	using namespace ft;

	redBlackTree<char, int>lol;

	lol.add('C', 22);
	COUT lol.root->value ENDL;
	lol.add('X', 50);
	lol.add('A', 20);
	COUT lol.root->childR->value ENDL;
	lol.add('W', 53);
	COUT lol.root->childR->childL->value ENDL;
	lol.add('C', 22);
	lol.print(lol.root, 0);


}