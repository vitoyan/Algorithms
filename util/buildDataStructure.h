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

}

#endif

