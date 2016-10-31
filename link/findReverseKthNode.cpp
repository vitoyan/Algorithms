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

Node* findLastKNote(Node *head, int k)
{
	if(!head)
		return NULL;

	Node *p = head;
	Node *q = head;

	for(int i = 0; i < k - 1; i++)
	{
		q = q->next;
		if(!q)
			return NULL;
	}
	while(q->next)
	{
		p = p->next;
		q = q->next;
	}
	return p;
}

int main()
{
	std::vector<int> input;
    while(!getIntArrayFromConsole(input));

	Node* head = DataStructure::buildLink<int, Node>(input);
    Node* node = findLastKNote(head, input.size()/2);
    
    if(node)
   	std::cout<<node->data<<" "<<std::endl;
}