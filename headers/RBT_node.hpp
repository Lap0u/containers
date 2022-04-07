#ifndef RBT_NODE_HPP
# define RBT_NODE_HPP

template<typename K, typename V>
struct Node
{
	Node*	parent;
	Node*	childR;
	Node*	childL;
	bool	color;
	bool	leftChild;
	K		key;
	V		value;
	
	Node(K key, V value) : 
	parent(NULL), childR(NULL), childL(NULL), color (0), leftChild(0), key(key), value(value) {}
};

#endif