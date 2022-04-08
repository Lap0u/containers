#ifndef M_ITERATOR_HPP
# define M_ITERATOR_HPP

# include "RBT_node.hpp"

namespace ft {

template<typename VT>
class mapIterator
{
public:
	typedef		VT									value_type;
	typedef		std::ptrdiff_t						difference_type;
	typedef		value_type*							pointer;
	typedef		value_type&							reference;
	typedef		std::bidirectional_iterator_tag 	iterator_category;
private:
	Node<typename VT::first_type, typename VT::second_type>*	_ptr;
};
}

#endif