#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <sstream>
#include <stack>
#include <queue>

#include "./util/util.h"
#include "./util/buildDataStructure.h"
#include "./util/printDataStructure.h"

class Node
{
public:
	Node():key(0), color(""), left(NULL), right(NULL), p(NULL)
	{

	}
	int key;
	std::string color;
	Node* left;
	Node* right;
	Node* p;
};

class RBTree
{
public:
	RBTree()
	{
		root = NULL;
	}
	void leftRotate(Node *n);
	void rightRotate(Node *n);
	Node* find(int key);
	Node* getRoot()
	{
		return root;
	}
	void transplant(Node *m, Node *n);
	void insert(Node *n);
	void del(Node *n);
private:
	Node *root;
};

void RBTree::leftRotate(Node *n)
{
	if(!n || !n->right)
		return;

	Node* m = n->right;
	
	n->right = m->left;
	if(m->left)
		m->left->p = n;
	m->left = n;

	m->p = n->p;
	if(!n->p)
		root = m;
	else if(n == n->p->left)
		n->p->left = m;
	else
		n->p->right = m;

	n->p = m;	
}

void RBTree::rightRotate(Node *n)
{
	if(!n || !n->left)
		return;

	Node* m = n->left;

	n->left = m->right;
	if(n->left)
		n->left->p = n;
	m->right = n;

	if(!n->p)
		root = m;
	else if(n == n->p->left)
		n->p->left = m;
	else
		n->p->right = m;

	m->p = n->p;
	n->p = m;
}

Node* RBTree::find(int key)
{
	Node *result = NULL;
	Node *p = root;
	while(p)
	{
		if(p->key > key)
			p = p->left;
		else if(p->key < key)
			p = p->right;
		else
		{
			result = p;
			break;
		}
	}

	return result;
}

void RBTree::insert(Node* n)
{
	if(!n)
		return;

	if(!root)
	{
		n->color = "black";
		n->p = NULL;
		root = n;
		return;
	}

	Node *f = NULL;
	Node *s = root;

	while(s)
	{
		f = s;
		if(s->key > n->key)
			s = s->left;
		else
			s = s->right;
	}

	if(f->key > n->key)
	{
		f->left = n;
	}
	else
	{
		f->right = n;
	}

	n->color = "red";
	n->p = f;

	s = n;
	while(s->p && s->p->color == "red")
	{
		if(!s->p->p)
			break;

		//for uncle on right
		if(s->p == s->p->p->left)
		{
			Node *k = s->p->p->right;
			//for case 1, uncle is red
			if(k && k->color == "red")
			{
				k->color = "black";
				s->p->color = "black";
				s->p->p->color = "red";
				s = s->p->p;				
			}
			else
			{
			//for case 2, uncle is balck and the insert node is on right;
				if(s == s->p->right)
				{
					leftRotate(s->p);
					s = s->left;
				}
			//for case 3, uncle is black and the insert node is on left;
				s->p->color = "black";
				s->p->p->color = "red";
				rightRotate(s->p->p);
			}
		}
		else
		{
			Node *k = s->p->p->left;
			if(k && k->color == "red")
			{
				k->color = "black";
				s->p->color = "black";
				s->p->p->color = "red";
				s = s->p->p;
			}
			else
			{
				//for case 2, uncle is balck and the insert node is on right;
				if(s == s->p->left)
				{
					rightRotate(s->p);
					s = s->right;
				}
				//for case 3, uncle is black and the insert node is on left;
				s->p->color = "black";
				s->p->p->color = "red";
				leftRotate(s->p->p);
			}

		}
	}
	root->color = "black";
}

void RBTree::transplant(Node *m, Node *n)
{
	if(!m)
		return;
	if(m->p == NULL)
		root = n;
	else if(m == m->p->left)
		m->p->left = n;
	else
		m->p->right = n;

	if(n)
		n->p = m->p;
}

void RBTree::del(Node *n)
{
	if(!n)
		return;
	if(!root || !find(n->key))
		return;

	Node* s = n;
	Node* k = NULL;

	std::string sOrignalColor = s->color;

	if(!n->left)
	{
		k = n->right;
		transplant(n, k);
	}
	else if(!n->right)
	{
		k = n->left;
		transplant(n, k);
	}
	else 
	{
		
		Node *tmp = s->right;
		while(tmp)
		{
			s = tmp;
			tmp = tmp->left;
		}
		sOrignalColor = s->color;

		k = s->right;
		if(s->p == n)
		{
			if(k)
				k->p = s;
		}
		else
		{
			transplant(s, k);
			s->right = n->right;
			s->right->p = s;
		}
		
		transplant(n, s);
		s->left = n->left;
		s->left->p = s;
		s->color = n->color;
	}
	
	if(k && sOrignalColor == "black")
	{
		while(k != root && k->color == "black")
		{
			Node* w = NULL;
			if(k == k->p->left)
			{
				w = k->p->right;
				if(w->color == "red")
				{
					w->color = "black";
					w->p->color = "red";
					leftRotate(w->p);
					w = k->p->right;
				}
				else if(w->right->color == "black" && w->left->color == "black")
				{
					w->color = "red";
					k = k->p;
				}
				else if(w->right->color == "black" && w->left->color == "red")
				{	
					w->right->color = "black";
					w->color = "red";
					rightRotate(w);
					w = w->p;
				}
				else if(w->right->color == "red")
				{
					w->color = w->p->color;
					w->p->color = "black";
					w->right->color = "black";
					leftRotate(k->p);
					k = root;
				}
			}
			else
			{
				w = k->p->left;
				if(w->color == "red")
				{
					w->color = "black";
					w->p->color = "red";
					rightRotate(w->p);
					w = k->p->left;
				}
				else if(w->right->color == "black" && w->left->color == "black")
				{
					w->color = "red";
					k = k->p;					
				}
				else if(w->right->color == "red" && w->left->color == "black")
				{	
					w->color = "red";
					w->right->color = "black";
					rightRotate(w);
					w = w->p;					
				}
				else if(w->right->color == "red")
				{
					w->color = w->p->color;
					w->p->color = "black";
					w->left->color = "black";
					rightRotate(w->p);
					k = root;
				}
			}
		}
			k->color = "black";
	}

	delete n;
}


int main()
{
	std::vector<int> input;
    while(!getIntArrayFromConsole(input));  
   	
   	RBTree rbt;

   	for(auto i : input)
   	{
   		Node* n = new Node();
   		n->key = i;
   		rbt.insert(n);
   	}

    DataStructure::printRedBlackTreeLayers<Node>(rbt.getRoot());

    //test case
    //input 1 2 3 4 5 6 7 8
    rbt.del(rbt.find(3));
    DataStructure::printRedBlackTreeLayers<Node>(rbt.getRoot());
}