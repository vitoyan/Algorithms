 #include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <sstream>
#include <stack>

#include "./util/util.h"
#include "./util/buildDataStructure.h"


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

void preorderTreeWalkRecursively(Node* root)
{
	if(!root)
		return;
	std::cout<<root->key<<" ";
	preorderTreeWalkRecursively(root->left);
	preorderTreeWalkRecursively(root->right);
}

void preorderTreeWalk(Node* root)
{
	if(!root)
		return;
	Node* n = root;
	std::stack<Node*> s;
	s.push(n);
	while(!s.empty())
	{
		n = s.top();
		s.pop();
		std::cout<<n->key<<" ";		
		if(n->right)
			s.push(n->right);
		if(n->left)
			s.push(n->left);
	}
}

void preorderTreeWalkMorris(Node* root)
{
	if(!root)
		return;
	Node* n = root;
	while(n)
	{
		if(!(n->left))
		{
			std::cout<<n->key<<" ";
			n = n->right;
		}
		else
		{
			Node* pre = n->left;
			while(pre->right && pre->right != n)
				pre = pre->right;
			if(pre->right != n)
			{
				pre->right = n;
				std::cout<<n->key<<" ";
				n = n->left;
			}
			else
			{
				pre->right = NULL;
				n = n->right;
			}
		}
	}

}


int main()
{
	std::vector<int> input;
    while(!getIntArrayFromConsole(input));
	Node* root = DataStructure::buildBinaryTreeLowestHigh<int, Node>(input, 0, input.size() - 1);
	
	preorderTreeWalkRecursively(root);
	std::cout<<std::endl;

	preorderTreeWalk(root);
	std::cout<<std::endl;

	preorderTreeWalkMorris(root);
	std::cout<<std::endl;	
}