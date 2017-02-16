#ifndef PRINTDATASTRUCTURE
#define PRINTDATASTRUCTURE

#include <iostream>
#include <string>
#include <iterator>
#include <sstream>
#include <map>
#include <algorithm>
#include <stack>
#include <iomanip>

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

template <typename T>
void printTreeLayers(T* node)
{
	if(!node)
		return;
	std::queue<T*> p;
	std::queue<T*> q;
	
	p.push(node);
	while(!p.empty())
	{
		T* n = p.front();
		if(n->left)
			q.push(n->left);
		if(n->right)
			q.push(n->right);
		p.pop();
		std::cout<<n->key<<" ";
		if(p.empty())
		{
			std::cout<<std::endl;
			if(!q.empty())
			{
				p.swap(q);
			}
		}
	}		
}

template <typename T>
void printRedBlackTreeLayers(T* node)
{
	if(!node)
		return;
	std::queue<T*> p;
	std::queue<T*> q;
	
	p.push(node);
	while(!p.empty())
	{
		T* n = p.front();
		if(n->left)
			q.push(n->left);
		if(n->right)
			q.push(n->right);
		p.pop();
		std::cout<<"Node : "<<n->key<<" "<<n->color<<" ";
		if(n->p)
		std::cout<<"father is "<<n->p->key<<" ";
		if(p.empty())
		{
			std::cout<<std::endl;
			if(!q.empty())
			{
				p.swap(q);
			}
		}
	}		
}

template <typename T>
void printAVLTreeLayers(T* node)
{
	if(!node)
		return;
	std::queue<T*> p;
	std::queue<T*> q;
	
	p.push(node);
	while(!p.empty())
	{
		T* n = p.front();
		if(n->left)
			q.push(n->left);
		if(n->right)
			q.push(n->right);
		p.pop();
		std::cout<<"Node : "<<n->key<<" height is "<<n->height<<" ";
		if(n->p)
		std::cout<<"father is Node : "<<n->p->key<<" *** ";
		if(p.empty())
		{
			std::cout<<std::endl;
			if(!q.empty())
			{
				p.swap(q);
			}
		}
	}		
}

}

#endif