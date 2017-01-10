#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <sstream>
#include <stack>
#include <queue>

#include "./util/util.h"
#include "./util/buildDataStructure.h"
#include "./util/printDataStructure.h"

class Node
{
public:
	Node():key(0), height(1), color(""), left(NULL), right(NULL), p(NULL)
	{

	}
	int key;
	int height;
	std::string color;
	Node* left;
	Node* right;
	Node* p;
};

class AVL
{
public:
	AVL()
	{
		root = NULL;
	}
	Node* getRoot();
	Node* leftRotate(Node *n);
	Node* rightRotate(Node *n);
	Node* find(int key);
	void transplant(Node *m, Node *n);
	Node* insertRecurisvely(Node *m, Node *n);
	Node* deleteRecurisvely(Node *m, Node *n);
	void insert(Node *n);
	void doBalance();
	int getBalance(Node *n)
	{
		int nLeftHeight = n->left ? n->left->height : 0;
		int nRightHeight = n->right ? n->right->height : 0;
		return nLeftHeight - nRightHeight;
	}
private:
	Node *root;
};

Node* AVL::getRoot()
{
	return root;
}

Node* AVL::find(int key)
{
	if(!root)
		return NULL;
	Node *n = root;
	Node *result = NULL;
	while(n)
	{
		if(n->key > key)
			n = n->left;
		else if(n->key < key)
			n = n->right;
		else
		{
			result = n;
			break;
		}
	}
	return result;
}

void AVL::transplant(Node *m, Node *n)
{
	if(!m)
		return;
	if(!m->p)
		root = n;
	else if(m == m->p->left)
		m->p->left = n;
	else
		m->p->right = n;

	if(n)
		n->p = m->p;
}

Node* AVL::leftRotate(Node *n)
{
	if(!n || !n->right)
		return NULL;

	Node *m = n->right;

	n->right = m->left;
	if(n->right)
		n->right->p = n;
	m->left = n;

	if(!n->p)
		root = m;
	else if(n == n->p->left)
		n->p->left = m;
	else 
		n->p->right = m;

	m->p = n->p;
	n->p = m;

	int nLeftHeight = n->left ? n->left->height : 0;
	int nRightHeight = n->right ? n->right->height : 0;

	n->height = nLeftHeight > nRightHeight ? nLeftHeight + 1 : nRightHeight + 1;

	int mLeftHeight = m->left ? m->left->height : 0;
	int mRightHeight = m->right ? m->right->height : 0;

	m->height = mLeftHeight > mRightHeight ? mLeftHeight + 1 : mRightHeight + 1;

	return m;
}


Node* AVL::rightRotate(Node *n)
{
	if(!n || !n->left)
		return NULL;

	Node* m = n->left;

	n->left = m->right;
	if(n->left)
		n->left->p = n;
	m->right = n;

	if(!n->p)
		root = m;
	else if(n == n->p->left)
		n->p->left = m;
	else
		n->p->right = m;

	m->p = n->p;
	n->p = m;

	int nLeftHeight = n->left ? n->left->height : 0;
	int nRightHeight = n->right ? n->right->height : 0;

	n->height = nLeftHeight > nRightHeight ? nLeftHeight + 1 : nRightHeight + 1;

	int mLeftHeight = m->left ? m->left->height : 0;
	int mRightHeight = m->right ? m->right->height : 0;

	m->height = mLeftHeight > mRightHeight ? mLeftHeight + 1 : mRightHeight + 1;
	return m;
}

//recursively 
Node* AVL::insertRecurisvely(Node *m, Node *n)
{
	if(!n)
		return NULL;

	if(!root)
	{
		root = n;
		return n;
	}

	if(!m)
	{
		return n;
	}	

	if(m->key > n->key)
	{
		m->left =  insertRecurisvely(m->left, n);
		m->left->p = m;
	}
	else
	{
		m->right = insertRecurisvely(m->right, n);
		m->right->p = m;
	}

	int leftHeight = m->left ? m->left->height : 0;
	int rightHeight = m->right ? m->right->height : 0;

	m->height = leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;

	int balance = leftHeight - rightHeight;

	//right left
	if(balance <= -2 && n->key < m->right->key)
	{
		rightRotate(m->right);
		return leftRotate(m);
	}
	//right right 
	else if(balance <= -2)
	{
		return leftRotate(m);
	}
	//left left
	else if(balance >= 2 && n->key < m->right->key)
	{
		return rightRotate(m);
	}
	//left right
	else if(balance >= 2)
	{
		leftRotate(m->left);
		return rightRotate(m);
	}

	return m;
}

//NonRecursive
void AVL::insert(Node *n)
{
	if(!n)
		return;
	if(!root)
	{
		root = n;
		return;
	}

	//pretend we don't have parent pointer in Node
	std::stack<Node*> s;
	Node *parent = NULL;
	Node *tmp = root;
	while(tmp)
	{
		parent = tmp;
		s.push(parent);
		if(tmp->key > n->key)
			tmp = tmp->left;
		else
			tmp = tmp->right;
	}

	if(parent->key > n->key)
	{
		parent->left = n;
		parent->left->p = parent;
	}
	else
	{
		parent->right = n;
		parent->right->p = parent;
	}

	while(!s.empty())
	{
		parent = s.top();
		s.pop();
		int leftHeight = parent->left ? parent->left->height : 0;
		int rightHeight = parent->right ? parent->right->height : 0;

		parent->height = leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;

		int balance = leftHeight - rightHeight;

		//right left
		if(balance <= -2 && n->key < parent->right->key)
		{
			rightRotate(parent->right);
			leftRotate(parent);
		}
		//right right 
		else if(balance <= -2)
		{
			leftRotate(parent);
		}
		//left left
		else if(balance >= 2 && n->key < parent->right->key)
		{
			rightRotate(parent);
		}
		//left right
		else if(balance >= 2)
		{
			leftRotate(parent->left);
			rightRotate(parent);
		}
	}
}

Node* AVL::deleteRecurisvely(Node *m, Node *n)
{
	if(!root || !m || !n)
		return NULL;

	if(n->key > m->key)
	{
		m->right = deleteRecurisvely(m->right, n);
		if(m->right)
			m->right->p = m;
	}
	else if(n->key < m->key)
	{
		m->left = deleteRecurisvely(m->left, n);
		if(m->left)
			m->left->p = m;
	}
	else
	{
		if(!m->right && !m->left)
		{
			if(root == n)
				root = NULL;
			delete n;			
			m = n = NULL;			
		}
		else if(!m->right)
		{
			m = m->left;
			m->p = n->p;
			if(root == n)
				root = m;
			delete n;
			n = NULL;
		}
		else if(!m->left)
		{
			m = m->right;
			m->p = n->p;
			if(root == n)
				root = m;
			delete n;
			n = NULL;
		}
		else
		{
			//find the predecessor
			Node *pre = NULL;
			Node *tmp = m->left;
			while(tmp)
			{
				pre = tmp;
				tmp = tmp->right;
			}
			
			m->key = pre->key;
			m->left = deleteRecurisvely(m->left, pre);			
		}
	}

	if(!m)
		return NULL;


	int leftHeight = m->left ? m->left->height : 0;
	int rightHeight = m->right ? m->right->height : 0;

	m->height = leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;

	int balance = leftHeight - rightHeight;

	//right left
	if(balance <= -2 && getBalance(m->right) > 0)
	{
		rightRotate(m->right);
		return leftRotate(m);
	}
	//right right 
	else if(balance <= -2)
	{
		return leftRotate(m);
	}
	//left left
	else if(balance >= 2 && getBalance(m->left) <= 0)
	{
		return rightRotate(m);
	}
	//left right
	else if(balance >= 2)
	{
		leftRotate(m->left);
		return rightRotate(m);
	}

	return m;
}

int main()
{
	std::vector<int> input;
    while(!getIntArrayFromConsole(input));  
   	
   	AVL avl, avl2;

   	for(auto i : input)
   	{
   		Node* n = new Node();
   		n->key = i;
   		avl.insertRecurisvely(avl.getRoot(), n);
   	}

    DataStructure::printAVLTreeLayers<Node>(avl.getRoot());

    for(auto i : input)
   	{
   		Node* n = new Node();
   		n->key = i;
   		avl2.insert(n);
   	}

    DataStructure::printAVLTreeLayers<Node>(avl2.getRoot());

    int nu;
    while(true)
    {
    	std::cout<<"pls input number : ";
    	std::cin>>nu;
    	avl.deleteRecurisvely(avl.getRoot(), avl.find(nu));
    	DataStructure::printAVLTreeLayers<Node>(avl.getRoot());
    }
    
}

