#ifndef RBT_HPP
# define RBT_HPP

# include "RBT_node.hpp"

namespace ft{

template<typename K, typename V>
struct redBlackTree
{
	Node<K, V>*			root;
	std::size_t			size;
};
}
#endif