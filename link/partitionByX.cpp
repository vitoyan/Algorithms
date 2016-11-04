#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <sstream>

#include "./util/util.h"
#include "./util/buildDataStructure.h"

class Node
{
public:
	int data;
	Node *next;
};

Node* partitionByX(Node *head, int x)
{
	if(!head || !(head->next))
		return head;

	Node *tail = head;
	while(tail->next)
	{
		tail = tail->next;
	}

	Node *pre = NULL;
	Node *node = head;
	Node *newHead = head;
	Node *newTail = tail;
	while(node != tail)
	{
		Node* next = node->next;
		if(node->data >= x)
		{
			if(pre)
			{
				pre->next = node->next;
			}
			if(node == newHead)
				newHead = newHead->next;
			newTail->next = node;
			newTail = newTail->next;
			newTail->next = NULL;	
		}
		else
		{
			pre = node;
		}
		node = next;
	}

	return newHead;
}

int main()
{
    std::vector<int> input;
    while(!getIntArrayFromConsole(input));
    
    Node* head = DataStructure::buildLink<int, Node>(input);
    Node* node = partitionByX(head, head->data);
    
    while(node)
    {
    	std::cout<<node->data<<" ";
    	node = node->next;
    }
    std::cout<<std::endl;
}