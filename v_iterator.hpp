#ifndef I_ITERATOR_HPP
# define I_ITERATOR_HPP

#include "ft_vector.hpp"
// # include <vector>

namespace ft {

template<typename T>
class myIterator
{
public:

	typedef T			value_type;
	typedef	T*			pointer;
	typedef	T&			reference;
	typedef std::ptrdiff_t	difference_type;
	typedef	std::random_access_iterator_tag iterator_category;


    myIterator():                    v(nullptr), i(0) {}   
    myIterator(T* v, int i): v(v),       i(i) {}
    // Default Copy/Move Are Fine.
    // Default Destructor fine.

    reference       operator*()             {return (*v)[i];}
    reference 		operator*()       const {return (*v)[i];}
    pointer         operator->()            {return &((*v)[i]);}
    pointer			operator->()      const {return &((*v)[i]);}
    reference       operator[](int m)       {return (*v)[i + m];}
    reference		operator[](int m) const {return (*v)[i + m];}
    

    myIterator& operator++()       {++i;return *this;}
    myIterator& operator--()       {--i;return *this;}
    myIterator  operator++(int)    {myIterator r(*this);++i;return r;}
    myIterator  operator--(int)    {myIterator r(*this);--i;return r;}

    myIterator& operator+=(int n)  {i += n;return *this;}
    myIterator& operator-=(int n)  {i -= n;return *this;}

    myIterator operator+(int n)   const {myIterator r(*this);return r += n;}
    myIterator operator-(int n)   const {myIterator r(*this);return r -= n;}

    difference_type operator-(myIterator const& r) const {return i - r.i;}

    // Note: comparing iterator from different containers
    //       is undefined behavior so we don't need to check
    //       if they are the same container.
    bool operator<(myIterator const& r)  const {return i <  r.i;}
    bool operator<=(myIterator const& r) const {return i <= r.i;}
    bool operator>(myIterator const& r)  const {return i >  r.i;}
    bool operator>=(myIterator const& r) const {return i >= r.i;}
    bool operator!=(const myIterator &r) const {return i != r.i;}
    bool operator==(const myIterator &r) const {return i == r.i;}

private:
    T* v;
    int        i;
};
}
#endif