#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP
# include "iterator_traits.hpp"

namespace ft {

template <class Iterator> 
	class reverse_iterator
{
	typedef	Iterator												iterator_type;
	typedef typename iterator_traits<Iterator>::value_type			value_type;
	typedef	typename iterator_traits<Iterator>::pointer				pointer;
	typedef	typename iterator_traits<Iterator>::reference			reference;
	typedef typename iterator_traits<Iterator>::difference_type		difference_type;
	typedef	typename iterator_traits<Iterator>::iterator_category	iterator_category;

};

}

#endif