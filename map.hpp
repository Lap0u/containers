#ifndef MAP_HPP
# define MAP_HPP

# include <memory>
# include <functional>
# include "./headers/RBT.hpp"
# include "./headers/pair.hpp"
# include "./headers/reverse_iterator.hpp"
# include "./headers/iterator_traits.hpp"
# include "./headers/m_iterator.hpp"

namespace ft {

template<class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<pair<const Key,T> > >
class map
{

public:
	void	disp() {rbt.print(rbt.root, 0);}
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
		: rbt(), _alloc(alloc), _comp(comp) {}

	template <class InputIterator> 
	map(InputIterator first, InputIterator last,const key_compare& comp = key_compare(),
    	const allocator_type& alloc = allocator_type()) : _alloc(alloc), _comp(comp)
	{
		this->insert(first, last);
	}

	map	(const map& x) : _alloc(x._alloc), _comp(x._comp)
	{
		this->insert(x.begin(), x.last());
	}

	/*		Destructor		*/
	~map() {}

	/*		Operator=		*/
	map& operator= (const map& other)
	{
		if (this != &other)
		{
			this->clear();
			_alloc = other._alloc;
			_comp = other.comp;
			this->insert(other.begin(), other.last());
		}
	}


/*==Iterators==*/

	/*		Begin		*/
	iterator begin() {return iterator(rbt.first());}
	const_iterator begin() const {return const_iterator(rbt.first());}


	/*		End			*/
	iterator end() {return iterator(rbt.last());}
	const_iterator end() const {return const_iterator(rbt.last());}
	

	/*		Rbegin		*/
	/*		Rend		*/

/*==Capacity==*/

	/*		Empty		*/
	bool empty() const {return !this->rbt._size;}

	/*		Size		*/
	size_type size() const {return !this->rbt._size;}
	/*		Max_size		*/
	size_type max_size() const {return allocator_type().max_size();}/////////////////////////////////voir vraie maxsize


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


		if (find(val.first) == end())
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
			add(first->first, first->second);
			first++;
		}
	}
	/*		Erase		*/
	/*		Swap		*/
	/*		Clear		*/

/*==Observers==*/

	/*		Key_comp		*/
	/*		Value_comp		*/

/*==Operations==*/

	/*		Find		*/
	iterator find (const key_type& k)
	{
		iterator it;

		for (it = begin(); it != end(); it++)
		{
			if (it->first == k)
				return it;
		}
		return end();
	}
	const_iterator find (const key_type& k) const;
	/*		Count		*/
	/*		Lower_bound		*/
	/*		Upper_bound		*/
	/*		Equal_range		*/

/*==Allocator==*/

	/*		Get_allocator		*/


};
}

/*==Relational operators==*/


/*==Swap==*/

#endif