#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <sstream>
#include <stack>
#include <limits> 

#include "./util/util.h"
#include "./util/buildDataStructure.h"


void Hanoi(int n, std::stack<int> &source, std::stack<int> &destination, std::stack<int> &buffer)
{
	if(source.empty())
		return;

	if(n <= 0)
		return;

	Hanoi(n-1, source, buffer, destination);
	destination.push(source.top());
	source.pop();
	Hanoi(n-1, buffer, destination, source);	
}

int main()
{
	std::vector<int> input;
    while(!getIntArrayFromConsole(input));

    std::stack<int> s1, d1, b1;
    for(auto i : input)
    {
    	if(s1.empty())
    	{
    		s1.push(i);
    		continue;
    	}
    	if(i <= s1.top())
    		s1.push(i);
    	else
    	{
    		std::cout<<"pls input correct"<<std::endl;
    		return 0;
    	}    	
    }

    Hanoi(s1.size(), s1, d1, b1);
    while(!d1.empty())
    {
    	std::cout<<d1.top()<<" ";
    	d1.pop();
    }

}