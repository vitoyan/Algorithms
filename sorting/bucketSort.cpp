#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <sstream>
#include <math.h>

#include "./util/util.h"

class Node
{
public:
	int data;
	Node *next;
};

Node* insertion(Node* head, Node* insertNode)
{
	if(!head)
	{
		head = insertNode;
		return head;
	}

	Node* node = head;
	Node* preNode = NULL;
	while(node)
	{
		if(node->data > insertNode->data)
		{						
			break;
		}
		else
		{
			preNode = node;
			node = node->next;
		}
	}	
	
	if(preNode)
	{
		insertNode->next = preNode->next;
		preNode->next = insertNode;	
	}
	else
	{
		insertNode->next = head;
		head = insertNode;
	}

	return head;

}

void bucketSort(std::vector<int> &input)
{
	if(input.empty())
		return;

	Node* bucket[10] = {0};
	int max = input[0];
	for(auto i : input)
	{
		if(i > max)
			max = i;
	}

	for(auto i : input)
	{
		int index = (i*10)/(max + 1);
		Node* n = new Node;
		n->data = i;
		n->next = NULL;
		bucket[index] = insertion(bucket[index], n);
	}

	int size = (int)input.size();
	input.clear();
	input.resize(size);
	auto it = input.begin();
	for(int i = 0; i < 10; i++)
	{
		Node* n = bucket[i];
		while(n)
		{
			*it = n->data;
			it++;
			n = n->next; 			
		}
	}
};



int main()
{
    std::vector<int> input;
    while(!getIntArrayFromConsole(input));

    bucketSort(input);

    for(auto it : input)
    {
    	std::cout<<it<<" ";
    }
    std::cout<<std::endl;
}