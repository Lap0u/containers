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
	allocator_type				_allocator;
	key_compare					_comp;

	redBlackTree(K key, V val, const key_compare& compare = key_compare(), const allocator_type & alloc = allocator_type())
	 : root(NULL), size(0), _allocator(alloc) , _comp(compare)
	{
		sent_L = _allocator.allocate(1);
		_allocator.construct(sent_L, Node<const K,V>(key, val));
		sent_L->leftChild = 1;
		sent_R = _allocator.allocate(1);
		_allocator.construct(sent_R, Node<const K,V>(key, val));
		sent_R->leftChild = 0;

	}

	Node<const K, V> & first() const
	{
		if (sent_L == NULL)
			return *sent_L;
		return *sent_L->parent;

	}

	void	hideSent()
	{
		sent_L->parent->childL = NULL;
		sent_R->parent->childR = NULL;
	}

	void	revealSent()
	{
		Node<const K, V>* temp = root;
		while(temp->childL)
			temp = temp->childL;
		temp->childL = sent_L;
		temp = root;
		while(temp->childR)
			temp = temp->childR;
		temp->childR = sent_R;
	}

	Node<const K, V> & last() const 
	{
		return *sent_R;
	}

	void	erase(Node<const K, V>* toDel)
	{
		hideSent();
		if (toDel == root && size == 1)
		{
			_allocator.destroy(toDel);
			_allocator.deallocate(toDel, sizeof(toDel));
			root = NULL;
			return ;
		}
		if (toDel->childL == NULL && toDel->childR == NULL)
		{
			if (toDel->leftChild == 1)
				toDel->parent->childL = NULL;
			else
				toDel->parent->childR = NULL;
			_allocator.destroy(toDel);
			_allocator.deallocate(toDel, sizeof(toDel));
			revealSent();

			return ;
		}
	}

	void	add(K x, V y)
	{
		Node<const K, V>* newNode = _allocator.allocate(1);
		_allocator.construct(newNode, Node<const K,V>(x,y));
		if (this->root == NULL)
		{
			if (sent_L == NULL)
			{
				sent_L = _allocator.allocate(1);
				_allocator.construct(sent_L, Node<const K,V>(x, y));
				sent_L->leftChild = 1;
			}
			if (sent_R == NULL)
			{
				sent_R = _allocator.allocate(1);
				_allocator.construct(sent_R, Node<const K,V>(x, y));
				sent_R->leftChild = 0;	
			}
			this->root = newNode;
			newNode->black = 1;
			this->root->childL = sent_L;
			sent_L->parent = newNode;
			this->root->childR = sent_R;
			sent_R->parent = newNode;
			size++;
			return ;
		}
		add(*this->root, *newNode);
		size++;
	}

	void	clear_sent()
	{
		_allocator.destroy(sent_L);
		_allocator.deallocate(sent_L, sizeof(Node<const K, V>));
		_allocator.destroy(sent_R);
		_allocator.deallocate(sent_R, sizeof(Node<const K, V>));
	}

	void clear(Node<const K, V> *toDel)
	{
		if (toDel->childL)
			clear(toDel->childL);
		if (toDel->childR)
			clear(toDel->childR);
		_allocator.destroy(toDel);
		_allocator.deallocate(toDel, sizeof(Node<const K, V>));
	}
	
	Node<const K, V>* search(Node<const K, V> & parent, K key) const
	{
		if(parent.childR && _comp(parent.mypair.first, key))
			return search(*parent.childR, key);
		
		if(parent.childL && _comp(key, parent.mypair.first))
			return search(*parent.childL, key);
		if (_comp(parent.mypair.first, key) == 0 && _comp(key, parent.mypair.first) == 0)
			return &parent;
		return sent_R;
	}

	void print(Node<const K, V> *current, int space)
	{
		if (space == 0)
		{
			COUT sent_L->leftChild << "  Sent_L parent is " << sent_L->parent->mypair.first << " and " << sent_L->parent->mypair.second ENDL;
			COUT sent_R->leftChild << "  Sent_R parent is " << sent_R->parent->mypair.first << " and " << sent_R->parent->mypair.second ENDL;
		}
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
			COUT current->mypair.first << " : " << current->mypair.second;
			if (current->leftChild == 1)
				COUT "  L" ENDL;
			else
				COUT "  R" ENDL;
			COUT RESET;
			print(current->childL, space);
		}
	}
private:

	void	add(Node<const K, V> & parent, Node<const K, V> & newNode)
	{
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
				sent_L->parent = &newNode;
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
				sent_R->parent = &newNode;
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