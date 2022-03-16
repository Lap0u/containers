#ifndef FT_VECTOR_HPP
# define FT_VECTOR_HPP

# include <memory>
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
	/*iterators!!*/
	typedef				ft::myIterator<T>								iterator;
	typedef				ft::myIterator<const T>							const_iterator;

	typedef             std::reverse_iterator<iterator>					reverse_iterator;
    typedef				std::reverse_iterator<const_iterator>			const_reverse_iterator;
	/*!!!!!!!!!!!*/

private:
	allocator_type	_allocator;
	value_type*				_start;
	size_t			_size;
	size_t			_filled;

public:
/*==Basics==*/

    /*      Constructor     */

	// Default constructor. Constructs an empty container with 
	// a default-constructed allocator.
	vector() {};

	// Constructs an empty container with the given allocator alloc.
	explicit vector(const Allocator& alloc) : 
		_allocator(alloc),
		_start(NULL),
		_size(0),
		_filled(0)
	{}

	// Constructs the container with count copies of elements with value value.
	explicit vector(size_type count, const T& value = T(),
		const Allocator& alloc = Allocator()) : _allocator(alloc), _size(count)
	{
		_start = _allocator.allocate(count);
		for (size_type i = 0; i < count; i++)
			_start[i] = value;
		_filled = _size;
	}

	// Constructs the container with the contents of the range [first, last).
	template<class InputIt>
	vector(InputIt first, InputIt last, const Allocator & alloc = Allocator()) :
		_allocator(alloc)
	{
		_size = last - first;
		_start = _allocator.allocate(_size);
		for (size_type i = 0; i < _size; i++)
		{	
			_start[i] = first;
			first++;
		}
		_filled = _size;
	}

	// Copy constructor. Constructs the container with the copy of the contents of other.
	vector(const vector & other) : _allocator(other._allocator), _size(other._size), _filled(other._filled)
	{
		this->_start = _allocator.allocate(_size);
		for(size_t i = 0; i < _filled; i++)
			this->_start[i] = other._start[i];
	}
    /*      Destructor      */
	// Destructs the vector. The destructors of the elements 
	// are called and the used storage is deallocated. 
	virtual ~vector() { _allocator.deallocate(_start, _size);}
    
    /*      Operator=       */
    // Copy assignment operator. Replaces the contents with a copy of the contents of other.
    vector& operator=( const vector& other )
    {
        if (this != &other)
        {
            this->_allocator.deallocate(_start, _size);
            this->_allocator = other._allocator;
            this->_size = other._size;
            this->_filled = other._filled;
            this->_start = this->_allocator.allocate(this->_size);
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
    /*      Operator[]      */
    /*      Front           */
    /*      Back            */
    /*      Data            */

/*==Iterators==*/
    
    /*      Begin           */
    /*      End             */
    /*      Rbegin          */
    /*      Rend            */

/*==Capacity==*/

    /*      Empty           */
    /*      Size            */
    /*      Max_size        */
    /*      Reserve         */
    /*      Capacity        */

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