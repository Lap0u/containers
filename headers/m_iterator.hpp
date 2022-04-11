#ifndef M_ITERATOR_HPP
# define M_ITERATOR_HPP

# include "RBT_node.hpp"

namespace ft {

template<typename VT>
class mapIterator
{
private:
	Node<typename VT::first_type, typename VT::second_type>*	_ptr;
public:
	typedef		VT									value_type;
	typedef		std::ptrdiff_t						difference_type;
	typedef		value_type*							pointer;
	typedef		value_type&							reference;
	typedef		std::bidirectional_iterator_tag 	iterator_category;

	mapIterator() : _ptr(NULL){}
	mapIterator(const mapIterator<VT>& other) : _ptr(other._ptr) {}
	mapIterator(Node<typename VT::first_type, typename VT::second_type> & cpy)
	{
		_ptr = &cpy;
	}

	mapIterator & operator=(const mapIterator<VT>& other)
	{
		if (this != &other)
		{
			this->_ptr = other._ptr;
		}
		return *this;
	}

	pointer operator->()
	{
		return _ptr->getPair();
	}
};
}

#endif