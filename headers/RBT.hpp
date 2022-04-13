#define RESET   "\033[0m"
#define BLACK   "\033[1m\033[30m"		/* Bold Black	*/
#define RED     "\033[1m\033[31m"		/* Bold Red		*/
#define CYAN    "\033[1m\033[36m" 		/* Bold Cyan	*/

#ifndef RBT_HPP
# define RBT_HPP

# include "RBT_node.hpp"

namespace ft{

template<typename K, typename V>
struct redBlackTree
{
	Node<const K, V>*			root;
	std::size_t					size;


	redBlackTree() : root(NULL), size(0) {}

	Node<const K, V> & first()
	{
		Node<const K, V>* temp = root;
		if (root == NULL)
			return *temp;
		while (temp->childL != NULL)
			temp = temp->childL;
		return *temp;
	}

	Node<const K, V> & last()
	{
		Node<const K, V>* temp = root;
		if (root == NULL)
			return *temp;
		while (temp != NULL)
			temp = temp->childR;
		return *temp;
	}

	void	add(K x, V y)
	{
		Node<const K, V>* newNode = new Node<const K, V> (x, y);//utiliser allocator
		if (this->root == NULL)
		{
			this->root = newNode;
			newNode->black = 1;
			size++;
			return ;
		}
		add(*this->root, *newNode);
		size++;
		
	}

	void print(Node<const K, V> *current, int space)
	{
		if ( current != NULL ){
			space += 10;
			print(current->childR, space);
			std::cout << std::endl;
			for ( int _ = 0 ; _ < space ; _++ ){ std::cout << " "; }
			if (current->black == 1)
				COUT BLACK;
			else
				COUT RED;
			COUT current->key << " : " << current->value ENDL;
			COUT RESET;
			print(current->childL, space);
		}
	}
private:

	void	add(Node<const K, V> & parent, Node<const K, V> & newNode)
	{

		if (newNode.key < parent.key)//utiliser comp
		{
			if (parent.childL == NULL)
			{
				parent.childL = &newNode;
				newNode.parent = &parent;
				newNode.leftChild = 1;
			}
			else
				add(*parent.childL, newNode);
			return ;
		}
		else if (newNode.key > parent.key)//utliser comp
		{
			if (parent.childR == NULL)
			{
				parent.childR = &newNode;
				newNode.parent = &parent;
				newNode.leftChild = 0;
			}
			else
				add(*parent.childR, newNode);
			return ;
		}
		COUT CYAN << "Node is equal " << RESET ENDL;
	}
};
}
#endif