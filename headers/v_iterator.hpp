#ifndef I_ITERATOR_HPP
# define I_ITERATOR_HPP

namespace ft {

template<class Iterator>
class iterator_traits;

template<typename T>
class myIterator
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
	pointer base () const {return this->_m_ptr;}
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

private:
    pointer	_m_ptr;
};

template<typename T>
	bool operator==(const myIterator<T> & lhs, const myIterator<T> & rhs)
	{
		return lhs.base() == rhs.base();
	}

template<typename L, typename R>
	bool operator==(const myIterator<L> & lhs, const myIterator<R> & rhs)
	{
		return lhs.base() == rhs.base();
	}
template<typename T>
	bool operator!=(const myIterator<T> & lhs, const myIterator<T> & rhs)
	{
		return lhs.base() != rhs.base();
	}

template<typename L, typename R>
	bool operator!=(const myIterator<L> & lhs, const myIterator<R> & rhs)
	{
		return lhs.base() != rhs.base();
	}

template<typename T>
	bool operator<(const myIterator<T> & lhs, const myIterator<T> & rhs)
	{
		return lhs.base() < rhs.base();
	}

template<typename L, typename R>
	bool operator<(const myIterator<L> & lhs, const myIterator<R> & rhs)
	{
		return lhs.base() < rhs.base();
	}
template<typename T>
	bool operator>(const myIterator<T> & lhs, const myIterator<T> & rhs)
	{
		return lhs.base() > rhs.base();
	}

template<typename L, typename R>
	bool operator>(const myIterator<L> & lhs, const myIterator<R> & rhs)
	{
		return lhs.base() > rhs.base();
	}
template<typename T>
	bool operator<=(const myIterator<T> & lhs, const myIterator<T> & rhs)
	{
		return lhs.base() <= rhs.base();
	}

template<typename L, typename R>
	bool operator<=(const myIterator<L> & lhs, const myIterator<R> & rhs)
	{
		return lhs.base() <= rhs.base();
	}
template<typename T>
	bool operator>=(const myIterator<T> & lhs, const myIterator<T> & rhs)
	{
		return lhs.base() >= rhs.base();
	}

template<typename L, typename R>
	bool operator>=(const myIterator<L> & lhs, const myIterator<R> & rhs)
	{
		return lhs.base() >= rhs.base();
	}

template<typename L, typename R>
	typename myIterator<L>::difference_type	operator-(const myIterator<L> & lhs, const myIterator<R> & rhs) 
	{
		return (lhs.base() - rhs.base());
	}
}
#endif