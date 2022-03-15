#ifndef FT_VECTOR_HPP
# define FT_VECTOR_HPP

# include <memory>

/*https://en.cppreference.com/w/cpp/container/vector*/

namespace ft {
template <class T, class Allocator = std::allocator<T> >
class vector
{
public:
    void disp() { std::cout <<"Lol" << std::endl;};
/*==Member types==*/

	typedef	T 					value_type;
	typedef	Allocator			allocator_type;
	typedef	std::size_t			size_type;
	typedef	std::ptrdiff_t		difference_type;
	typedef	value_type&			reference;
	typedef	const value_type&	const_reference;
	typedef	typename Allocator::pointer	pointer;
/*==Basics==*/

    /*      Constructor     */
    /*      Destructor      */
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
}; }

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


#endif