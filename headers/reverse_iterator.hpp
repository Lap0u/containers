#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

# include "iterator_traits.hpp"

namespace ft {

template <class Iterator> 
	class reverse_iterator
{
public:
	typedef	Iterator												iterator_type;
	typedef typename iterator_traits<Iterator>::value_type			value_type;
	typedef	typename iterator_traits<Iterator>::pointer				pointer;
	typedef	typename iterator_traits<Iterator>::reference			reference;
	typedef typename iterator_traits<Iterator>::difference_type		difference_type;
	typedef	typename iterator_traits<Iterator>::iterator_category	iterator_category;

	reverse_iterator() : _base(NULL){};

	explicit reverse_iterator (iterator_type it) : _base(it){};

template <class Iter>
	reverse_iterator (const reverse_iterator<Iter>& rev_it) : _base(rev_it.base()){};

	iterator_type base() const { return this->_base;}
	
	reference operator*() const { return *(this->_base - 1);}

	reverse_iterator operator+ (difference_type n) const { return reverse_iterator(this->_base - n);}

	friend		reverse_iterator operator+(difference_type index, reverse_iterator rhs) { return reverse_iterator(rhs._base - index);}

	reverse_iterator& operator++() {--this->_base; return *this;}

	reverse_iterator operator++(int) {reverse_iterator temp = *this; ++(*this); return temp;}

	reverse_iterator& operator+= (difference_type n) {this->_base -= n; return *this;}

	reverse_iterator operator- (difference_type n) const { return reverse_iterator(this->_base + n);}

	reverse_iterator& operator--() {++this->_base; return *this;}

	reverse_iterator operator--(int) {reverse_iterator temp = *this; --(*this); return temp;}

	reverse_iterator& operator-= (difference_type n) {this->_base += n; return *this;}

	pointer operator->() const { return &(this->operator*());}

	reference operator[] (difference_type n) const { return *(this->_base - n - 1);}

	// operator reverse_iterator <Iterator<const value_type> >() { return reverse_iterator <Iterator <const value_type> > (this->_base);}

private: 
	Iterator _base;
};

template <class Iterator>
	bool operator==(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) { return lhs.base() == rhs.base();}

template <class It1, class It2>
	bool operator==(const reverse_iterator<It1>& lhs, const reverse_iterator<It2>& rhs) { return lhs.base() == rhs.base();}

template <class Iterator>
	bool operator!=(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) { return lhs.base() != rhs.base();}

template <class It1, class It2>
	bool operator!=(const reverse_iterator<It1>& lhs, const reverse_iterator<It2>& rhs) { return lhs.base() != rhs.base();}

template <class Iterator>
	bool operator<(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) { return lhs.base() > rhs.base();}

template <class It1, class It2>
	bool operator<(const reverse_iterator<It1>& lhs, const reverse_iterator<It2>& rhs) { return lhs.base() > rhs.base();}

template <class Iterator>
	bool operator>(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) { return lhs.base() < rhs.base();}

template <class It1, class It2>
	bool operator>(const reverse_iterator<It1>& lhs, const reverse_iterator<It2>& rhs) { return lhs.base() < rhs.base();}

template <class Iterator>
	bool operator<= (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) { return lhs.base() >= rhs.base();}

template <class It1, class It2>
	bool operator<= (const reverse_iterator<It1>& lhs, const reverse_iterator<It2>& rhs) { return lhs.base() >= rhs.base();}

template <class Iterator>
	bool operator>= (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) { return lhs.base() <= rhs.base();}

template <class It1, class It2>
	bool operator>= (const reverse_iterator<It1>& lhs, const reverse_iterator<It2>& rhs) { return lhs.base() <= rhs.base();}

template <class Iterator>
	typename reverse_iterator<Iterator>::difference_type operator- (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
	{
		return rhs.base() - lhs.base();
	}

template <class It1, class It2>
	typename reverse_iterator<It1>::difference_type operator- (const reverse_iterator<It1>& lhs, const reverse_iterator<It2>& rhs)
	{
		return rhs.base() - lhs.base();
	}

}

#endif