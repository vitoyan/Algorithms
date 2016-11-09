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
	int data;
	Node *next;
	Node()
	{
		data = 0;
		next = NULL;
	}
};

bool isPalindrome(Node *head)
{
	if(!head)
		return false;
	if(!(head->next))
		return true;

	Node *p = head;
	Node *q = head;
	std::stack<int> s;
	while(p && q && q->next)
	{
		s.push(p->data);
		p = p->next;
		q = q->next->next;
	}

	if(q)
		p = p->next;

	while(p)
	{
		int m = s.top();
		s.pop();
		if(m != p->data)
			return false;
		p = p->next;
	}

	return true;
}

int main()
{
	std::vector<int> input;
    while(!getIntArrayFromConsole(input));
	Node* head = DataStructure::buildLink<int, Node>(input);

	if(isPalindrome(head))
		std::cout<<"this is palindrome"<<std::endl;
	else
		std::cout<<"this is not palindrome"<<std::endl;
}