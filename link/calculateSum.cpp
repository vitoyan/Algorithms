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
	int carry;
	Node *next;
	Node()
	{
		data = 0;
		next = NULL;
		carry = 0;
	}
};


Node* calculateSum(Node *head1, Node *head2, Node* head3, int carry)
{
	if(!head1 && !head2 && carry == 0)
		return 0;

	Node *node = NULL;
	Node *head = NULL;
	Node *node1 = head1;
	Node *node2 = head2;
	int temp = 0;
	if(node1 || node2)
	{		
		if(node1)
		{
			temp = node1->data;
			node1 = node1->next;
		}

		if(node2)
		{
			temp = temp + node2->data;
			node2 = node2->next;
		}					
	}

	temp += carry;
	node = new Node();
	carry = temp/10;
	node->data = carry ? temp%10 : temp;
	node->next = head3;
	if(carry || node1 || node2)
	{
		head = calculateSum(node1, node2, node, carry);
	}
	else
		head = node;	

	return head;
}

Node* padList(Node *head, int number)
{
	if(!head || number == 0)
		return head;

	while(number)
	{
		Node *node = new Node;
		node->data = 0;
		node->next = head;
		head = node;
		number--;
	}
	return head;
}

int calListLength(Node *head)
{
	int number = 0;
	while(head)
	{
		number++;
		head = head->next;
	}

	return number;
}

Node* addListHelper(Node *head1, Node *head2)
{
	if(!head1 && !head2)
		return NULL;
	

	Node *sumLower = addListHelper(head1->next, head2->next);

	int sum = head1->data + head2->data + (sumLower ? sumLower->carry:0);

	int carry = sum/10;

	Node* node = new Node;
	if(carry)
	{
		node->data = sum%10;		
		node->carry = carry;
		
	}
	else
	{
		node->data = sum;
	}
	node->next = sumLower;
	
	return node;
}



Node* calculateSumReverse(Node *head1, Node *head2)
{
	if(!head1 && !head2)
		return 0;

	Node *node1 = head1;
	Node *node2 = head2;
	int length1 = 0, length2 = 0;

	length1 = calListLength(head1);
	length2 = calListLength(head2);

	if(length1 > length2)
	{
		node2 = padList(node2, length1 - length2);
	}
	else
		node1 = padList(node1, length2 - length1);

	Node* node = addListHelper(node1, node2);
	if(node && node->carry != 0)
	{
		Node *temp = new Node;
		temp->data = node->carry;
		temp->next = node;
		node = temp;
	}

	return node;
}


int main()
{
	std::vector<int> input1;
    while(!getIntArrayFromConsole(input1));
	Node* head1 = DataStructure::buildLink<int, Node>(input1);

	std::vector<int> input2;
    while(!getIntArrayFromConsole(input2));
	Node* head2 = DataStructure::buildLink<int, Node>(input2);
    

    Node* result1 = calculateSum(head1, head2, NULL, 0);
        
   	while(result1)
   	{
   		std::cout<<result1->data;
   		result1 = result1->next;
   	}
   	std::cout<<std::endl;

   	Node* result2 = calculateSumReverse(head1, head2);
        
   	while(result2)
   	{
   		std::cout<<result2->data;
   		result2 = result2->next;
   	}
   	std::cout<<std::endl;
}