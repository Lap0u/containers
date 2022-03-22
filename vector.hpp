#ifndef FT_VECTOR_HPP
# define FT_VECTOR_HPP

# include <memory>
# include <limits>
# include <exception>
# include <iterator>

# include "v_iterator.hpp"
# define COUT std::cout <<
# define ENDL << std::endl

/*https://en.cppreference.com/w/cpp/container/vector*/

/*https://www.cplusplus.com/reference/vector/vector/?kw=vector*/

/*https://www.lirmm.fr/~ducour/Doc-objets/ISO+IEC+14882-1998.pdf*/


namespace ft {

template <class T, class Allocator = std::allocator<T> >
class vector
{
public:
    void disp() { std::cout <<"Lol" << std::endl;};
/*==Member types==*/

	typedef				T 												value_type;
	typedef				Allocator										allocator_type;
	typedef				std::size_t										size_type;
	typedef				std::ptrdiff_t									difference_type;
	typedef				value_type&										reference;
	typedef	const 		value_type&										const_reference;
	typedef	typename 	Allocator::pointer								pointer;
	typedef	typename 	Allocator::const_pointer						const_pointer;

	typedef				ft::myIterator<value_type>						iterator;
	typedef				ft::myIterator<const value_type>				const_iterator;

	typedef             std::reverse_iterator<iterator>					reverse_iterator;
    typedef				std::reverse_iterator<const_iterator>			const_reverse_iterator;
	

private:
	allocator_type		_allocator;
	value_type*			_start;
	size_t				_capacity;
	size_t				_filled;

public:
/*==Basics==*/

    /*      Constructor     */

	// Default constructor. Constructs an empty container with 
	// a default-constructed allocator.
	vector() :
		_allocator(std::allocator<value_type>()),
		_start(NULL),
		_capacity(0),
		_filled(0)
	{}

	// Constructs an empty container with the given allocator alloc.
	explicit vector(const Allocator& alloc) : 
		_allocator(alloc),
		_start(NULL),
		_capacity(0),
		_filled(0)
	{}

	// Constructs the container with count copies of elements with value value.
	explicit vector(size_type count, const T& value = T(),
		const Allocator& alloc = Allocator()) : _allocator(alloc), _capacity(count)
	{
		_start = _allocator.allocate(count);
		for (size_type i = 0; i < count; i++)
			_start[i] = value;
		_filled = _capacity;
	}

	// Constructs the container with the contents of the range [first, last).
	template<class InputIt>
	vector(InputIt first, InputIt last, const Allocator & alloc = Allocator()) :
		_allocator(alloc)
	{
		_capacity = last - first;
		_start = _allocator.allocate(_capacity);
		for (size_type i = 0; i < _capacity; i++)
		{	
			_start[i] = *first;
			first++;
		}
		_filled = _capacity;
	}

	// Copy constructor. Constructs the container with the copy of the contents of other.
	vector(const vector & other) : _allocator(other._allocator), _capacity(other._capacity), _filled(other._filled)
	{
		this->_start = _allocator.allocate(_capacity);
		for(size_t i = 0; i < _filled; i++)
			this->_start[i] = other._start[i];
	}
    /*      Destructor      */
	// Destructs the vector. The destructors of the elements 
	// are called and the used storage is deallocated. 
	virtual ~vector() { _allocator.deallocate(_start, _capacity);}
    
    /*      Operator=       */
    // Copy assignment operator. Replaces the contents with a copy of the contents of other.
    vector& operator=( const vector& other )
    {
        if (this != &other)
        {
            this->_allocator.deallocate(_start, _capacity);
            this->_allocator = other._allocator;
            this->_capacity = other._capacity;
            this->_filled = other._filled;
            this->_start = this->_allocator.allocate(this->_capacity);
    		for(size_t i = 0; i < _filled; i++)
			    this->_start[i] = other._start[i];
        }
		return *this;
    }

    /*      Assign          */
    // Replaces the contents with count copies of value value
    // void assign( size_type count, const T& value )
    /*      Allocator       */

/*==Element access==*/

    /*      At              */
	reference at(size_type pos)
	{
		if (pos >= _filled)
			throw(std::out_of_range("Pos out of bonds"));
		return *(_start + pos);
	}

	const_reference at(size_type pos) const
	{
		if (pos >= _filled)
			throw(std::out_of_range("Pos out of bonds"));
		return *(_start + pos);
	}	

    /*      Operator[]      */
    reference operator[](size_type pos) { return *(_start + pos);}
    const_reference operator[](size_type pos) const { return *(_start + pos);}
	
	/*      Front           */
	reference front() { return *this->begin();}
	const_reference front() const { return *this->begin();}
    
	/*      Back            */
   	reference back() { return *(this->end() - 1);}
	const_reference back() const { return *(this->end() - 1);}
	/*      Data            */
	T*	data() { return this->_start;}
	const T* data() const { return this->_start;}

/*==Iterators==*/
    
    /*      Begin           */
	iterator begin() {return _start;}
	const_iterator begin() const {return _start;}
    /*      End             */
	iterator end() {return _start + _filled;}
	const_iterator end() const {return _start + _filled;}	
    /*      Rbegin          */
    /*      Rend            */

/*==_Capacity==*/

    /*      Empty           */
	bool empty () const { return !capacity();} 
    /*      Size            */
	size_type size() const { return _filled;}
    /*      Max_size        */
	size_type max_size() const { return allocator_type().max_size();}
    /*      Reserve         */
	void reserve(size_type n)
	{
		if (n > max_size())
			throw std::length_error("Not enough space to allocate memory");
		if (n > this->capacity())
		{
			this->_allocator.deallocate(_start, _capacity);
			_start = this->_allocator.allocate(n);
			this->_capacity = n;

		}
	}
    /*      _Capacity        */
	size_type capacity() const { return _capacity;}

/*==Modifiers==*/

	/*		Clear			*/
	void	clear()
	{
		size_t	save = this->_filled;
		while (this->_filled != 0)
		{
			this->_allocator.destroy(this->_start + this->_filled - 1);
			this->_filled--;
		}
		this->_allocator.deallocate(this->_start, save);
	}
	/*		Insert			*/

	/*		Erase			*/
	iterator erase(iterator pos)
	{
		size_type	i;
		iterator	beg;

		beg = this->begin();

		for (i = 0; beg + i != pos; i++);
		this->_allocator.destroy(this->_start + i);
		this->_filled--;
		for (size_type j = i; j != this->_filled; j++)
		{
			*(this->_start + j) = *(this->_start + (j + 1));
		}
		// this->_allocator.deallocate(this->_start + this->_filled - 1, 1);
		return pos;
	}

	iterator erase(iterator first, iterator last)
	{
		size_type	i;
		iterator	beg;

		beg = this->begin();
		if (last == first)
			return first;

		for (i = 0; beg + i != first; i++);
		for (size_type j = i; beg + j != last; j++)
		{
			this->_allocator.destroy(beg + j);
		}
		for (size_type j = i; j != this->end(); j++)
		{
			this->_start + j = this->_start + j + (last - first);
		}
		this->_filled -= last - first;
		this->_start += last - first;
		return last;
	}
	/*		Push_back		*/
	void push_back (const value_type& val)
	{
		ft::vector<value_type> temp;
		if (this->_filled == this->_capacity && this->_capacity != 0)
		{
			temp._allocator = this->_allocator;
			temp._filled = this->_filled;
			temp._capacity = this->_capacity * 2;
			temp._start = temp._allocator.allocate(temp._capacity);
			for (size_type i = 0; i < temp._filled; i++)
				*(temp._start + i) = *(this->_start + i);
			*(temp._start + temp._filled) = val;
			temp._filled++;
			// this->_allocator.deallocate(this->_start, this->_capacity);
			*this = temp;
		}
		else if (this->_capacity == 0)
		{
			this->_start = this->_allocator.allocate(1);
			this->_filled = 1;
			this->_capacity = 1;
			*(this->_start) = val;
		}
		else
		{
			size_type	i;
			for (i = 0; i < this->_filled; i++);
			*(this->_start + i) = val;
		}
	}
	/*		Pop-back		*/
	void	pop_back()
	{
		size_type	i;

		if (this->_filled == 0)
			return ;
		for (i = 0; i != this->_filled;i++);
		this->_allocator.destroy(this->_start + i);
		this->_filled--;
	}
	/*		Resize			*/
	
	/*		Swap			*/

};

/*==Operators overload==*/

	/*		==				*/
	/*		Const==			*/
	/*		!=				*/
	/*		<				*/
	/*		<=				*/
	/*		>=				*/
	/*		>=				*/


/*==Swap==*/

	/*		Swap			*/


}

#endif