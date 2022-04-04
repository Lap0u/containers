#include "../vector.hpp"
#include <vector>
#include <iostream>
#include <stdlib.h>

# define COUT std::cout <<
# define ENDL << std::endl
# define NL COUT std::endl;
# define SEP COUT "###############################" ENDL ENDL;

using namespace NS;

void	printVec(const vector<int> & vec)
{
	COUT "vec is empty = " << vec.empty() ENDL;
	if (vec.empty())
		return ;
	COUT "capacity is " << vec.capacity() << " and size is " << vec.size() ENDL;
	for (vector<int>::const_iterator beg = vec.begin(); beg != vec.end(); beg++)
		COUT *beg ENDL;
	NL
}

void	printVec(const vector<std::string> & vec)
{
	COUT "vec is empty = " << vec.empty() ENDL;
	if (vec.empty())
		return ;
	COUT "capacity is " << vec.capacity() << "  and size is " << vec.size() ENDL;
	for (vector<std::string>::const_iterator beg = vec.begin(); beg != vec.end(); beg++)
		COUT *beg ENDL;
	NL
}

int main()
{

# if 1 //enable/disable int tests (next L 378)

#if 1
	COUT "****Constructors****" ENDL ENDL;

	vector<int>empI;
	printVec(empI);
	vector<int>fillI (5, 11);
	fillI[2] = 42;
	printVec(fillI);
	vector<int>rangeI (fillI.begin(), fillI.end());
	rangeI[3] = 100;
	printVec(rangeI);
	vector<int>copyI (rangeI);
	printVec(copyI);
	copyI[0] = -10;
	printVec(rangeI);
	printVec(copyI);
	SEP
#endif
#if 1
	COUT "****Assign****" ENDL ENDL;
	rangeI.assign(copyI.begin(), copyI.end());
	printVec(rangeI);
	fillI.assign(10, 85);
	printVec(fillI);
	SEP
#endif
#if 1
	COUT "****At****" ENDL ENDL;
	COUT "Print using at " ENDL;
	for (size_t i = 0; i < rangeI.size(); i++)
		COUT rangeI.at(i) ENDL;
	NL
	printVec(rangeI);
	COUT "Print using at " ENDL;
	for (size_t i = 0; i < fillI.size(); i++)
		COUT fillI.at(i) ENDL;
	NL
	printVec(fillI);
	SEP
#endif
#if 1
	COUT "****Back****" ENDL ENDL;
	copyI[copyI.size() - 1] = 66;
	printVec(empI);
	printVec(rangeI);
	printVec(fillI);
	printVec(copyI);
	COUT "Back on empty ctnr is undefined behavior" ENDL;
	COUT "Range back is " << rangeI.back() ENDL;
	COUT "Fill back is " << fillI.back() ENDL;
	COUT "CopyI back is " << copyI.back() ENDL;
	SEP
#endif
#if 1
	COUT "****Capacity****" ENDL ENDL;

	COUT "Emp capacity is " << empI.capacity() ENDL;
	COUT "Range back is " << rangeI.capacity() ENDL;
	COUT "Fill back is " << fillI.capacity() ENDL;
	COUT "CopyI back is " << copyI.capacity() ENDL;
	SEP
#endif
#if 1
	COUT "****Clear****" ENDL ENDL;
	empI.clear();
	rangeI.clear();
	fillI.clear();
	copyI.clear();
	printVec(empI);
	printVec(rangeI);
	printVec(fillI);
	printVec(copyI);
	COUT "Emp capacity is " << empI.capacity() << " and size is " << empI.size() ENDL;
	COUT "Range capacity is " << rangeI.capacity() << " and size is " << rangeI.size() ENDL;
	COUT "Fill capacity is " << fillI.capacity() << " and size is " << fillI.size() ENDL;
	COUT "CopyI capacity is " << copyI.capacity() << " and size is " << copyI.size() ENDL;
	for (size_t i = 0; i < rangeI.capacity(); i++)
		rangeI.push_back(i * 4);
	for (size_t i = 0; i < fillI.capacity(); i++)
		fillI.push_back(i * 5);
	for (size_t i = 0; i < copyI.capacity(); i++)
		copyI.push_back(i * 6);
	SEP
#endif
#if 1
	COUT "****Erase****" ENDL ENDL;
	printVec(empI);
	printVec(rangeI);
	printVec(fillI);
	printVec(copyI);
	rangeI.erase(rangeI.begin(), rangeI.end() - 2);
	fillI.erase(fillI.begin());
	copyI.erase(copyI.begin() + 1);
	COUT "After deletion" ENDL ENDL;
	printVec(empI);
	printVec(rangeI);
	printVec(fillI);
	printVec(copyI);
	SEP
#endif
#if 1
	COUT "****Front****" ENDL ENDL;
	COUT "Front on empty ctnr is undefined behavior" ENDL;
	COUT "Range front is " << rangeI.front() ENDL;
	COUT "Fill front is " << fillI.front() ENDL;
	COUT "CopyI front is " << copyI.front() ENDL;
	SEP
#endif
#if 1
	COUT "****Allocator****" ENDL ENDL;
	int *lol;

	lol = rangeI.get_allocator().allocate(3);
	rangeI.get_allocator().construct(&lol[0], 11);
	rangeI.get_allocator().construct(&lol[1], 12);
	rangeI.get_allocator().construct(&lol[2], 13);
	COUT lol[0] ENDL;
	COUT lol[1] ENDL;
	COUT lol[2] ENDL;
	rangeI.get_allocator().destroy(&lol[0]);
	rangeI.get_allocator().destroy(&lol[1]);
	rangeI.get_allocator().destroy(&lol[2]);
	rangeI.get_allocator().deallocate(lol, 3);
	SEP
#endif
#if 1
	COUT "****Insert****" ENDL ENDL;
	printVec(empI);
	printVec(rangeI);
	printVec(fillI);
	empI.insert(empI.begin(), 30);
	empI.insert(empI.begin(), 20);
	empI.insert(empI.begin(), 10);
	rangeI.insert(rangeI.begin() + 1, empI.begin(), empI.begin() + 1);
	rangeI.insert(rangeI.begin() + 1, empI.begin(), empI.begin() + 1);
	fillI.insert(fillI.begin(), 3, 29);
	printVec(fillI);
	fillI.insert(fillI.begin(), 3, 40);
	COUT "After insert" ENDL ENDL;
	printVec(empI);
	printVec(rangeI);
	printVec(fillI);
	SEP
#endif
#if 1
	COUT "****Max_Size****" ENDL ENDL;
	COUT "Max size is " << empI.max_size() ENDL;
	COUT "Max size is " << rangeI.max_size() ENDL;
	COUT "Max size is " << fillI.max_size() ENDL;
	COUT "Max size is " << copyI.max_size() ENDL;
	NL
	SEP
#endif
#if 0
	COUT "****Operator=****" ENDL ENDL;

	printVec(empI);
	printVec(rangeI);
	printVec(fillI);
	printVec(copyI);
	vector<int>t_emp = empI;
	vector<int>t_fill = fillI;
	vector<int>t_range = rangeI;
	vector<int>t_copyI = copyI;
	COUT "After assignement and modifications" ENDL ENDL;
	t_emp[1] = t_fill[1] = t_range[1] = t_copyI[1] = -99;
	printVec(empI);
	printVec(t_emp);
	printVec(rangeI);
	printVec(t_range);
	printVec(fillI);
	printVec(t_fill);
	printVec(copyI);	
	printVec(t_copyI);
	SEP
#endif
#if 1
	COUT "****Pop_back****" ENDL ENDL;

	printVec(empI);
	printVec(rangeI);
	printVec(fillI);
	printVec(copyI);
	COUT "After 3 pop_backs each" ENDL;
	for (int i = 0; i < 3; i++)
	{
		empI.pop_back();
		rangeI.pop_back();
		fillI.pop_back();
		copyI.pop_back();
	}
	printVec(empI);
	printVec(rangeI);
	printVec(fillI);
	printVec(copyI);
	SEP
#endif
#if 1
	COUT "****Push_back****" ENDL ENDL;

	printVec(empI);
	printVec(rangeI);
	printVec(fillI);
	printVec(copyI);
	COUT "After 3 push_backs each" ENDL;
	for (int i = 0; i < 3; i++)
	{
		empI.push_back(i * -2);
		rangeI.push_back(i * -3);
		fillI.push_back(i * -4);
		copyI.push_back(i * -5);
	}
	printVec(empI);
	printVec(rangeI);
	printVec(fillI);
	printVec(copyI);
	SEP
#endif
#if 1
	COUT "****Rbegin/Rend****" ENDL;

	vector<int>::reverse_iterator emprbeg = empI.rbegin();
	vector<int>::reverse_iterator rangerbeg = rangeI.rbegin();
	vector<int>::reverse_iterator fillrbeg = fillI.rbegin();
	vector<int>::reverse_iterator copyIrbeg = copyI.rbegin();

	COUT "Displaying in reverse order" ENDL;
	for (;emprbeg != empI.rend(); emprbeg++)
		COUT *emprbeg ENDL;
	NL
	for (;rangerbeg != rangeI.rend(); rangerbeg++)
		COUT *rangerbeg ENDL;
	NL
	for (;fillrbeg != fillI.rend(); fillrbeg++)
		COUT *fillrbeg ENDL;
	NL
	for (;copyIrbeg != copyI.rend(); copyIrbeg++)
		COUT *copyIrbeg ENDL;
	NL
	COUT "Original order" ENDL;
	printVec(empI);
	printVec(rangeI);
	printVec(fillI);
	printVec(copyI);
	SEP
#endif
#if 1
	COUT "****Reserve****" ENDL;

	printVec(rangeI);
	COUT "rangeI capacity is " << rangeI.capacity() ENDL;
	rangeI.reserve(20);
	COUT "rangeI capacity is " << rangeI.capacity() ENDL;
	rangeI.reserve(10);
	COUT "rangeI capacity is " << rangeI.capacity() ENDL;
	rangeI.reserve(400);
	//rangeI.reserve(-20); /*************************************test si envoie exception car -20 = trop grand nombre(size_t)********/
	COUT "rangeI capacity is " << rangeI.capacity() ENDL;
	printVec(rangeI);
	SEP
#endif
#if 1
	COUT "****Resize****" ENDL;

	printVec(rangeI);
	COUT "rangeI size is " << rangeI.size() ENDL;
	rangeI.resize(2);
	printVec(rangeI);
	COUT "rangeI size is " << rangeI.size() ENDL;
	rangeI.resize(5, 55);
	printVec(rangeI);
	COUT "rangeI size is " << rangeI.size() ENDL;
	rangeI.resize(10);
	// rangeI.resize(-20); /*************************************test si envoie exception car -20 = trop grand nombre(size_t)********/
	printVec(rangeI);
	COUT "rangeI size is " << rangeI.size() ENDL;
	NL
	SEP
#endif
#if 1
	COUT "****Vector::Swap****" ENDL;

	printVec(rangeI);
	printVec(fillI);
	fillI.swap(rangeI);
	printVec(rangeI);
	printVec(fillI);
	rangeI.swap(fillI);	
	printVec(rangeI);
	printVec(fillI);
	SEP
#endif
#if 1
	COUT "****Relational Operator****" ENDL;
	COUT (rangeI == fillI) ENDL;
	COUT (rangeI != fillI) ENDL;
	COUT (rangeI < fillI) ENDL;
	COUT (rangeI > fillI) ENDL;
	COUT (rangeI <= fillI) ENDL;
	COUT (rangeI >= fillI) ENDL;
	
	NL
	
	COUT (fillI ==  rangeI) ENDL;
	COUT (fillI !=  rangeI) ENDL;
	COUT (fillI <  rangeI) ENDL;
	COUT (fillI >  rangeI) ENDL;
	COUT (fillI <=  rangeI) ENDL;
	COUT (fillI >=  rangeI) ENDL;

	NL

	COUT (fillI ==  fillI) ENDL;
	COUT (fillI !=  fillI) ENDL;
	COUT (fillI <  fillI) ENDL;
	COUT (fillI >  fillI) ENDL;
	COUT (fillI <=  fillI) ENDL;
	COUT (fillI >=  fillI) ENDL;
	NL
	SEP
#endif
#if 1
	COUT "****Generic swap overload****" ENDL;

	printVec(rangeI);
	printVec(fillI);
	swap(fillI, rangeI);
	printVec(rangeI);
	printVec(fillI);
	swap(rangeI, fillI);	
	printVec(rangeI);
	printVec(fillI);
	SEP
#endif

# endif

# if 1 //enable/disable std::string tests

# include <string>

#if 1
	COUT "****Constructors****" ENDL ENDL;

	vector<std::string>empS;
	printVec(empS);
	vector<std::string>fillS (5, "Hello");
	fillS[2] = "Party";
	printVec(fillS);
	vector<std::string>rangeS (fillS.begin(), fillS.end());
	rangeS[3] = "Night";
	printVec(rangeS);
	vector<std::string>copyS (rangeS);
	printVec(copyS);
	copyS[0] = "Tomorrow";
	printVec(rangeS);
	printVec(copyS);
	SEP
#endif
#if 1
	COUT "****Assign****" ENDL ENDL;
	rangeS.assign(copyS.begin(), copyS.end());
	printVec(rangeS);
	fillS.assign(10, "Pli");
	printVec(fillS);
	SEP
#endif
#if 1
	COUT "****At****" ENDL ENDL;
	COUT "Print using at " ENDL;
	for (size_t i = 0; i < rangeS.size(); i++)
		COUT rangeS.at(i) ENDL;
	NL
	printVec(rangeS);
	COUT "Print using at " ENDL;
	for (size_t i = 0; i < fillS.size(); i++)
		COUT fillS.at(i) ENDL;
	NL
	printVec(fillS);
	SEP
#endif
#if 1
	COUT "****Back****" ENDL ENDL;
	copyS[copyS.size() - 1] = "Marty";
	printVec(empS);
	printVec(rangeS);
	printVec(fillS);
	printVec(copyS);
	COUT "Back on empty ctnr is undefined behavior" ENDL;
	COUT "Range back is " << rangeS.back() ENDL;
	COUT "Fill back is " << fillS.back() ENDL;
	COUT "Copy back is " << copyS.back() ENDL;
	SEP
#endif
#if 1
	COUT "****Capacity****" ENDL ENDL;

	COUT "Emp capacity is " << empS.capacity() ENDL;
	COUT "Range back is " << rangeS.capacity() ENDL;
	COUT "Fill back is " << fillS.capacity() ENDL;
	COUT "Copy back is " << copyS.capacity() ENDL;
	SEP
#endif
#if 1
	COUT "****Clear****" ENDL ENDL;
	vector<std::string>t_empS = empS;
	vector<std::string>t_rangeS = rangeS;
	vector<std::string>t_fillS = fillS;
	vector<std::string>t_copyS = copyS;

	empS.clear();
	rangeS.clear();
	fillS.clear();
	copyS.clear();
	printVec(empS);
	printVec(rangeS);
	printVec(fillS);
	printVec(copyS);
	COUT "Emp capacity is " << empS.capacity() << " and size is " << empS.size() ENDL;
	COUT "Range capacity is " << rangeS.capacity() << " and size is " << rangeS.size() ENDL;
	COUT "Fill capacity is " << fillS.capacity() << " and size is " << fillS.size() ENDL;
	COUT "Copy capacity is " << copyS.capacity() << " and size is " << copyS.size() ENDL;
	empS = t_empS;
	rangeS = t_rangeS;
	fillS = t_fillS;
	copyS = t_copyS;
	SEP
#endif
#if 1
	COUT "****Erase****" ENDL ENDL;
	printVec(empS);
	printVec(rangeS);
	printVec(fillS);
	printVec(copyS);
	rangeS.erase(rangeS.begin(), rangeS.end() - 2);
	fillS.erase(fillS.begin());
	copyS.erase(copyS.begin() + 1);
	COUT "After deletion" ENDL ENDL;
	printVec(empS);
	printVec(rangeS);
	printVec(fillS);
	printVec(copyS);
	SEP
#endif
#if 1
	COUT "****Front****" ENDL ENDL;
	COUT "Front on empty ctnr is undefined behavior" ENDL;
	COUT "Range front is " << rangeS.front() ENDL;
	COUT "Fill front is " << fillS.front() ENDL;
	COUT "Copy front is " << copyS.front() ENDL;
	SEP
#endif
#if 1
	COUT "****Allocator****" ENDL ENDL;
	std::string *lolS;

	lolS = rangeS.get_allocator().allocate(3);
	rangeS.get_allocator().construct(&lolS[0], "pif");
	rangeS.get_allocator().construct(&lolS[1], "paf");
	rangeS.get_allocator().construct(&lolS[2], "pouf");
	COUT lolS[0] ENDL;
	COUT lolS[1] ENDL;
	COUT lolS[2] ENDL;
	rangeS.get_allocator().destroy(&lolS[0]);
	rangeS.get_allocator().destroy(&lolS[1]);
	rangeS.get_allocator().destroy(&lolS[2]);
	rangeS.get_allocator().deallocate(lolS, 3);
	SEP
#endif
#if 1
	COUT "****Insert****" ENDL ENDL;
	printVec(empS);
	printVec(rangeS);
	printVec(fillS);
	empS.insert(empS.begin(), "pif");
	empS.insert(empS.begin(), "paf");
	empS.insert(empS.begin(), "anticonstitutionnellement");
	rangeS.insert(rangeS.begin() + 1, empS.begin(), empS.begin() + 1);
	rangeS.insert(rangeS.begin() + 1, empS.begin() + 1, empS.begin() + 2);
	printVec(fillS);
	fillS.insert(fillS.begin(), 3, "oiseau");
	printVec(fillS);
	fillS.insert(fillS.begin(), 3, "voiture");
	COUT "After insert" ENDL ENDL;
	printVec(empS);
	printVec(rangeS);
	printVec(fillS);
	SEP
#endif
#if 1
	COUT "****Max_Size****" ENDL ENDL;
	COUT "Max size is " << empS.max_size() ENDL;
	COUT "Max size is " << rangeS.max_size() ENDL;
	COUT "Max size is " << fillS.max_size() ENDL;
	COUT "Max size is " << copyS.max_size() ENDL;
	NL
	SEP
#endif
#if 1
	COUT "****Operator=****" ENDL ENDL;

	printVec(empS);
	printVec(rangeS);
	printVec(fillS);
	printVec(copyS);
	vector<std::string>rt_emp = empS;
	vector<std::string>rt_fill = fillS;
	vector<std::string>rt_range = rangeS;
	vector<std::string>rt_copy = copyS;
	COUT "After assignement and modifications" ENDL ENDL;
	rt_emp[1] = rt_fill[1] = rt_range[1] = rt_copy[1] = "aurevoir";
	printVec(empS);
	printVec(rt_emp);
	printVec(rangeS);
	printVec(rt_range);
	printVec(fillS);
	printVec(rt_fill);
	printVec(copyS);	
	printVec(rt_copy);
	SEP
#endif
#if 1
	COUT "****Pop_back****" ENDL ENDL;

	printVec(empS);
	printVec(rangeS);
	printVec(fillS);
	printVec(copyS);
	COUT "After 3 pop_backs each" ENDL;
	for (int i = 0; i < 3; i++)
	{
		empS.pop_back();
		rangeS.pop_back();
		fillS.pop_back();
		copyS.pop_back();
	}
	printVec(empS);
	printVec(rangeS);
	printVec(fillS);
	printVec(copyS);
	SEP
#endif
#if 1
	COUT "****Push_back****" ENDL ENDL;

	printVec(empS);
	printVec(rangeS);
	printVec(fillS);
	printVec(copyS);
	COUT "After 3 push_backs each" ENDL;
	for (int i = 0; i < 3; i++)
	{
		empS.push_back("avion");
		rangeS.push_back("poisson");
		fillS.push_back("comique");
		copyS.push_back("panneauxx");
	}
	printVec(empS);
	printVec(rangeS);
	printVec(fillS);
	printVec(copyS);
	SEP
#endif
#if 1
	COUT "****Rbegin/Rend****" ENDL;

	vector<std::string>::reverse_iterator empSrbeg = empS.rbegin();
	vector<std::string>::reverse_iterator rangeSrbeg = rangeS.rbegin();
	vector<std::string>::reverse_iterator fillSrbeg = fillS.rbegin();
	vector<std::string>::reverse_iterator copySrbeg = copyS.rbegin();

	COUT "Displaying in reverse order" ENDL;
	for (;empSrbeg != empS.rend(); empSrbeg++)
		COUT *empSrbeg ENDL;
	NL
	for (;rangeSrbeg != rangeS.rend(); rangeSrbeg++)
		COUT *rangeSrbeg ENDL;
	NL
	for (;fillSrbeg != fillS.rend(); fillSrbeg++)
		COUT *fillSrbeg ENDL;
	NL
	for (;copySrbeg != copyS.rend(); copySrbeg++)
		COUT *copySrbeg ENDL;
	NL
	COUT "Original order" ENDL;
	printVec(empS);
	printVec(rangeS);
	printVec(fillS);
	printVec(copyS);
	SEP
#endif
#if 1
	COUT "****Reserve****" ENDL;

	printVec(rangeS);
	COUT "rangeS capacity is " << rangeS.capacity() ENDL;
	rangeS.reserve(20);
	COUT "rangeS capacity is " << rangeS.capacity() ENDL;
	rangeS.reserve(10);
	COUT "rangeS capacity is " << rangeS.capacity() ENDL;
	rangeS.reserve(400);
	// rangeS.reserve(-20); /*************************************test si envoie exception car -20 = trop grand nombre(size_t)********/
	COUT "rangeS capacity is " << rangeS.capacity() ENDL;
	printVec(rangeS);
	SEP
#endif
#if 1
	COUT "****Resize****" ENDL;

	printVec(rangeS);
	rangeS.resize(2);
	printVec(rangeS);
	rangeS.resize(5, "Pelouse");
	printVec(rangeS);
	rangeS.resize(10);
	// rangeS.resize(-20); /*************************************test si envoie exception car -20 = trop grand nombre(size_t)********/
	printVec(rangeS);
	NL
	SEP
#endif
#if 1
	COUT "****Vector::Swap****" ENDL;

	printVec(rangeS);
	printVec(fillS);
	fillS.swap(rangeS);
	printVec(rangeS);
	printVec(fillS);
	rangeS.swap(fillS);	
	printVec(rangeS);
	printVec(fillS);
	SEP
#endif
#if 1
	COUT "****Relational Operator****" ENDL;
	COUT (rangeS == fillS) ENDL;
	COUT (rangeS != fillS) ENDL;
	COUT (rangeS < fillS) ENDL;
	COUT (rangeS > fillS) ENDL;
	COUT (rangeS <= fillS) ENDL;
	COUT (rangeS >= fillS) ENDL;
	
	NL
	
	COUT (fillS ==  rangeS) ENDL;
	COUT (fillS !=  rangeS) ENDL;
	COUT (fillS <  rangeS) ENDL;
	COUT (fillS >  rangeS) ENDL;
	COUT (fillS <=  rangeS) ENDL;
	COUT (fillS >=  rangeS) ENDL;

	NL

	COUT (fillS ==  fillS) ENDL;
	COUT (fillS !=  fillS) ENDL;
	COUT (fillS <  fillS) ENDL;
	COUT (fillS >  fillS) ENDL;
	COUT (fillS <=  fillS) ENDL;
	COUT (fillS >=  fillS) ENDL;
	NL
	SEP
#endif
#if 1
	COUT "****Generic swap overload****" ENDL;

	printVec(rangeS);
	printVec(fillS);
	swap(fillS, rangeS);
	printVec(rangeS);
	printVec(fillS);
	swap(rangeS, fillS);	
	printVec(rangeS);
	printVec(fillS);
	SEP
#endif

#endif

return 0;
}