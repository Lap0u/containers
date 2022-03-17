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
	/*		Insert			*/
	/*		Erase			*/
	/*		Push_back		*/
	/*		Pop-back		*/
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