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
	
	
	using namespace ft;

	map<int,int>re;

	re[12] = 12;
	re[13] = 13;
	re[11] = 11;
	re.disp();
	re[10] = 10;
	re.disp();
	re[9] = 9;
	re.disp();


 	
	 
	 
	 
	 
	std::clock_t c_end = std::clock();
    auto t_end = std::chrono::high_resolution_clock::now();
 
    std::cout << std::fixed << std::setprecision(2) << "CPU time used: "
              << 1000.0 * (c_end - c_start) / CLOCKS_PER_SEC << " ms\n"
              << "Wall clock time passed: "
              << std::chrono::duration<double, std::milli>(t_end-t_start).count()
              << " ms\n";
}