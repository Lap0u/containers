#define CIN >> std::cin
#define COUT std::cout <<
#define ENDL << std::endl
#define NL COUT std::endl;

#include <iostream>
#include <iomanip>
#include <chrono>
#include <ctime>
#include <thread>

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

	std::clock_t c_start = std::clock();
	auto t_start = std::chrono::high_resolution_clock::now();
	
	
	using namespace std;

	map<int,int>re;

	re[0] = 0;
	re[1] = 1;
	re[2] = 2;
	re[3] = 3;
	re[4] = 4;
	map<int,int>::reverse_iterator it = re.rbegin();
	COUT it->first << " and " << it->second ENDL;
	it++;
	COUT it->first << " andwww " << it->second ENDL;
 	
	 
	 
	 
	 
	std::clock_t c_end = std::clock();
    auto t_end = std::chrono::high_resolution_clock::now();
 
    std::cout << std::fixed << std::setprecision(2) << "CPU time used: "
              << 1000.0 * (c_end - c_start) / CLOCKS_PER_SEC << " ms\n"
              << "Wall clock time passed: "
              << std::chrono::duration<double, std::milli>(t_end-t_start).count()
              << " ms\n";
}