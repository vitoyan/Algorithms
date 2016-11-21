#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <sstream>
#include <stack>
#include <limits> 

#include "./util/util.h"
#include "./util/buildDataStructure.h"

class ascendingStack
{
public:
	void pop()
	{
		asStack.pop();
	}

	void push(int e)
	{
		std::stack<int> tmpStack;
		while(!asStack.empty() && asStack.top() > e)
		{
			tmpStack.push(asStack.top());
			asStack.pop();
		}

		asStack.push(e);

		while(!tmpStack.empty())
		{
			asStack.push(tmpStack.top());
			tmpStack.pop();
		}
	}

	int top()
	{
		return asStack.top();
	}

	int isEmpty()
	{
		return asStack.empty();
	}


private:
	std::stack<int> asStack;
};


int main()
{
	std::vector<int> input;
    while(!getIntArrayFromConsole(input));

    ascendingStack s;
    for(int i : input)
    {
    	s.push(i);
    }

    if(!s.isEmpty())
    {
    	std::cout << "the top element is" << s.top() << std::endl;
    	s.pop();
    	std::cout << "the top element is" << s.top();    	
    }

}