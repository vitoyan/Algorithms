#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <sstream>
#include <stack>
#include <limits> 

#include "./util/util.h"
#include "./util/buildDataStructure.h"


class myQueue
{
public:
	void push(int e)
	{
		newStack.push(e);
	}

	void remove()
	{
		moveElement();
		if(!oldStack.empty())
			oldStack.pop();
	}

	int peek()
	{
		moveElement();
		return oldStack.top();
	}

	int size()
	{
		return newStack.size() + oldStack.size();
	}

protected:
	void moveElement()
	{
		if(oldStack.empty())
		{
			while(!newStack.empty())
			{
				oldStack.push(newStack.top());
				newStack.pop();
			}
		}
	}

private:
	std::stack<int> newStack;
	std::stack<int> oldStack;

};


int main()
{
	std::vector<int> input;
    while(!getIntArrayFromConsole(input));

    myQueue que;

    for(auto e : input)
    {
    	que.push(e);
    }

    std::cout<<"the front is "<< que.peek()<<std::endl;

    que.remove();

    std::cout<<"the new front is "<< que.peek()<<std::endl;
}