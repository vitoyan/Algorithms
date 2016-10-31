#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <sstream>
#include <map>

#include "./util/util.h"
#include "./util/buildDataStructure.h"

class Node
{
public:
	int data;
	Node *next;
};

void removeDuplicates(Node *head)
{
	if(!head || !(head->next))
		return;

	std::map<int, bool> tag;

	Node *pre = NULL;
	Node *n = head;
	while(n)
	{
		if(tag.find(n->data) != tag.end())
		{
			pre->next = n->next;
			Node* temp = n;
			n = n->next;
			delete temp;
		}
		else
		{
			tag.insert({n->data, 1});
			pre = n;
			n = n->next;
		}
	}

}

int main()
{
	std::vector<int> input;
    while(!getIntArrayFromConsole(input));

	Node* head = DataStructure::buildLink<int, Node>(input);
    removeDuplicates(head);
    
    while(head)
    {
    	std::cout<<head->data<<" ";
    	head = head->next;
    }
    std::cout<<std::endl;
}