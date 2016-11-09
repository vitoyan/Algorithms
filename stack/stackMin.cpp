#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <sstream>
#include <stack>
#include <limits> 

#include "./util/util.h"
#include "./util/buildDataStructure.h"

class stackMin
{
public:

	void push(int e)
	{
		if(e <= min())
			minS.push(e);
		main.push(e);
	}

	int pop()
	{
		if(!main.empty())
		{
			int ret = main.top();
				main.pop();
			if(ret == min() && !minS.empty())
				minS.pop();
			return ret;
		}
		else
			return 0;
		
	}

	int min()
	{
		if(minS.empty())
		{
			return std::numeric_limits<int>::max();
		}
		else
			return minS.top();
	}

private:
	std::stack<int> main;
	std::stack<int> minS; 
};

int main()
{
	std::vector<int> input;
    while(!getIntArrayFromConsole(input));

    stackMin sm;
    for(auto i :input)
    {
    	sm.push(i);
    	std::cout<<"push is "<<i<<" ";
    	std::cout<<"min is "<<sm.min()<<" "<<std::endl;
    }
    std::cout<<std::endl;        
}