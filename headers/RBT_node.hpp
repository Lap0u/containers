#ifndef RBT_NODE_HPP
# define RBT_NODE_HPP

# include <iostream>

namespace ft{
template<typename K, typename V>
struct Node
{
	typedef	K		key_type;
	typedef	V		mapped_type;
	
	Node*	parent;
	Node*	childR;
	Node*	childL;
	bool	black;
	bool	leftChild;
	K		key;
	V		value;

	Node(K key, V value) : 
	parent(NULL), childR(NULL), childL(NULL), black (0), leftChild(0), key(key), value(value) {}

	void	switchColor()
	{
		if (black == true)
			black = false;
		else
			black = true;
	}
	void	switchChild()
	{
		if (leftChild == true)
			leftChild = false;
		else
			leftChild = true;
	}
};
}

#endif