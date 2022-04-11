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
	redBlackTree<Key, T> 	rbt;
	allocator_type			_alloc;
	key_compare				_comp;


public:

/*==Basics==*/

	/*		Constructor		*/
	explicit map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
		: rbt(NULL), _alloc(alloc), _comp(comp) {}

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
	/*		Operator=		*/

/*==Iterators==*/

	/*		Begin		*/
	/*		End			*/
	/*		Rbegin		*/
	/*		Rend		*/

/*==Capacity==*/

	/*		Empty		*/
	/*		Size		*/
	/*		Max_size		*/

/*==Element acces==*/

	/*		Operator[]		*/

/*==Modifiers==*/

	/*		Insert		*/
	/*		Erase		*/
	/*		Swap		*/
	/*		Clear		*/

/*==Observers==*/

	/*		Key_comp		*/
	/*		Value_comp		*/

/*==Operations==*/

	/*		Find		*/
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