#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <sstream>
#include <stack>
#include <set>
#include <limits>
#include <algorithm>

#include "./util/util.h"

struct activity{
	activity():s(0),f(0)
	{}
	int id;
	int s;
	int f;
};

std::vector<activity> activityOrder(std::vector<activity> &o)
{
	if(o.empty())
		return std::vector<activity>();

	int size = (int)o.size();
	std::sort(o.begin(), o.end(), [](activity &a, activity &b)
	{
		return a.f <= b.f;
	});

	std::vector<activity> r;
	auto tmp = o[0]; 
	r.push_back(o[0]);
	for(int i = 0; i < size; i++)
	{
		if(tmp.f <= o[i].s)
		{
			tmp = o[i];
			r.push_back(o[i]);
		}
	}
	return r;
}



int main()
{
	std::cout<<"pls input activity number"<<std::endl;

	int n;
	std::cin>>n;
	std::cout<<"pls input activity start and finish time"<<std::endl;
	int id = 1;
	std::vector<activity> o;
	while(n)
	{
		activity a;
		std::cout<<"start: ";
		std::cin>>a.s;
		std::cout<<"end: ";
		std::cin>>a.f;
		a.id = id;
		id++;
		o.push_back(a);
		n--;
	}	

	auto r = activityOrder(o);
	for(auto &it : r)
	{
		std::cout<<it.id<<" ";
	}
	std::cout<<std::endl;
}