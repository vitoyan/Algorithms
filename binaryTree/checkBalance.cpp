#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <sstream>
#include <stack>
#include <set>
#include <limits>
#include <algorithm>

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

int getHeight(Node* root)
{
	if(!root)
		return -1;
	if(!root->left && !root->right)
		return 1;

	int leftHeight = 0;
	int rightHeight = 0;

	if(root->left)
	{
		leftHeight = getHeight(root->left) + 1;
		if(leftHeight == 0)
			return -1;
	}

	if(root->right)
	{
		rightHeight = getHeight(root->right) + 1;
		if(rightHeight == 0)
			return -1;
	}

	int diff = leftHeight - rightHeight;
	if(diff == 0 || diff == 1 || diff == -1)
		return leftHeight > rightHeight ? leftHeight : rightHeight;
	else
		return -1;
}

bool isBalance(Node* root)
{
	if(!root)
		return false;
	if(getHeight(root) < 0)
	{
		return false;
	}
	else
		return true;
}

int main()
{
	std::vector<int> input;
    while(!getIntArrayFromConsole(input));
    Node* root = DataStructure::buildBinaryTree<int, Node>(input);	 

    if(isBalance(root))
    	std::cout<<"the tree is balance"<<std::endl;
    else
    	std::cout<<"the tree is not balance"<<std::endl;   
}