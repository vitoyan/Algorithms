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
	Node():key(0), left(NULL), right(NULL), p(NULL)
	{

	}
	int key;
	Node* left;
	Node* right;
	Node* p;
};

int getHeight(Node *root)
{
	if(!root)
		return 0;

	int height = 0;
	std::queue<Node*> p;
	p.push(root);

	while(!p.empty())
	{
		std::queue<Node*> q;
		while(!p.empty())
		{
			Node *tmp = p.front();
			p.pop();
			if(tmp->left)
				q.push(tmp->left);
			if(tmp->right)
				q.push(tmp->right);
		}
		p.swap(q);
		height++;
	}

	return height;

}

int main()
{
	std::vector<int> input;
    while(!getIntArrayFromConsole(input));
	Node* root = DataStructure::buildBinaryTree<int, Node>(input);

	std::cout<<getHeight(root)<<std::endl;

}