#ifndef FT_VECTOR_HPP
# define FT_VECTOR_HPP

# include <memory>

namespace ft {
template <class T, class Allocator = std::allocator<T> >
class vector
{
public:
    void disp() { std::cout <<"Lol" << std::endl;};
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
}; }

#endif