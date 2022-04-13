#ifndef M_ITERATOR_HPP
# define M_ITERATOR_HPP

# include "RBT_node.hpp"

namespace ft {

template<typename VT>
class mapIterator
{
private:
	Node<typename VT::first_type, typename VT::second_type>*	_ptr;

	int		isLast() const
	{
		mapIterator<VT> temp = *this;

		while (temp._ptr->parent)
		{
			if (temp._ptr->leftChild == 1)
				return (0);
			temp._ptr = temp._ptr->parent;
		}
		return (1);
	}

	int		isFirst() const
	{
		mapIterator<VT> temp = *this;

		while (temp._ptr->parent)
		{
			if (temp._ptr->leftChild == 0)
				return (0);
			temp._ptr = temp._ptr->parent;
		}
		return (1);
	}

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
	// virtual ~mapIterator();
	pointer operator->()
	{
		return _ptr->getPair();
	}
	bool operator==(const mapIterator<VT> & rhs)
	{
		if (_ptr == rhs._ptr)
			return true;
		return false;
	}
	bool operator!=(const mapIterator<VT> & rhs)
	{
		return !(*this == rhs);
	}

	mapIterator & operator++()
	{
		if (_ptr->childR || isLast() == 1)
		{
			_ptr = _ptr->childR;
			return *this;
		}
		while (_ptr->parent->leftChild == 0)
			_ptr = _ptr->parent;
		_ptr = _ptr->parent;
		return *this;
		
	}

	mapIterator operator++(int)
	{
		mapIterator<VT>it = *this;
		++(*this);
		return it;
	}

	mapIterator & operator--()
	{
		if (_ptr->childL || isFirst() == 1)
		{
			_ptr = _ptr->childL;
			return *this;
		}
		while (_ptr->parent->leftChild == 1)
			_ptr = _ptr->parent;
		_ptr = _ptr->parent;
		return *this;
	}

	mapIterator operator--(int)
	{
		mapIterator<VT>it = *this;
		--(*this);
		return it;
	}
};
}

#endif