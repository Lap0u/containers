#ifndef I_ITERATOR_HPP
# define I_ITERATOR_HPP

#include "ft_vector.hpp"
// # include <vector>

namespace ft {

template<typename T>
class myIterator
{
public:

	typedef typename T::value_type			value_type;
	typedef	value_type*			pointer;
	typedef	value_type&			reference;
	typedef std::ptrdiff_t	difference_type;
	typedef	std::random_access_iterator_tag iterator_category;

    myIterator() :	_m_ptr(NULL){}   
    myIterator(pointer ptr) :	_m_ptr(ptr){}   
	virtual ~myIterator() {}
	myIterator (reference src): _m_ptr(src->_m_ptr) {}
	myIterator operator=(reference rhs)
	{
		this->_m_ptr = rhs._m_ptr;
		return *this;
	}

	difference_type operator-(pointer rhs)
	{
		return (rhs - *this);
	}
	pointer operator+=(int index)
	{
		*this += index;
		return *this;
	}
	
	pointer operator-=(int index)
	{
		*this -= index;
		return *this;
	}
	
	pointer	operator+(int index) const 
	{
		return (_m_ptr + index);
	}

	pointer operator-(int index) const
	{
		return (_m_ptr - index);
	}

	bool operator==(pointer rhs) const 
	{
		return *this = *rhs;
	}

	bool operator!=(pointer rhs) const 
	{
		return *this != *rhs;
	}	

	bool operator<(pointer rhs) const
	{
		return *this < rhs;
	}

	bool operator<=(pointer rhs) const
	{
		return *this <= rhs;
	}

	bool operator>(pointer rhs) const
	{
		return *this > rhs;
	}

	bool operator>=(pointer rhs) const
	{
		return *this >= rhs;
	}

	myIterator& operator++()
	{
		_m_ptr++;
		return *this;
	}

	myIterator operator++(int)
	{
		myIterator it  = *this;
		++(*this);
		return it;
	}
	
	myIterator& operator--()
	{
		_m_ptr--;
		return *this;
	}

	myIterator operator--(int)
	{
		myIterator it  = *this;
		--(*this);
		return it;
	}

	reference operator[](int index)
	{
		return *(_m_ptr + index);
	}

	pointer operator->()
	{
		return _m_ptr;
	}

	reference operator*()
	{
		return * _m_ptr;
	}
private:
    pointer	_m_ptr;
};
}
#endif