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

# if 0 //enable/disable int tests (next L 371)

#if 1
	COUT "****Constructors****" ENDL ENDL;

	vector<int>emp;
	printVec(emp);
	vector<int>fill (5, 11);
	fill[2] = 42;
	printVec(fill);
	vector<int>range (fill.begin(), fill.end());
	range[3] = 100;
	printVec(range);
	vector<int>copy (range);
	printVec(copy);
	copy[0] = -10;
	printVec(range);
	printVec(copy);
	SEP
#endif
#if 1
	COUT "****Assign****" ENDL ENDL;
	range.assign(copy.begin(), copy.end());
	printVec(range);
	fill.assign(10, 85);
	printVec(fill);
	SEP
#endif
#if 1
	COUT "****At****" ENDL ENDL;
	COUT "Print using at " ENDL;
	for (size_t i = 0; i < range.size(); i++)
		COUT range.at(i) ENDL;
	NL
	printVec(range);
	COUT "Print using at " ENDL;
	for (size_t i = 0; i < fill.size(); i++)
		COUT fill.at(i) ENDL;
	NL
	printVec(fill);
	SEP
#endif
#if 1
	COUT "****Back****" ENDL ENDL;
	copy[copy.size() - 1] = 66;
	printVec(emp);
	printVec(range);
	printVec(fill);
	printVec(copy);
	COUT "Back on empty ctnr is undefined behavior" ENDL;
	COUT "Range back is " << range.back() ENDL;
	COUT "Fill back is " << fill.back() ENDL;
	COUT "Copy back is " << copy.back() ENDL;
	SEP
#endif
#if 1
	COUT "****Capacity****" ENDL ENDL;

	COUT "Emp capacity is " << emp.capacity() ENDL;
	COUT "Range back is " << range.capacity() ENDL;
	COUT "Fill back is " << fill.capacity() ENDL;
	COUT "Copy back is " << copy.capacity() ENDL;
	SEP
#endif
#if 1
	COUT "****Clear****" ENDL ENDL;
	emp.clear();
	range.clear();
	fill.clear();
	copy.clear();
	printVec(emp);
	printVec(range);
	printVec(fill);
	printVec(copy);
	COUT "Emp capacity is " << emp.capacity() << " and size is " << emp.size() ENDL;
	COUT "Range capacity is " << range.capacity() << " and size is " << range.size() ENDL;
	COUT "Fill capacity is " << fill.capacity() << " and size is " << fill.size() ENDL;
	COUT "Copy capacity is " << copy.capacity() << " and size is " << copy.size() ENDL;
	for (size_t i = 0; i < range.capacity(); i++)
		range.push_back(i * 4);
	for (size_t i = 0; i < fill.capacity(); i++)
		fill.push_back(i * 5);
	for (size_t i = 0; i < copy.capacity(); i++)
		copy.push_back(i * 6);
	SEP
#endif
#if 1
	COUT "****Erase****" ENDL ENDL;
	printVec(emp);
	printVec(range);
	printVec(fill);
	printVec(copy);
	range.erase(range.begin(), range.end() - 2);
	fill.erase(fill.begin());
	copy.erase(copy.begin() + 1);
	COUT "After deletion" ENDL ENDL;
	printVec(emp);
	printVec(range);
	printVec(fill);
	printVec(copy);
	SEP
#endif
#if 1
	COUT "****Front****" ENDL ENDL;
	COUT "Front on empty ctnr is undefined behavior" ENDL;
	COUT "Range front is " << range.front() ENDL;
	COUT "Fill front is " << fill.front() ENDL;
	COUT "Copy front is " << copy.front() ENDL;
	SEP
#endif
#if 1
	COUT "****Allocator****" ENDL ENDL;
	int *lol;

	lol = range.get_allocator().allocate(3);
	range.get_allocator().construct(&lol[0], 11);
	range.get_allocator().construct(&lol[1], 12);
	range.get_allocator().construct(&lol[2], 13);
	COUT lol[0] ENDL;
	COUT lol[1] ENDL;
	COUT lol[2] ENDL;
	range.get_allocator().destroy(&lol[0]);
	range.get_allocator().destroy(&lol[1]);
	range.get_allocator().destroy(&lol[2]);
	range.get_allocator().deallocate(lol, 3);
	SEP
#endif
#if 1
	COUT "****Insert****" ENDL ENDL;
	printVec(emp);
	printVec(range);
	printVec(fill);
	printVec(copy);
	emp.insert(emp.begin(), 30);
	emp.insert(emp.begin(), 20);
	emp.insert(emp.begin(), 10);
	range.insert(range.begin() + 1, emp.begin(), emp.begin() + 1);
	range.insert(range.begin() + 1, emp.begin(), emp.begin() + 1);
	fill.insert(fill.begin(), 3, 29);
	fill.insert(fill.begin(), 3, 40);
	COUT "After insert" ENDL ENDL;
	printVec(emp);
	printVec(range);
	printVec(fill);
	printVec(copy);
	SEP
#endif
#if 1
	COUT "****Max_Size****" ENDL ENDL;
	COUT "Max size is " << emp.max_size() ENDL;
	COUT "Max size is " << range.max_size() ENDL;
	COUT "Max size is " << fill.max_size() ENDL;
	COUT "Max size is " << copy.max_size() ENDL;
	NL
	SEP
#endif
#if 1
	COUT "****Operator=****" ENDL ENDL;

	printVec(emp);
	printVec(range);
	printVec(fill);
	printVec(copy);
	vector<int>t_emp = emp;
	vector<int>t_fill = fill;
	vector<int>t_range = range;
	vector<int>t_copy = copy;
	COUT "After assignement and modifications" ENDL ENDL;
	t_emp[1] = t_fill[1] = t_range[1] = t_copy[1] = -99;
	printVec(emp);
	printVec(t_emp);
	printVec(range);
	printVec(t_range);
	printVec(fill);
	printVec(t_fill);
	printVec(copy);	
	printVec(t_copy);
	SEP
#endif
#if 1
	COUT "****Pop_back****" ENDL ENDL;

	printVec(emp);
	printVec(range);
	printVec(fill);
	printVec(copy);
	COUT "After 3 pop_backs each" ENDL;
	for (int i = 0; i < 3; i++)
	{
		emp.pop_back();
		range.pop_back();
		fill.pop_back();
		copy.pop_back();
	}
	printVec(emp);
	printVec(range);
	printVec(fill);
	printVec(copy);
	SEP
#endif
#if 1
	COUT "****Push_back****" ENDL ENDL;

	printVec(emp);
	printVec(range);
	printVec(fill);
	printVec(copy);
	COUT "After 3 push_backs each" ENDL;
	for (int i = 0; i < 3; i++)
	{
		emp.push_back(i * -2);
		range.push_back(i * -3);
		fill.push_back(i * -4);
		copy.push_back(i * -5);
	}
	printVec(emp);
	printVec(range);
	printVec(fill);
	printVec(copy);
	SEP
#endif
#if 1
	COUT "****Rbegin/Rend****" ENDL;

	vector<int>::reverse_iterator emprbeg = emp.rbegin();
	vector<int>::reverse_iterator rangerbeg = range.rbegin();
	vector<int>::reverse_iterator fillrbeg = fill.rbegin();
	vector<int>::reverse_iterator copyrbeg = copy.rbegin();

	COUT "Displaying in reverse order" ENDL;
	for (;emprbeg != emp.rend(); emprbeg++)
		COUT *emprbeg ENDL;
	NL
	for (;rangerbeg != range.rend(); rangerbeg++)
		COUT *rangerbeg ENDL;
	NL
	for (;fillrbeg != fill.rend(); fillrbeg++)
		COUT *fillrbeg ENDL;
	NL
	for (;copyrbeg != copy.rend(); copyrbeg++)
		COUT *copyrbeg ENDL;
	NL
	COUT "Original order" ENDL;
	printVec(emp);
	printVec(range);
	printVec(fill);
	printVec(copy);
	SEP
#endif
#if 1
	COUT "****Reserve****" ENDL;

	printVec(range);
	COUT "range capacity is " << range.capacity() ENDL;
	range.reserve(20);
	COUT "range capacity is " << range.capacity() ENDL;
	range.reserve(10);
	COUT "range capacity is " << range.capacity() ENDL;
	range.reserve(400);
	//range.reserve(-20); /*************************************test si envoie exception car -20 = trop grand nombre(size_t)********/
	COUT "range capacity is " << range.capacity() ENDL;
	printVec(range);
	SEP
#endif
#if 1
	COUT "****Resize****" ENDL;

	printVec(range);
	COUT "range size is " << range.size() ENDL;
	range.resize(2);
	printVec(range);
	COUT "range size is " << range.size() ENDL;
	range.resize(5, 55);
	printVec(range);
	COUT "range size is " << range.size() ENDL;
	range.resize(10);
	// range.resize(-20); /*************************************test si envoie exception car -20 = trop grand nombre(size_t)********/
	printVec(range);
	COUT "range size is " << range.size() ENDL;
	NL
	SEP
#endif
#if 1
	COUT "****Vector::Swap****" ENDL;

	printVec(range);
	printVec(fill);
	fill.swap(range);
	printVec(range);
	printVec(fill);
	range.swap(fill);	
	printVec(range);
	printVec(fill);
	SEP
#endif
#if 1
	COUT "****Relational Operator****" ENDL;
	COUT (range == fill) ENDL;
	COUT (range != fill) ENDL;
	COUT (range < fill) ENDL;
	COUT (range > fill) ENDL;
	COUT (range <= fill) ENDL;
	COUT (range >= fill) ENDL;
	
	NL
	
	COUT (fill ==  range) ENDL;
	COUT (fill !=  range) ENDL;
	COUT (fill <  range) ENDL;
	COUT (fill >  range) ENDL;
	COUT (fill <=  range) ENDL;
	COUT (fill >=  range) ENDL;

	NL

	COUT (fill ==  fill) ENDL;
	COUT (fill !=  fill) ENDL;
	COUT (fill <  fill) ENDL;
	COUT (fill >  fill) ENDL;
	COUT (fill <=  fill) ENDL;
	COUT (fill >=  fill) ENDL;
	NL
	SEP
#endif
#if 1
	COUT "****Generic swap overload****" ENDL;

	printVec(range);
	printVec(fill);
	swap(fill, range);
	printVec(range);
	printVec(fill);
	swap(range, fill);	
	printVec(range);
	printVec(fill);
	SEP
#endif

# endif

# if 1 //enable/disable std::string tests

# include <string>

#if 1
	COUT "****Constructors****" ENDL ENDL;

	vector<std::string>emp;
	printVec(emp);
	vector<std::string>fill (5, "Hello");
	fill[2] = "Party";
	printVec(fill);
	vector<std::string>range (fill.begin(), fill.end());
	range[3] = "Night";
	printVec(range);
	vector<std::string>copy (range);
	printVec(copy);
	copy[0] = "Tomorrow";
	printVec(range);
	printVec(copy);
	SEP
#endif
#if 1
	COUT "****Assign****" ENDL ENDL;
	range.assign(copy.begin(), copy.end());
	printVec(range);
	fill.assign(10, "Pli");
	printVec(fill);
	SEP
#endif
#if 1
	COUT "****At****" ENDL ENDL;
	COUT "Print using at " ENDL;
	for (size_t i = 0; i < range.size(); i++)
		COUT range.at(i) ENDL;
	NL
	printVec(range);
	COUT "Print using at " ENDL;
	for (size_t i = 0; i < fill.size(); i++)
		COUT fill.at(i) ENDL;
	NL
	printVec(fill);
	SEP
#endif
#if 1
	COUT "****Back****" ENDL ENDL;
	copy[copy.size() - 1] = "Marty";
	printVec(emp);
	printVec(range);
	printVec(fill);
	printVec(copy);
	COUT "Back on empty ctnr is undefined behavior" ENDL;
	COUT "Range back is " << range.back() ENDL;
	COUT "Fill back is " << fill.back() ENDL;
	COUT "Copy back is " << copy.back() ENDL;
	SEP
#endif
#if 1
	COUT "****Capacity****" ENDL ENDL;

	COUT "Emp capacity is " << emp.capacity() ENDL;
	COUT "Range back is " << range.capacity() ENDL;
	COUT "Fill back is " << fill.capacity() ENDL;
	COUT "Copy back is " << copy.capacity() ENDL;
	SEP
#endif
#if 1
	COUT "****Clear****" ENDL ENDL;
	vector<std::string>t_emp = emp;
	vector<std::string>t_range = range;
	vector<std::string>t_fill = fill;
	vector<std::string>t_copy = copy;

	emp.clear();
	range.clear();
	fill.clear();
	copy.clear();
	printVec(emp);
	printVec(range);
	printVec(fill);
	printVec(copy);
	COUT "Emp capacity is " << emp.capacity() << " and size is " << emp.size() ENDL;
	COUT "Range capacity is " << range.capacity() << " and size is " << range.size() ENDL;
	COUT "Fill capacity is " << fill.capacity() << " and size is " << fill.size() ENDL;
	COUT "Copy capacity is " << copy.capacity() << " and size is " << copy.size() ENDL;
	emp = t_emp;
	range = t_range;
	fill = t_fill;
	copy = t_copy;
	SEP
#endif
#if 1
	COUT "****Erase****" ENDL ENDL;
	printVec(emp);
	printVec(range);
	printVec(fill);
	printVec(copy);
	range.erase(range.begin(), range.end() - 2);
	fill.erase(fill.begin());
	copy.erase(copy.begin() + 1);
	COUT "After deletion" ENDL ENDL;
	printVec(emp);
	printVec(range);
	printVec(fill);
	printVec(copy);
	SEP
#endif
#if 1
	COUT "****Front****" ENDL ENDL;
	COUT "Front on empty ctnr is undefined behavior" ENDL;
	COUT "Range front is " << range.front() ENDL;
	COUT "Fill front is " << fill.front() ENDL;
	COUT "Copy front is " << copy.front() ENDL;
	SEP
#endif
#if 1
	COUT "****Allocator****" ENDL ENDL;
	std::string *lol;

	lol = range.get_allocator().allocate(3);
	range.get_allocator().construct(&lol[0], "pif");
	range.get_allocator().construct(&lol[1], "paf");
	range.get_allocator().construct(&lol[2], "pouf");
	COUT lol[0] ENDL;
	COUT lol[1] ENDL;
	COUT lol[2] ENDL;
	range.get_allocator().destroy(&lol[0]);
	range.get_allocator().destroy(&lol[1]);
	range.get_allocator().destroy(&lol[2]);
	range.get_allocator().deallocate(lol, 3);
	SEP
#endif
#if 1
	COUT "****Insert****" ENDL ENDL;
	printVec(emp);
	// printVec(range);
	// printVec(fill);
	// printVec(copy);
	emp.insert(emp.begin(), "pif");
	printVec(emp);
	emp.insert(emp.begin(), "paf");
	printVec(emp);
	emp.insert(emp.begin(), "anticonstitutionnellement");
	printVec(emp);
	// range.insert(range.begin() + 1, "lol");
	// // printVec(range);
	// // range.insert(range.begin() + 1, emp.begin(), emp.begin() + 1);
	// // range.insert(range.begin() + 1, emp.begin(), emp.begin() + 1);
	// // NL NL NL
	// // printVec(fill);
	// // fill.insert(fill.begin(), 3, "oiseau");
	// // printVec(fill);
	// // fill.insert(fill.begin(), 3, "voiture");
	// // COUT "After insert" ENDL ENDL;
	// printVec(emp);
	// printVec(range);
	// printVec(fill);
	// printVec(copy);
	SEP
#endif
#if 0
	COUT "****Max_Size****" ENDL ENDL;
	COUT "Max size is " << emp.max_size() ENDL;
	COUT "Max size is " << range.max_size() ENDL;
	COUT "Max size is " << fill.max_size() ENDL;
	COUT "Max size is " << copy.max_size() ENDL;
	NL
	SEP
#endif
#if 0
	COUT "****Operator=****" ENDL ENDL;

	printVec(emp);
	printVec(range);
	printVec(fill);
	printVec(copy);
	vector<std::string>rt_emp = emp;
	vector<std::string>rt_fill = fill;
	vector<std::string>rt_range = range;
	vector<std::string>rt_copy = copy;
	COUT "After assignement and modifications" ENDL ENDL;
	rt_emp[1] = rt_fill[1] = rt_range[1] = rt_copy[1] = "aurevoir";
	printVec(emp);
	printVec(rt_emp);
	printVec(range);
	printVec(rt_range);
	printVec(fill);
	printVec(rt_fill);
	printVec(copy);	
	printVec(rt_copy);
	SEP
#endif
#if 0
	COUT "****Pop_back****" ENDL ENDL;

	printVec(emp);
	printVec(range);
	printVec(fill);
	printVec(copy);
	COUT "After 3 pop_backs each" ENDL;
	for (int i = 0; i < 3; i++)
	{
		emp.pop_back();
		range.pop_back();
		fill.pop_back();
		copy.pop_back();
	}
	printVec(emp);
	printVec(range);
	printVec(fill);
	printVec(copy);
	SEP
#endif
#if 0
	COUT "****Push_back****" ENDL ENDL;

	printVec(emp);
	printVec(range);
	printVec(fill);
	printVec(copy);
	COUT "After 3 push_backs each" ENDL;
	for (int i = 0; i < 3; i++)
	{
		emp.push_back("avion");
		range.push_back("poisson");
		fill.push_back("comique");
		copy.push_back("panneauxx");
	}
	printVec(emp);
	printVec(range);
	printVec(fill);
	printVec(copy);
	SEP
#endif
#if 0
	COUT "****Rbegin/Rend****" ENDL;

	vector<std::string>::reverse_iterator emprbeg = emp.rbegin();
	vector<std::string>::reverse_iterator rangerbeg = range.rbegin();
	vector<std::string>::reverse_iterator fillrbeg = fill.rbegin();
	vector<std::string>::reverse_iterator copyrbeg = copy.rbegin();

	COUT "Displaying in reverse order" ENDL;
	for (;emprbeg != emp.rend(); emprbeg++)
		COUT *emprbeg ENDL;
	NL
	for (;rangerbeg != range.rend(); rangerbeg++)
		COUT *rangerbeg ENDL;
	NL
	for (;fillrbeg != fill.rend(); fillrbeg++)
		COUT *fillrbeg ENDL;
	NL
	for (;copyrbeg != copy.rend(); copyrbeg++)
		COUT *copyrbeg ENDL;
	NL
	COUT "Original order" ENDL;
	printVec(emp);
	printVec(range);
	printVec(fill);
	printVec(copy);
	SEP
#endif
#if 0
	COUT "****Reserve****" ENDL;

	printVec(range);
	COUT "range capacity is " << range.capacity() ENDL;
	range.reserve(20);
	COUT "range capacity is " << range.capacity() ENDL;
	range.reserve(10);
	COUT "range capacity is " << range.capacity() ENDL;
	range.reserve(400);
	//range.reserve(-20); /*************************************test si envoie exception car -20 = trop grand nombre(size_t)********/
	COUT "range capacity is " << range.capacity() ENDL;
	printVec(range);
	SEP
#endif
#if 0
	COUT "****Resize****" ENDL;

	printVec(range);
	COUT "range size is " << range.size() ENDL;
	range.resize(2);
	printVec(range);
	COUT "range size is " << range.size() ENDL;
	range.resize(5, "Pelouse");
	printVec(range);
	COUT "range size is " << range.size() ENDL;
	range.resize(10);
	// range.resize(-20); /*************************************test si envoie exception car -20 = trop grand nombre(size_t)********/
	printVec(range);
	COUT "range size is " << range.size() ENDL;
	NL
	SEP
#endif
#if 0
	COUT "****Vector::Swap****" ENDL;

	printVec(range);
	printVec(fill);
	fill.swap(range);
	printVec(range);
	printVec(fill);
	range.swap(fill);	
	printVec(range);
	printVec(fill);
	SEP
#endif
#if 0
	COUT "****Relational Operator****" ENDL;
	COUT (range == fill) ENDL;
	COUT (range != fill) ENDL;
	COUT (range < fill) ENDL;
	COUT (range > fill) ENDL;
	COUT (range <= fill) ENDL;
	COUT (range >= fill) ENDL;
	
	NL
	
	COUT (fill ==  range) ENDL;
	COUT (fill !=  range) ENDL;
	COUT (fill <  range) ENDL;
	COUT (fill >  range) ENDL;
	COUT (fill <=  range) ENDL;
	COUT (fill >=  range) ENDL;

	NL

	COUT (fill ==  fill) ENDL;
	COUT (fill !=  fill) ENDL;
	COUT (fill <  fill) ENDL;
	COUT (fill >  fill) ENDL;
	COUT (fill <=  fill) ENDL;
	COUT (fill >=  fill) ENDL;
	NL
	SEP
#endif
#if 0
	COUT "****Generic swap overload****" ENDL;

	printVec(range);
	printVec(fill);
	swap(fill, range);
	printVec(range);
	printVec(fill);
	swap(range, fill);	
	printVec(range);
	printVec(fill);
	SEP
#endif

#endif

return 0;
}