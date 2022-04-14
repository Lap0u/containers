#define RESET   "\033[0m"
#define BLACK   "\033[1m\033[30m"		/* Bold Black	*/
#define RED     "\033[1m\033[31m"		/* Bold Red		*/
#define CYAN    "\033[1m\033[36m" 		/* Bold Cyan	*/

#ifndef RBT_HPP
# define RBT_HPP

# define CIN >> std::cin
# define COUT std::cout <<
# define ENDL << std::endl
# define NL COUT std::endl;
# define RESET   "\033[0m"
# define BLACK   "\033[1m\033[30m"		/* Bold Black	*/
# define RED     "\033[1m\033[31m"		/* Bold Red		*/
# define CYAN    "\033[1m\033[36m" 		/* Bold Cyan	*/

# include "RBT_node.hpp"

namespace ft{

template<typename K, typename V, class Compare = std::less<K>, class Alloc = std::allocator<Node<const K, V> > >
struct redBlackTree
{
	typedef	Alloc	allocator_type;
	typedef	Compare	key_compare;

	Node<const K, V>*			root;
	Node<const K, V>*			sent_L;
	Node<const K, V>*			sent_R;

	std::size_t					size;
	allocator_type			_allocator;
	key_compare				_comp;

	redBlackTree(K key, V val, const key_compare& compare = key_compare(), const allocator_type & alloc = allocator_type())
	 : root(NULL), size(0), _allocator(alloc) , _comp(compare)
	{
		sent_L = _allocator.allocate(1);
		_allocator.construct(sent_L, Node<const K,V>(key, val));
		sent_R = _allocator.allocate(1);
		_allocator.construct(sent_R, Node<const K,V>(key, val));
	}

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
		Node<const K, V>* newNode = _allocator.allocate(1);
		_allocator.construct(newNode, Node<const K,V>(x,y));
		if (this->root == NULL)
		{
			this->root = newNode;
			newNode->black = 1;
			this->root->childL = sent_L;
			this->root->childR = sent_R;
			size++;
			return ;
		}
		add(*this->root, *newNode);
		size++;
		
	}

	void clear(Node<const K, V> *toDel)
	{
		if (sent_L)
		{
			_allocator.destroy(sent_L);
			_allocator.deallocate(sent_L, sizeof(Node<const K, V>));
		}
		if (sent_R)
		{
			_allocator.destroy(sent_R);
			_allocator.deallocate(sent_R, sizeof(Node<const K, V>));
		}
		if (toDel->childL && toDel->childL != sent_L)
			clear(toDel->childL);
		if (toDel->childR && toDel->childR != sent_R)
			clear(toDel->childR);
		_allocator.destroy(toDel);
		_allocator.deallocate(toDel, sizeof(Node<const K, V>));
	}

	Node<const K, V>* search(Node<const K, V> & parent, K key)
	{
		if(parent.childR && _comp(parent.mypair.first, key))
			return search(*parent.childR, key);
		
		if(parent.childL && _comp(key, parent.mypair.first))
			return search(*parent.childL, key);
		if (_comp(parent.mypair.first, key) == 0 && _comp(key, parent.mypair.first) == 0)
			return &parent;
		return NULL;
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
			if (current == sent_L || current == sent_R)
				COUT CYAN;
			COUT current->mypair.first << " : " << current->mypair.second ENDL;
			COUT RESET;
			print(current->childL, space);
		}
	}
private:

	void	add(Node<const K, V> & parent, Node<const K, V> & newNode)
	{
		// if (&parent == sent_L)
		// {
		// 	parent.childL = &newNode;
		// 	newNode.parent = parent.parent;
		// 	newNode.leftChild = 1;
		// 	newNode.childL = sent_L;
		// 	return ;
		// }
		// if (&parent == sent_R)
		// {
		// 	parent.childR = &newNode;
		// 	newNode.parent = parent.parent;
		// 	newNode.leftChild = 0;
		// 	newNode.childR = sent_R;
		// 	return ;
		// }
		if (_comp(newNode.mypair.first, parent.mypair.first))
		{
			if (parent.childL == NULL)
			{
				parent.childL = &newNode;
				newNode.parent = &parent;
				newNode.leftChild = 1;
			}
			else if (parent.childL == sent_L)
			{
				parent.childL = &newNode;
				newNode.parent = &parent;
				newNode.leftChild = 1;
				newNode.childL = sent_L;
			}
			else
				add(*parent.childL, newNode);
			return ;
		}
		else if (_comp(parent.mypair.first, newNode.mypair.first))
		{
			if (parent.childR == NULL)
			{
				parent.childR = &newNode;
				newNode.parent = &parent;
				newNode.leftChild = 0;
			}
			else if (parent.childR == sent_R)
			{
				parent.childR = &newNode;
				newNode.parent = &parent;
				newNode.leftChild = 0;
				newNode.childR = sent_R;
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