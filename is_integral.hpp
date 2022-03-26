#ifndef IS_INTEGRAL_HPP
# define IS_INTEGRAL_HPP
# include <uchar.h>
# include <stdint.h>

namespace ft {

template <typename>
struct is_integral_base
{
	const static bool value = false;
};

template <>
struct is_integral_base<bool>
{
	const static bool value = true;
};

template <>
struct is_integral_base<char>
{
	const static bool value = true;
};

template <>
struct is_integral_base<char16_t>
{
	const static bool value = true;
};

template <>
struct is_integral_base<char32_t>
{
	const static bool value = true;
};

template <>
struct is_integral_base<wchar_t>
{
	const static bool value = true;
};

template <>
struct is_integral_base<signed char>
{
	const static bool value = true;
};

template <>
struct is_integral_base<short int>
{
	const static bool value = true;
};

template <>
struct is_integral_base<int>
{
	const static bool value = true;
};

template <>
struct is_integral_base<long int>
{
	const static bool value = true;
};

template <>
struct is_integral_base<long long int>
{
	const static bool value = true;
};

template <>
struct is_integral_base<unsigned char>
{
	const static bool value = true;
};

// template <>
// struct is_integral_base<unsigned short int>
// {
// 	const static bool value = true;
// };

// template <>
// struct is_integral_base<unsigned int>
// {
// 	const static bool value = true;
// };

template <>
struct is_integral_base<unsigned long int>
{
	const static bool value = true;
};

template <>
struct is_integral_base<unsigned long long int>
{
	const static bool value = true;
};

template <class T>
struct is_integral : public is_integral_base<T> 
{
	typedef T type;
};

}

#endif