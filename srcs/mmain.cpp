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
	COUT "Container size is " << map.size() ENDL;
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
		// COUT "lower bound points to: "; (this would crash)
  		// COUT ret.first->first << " => " << ret.first->second << '\n';

 		// COUT "upper bound points to: ";
 		// COUT ret.second->first << " => " << ret.second->second << '\n';

		ret = copy.equal_range("C");
		COUT "We looked for C in copy" ENDL;
		COUT "lower bound points to: ";
  		COUT ret.first->first << " => " << ret.first->second << '\n';

 		COUT "upper bound points to: ";
 		COUT ret.second->first << " => " << ret.second->second << '\n';
		SEP
	#endif
	#if 1
		COUT "Erase" ENDL ENDL;

		map<std::string, int>erase_copy = copy;
		emp["X"] = 0;
		emp["Y"] = 10;
		emp["Z"] = 20;
		printMap(emp);
		printMap(range);
		printMap(copy);
		COUT "Erase emp.begin (position erase)" ENDL;
		COUT "Erase range[C] (key erase)" ENDL;
		COUT "Erase copy entirely (iterator range)" ENDL ENDL;
		emp.erase(emp.begin());
		range.erase("C");
		erase_copy.erase(erase_copy.begin(), erase_copy.end());
		printMap(emp);
		printMap(range);
		printMap(erase_copy);
		SEP
	#endif
	#if 1
		COUT "Find" ENDL ENDL;

		printMap(emp);
		printMap(range);
		printMap(copy);
		COUT "Looking for H in emp (doesn't exist)" ENDL;
		COUT "Looking for B in range" ENDL;
		COUT "Looking for C in copy (const)" ENDL;
		map<std::string, int>::iterator find_emp_it = emp.find("H");
		map<std::string, int>::iterator find_range_it = range.find("B");
		map<std::string, int>::const_iterator find_copy_it = copy.find("C");

		COUT "emp result : key is (print one before) " << (--find_emp_it)->first << " content is " << find_emp_it->second ENDL; 
		COUT "range result : key is " << find_range_it->first << " content is " << find_range_it->second ENDL; 
		COUT "copy result : key is " << find_copy_it->first << " content is " << find_copy_it->second ENDL; 
		SEP
	#endif
	#if 1
		COUT "Get_allocator" ENDL ENDL;

		pair<const std::string, int> *tab;

		COUT "Commenting the deallocation will cause a leak" ENDL;
		tab = range.get_allocator().allocate(4);
		range.get_allocator().deallocate(tab, 4);
		SEP
	#endif
	#if 1

		pair<map<std::string, int>::iterator, bool>Insert_emp_it;
		map<std::string, int>::iterator Insert_range_it;
		pair<std::string, int>j_pair = make_pair("J", 88);
		pair<std::string, int>l_pair = make_pair("L", 99);
		COUT "Insert" ENDL ENDL;
		printMap(emp);
		printMap(range);
		printMap(copy);

		COUT "Inserting J - 88 pair to emp twice (pair only added once)" ENDL;
		COUT "Inserting L -99 pair to range.beg() + 1 (pair only added once)" ENDL;
		COUT "Inserting range content to copy (iterator range)" ENDL ENDL;
		Insert_emp_it = emp.insert(j_pair);
		COUT "key res is " << Insert_emp_it.first->first << " and content res is " << Insert_emp_it.first->second <<
		" and it has been inserted? : " << Insert_emp_it.second ENDL;
		Insert_emp_it = emp.insert(j_pair);
		COUT "key res is " << Insert_emp_it.first->first << " and content res is " << Insert_emp_it.first->second <<
		" and it has been inserted? : " << Insert_emp_it.second ENDL;
		Insert_range_it = range.insert(++range.begin(), l_pair);
		COUT "key res is " << Insert_range_it->first << " and content res is " << Insert_range_it->second ENDL;
		copy.insert(range.begin(), range.end());
		printMap(emp);
		printMap(range);
		printMap(copy);
		SEP
	#endif
	#if 1
		COUT "Key_comp" ENDL ENDL;

		pair<const std::string, int> kc1 = make_pair("R", 23);
		pair<const std::string, int> kc2 = make_pair("J", 23);
		pair<const std::string, int> kc3 = make_pair("R", 20);
		map<std::string, int>::key_compare comp;

		comp = range.key_comp();
		COUT "Using map comp to compare keys" ENDL;
		COUT "Is R - 23 lower than J - 22 : " << comp(kc1.first, kc2.first) ENDL;
		COUT "Is J - 22 lower than R - 23 : " << comp(kc2.first, kc1.first) ENDL;
		COUT "Is R - 23 lower than R - 20 : " << comp(kc1.first, kc3.first) ENDL;
		COUT "Is R - 20 lower than R - 20 : " << comp(kc3.first, kc1.first) ENDL;
		SEP
	#endif
	#if 1
		COUT "Lower bound" ENDL ENDL;
		printMap(emp);
		printMap(range);
		printMap(copy);
		map<std::string, int>::iterator Lb_emp_it;
		map<std::string, int>::const_iterator Lb_range_it;
		map<std::string, int>::const_iterator Lb_null;


		COUT "Looking for first member equals or after K in emp" ENDL;
		Lb_emp_it = emp.lower_bound("K");
		COUT "Key found is " << Lb_emp_it->first << " and content is " << Lb_emp_it->second ENDL ENDL;
		COUT "Looking for first member equals or after J in emp" ENDL;
		Lb_emp_it = emp.lower_bound("J");
		COUT "Key found is " << Lb_emp_it->first << " and content is " << Lb_emp_it->second ENDL ENDL;
		COUT "Looking for first member equals or after B in range" ENDL;
		Lb_range_it = range.lower_bound("B");
		COUT "Key found is " << Lb_range_it->first << " and content is " << Lb_range_it->second ENDL ENDL;
		COUT "Looking for first member equals or after G in range" ENDL;
		Lb_range_it = range.lower_bound("G");
		COUT "Key found is " << Lb_range_it->first << " and content is " << Lb_range_it->second ENDL ENDL;
		COUT "Looking for invalid member, display real result would crash" ENDL;
		Lb_null = range.lower_bound("M");
		if (Lb_null == range.end())
			COUT "Lower bound returned end() succesfully" ENDL;
		else
			COUT "Wrong return value" ENDL;		
		SEP
	#endif
	#if 1
		COUT "Max_size" ENDL ENDL;
		
		COUT emp.max_size() ENDL;
		COUT range.max_size() ENDL;
		COUT copy.max_size() ENDL;

		SEP
	#endif
	#if 1
		COUT "Operator=" ENDL ENDL;
		
		map<std::string, int>temp_opeq;

		temp_opeq = range;
		printMap(temp_opeq);
		printMap(range);
		temp_opeq["A"] = 56;
		range["P"] = -78;
		printMap(temp_opeq);
		printMap(range);
		SEP
	#endif
	#if 1
		COUT "Reverse_iterator" ENDL ENDL;
		
		printMap(emp);
		printMap(range);
		printMap(copy);
		COUT "Printed using reverse_iterators" ENDL;

		map<std::string, int>::reverse_iterator rit = emp.rbegin();
		map<std::string, int>::const_reverse_iterator crit = range.rbegin();
		for (;rit != emp.rend(); rit++)
			COUT "Member key is " << rit->first << " and content is " << rit->second ENDL;
		NL
		for (;crit != range.rend(); crit++)
			COUT "Member key is " << crit->first << " and content is " << crit->second ENDL;
		NL
		for (crit = copy.rbegin() ;crit != copy.rend(); crit++)
			COUT "Member key is " << crit->first << " and content is " << crit->second ENDL;
		NL
		SEP
	#endif
	#if 1
		COUT "Swap=" ENDL ENDL;
		
		COUT "Swapping copy and range twice" ENDL;
		
		printMap(copy);
		printMap(range);
		copy.swap(range);
		COUT "After one swap" ENDL;
		printMap(copy);
		printMap(range);
		copy.swap(range);
		COUT "Original state" ENDL;
		printMap(copy);
		printMap(range);


		COUT "Swapping copy and emp twice" ENDL;

		printMap(emp);
		printMap(copy);
		copy.swap(emp);
		COUT "After one swap" ENDL;
		printMap(emp);
		printMap(copy);
		copy.swap(emp);
		COUT "Original state" ENDL;
		printMap(emp);
		printMap(copy);
		NL
		SEP
	#endif
	#if 1
		COUT "Upper bound" ENDL ENDL;
		printMap(emp);
		printMap(range);
		printMap(copy);
		map<std::string, int>::iterator Ub_emp_it;
		map<std::string, int>::const_iterator Ub_range_it;
		map<std::string, int>::const_iterator Ub_null;


		COUT "Looking for first member after K in emp" ENDL;
		Ub_emp_it = emp.upper_bound("K");
		COUT "Key found is " << Ub_emp_it->first << " and content is " << Ub_emp_it->second ENDL ENDL;
		COUT "Looking for first member after J in emp" ENDL;
		Ub_emp_it = emp.upper_bound("J");
		COUT "Key found is " << Ub_emp_it->first << " and content is " << Ub_emp_it->second ENDL ENDL;
		COUT "Looking for first member after B in range" ENDL;
		Ub_range_it = range.upper_bound("B");
		COUT "Key found is " << Ub_range_it->first << " and content is " << Ub_range_it->second ENDL ENDL;
		COUT "Looking for first member after N in range" ENDL;
		Ub_range_it = range.upper_bound("G");
		COUT "Key found is " << Ub_range_it->first << " and content is " << Ub_range_it->second ENDL ENDL;
		COUT "Looking for invalid member, display real result would crash" ENDL;
		Ub_null = copy.upper_bound("M");
		if (Ub_null == copy.end())
			COUT "Upper bound returned end() succesfully" ENDL;
		else
			COUT "Wrong return value" ENDL;		
		SEP
	#endif
	#if 1
		COUT "Value_comp" ENDL ENDL;
		
		map<std::string, int>::value_compare myvcomp = range.value_comp();
		printMap(range);

		COUT "Comparing values of range (the key is compared)" ENDL ENDL;
		COUT range["L"] ENDL;
		COUT "99 < -78? :" << myvcomp(*(--range.rbegin()),*(range.rbegin())) ENDL;
		COUT "20 < -78? :" << myvcomp(*(++range.begin()),*(range.rbegin())) ENDL;
		SEP
	#endif
	}
#endif
}