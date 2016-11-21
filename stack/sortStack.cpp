#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <sstream>
#include <stack>
#include <limits> 

#include "./util/util.h"
#include "./util/buildDataStructure.h"

template <typename T>
void sortStack(std::stack<T> &s)
{
	std::stack<T> r;
	while(!s.empty())
	{
		T tmp = s.top();
		s.pop();
		while(!r.empty() && r.top() > tmp)
		{
			s.push(r.top());
			r.pop();
		}
		r.push(tmp);
	}

	s.swap(r);
}


int main()
{
	std::vector<int> input;
    while(!getIntArrayFromConsole(input));

    std::stack<int> s;

    for(auto e : input)
    {
    	s.push(e);
    }

    sortStack<int>(s);

    while(!s.empty())
    {
    	std::cout<<s.top()<<" ";
    	s.pop();
    }
}