#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <iterator>
#include <sstream>

#include "./util/util.h"
#include "./util/buildDataStructure.h"

class Node
{
public:
	int data;
	Node* next;
};

void removeNode(Node *node)
{
	if(!node)
		return;

	Node *next = node->next;
	node->data = next->data;
	node->next = next->next;
	delete next;
}

int main()
{
    std::vector<int> input;
    while(!getIntArrayFromConsole(input));
    
    Node* head = DataStructure::buildLink<int, Node>(input);
    removeNode(head->next);
    
    while(head)
    {
    	std::cout<<head->data<<" ";
    	head = head->next;
    }
    std::cout<<std::endl;
}