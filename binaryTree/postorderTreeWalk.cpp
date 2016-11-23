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


void postorderTreeWalkRecursively(Node* root)
{
	if(!root)
		return;
	postorderTreeWalkRecursively(root->left);
	postorderTreeWalkRecursively(root->right);
	std::cout<<root->key<<" ";
}

void postorderTreeWalkSingleStack1(Node* root)
{
	if(!root)
		return;
	std::stack<Node*> s;
	s.push(root);
	Node* pre = NULL;
	while(!s.empty())
	{
		Node* n = s.top();
		if(!pre || pre->left == n || pre->right == n)
		{
			if(n->left)
				s.push(n->left);
			else if(n->right)
				s.push(n->right);
			else
			{
				std::cout<<n->key<<" ";
				s.pop();
			}
		}
		else if(n->left == pre)
		{
			if(n->right)
				s.push(n->right);
			else
			{
				std::cout<<n->key<<" ";
				s.pop();
			}
		}
		else if(n->right == pre)
		{
			std::cout<<n->key<<" ";
			s.pop();
		}
		pre = n;
	}
}

void postorderTreeWalkSingleStack2(Node* root)
{
	if(!root)
		return;
	std::stack<Node*> s;
	Node* lastVisted = NULL;
	Node* p = root;
	while(!s.empty() || p)
	{
		if(p)
		{
			s.push(p);
			p = p->left;
		}
		else
		{
			p = s.top();
			if(!p->right || p->right == lastVisted)
			{
				std::cout<<p->key<<" ";
				lastVisted = p;
				p = NULL;
				s.pop();
			}
			else
			{
				p = p->right;
			}

		}
	}

}

void postorderTreeWalkTwoStacks(Node* root)
{
	if(!root)
		return;
	std::stack<Node*> s;
	std::stack<Node*> output;
	s.push(root);
	while(!s.empty())
	{
		Node* n = s.top();
		s.pop();
		output.push(n);
		if(n->left)
			s.push(n->left);
		if(n->right)
			s.push(n->right);
	}

	while(!output.empty())
	{
		Node* n = output.top();
		output.pop();
		std::cout<<n->key<<" ";
	}
}

void reverse(Node* from, Node* to)
{
	if(from == to)
		return;

	Node *p = from, *q = from->right;
	while(p != to)
	{
		Node* temp = q->right;
		q->right = p;
		p = q;
		q = temp;
	}

}

void reversePrint(Node* from, Node* to)
{
	if(!from || !to)
		return;
	reverse(from, to);
	Node* n = to;
	while(true)
	{
		std::cout<<n->key<<" ";
		if(n == from)
			break;
		n = n->right;
	}
	reverse(to, from);

}
void postorderTreeWalkMorris(Node* root)
{
	if(!root)
		return;

	Node* dummy = new Node();
	dummy->left = root;
	Node* pre = NULL;
	while(dummy)
	{
		if(!dummy->left)
		{
			dummy = dummy->right;
		}
		else
		{
			pre = dummy->left;
			while(pre->right && pre->right != dummy)
				pre = pre->right;
			if(pre->right != dummy)
			{
				pre->right = dummy;
				dummy = dummy->left;
			}
			else
			{
				reversePrint(dummy->left, pre);
				dummy = dummy->right;
				pre->right = NULL;
			}
		}
	}


}

int main()
{
	std::vector<int> input;
    while(!getIntArrayFromConsole(input));
	Node* root = DataStructure::buildBinaryTreeLowestHigh<int, Node>(input, 0, input.size() - 1);
	
	postorderTreeWalkRecursively(root);
	std::cout<<std::endl;

	postorderTreeWalkSingleStack1(root);
	std::cout<<std::endl;


	postorderTreeWalkSingleStack2(root);
	std::cout<<std::endl;

	postorderTreeWalkMorris(root);
	std::cout<<std::endl;	
}