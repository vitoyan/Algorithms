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

Node* reverseLink(Node *head)
{
	if(!head || !(head->next))
		return head;

	Node* pre = head;
	Node* node = head->next;
	head->next = NULL;

	while(node)
	{
		Node* next = node->next;
		node->next = pre;
		pre = node;
		node = next;
	}

	head = pre;
	return head;
}


int main()
{
    std::vector<int> input;
    while(!getIntArrayFromConsole(input));
    
    Node* head = DataStructure::buildLink<int, Node>(input);
    Node* node = reverseLink(head);
    
    while(node)
    {
    	std::cout<<node->data<<" ";
    	node = node->next;
    }
    std::cout<<std::endl;
}