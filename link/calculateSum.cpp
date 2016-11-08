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


int calculateSum(Node *head1, Node *head2)
{
	if(!head1 && !head2)
		return 0;

	int sum = 0;
	Node *node1 = head1;
	Node *node2 = head2;
	int bit = 1;
	while(node1 || node2)
	{
		int temp = 0;
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

		sum = sum + temp*bit;
		bit = 10*bit;
	}

	return sum;
}

int calculateSumReverse(Node *head1, Node *head2)
{
	if(!head1 && !head2)
		return 0;

	int sum = 0;
	Node *node1 = head1;
	Node *node2 = head2;
	int op1 = 0, op2 = 0;
	while(node1 || node2)
	{
		int temp = 0;
		if(node1)
		{
			temp = node1->data;
			node1 = node1->next;
			op1 = op1*10 + temp;
		}

		temp = 0;
		if(node2)
		{
			temp = temp + node2->data;
			node2 = node2->next;
			op2 = op2*10 + temp;
		}
		
	}

	sum = op1 + op2;

	return sum;
}


int main()
{
	std::vector<int> input1;
    while(!getIntArrayFromConsole(input1));
	Node* head1 = DataStructure::buildLink<int, Node>(input1);

	std::vector<int> input2;
    while(!getIntArrayFromConsole(input2));
	Node* head2 = DataStructure::buildLink<int, Node>(input2);
    

    int result1 = calculateSum(head1, head2);
        
   	std::cout<<result1<<" "<<std::endl;

   	int result2 = calculateSumReverse(head1, head2);
        
   	std::cout<<"reverse is "<<result2<<" "<<std::endl;
}