#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <sstream>
#include <stack>
#include <queue>

#include "./util/util.h"
#include "./util/buildDataStructure.h"

class Node
{
public:
	Node():key(0), rightThreaded(false), left(NULL), right(NULL), p(NULL)
	{

	}
	int key;
	bool rightThreaded;
	Node* left;
	Node* right;
	Node* p;
};

void convertBinaryTreeToThreadedWihtSingleStack(Node *root)
{
	if(!root)
		return;

	std::stack<Node*> s;
	Node *p = root;
	while(!s.empty() || p)
	{
		if(p)
		{
			s.push(p);
			p = p->left;			
		}
		else
		{
			if(s.empty())
				return;
			p = s.top();
			s.pop();
			if(!p->right)
			{
				if(!s.empty())
				{
					p->right = s.top();
					p->rightThreaded = true;
				}
				p = NULL;
			}
			else
				p = p->right;
		}
	}
}

void convertBinaryTreeToThreaded(Node *root)
{
	if(!root)
		return;
	Node *p = root;
	while(p)
	{
		if(p->left)
		{
			Node *n = p->left;
			while(n->right && n->right != p)
				n = n->right;
			if(!n->right)
			{
				n->right = p;
				n->rightThreaded = true;
				p = p->left;
			}
			else
				p = p->right;
		}
		else
		{
			p = p->right;
		}

	}
}

void inorderWalkThreadedTree(Node *root)
{
	if(!root)
		return;

	Node *p = root;
	bool fromThread = false;
	while(p)
	{
		if(p->left && !fromThread)
		{
			p = p->left;
		}
		else
		{
			std::cout<<p->key<<" ";
			if(p->rightThreaded)
				fromThread = true;
			else
				fromThread = false;
			p = p->right;			
		}
	}
	std::cout<<std::endl;
}

int main()
{
	std::vector<int> input;
    while(!getIntArrayFromConsole(input));
	Node* root = DataStructure::buildBinaryTree<int, Node>(input);
	Node* root2 = DataStructure::buildBinaryTree<int, Node>(input);

	convertBinaryTreeToThreadedWihtSingleStack(root);
	std::cout<<"convert done"<<std::endl;
	inorderWalkThreadedTree(root);

	convertBinaryTreeToThreaded(root2);
	std::cout<<"convert done"<<std::endl;
	inorderWalkThreadedTree(root);
}