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

void inorderTreeWalkRecursively(Node* root)
{
	if(!root)
		return;
	inorderTreeWalkRecursively(root->left);
	std::cout<<root->key<<" ";
	inorderTreeWalkRecursively(root->right);
}

void inorderTreeWalk(Node* root)
{
	if(!root)
		return;
	Node* n = root;

	std::stack<Node*> s;
	while(!s.empty() || n)
	{
		if(n)
		{
			s.push(n);
			n = n->left;
		}
		else
		{
			if(s.empty())
				return;
			n = s.top();
			s.pop();
			std::cout<<n->key<<" ";
			n = n->right;			
		}
	}
}

int main()
{
	std::vector<int> input;
    while(!getIntArrayFromConsole(input));
	Node* root = DataStructure::buildBinaryTreeLowestHigh<int, Node>(input, 0, input.size() - 1);
	
	inorderTreeWalkRecursively(root);
	std::cout<<std::endl;

	inorderTreeWalk(root);
	std::cout<<std::endl;	
}