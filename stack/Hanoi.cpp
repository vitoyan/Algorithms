#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <sstream>
#include <stack>
#include <limits> 
#include <cmath>

#include "./util/util.h"
#include "./util/buildDataStructure.h"


void HanoiRecursively(int n, std::stack<int> &source, std::stack<int> &destination, std::stack<int> &buffer)
{
	if(source.empty())
		return;

	if(n <= 0)
		return;

	HanoiRecursively(n-1, source, buffer, destination);
	destination.push(source.top());
	source.pop();
	HanoiRecursively(n-1, buffer, destination, source);	
}

void makeMove(std::stack<int> &p, std::stack<int> &q)
{
    if(p.empty() && q.empty())
        return;

    if(p.empty())
    {
        p.push(q.top());
        q.pop();
        return;
    }    

    if(q.empty())
    {
        q.push(p.top());
        p.pop(); 
        return;
    }

    if(p.top() > q.top())
    {
        p.push(q.top());
        q.pop();
        return;
    }

    if(p.top() < q.top())
    {
        q.push(p.top());
        p.pop(); 
        return;
    }
}

void Hanoi1(std::stack<int> &source, std::stack<int> &destination)
{
    if(source.empty())
        return;

    std::stack<int> buffer;
    int size = (int) source.size();

    int n = 0;
    while(n < (std::pow(2, size) - 1))
    {
        if(size%2)
        {
            switch(n%3)
            {
                case 0:
                    makeMove(source, destination);
                    break;
                case 1:
                    makeMove(source, buffer);
                    break;
                case 2:
                    makeMove(buffer, destination);
                    break;
            }
            
        }
        else
        {
            switch(n%3)
            {
                case 0:
                    makeMove(source, buffer);
                    break;
                case 1:
                    makeMove(source, destination);
                    break;
                case 2:
                    makeMove(buffer, destination);
                    break;
            }
        }
        n++;
    }
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

    HanoiRecursively(s1.size(), s1, d1, b1);
    s1 = d1;
    while(!d1.empty())
    {
    	std::cout<<d1.top()<<" ";
    	d1.pop();
    }
    std::cout<<std::endl;

    Hanoi1(s1, d1);
    while(!d1.empty())
    {
        std::cout<<d1.top()<<" ";
        d1.pop();
    }
    std::cout<<std::endl;
}