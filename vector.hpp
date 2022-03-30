#ifndef FT_VECTOR_HPP
# define FT_VECTOR_HPP

# include <memory>
# include <limits>
# include <exception>
# include <iterator>

# include "v_iterator.hpp"
# include "enable_if.hpp"
# include "is_integral.hpp"
# include "equal.hpp"
# include "lexicographical_compare.hpp"
# include "iterator_traits.hpp"
# include "reverse_iterator.hpp"

# define COUT std::cout <<
# define ENDL << std::endl
# define DEB COUT "yo" ENDL ENDL;

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

	typedef				T 											value_type;
	typedef				Allocator									allocator_type;
	typedef				std::size_t									size_type;
	typedef				std::ptrdiff_t								difference_type;
	typedef				value_type&									reference;
	typedef	const 		value_type&									const_reference;
	typedef	typename 	Allocator::pointer							pointer;
	typedef	typename 	Allocator::const_pointer					const_pointer;

	typedef				ft::myIterator<value_type>					iterator;
	typedef				ft::myIterator<const value_type>			const_iterator;

	typedef             ft::reverse_iterator<iterator>					reverse_iterator;
    typedef				ft::reverse_iterator<const_iterator>			const_reverse_iterator;
	

private:
	allocator_type		_allocator;
	value_type*			_start;
	size_type			_capacity;
	size_type			_filled;

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
		this->_start = this->_allocator.allocate(count);
		for (size_type i = 0; i < count; i++)
			this->_allocator.construct(this->_start + i, value);
		this->_filled = this->_capacity;
	}

	// Constructs the container with the contents of the range [first, last).
	template<class InputIt>
	vector(InputIt first, InputIt last, const Allocator & alloc = Allocator(),
	typename enable_if<!is_integral<InputIt>::value, InputIt>::type* = NULL) : /////voir cond avec iterator_trait
		_allocator(alloc)
	{
		size_t diff = 0;
		InputIt	temp = first;
		while (temp++ != last)
			diff++;
		_capacity = diff;
		_start = _allocator.allocate(_capacity);
		for (size_type i = 0; i < _capacity; i++)
		{	
			*(_start + i) = *first;
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
			if (this->_start != NULL)
            	this->_allocator.deallocate(this->_start, this->_capacity);
            this->_allocator = other._allocator;
            this->_capacity = other._capacity;
            this->_filled = other._filled;
            this->_start = this->_allocator.allocate(this->_capacity);
    		for(size_t i = 0; i < other._filled; i++)
			    this->_allocator.construct(_start + i, other[i]);
        }
		return *this;
    }

    /*      Assign          */
    // Replaces the contents with count copies of value val
    void assign( size_type count, const T& val)
	{
		this->clear();
		this->insert(this->begin(), count, val);
	}

template <class InputIterator>
	void assign (InputIterator first, InputIterator last)
	{
		this->clear();
		this->insert(this->begin(), first, last);
	}
    /*      Allocator       */
	allocator_type get_allocator() const { return this->_allocator;}

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
	iterator begin() {return iterator(this->_start);}
	const_iterator begin() const {return const_iterator(this->_start);}
    /*      End             */
	iterator end() {return iterator(this->_start + this->_filled);}
	const_iterator end() const {return const_iterator(this->_start + this->_filled);}
	/*      RBegin           */
	reverse_iterator rbegin() {return reverse_iterator(this->end());}
	const_reverse_iterator rbegin() const {return const_reverse_iterator(this->end());}
    /*      REnd             */
	reverse_iterator rend() {return reverse_iterator(this->begin());}
	const_reverse_iterator rend() const {return const_reverse_iterator(this->begin());}

/*==_Capacity==*/

    /*      Empty           */
	bool empty () const { return !size();} 
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
			ft::vector<value_type>temp;

			temp._allocator = this->_allocator;
			temp._capacity = n;
			temp._filled = this->_filled;
			temp._start = temp._start = temp._allocator.allocate(temp._capacity);
			for (size_type i = 0; i < this->_filled; i++)
				*(temp._start + i) = *(this->_start + i);
			// this->_allocator.deallocate(_start, _capacity);
			*this = temp;
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
		this->_start = NULL;
	}
	/*		Insert			*/
	iterator insert (iterator position, const value_type& val)
	{

		if (this->_capacity == 0)
		{
			this->_start = this->_allocator.allocate(1);
			this->_allocator.construct(this->_start, val);
			this->_filled = 1;
			this->_capacity = 1;
			return this->begin();
		}
		if (this->_filled == 0)
		{
			this->_allocator.construct(this->_start, val);
			this->_filled++;
			return this->begin();
		}

		if (this->_filled == this->_capacity)//realloc required
		{
			ft::vector<value_type>	temp;
			size_type				i;
			size_type				ret;

			temp._capacity = this->_capacity * 2;
			temp._filled = this->_filled + 1;
			temp._allocator = this->_allocator;
			temp._start = temp._allocator.allocate(temp._capacity);
			for (i = 0; this->begin() + i != position; i++)
				*(temp._start + i) = *(this->_start + i);
			*(temp._start + i) = val;
			ret = i;
			i++;
			while (i < temp._filled)
			{
				*(temp._start + i) = *(this->_start + i - 1);
				i++;	
			}
			*this = temp;
			return this->begin() + ret;
		}
		else
		{
			size_type	offset = position - this->begin();
			size_type	save_off = offset;
			value_type	save;
			value_type	save_next;

			this->_filled++;
			save = *(this->_start + offset);
			*(this->_start + offset) = val;
			offset++;
			while(offset < this->_filled)
			{
				save_next = *(this->_start + offset);
				*(this->_start + offset) = save;
				offset++;
				save = save_next;
			}
			return this->begin() + save_off;
		}
	}

	void insert (iterator position, size_type n, const value_type& val)
	{
		if (this->_filled == 0)
		{
			ft::vector<value_type> temp(n);
			for (size_type i = 0; i < n; i++)
				*(temp._start + i) = val;
			*this = temp;
			return ;
		}
		if (this->_filled + n > this->_capacity)
		{
			ft::vector<value_type>	temp;
			size_type				i;
			size_type				j;

			if (this->_filled * 2 < this->_filled + n)
				temp._capacity = this->_filled + n;
			else
				temp._capacity = this->_capacity * 2;
			
			temp._filled = this->_filled + n;
			temp._allocator = this->_allocator;
			temp._start = temp._allocator.allocate(temp._capacity);
			for (i = 0; this->begin() + i != position; i++)
				*(temp._start + i) = *(this->_start + i);
			for (j = 0; j < n; j++)
				*(temp._start + j + i) = val;
			while (j + i < temp._filled)
			{
				*(temp._start + j + i) = *(this->_start + i);
				i++;
			}
			*this = temp;
		}
		else
		{
			size_type	offset = position - this->begin();
			size_type	last_off = this->end() - position;
			
			this->_filled += n;
			for (size_type i = 0; i < last_off; i++)
			{
				*(this->_start + this->_filled - 1 - i) = *(this->_start + this->_filled - 1 - i - last_off);
			}
			for (size_type j = 0; j < n; j++)
				*(this->_start + j + offset) = val;
		}
	}

template <class InputIterator>
    void insert (iterator position, InputIterator first, InputIterator last,
	typename enable_if<!is_integral<InputIterator>::value, InputIterator>::type* = NULL)
	{
		size_type n = 0;
		InputIterator temp = first;

		while (temp != last)
		{
			n++;
			temp++;
		}
		if (this->_filled == 0)
		{
			ft::vector<value_type> temp(n, 0);
			for (size_type i = 0; i < n; i++)
			{
				*(temp._start + i) = *first;
				first++;
			}
			*this = temp;
			return ;
		}
		if (this->_filled + n > this->_capacity)
		{
			ft::vector<value_type>	temp;
			size_type				i;
			size_type				j;

			if (this->_capacity * 2 < this->_filled + n)
				temp._capacity = this->_filled + n;
			else
				temp._capacity = this->_capacity * 2;
			
			temp._filled = this->_filled + n;
			temp._allocator = this->_allocator;
			temp._start = temp._allocator.allocate(temp._capacity);
			for (i = 0; this->begin() + i != position; i++)
				*(temp._start + i) = *(this->_start + i);
			for ( j = 0; j < n; j++)
				temp._allocator.construct(temp._start + i + j, *first++);
			for (; i + j < temp._filled; i++)
				*(temp._start + i + j) = *(this->_start + i);
			*this = temp;
		}
		else
		{
			size_type	offset = position - this->begin();
			size_type	last_off = this->end() - position;
			
			this->_filled += n;
			for (size_type i = 0; i < last_off; i++)
			{
				this->_allocator.construct((this->_start + this->_filled - 1 - i), *(this->_start + this->_filled - 1 - i - last_off));
			}
			for (size_type j = 0; j < n; j++)
				this->_allocator.construct(this->_start + j + offset, *(first++));
		}
	}

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
			this->_allocator.destroy(this->_start + j);
		}
		for (size_type j = i; beg + j != this->end(); j++)
		{
			*(this->_start + j )= *(this->_start + j + (last - first));
		}
		this->_filled -= last - first;
		return first;
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
				temp._allocator.construct(temp._start + i, *(this->_start + i));
			temp._allocator.construct(temp._start + temp._filled, val);
			temp._filled++;
			// this->_allocator.deallocate(this->_start, this->_capacity);
			*this = temp;
		}
		else if (this->_capacity == 0)
		{
			this->_start = this->_allocator.allocate(1);
			this->_filled = 1;
			this->_capacity = 1;
			this->_allocator.construct(this->_start, val);
		}
		else
		{
			size_type	i;
			for (i = 0; i < this->_filled; i++);
			*(this->_start + i) = val;
			this->_filled++;
		}
	}
	/*		Pop-back		*/
	void	pop_back()
	{
		if (this->_filled == 0)
			return ;
		this->_allocator.destroy(this->_start + this->_filled - 1);
		this->_filled--;
	}
	/*		Resize			*/
	void resize (size_type n, value_type val = value_type())
	{
		if (n < this->_filled)
		{
			for (size_type i = n; i < this->_filled; i++)
				this->_allocator.destroy(this->_start + i);
			this->_filled = n;
		}
		else if (n < this->_capacity)
		{
			while (this->_filled < n)
			{
				*(this->_start + this->_filled) = val;
				this->_filled++;
			}
		}
		else if (this->_filled * 2 >= n)
		{
			ft::vector<value_type> temp;

			temp._allocator = this->_allocator;
			temp._filled = this->_filled;
			temp._capacity = this->_capacity * 2;
			temp._start = temp._allocator.allocate(temp._capacity);
			for (size_type i = 0; i < temp._filled; i++)
				*(temp._start + i) = *(this->_start + i);
			while (temp._filled < n)
			{
				*(temp._start + temp._filled) = val;
				temp._filled++;
			}
			*this = temp;
		}
		else
		{
			ft::vector<value_type> temp;

			temp._allocator = this->_allocator;
			temp._capacity = n;
			temp._filled = n;
			temp._start = temp._allocator.allocate(temp._capacity);
			for (size_type i = 0; i < this->_filled; i++)
				*(temp._start + i) = *(this->_start + i);
			while (this->_filled < n)
			{
				*(temp._start + this->_filled) = val;
				this->_filled++;
			}
			*this = temp;
		}
	}
	/*		Swap			*/
	void swap (vector& x)
	{
		vector<value_type>	temp;
		pointer				point;

		point = x._start;
		temp._capacity = x._capacity;
		temp._filled = x._filled;
		temp._allocator = x._allocator;

		x._start = this->_start;
		x._capacity = this->_capacity;
		x._filled = this->_filled;
		x._allocator = this->_allocator;

		this->_start = point;
		this->_capacity = temp._capacity;
		this->_filled = temp._filled;
		this->_allocator = temp._allocator;

	}

};

/*==Operators overload==*/

	/*		==				*/
template <class T, class Alloc>
	bool operator==(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		if (lhs.size() != rhs.size())
			return false;
		return equal(lhs.begin(), lhs.end(), rhs.begin());
	}

	/*		!=				*/
template <class T, class Alloc>
	bool operator!=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{return !(lhs == rhs);}

	/*		<				*/
template <class T, class Alloc>
	bool operator<(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{return lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());}
	/*		<=				*/
template <class T, class Alloc>
	bool operator>(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{return rhs < lhs;}

	/*		>=				*/
template <class T, class Alloc>
	bool operator<=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{return !(rhs < lhs);}

	/*		>=				*/
template <class T, class Alloc>
	bool operator>=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{return !(lhs < rhs);}


/*==Swap==*/

	/*		Swap			*/


}

#endif