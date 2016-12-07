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

class LinkNode
{
public:
	LinkNode():key(0), next(NULL)
	{

	}
	int key;
	LinkNode *next;
};

std::queue<LinkNode*>* createdLinkedLists(Node *root)
{
	if(!root)
		return NULL;

	std::queue<Node*> p;

	std::queue<LinkNode*>* lists = new std::queue<LinkNode*>();

	p.push(root);

	while(!p.empty())
	{
		LinkNode* head = NULL, *tail =NULL;
		LinkNode* linkTmp = NULL;
		std::queue<Node*> q;
		while(!p.empty())
		{
			Node* tmp = p.front();
			if(tmp->left)
				q.push(tmp->left);
			if(tmp->right)
				q.push(tmp->right);
			p.pop();
			linkTmp = new LinkNode();
			linkTmp->next = NULL;
			linkTmp->key = tmp->key;
			if(tail)
			{
				tail->next = linkTmp;
				tail = linkTmp;
			}
			if(!head)
			{
				head = linkTmp;
				tail = linkTmp;
			}
			linkTmp = NULL;
		}
		lists->push(head);
		p.swap(q);
	}

	return lists;
}

int main()
{
	std::vector<int> input;
    while(!getIntArrayFromConsole(input));
	Node* root = DataStructure::buildBinaryTree<int, Node>(input);

	std::queue<LinkNode*>* list = createdLinkedLists(root);
	while(!list->empty())
	{
		LinkNode* root = list->front();
		list->pop();
		while(root)
		{
			std::cout<<root->key<<" ";
			root = root->next;
		}
		std::cout<<std::endl;
	}
}