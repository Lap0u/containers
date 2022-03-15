#ifndef FT_VECTOR_HPP
# define FT_VECTOR_HPP

# include <memory>

# define COUT std::cout <<
# define ENDL << std::endl

/*https://en.cppreference.com/w/cpp/container/vector*/

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


	/*!!!!!!!!!!!*/
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
	}

	// Constructs the container with the contents of the range [first, last).
	template<class InputIt>
	vector(InputIt first, InputIt last, const Allocator & alloc = Allocator()) :
		_allocator(alloc)
	{
		_size = last - first;
		_start = _allocator.allocate(_size);
		for (size_type i = 0; i < _size; i++)
		{	_start[i] = first;
			first++;
		}
	}

	// Copy constructor. Constructs the container with the copy of the contents of other.
	vector(const vector & other)
	{
		(void)other;
	}
    /*      Destructor      */
	// Destructs the vector. The destructors of the elements 
	// are called and the used storage is deallocated. 
	~vector() { _allocator.deallocate(_start, _size);}
    /*      Operator=       */
    /*      Assign          */
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

private:
	allocator_type	_allocator;
	value_type*		_start;
	size_t			_size;
	size_t			_filled;
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