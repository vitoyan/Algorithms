#ifndef BUILDDATASTRUCTURE
#define BUILDDATASTRUCTURE

#include <iostream>
#include <string>
#include <iterator>
#include <sstream>
#include <map>

namespace DataStructure
{

template <typename T,typename N>
N* buildLink(std::vector<T> input)
{
	if(input.empty())
		return NULL;

	N* head = NULL;
	N* tail = NULL;
	for(auto it : input)
	{
		N* n = new N;
		n->data = it;
		n->next = NULL;
		if(head)
		{
			tail->next = n;
			tail = n;
		}
		else
		{
			head = tail = n;
		}
	}

	return head;
}

template <typename T,typename N>
N* buildLoopLink(std::vector<T> input)
{
	if(input.empty())
		return NULL;

	N* head = NULL;
	N* tail = NULL;

	std::map<T, N*> linkElements;

	for(auto it : input)
	{
		if(linkElements.find(it) != linkElements.end())
		{
			tail->next = linkElements.find(it)->second;
			break;
		}

		N* n = new N;
		n->data = it;		
		if(head)
		{
			tail->next = n;
			tail = n;
		}
		else
		{
			head = tail = n;
		}
		
		linkElements.insert({it , n});
		n->next = NULL;		
	}

	return head;
}

/*
build a binary tree with lowest high
precondition: input must be order ascending
*/
template <typename T, typename N>
N* buildBinaryTreeLowestHigh(std::vector<T> input, int start, int end)
{
	if(end < start)
		return NULL;
	//check input in the frist call
	if(start == 0 && end == (int)(input.size() - 1))
	{
		auto pre = input.begin();
		for(auto i = (pre + 1); i != input.end(); i++, pre++)
		{
			if(*pre > *i)
				return NULL;
		}	
	}

	N* n = new N;

	n->key = input[(end + start)/2];
	n->left = buildBinaryTreeLowestHigh<T, N>(input, start, (end + start)/2 - 1); 
	n->right = buildBinaryTreeLowestHigh<T, N>(input, (end + start)/2 + 1, end);
	n->p = NULL;

	if(n->left)
		n->left->p = n;
	if(n->right)
		n->right->p = n;

	return n;
}

template <typename T, typename N>
N* buildBinaryTree(std::vector<T> input)
{
	if(input.empty())
		return NULL;
	N* n = new N;

	n->key = input[0];
	int size = (int)input.size();
	int offset = (size + 1)/2 + ((size-1)%2?1:0);
	if(size >= 2)
		n->left = buildBinaryTree<T, N>(std::vector<T>(input.begin() + 1, input.begin() + offset)); 
	if(size >= 3)
		n->right = buildBinaryTree<T, N>(std::vector<T>(input.begin() + offset, input.end()));
	n->p = NULL;

	if(n->left)
		n->left->p = n;
	if(n->right)
		n->right->p = n;

	return n;
}


}

#endif

