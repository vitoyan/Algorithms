#ifndef PRINTDATASTRUCTURE
#define PRINTDATASTRUCTURE

#include <iostream>
#include <string>
#include <iterator>
#include <sstream>
#include <map>
#include <algorithm>
#include <stack>

namespace DataStructure
{

template <typename T>
void printTreeInorder(T *node)
{
	if(!node)
		return;
	T* n = node;
	while(n)
	{
		if(!(n->left))
		{
			std::cout<<n->key<<" ";
			n = n->right;
		}
		else
		{
			T* pre = n->left;
			while(pre->right && pre->right != n)
				pre = pre->right;
			if(pre->right != n)
			{
				pre->right = n;
				n = n->left;
			}
			else
			{
				pre->right = NULL;
				std::cout<<n->key<<" ";
				n = n->right;
			}
		}
	}
}

template <typename T>
void printTreePreorder(T *node)
{
	if(!node)
		return;
	T* n = node;
	while(n)
	{
		if(!(n->left))
		{
			std::cout<<n->key<<" ";
			n = n->right;
		}
		else
		{
			T* pre = n->left;
			while(pre->right && pre->right != n)
				pre = pre->right;
			if(pre->right != n)
			{
				std::cout<<n->key<<" ";
				pre->right = n;
				n = n->left;
			}
			else
			{
				pre->right = NULL;				
				n = n->right;
			}
		}
	}
}

template <typename T>
void printTreePostorder(T* node)
{
	if(!node)
		return;
	std::stack<T*> s;
	T* lastVisted = NULL;
	T* p = node;
	while(!s.empty() || p)
	{
		if(p)
		{
			s.push(p);
			p = p->left;
		}
		else
		{
			p = s.top();
			if(!p->right || p->right == lastVisted)
			{
				std::cout<<p->key<<" ";
				lastVisted = p;
				p = NULL;
				s.pop();
			}
			else
			{
				p = p->right;
			}

		}
	}
}

}

#endif