#include "../vector.hpp"
#include <vector>
#include <iostream>

# define COUT std::cout <<
# define ENDL << std::endl
# define DEB COUT "yo" ENDL ENDL;

int main()
{
	using namespace NS;

	vector<int>re (3, 13);
	COUT re[1] ENDL;
	return 0;
}



