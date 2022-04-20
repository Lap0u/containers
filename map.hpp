#ifndef MAP_HPP
# define MAP_HPP

# define CIN >> std::cin
# define COUT std::cout <<
# define ENDL << std::endl
# define NL COUT std::endl;

# include <memory>
# include <functional>
# include "./headers/RBT.hpp"
# include "./headers/pair.hpp"
# include "./headers/reverse_iterator.hpp"
# include "./headers/iterator_traits.hpp"
# include "./headers/m_iterator.hpp"
# include "./headers/equal.hpp"
# include "./headers/lexicographical_compare.hpp"

namespace ft {

template<class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<pair<const Key,T> > >
class map
{

public:
	void	disp() {rbt.print(rbt.root, 0); COUT "size is " << size() ENDL << "#################################################" ENDL;}
	void	add(Key x, T y) {rbt.add(x, y);}
	typedef					Key											key_type;
	typedef					T											mapped_type;
	typedef					pair<const key_type, mapped_type>			value_type;
	
	typedef					Compare										key_compare;
	//value_compare
	
	typedef					Alloc										allocator_type;
	typedef		typename	allocator_type::reference					reference;
	typedef		typename	allocator_type::const_reference				const_reference;
	typedef		typename	allocator_type::pointer						pointer;
	typedef		typename	allocator_type::const_pointer				const_pointer;
	
	typedef					mapIterator<value_type>						iterator;
	typedef					mapIterator<const value_type>				const_iterator;

	typedef					ft::reverse_iterator<iterator>				reverse_iterator;
    typedef					ft::reverse_iterator<const_iterator>		const_reverse_iterator;

	typedef		typename	iterator_traits<iterator>::difference_type	difference_type;
	typedef					size_t										size_type;

private:
	redBlackTree<Key, T, Compare>	rbt;
	allocator_type					_alloc;
	key_compare						_comp;


public:

/*==Basics==*/

	/*		Constructor		*/
	explicit map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
		: rbt(key_type(), mapped_type()), _alloc(alloc), _comp(comp) {}

	template <class InputIterator> 
	map(InputIterator first, InputIterator last,const key_compare& comp = key_compare(),
    	const allocator_type& alloc = allocator_type()) : rbt(key_type(), mapped_type()), _alloc(alloc), _comp(comp)
	{
		this->insert(first, last);
	}

	map	(const map& x) : rbt(key_type(), mapped_type()), _alloc(x._alloc), _comp(x._comp)
	{
		this->insert(x.begin(), x.end());
	}

	/*		Destructor		*/
	~map() {clear();}

	/*		Operator=		*/
	map& operator= (const map& other)
	{
		if (this != &other)
		{
			this->clear();
			_alloc = other._alloc;
			_comp = other._comp;
			this->insert(other.begin(), other.end());
		}
		return *this;
	}


/*==Iterators==*/

	/*		Begin		*/
	iterator begin() {return iterator(rbt.first());}
	const_iterator begin() const {return const_iterator(rbt.first());}


	/*		End			*/
	iterator end() {return iterator(rbt.last());}
	const_iterator end() const {return const_iterator(rbt.last());}
	

	/*		Rbegin		*/
	reverse_iterator rbegin() {return reverse_iterator(end());}
	const_reverse_iterator rbegin() const {return const_reverse_iterator(end());}
	/*		Rend		*/
	reverse_iterator rend() {return reverse_iterator(begin());}
	const_reverse_iterator rend() const {return const_reverse_iterator(begin());}

/*==Capacity==*/

	/*		Empty		*/
	bool empty() const {return !this->rbt.size;}

	/*		Size		*/
	size_type size() const {return this->rbt.size;}
	/*		Max_size		*/
	size_type max_size() const {return rbt._allocator.max_size();}


/*==Element acces==*/

	/*		Operator[]		*/
	mapped_type& operator[] (const key_type& k)
	{
		iterator	save = find(k);
		if (save == end())
		{
			rbt.add(k, mapped_type());
			return find(k)->second;
		}
		return save->second;
	}


/*==Modifiers==*/

	/*		Insert		*/
	pair<iterator, bool> insert (const value_type &val)
	{
		bool	ret = false;
		iterator save;

		if (rbt.root == NULL || find(val.first) == end())
		{
			rbt.add(val.first, val.second);
			ret = true;
		}
		save = find(val.first);
		return pair<iterator, bool>(save, ret);
	}

	iterator insert(iterator hint, const value_type &val)
	{
		(void)hint;
		insert(val);
		return find(val.first);
	}
template <class InputIterator>
	void insert (InputIterator first, InputIterator last)
	{
		while (first != last)
		{
			if (rbt.root == NULL || find(first->first) == end())
				rbt.add(first->first, first->second);
			first++;
		}
	}
	/*		Erase		*/
	void erase (iterator position)
	{
		rbt.erase(position.get_node());
	}

	size_type erase (const key_type& k)
	{
		iterator temp = find(k);

		if (temp == end())
			return 0;
		rbt.erase(temp.get_node());
		return 1;
	}

	void erase (iterator first, iterator last)
	{
		iterator temp;
		if (first == begin() && last == end())
			return clear();
		while (first != last)
		{
			temp = first;
			temp++;
			rbt.erase(first.get_node());
			first = temp;
		}
	}
	/*		Swap		*/
	void swap(map & x)
	{
		redBlackTree<Key, T, Compare> temp(rbt.root->mypair.first, rbt.root->mypair.second);

		temp.clear_sent();
		temp = rbt;
		rbt = x.rbt;
		x.rbt = temp;

	}
	/*		Clear		*/
	void clear()
	{
		if (rbt.root)
		{
			rbt.clear(rbt.root);
			rbt.root = NULL;
			rbt.sent_L = NULL;
			rbt.sent_R = NULL;
		}
		else
		{
			rbt.clear_sent();
			rbt.root = NULL;
			rbt.sent_L = NULL;
			rbt.sent_R = NULL;
		}
		rbt.size = 0;
	}

/*==Observers==*/

	/*		Key_comp		*/
	key_compare key_comp() const //code from cplusplus.com
	{
		return _comp;
	}
	/*		Value_comp		*/
	class value_compare : std::binary_function<value_type,value_type,bool> //code from cplusplus.com
	{
		friend class map;
	protected:
		Compare comp;
		value_compare (Compare c) : comp(c) {}  // constructed with map's comparison object
	public:
		typedef bool result_type;
		typedef value_type first_argument_type;
		typedef value_type second_argument_type;
		bool operator() (const value_type& x, const value_type& y) const
		{
			return comp(x.first, y.first);
		}
	};

	value_compare value_comp() const { return (value_compare(Compare())); };


/*==Operations==*/

	/*		Find		*/
	iterator find (const key_type& k)
	{
		if (rbt.root == NULL)
			return end();
		iterator res = *rbt.search(*rbt.root, k);
		return res;
	}
	const_iterator find (const key_type& k) const
	{
		iterator res = *rbt.search(*rbt.root, k);
		return res;
	}
	/*		Count		*/
	size_type count (const key_type& k) const
	{
		if (find(k) == end())
			return 0;
		return 1;
	}
	/*		Lower_bound		*/
	iterator lower_bound(const key_type & k)
	{
		iterator res = begin();
		for (; res != end(); res++)
		{
			if (_comp(res->first, k) == 0)
				return res;
		}
		return end();
	}

	const_iterator lower_bound(const key_type & k) const
	{
		const_iterator res = begin();
		for (; res != end(); res++)
		{
			if (_comp(res->first, k) == 0)
				return res;
		}
		return end();
	}

	/*		Upper_bound		*/
	iterator upper_bound(const key_type & k)
	{
		iterator res = begin();
		for (; res != end(); res++)
		{
			if (_comp(k, res->first) == 1)
				return res;
		}
		return end();
	}

	const_iterator upper_bound(const key_type & k) const
	{
		const_iterator res = begin();
		for (; res != end(); res++)
		{
			if (_comp(k, res->first) == 1)
				return res;
		}
		return end();
	}
	/*		Equal_range		*/
	pair<iterator,iterator>	equal_range (const key_type& k)
	{
		iterator 	res = find(k);
		iterator	res_e;
		if (res == end())
			return pair<iterator, iterator>(upper_bound(k),upper_bound(k));
		res_e = res;
		res_e++;
		return pair<iterator, iterator>(res, res_e);
	}

	pair<const_iterator, const_iterator>	equal_range (const key_type& k) const
	{
		const_iterator 	res = find(k);
		const_iterator	res_e;
		if (res == end())
			return pair<const_iterator, const_iterator>(upper_bound(k),upper_bound(k));
		res_e = res;
		res_e++;
		return pair<const_iterator, const_iterator>(res, res_e);
	}

/*==Allocator==*/

	/*		Get_allocator		*/
	allocator_type get_allocator() const
	{
		return _alloc;
	}


};


/*==Relational operators==*/
template <class Key, class T, class Compare, class Alloc>
	 bool operator==( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs )
	{
		if (lhs.size() != rhs.size())
			return false;
		return ft::equal(lhs.begin(), lhs.end(), rhs.begin());
	}

template <class Key, class T, class Compare, class Alloc>
	 bool operator!=( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs )
	 {
		return !(lhs == rhs);
	 }
	
template <class Key, class T, class Compare, class Alloc>
	 bool operator<( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs )
	 {
		return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	 }

template <class Key, class T, class Compare, class Alloc>
	bool operator>(const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs)
	{
		return rhs < lhs;
	}

template <class Key, class T, class Compare, class Alloc>
	bool operator<=(const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs)
	{
		return !(rhs < lhs);
	}

template <class Key, class T, class Compare, class Alloc>
	bool operator>=(const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs)
	{
		return !(lhs < rhs);
	}

/*==Swap==*/
template <class Key, class T, class Compare, class Alloc>
  void swap (map<Key,T,Compare,Alloc>& x, map<Key,T,Compare,Alloc>& y)
  {
	  x.swap(y);
  }

}
#endif