#ifndef I_ITERATOR_HPP
# define I_ITERATOR_HPP

# include "vector.hpp"
# include "iterator_traits.hpp"

namespace ft {
class iterator_traits;

template<typename T>
class myIterator : public iterator_traits
{
public:

	typedef T									value_type;
	typedef	value_type*							pointer;
	typedef	value_type&							reference;
	typedef std::ptrdiff_t						difference_type;
	typedef	std::random_access_iterator_tag 	iterator_category;

    myIterator() :	_m_ptr(NULL){}   
    myIterator(pointer ptr) :	_m_ptr(ptr){}
	virtual ~myIterator() {}
	myIterator (myIterator<value_type> const & src): _m_ptr(src._m_ptr) {}
	myIterator & operator=(myIterator<value_type> const & rhs)
	{
		this->_m_ptr = rhs._m_ptr;
		return *this;
	}

	myIterator & operator+=(difference_type index)
	{
		_m_ptr += index;
		return *this;
	}
	
	myIterator & operator-=(difference_type index)
	{
		_m_ptr -= index;
		return *this;
	}

	difference_type	operator-(myIterator rhs) const
	{
		return (this->_m_ptr - rhs._m_ptr);
	}

	myIterator	operator+(difference_type index) const
	{
		return myIterator(this->_m_ptr + index);
	}

	friend		myIterator	operator+(difference_type index, myIterator rhs)
	{
		return myIterator(rhs._m_ptr + index);
	}

	myIterator	operator-(difference_type index) const
	{
		return myIterator(this->_m_ptr - index);
	}

	bool operator==(const myIterator<value_type> & rhs)
	{
		return this->_m_ptr == rhs._m_ptr;
	}

	bool operator==(const myIterator<const value_type> & rhs) const 
	{
		return this->_m_ptr == rhs._m_ptr;
	}

	bool operator!=(const myIterator<value_type> & rhs) 
	{
		return this->_m_ptr != rhs._m_ptr;
	}

	bool operator!=(const myIterator<const value_type> & rhs) const 
	{
		return this->_m_ptr != rhs._m_ptr;
	}

	bool operator<(const myIterator<value_type> & rhs)
	{
		return this->_m_ptr < rhs._m_ptr;
	}

	bool operator<(const myIterator<const value_type> & rhs) const
	{
		return this->_m_ptr < rhs._m_ptr;
	}

	bool operator<=(const myIterator<value_type> & rhs) 
	{
		return this->_m_ptr <= rhs._m_ptr;
	}

	bool operator<=(const myIterator<const value_type> & rhs) const
	{
		return this->_m_ptr <= rhs._m_ptr;
	}

	bool operator>(const myIterator<value_type> & rhs) 
	{
		return this->_m_ptr > rhs._m_ptr;
	}

	bool operator>(const myIterator<const value_type> & rhs) const
	{
		return this->_m_ptr > rhs._m_ptr;
	}

	bool operator>=(const myIterator<value_type> & rhs) 
	{
		return this->_m_ptr >= rhs._m_ptr;
	}	

	bool operator>=(const myIterator<const value_type> & rhs) const
	{
		return this->_m_ptr >= rhs._m_ptr;
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
		return *_m_ptr;
	}
	
	operator myIterator <const value_type>() { return myIterator <const value_type> (_m_ptr);}

// private:
    pointer	_m_ptr;
};

/*****************************Reverse Iterator*****************************/

template<typename T>
class myRevIterator
{
public:

	typedef T									value_type;
	typedef	value_type*							pointer;
	typedef	value_type&							reference;
	typedef std::ptrdiff_t						difference_type;
	typedef	std::random_access_iterator_tag 	iterator_category;

    myRevIterator() :	_m_ptr(NULL){}   
    myRevIterator(pointer ptr) :	_m_ptr(ptr){}
	virtual ~myRevIterator() {}
	myRevIterator (myRevIterator<value_type> const & src): _m_ptr(src._m_ptr) {}
	myRevIterator & operator=(myRevIterator<value_type> const & rhs)
	{
		this->_m_ptr = rhs._m_ptr;
		return *this;
	}

	myRevIterator & operator+=(difference_type index)
	{
		_m_ptr += index;
		return *this;
	}
	
	myRevIterator & operator-=(difference_type index)
	{
		_m_ptr -= index;
		return *this;
	}
	
	difference_type	operator+(myRevIterator rhs) const
	{
		return (rhs._m_ptr + this->_m_ptr);
	}

	difference_type	operator-(myRevIterator rhs) const
	{
		return (this->_m_ptr - rhs._m_ptr);
	}

	myRevIterator	operator+(difference_type index) const
	{
		return myRevIterator(this->_m_ptr + index);
	}

	myRevIterator	operator-(difference_type index) const
	{
		return myRevIterator(this->_m_ptr - index);
	}

	bool operator==(myRevIterator<value_type> rhs) const 
	{
		return this->_m_ptr == rhs._m_ptr;
	}

	bool operator!=(myRevIterator<value_type> rhs) const 
	{
		return this->_m_ptr != rhs._m_ptr;
	}	

	bool operator<(myRevIterator<value_type> rhs) const
	{
		return this->_m_ptr < rhs._m_ptr;
	}

	bool operator<=(myRevIterator<value_type> rhs) const
	{
		return this->_m_ptr <= rhs._m_ptr;
	}

	bool operator>(myRevIterator<value_type> rhs) const
	{
		return this->_m_ptr > rhs._m_ptr;
	}

	bool operator>=(myRevIterator<value_type> rhs) const
	{
		return this->_m_ptr >= rhs._m_ptr;
	}	

	myRevIterator& operator++()
	{
		_m_ptr++;
		return *this;
	}

	myRevIterator operator++(int)
	{
		myRevIterator it  = *this;
		++(*this);
		return it;
	}
	
	myRevIterator& operator--()
	{
		_m_ptr--;
		return *this;
	}

	myRevIterator operator--(int)
	{
		myRevIterator it  = *this;
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

	operator myRevIterator <const value_type>() { return myRevIterator <const value_type> (_m_ptr);}

// private:
    pointer	_m_ptr;
};

}
#endif