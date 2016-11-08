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

Node* findLoopStart(Node *head)
{
	if(!head || !head->next)
		return NULL;

	Node *p = head;
	Node *q = head;

	while(p && q && q->next)
	{
		p = p->next;
		q = q->next->next;
		if(p == q)
		{
			std::cout<<p->data<<" "<<q->data<<std::endl;
			break;
		}
	}

	p = head;

	while(p && q && p != q)
	{
		p = p->next;
		q = q->next;
	}

	return q;
}


int main()
{
	std::vector<int> input;
    while(!getIntArrayFromConsole(input));

	Node* head = DataStructure::buildLoopLink<int, Node>(input);
	Node* node = findLoopStart(head);
	
	if(node)
		std::cout<<node->data<<std::endl;    
}