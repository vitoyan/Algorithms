#ifndef BUILDDATASTRUCTURE
#define BUILDDATASTRUCTURE

#include <iostream>
#include <string>
#include <iterator>
#include <sstream>


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

#endif

