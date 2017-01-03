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
	Node():key(0), left(NULL), right(NULL), p(NULL)
	{

	}
	int key;
	Node* left;
	Node* right;
	Node* p;
};

class BST
{
public:
	BST():root(NULL)
	{

	}

	void insert(Node* n);
	void del(Node* n);
	Node* find(int key);

	Node* getRoot()
	{
		return root;
	}

private:
	Node* root;
};

void BST::insert(Node* n)
{
	if(!n)
		return;

	Node *p = NULL;
	Node *q = root;

	while(q)
	{
		p = q;
		if(q->key > n->key)
			q = q->left;
		else
			q = q->right;
	}

	if(!p)
	{
		root = n;
		return;
	}

	if(p->key > n->key)
		p->left = n;
	else
		p->right = n;
}

void BST::del(Node* n)
{
	if(!n)
		return;

	Node *p = NULL;
	Node *father = NULL;
	Node *q = root;
	while(q)
	{
		if(q->key > n->key)
		{
			father = q;
			q = q->left;
		}
		else if(q->key < n->key)
		{
			father = q;
			q = q->right;
		}
		else
		{
			p = q;
			break;
		}
	}

	if(!p)
		return;

	if(!p->left && !p->right)
	{
		if(father)
		{
			if(father->key > p->key)
				father->left = NULL;
			else 
				father->right = NULL;
		}

		if(p->key == root->key)
			root = NULL;
		delete p;
	}

	if(!p->left && p->right)
	{
		if(father)
		{
			if(father->key > p->key)
				father->left = p->right;
			else
				father->right = p->right;
		}

		if(p->key == root->key)
			root = p->right;
		delete p;
	}

	if(!p->right && p->left)
	{
		if(father)
		{
			if(father->key > p->key)
				father->left = p->left;
			else
				father->right = p->left;
		}

		if(p->key == root->key)
			root = p->right;
		delete p;
	}


	if(p->left && p->right)
	{
		if(!(p->right->left))
		{
			if(father)
			{
				if(father->key > p->key)
					father->left = p->right;
				else
					father->right = p->right;
			}

			p->right->left = p->left;

			if(p->key == root->key)
				root = p->right;
			delete p;
			return;
		}

		Node *minimum = NULL;
		Node *minimumFather = NULL;

		minimumFather = p->right;
		minimum = p->right->left;
		while(minimum->left)
		{
			minimumFather = minimum;
			minimum = minimum->left;
		}

		if(minimum->right)
		{
			minimumFather->left = minimum->right;
		}
		else
			minimumFather->left = NULL;

		if(father)
		{
			if(father->key > p->key)
				father->left = minimum;
			else
				father->left = minimum;
		}


		minimum->left = p->left;
		minimum->right = p->right;

		if(p->key == root->key)
				root = minimum;
		delete p;
		return;
	}
}

Node* BST::find(int key)
{
	Node *result = NULL;
	Node *p = root;
	while(p)
	{
		if(p->key > key)
			p = p->left;
		else if(p->key < key)
			p = p->right;
		else
		{
			result = p;
			break;
		}
	}

	return result;
}


int main()
{
	std::vector<int> input;
    while(!getIntArrayFromConsole(input));
    Node* root = DataStructure::buildBinarySearchTree<int, Node>(input);

    BST bst;
    bst.insert(root);
    DataStructure::printTreeLayers<Node>(bst.getRoot());

    Node *n = new Node;
    n->key = 11;

    bst.insert(n);
    DataStructure::printTreeLayers<Node>(bst.getRoot());

    //test case
    // 		4
    //	 2		6
    // 1   3  5   11
    n = NULL;
    n = bst.find(4);
    bst.del(n);
    DataStructure::printTreeLayers<Node>(bst.getRoot());

}