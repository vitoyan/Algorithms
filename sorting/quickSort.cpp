#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <sstream>
#include <stack>

#include "./util/util.h"

int partition(std::vector<int> &input, int p, int r)
{
	int i = p- 1;
	for(int j = p; j <= r; j++)
	{
		if(input[j] <= input[r])
		{
			i++;
			int temp = input[j];
			input[j] = input[i];
			input[i] = temp;
		}
	}	
	return i;
}

void quickSortRecursively(std::vector<int> &input, int p, int r)
{
	if(p < r)
	{
		int q = partition(input, p, r);		  	
		quickSortRecursively(input, p, q - 1 );
		quickSortRecursively(input, q + 1, r);
	}	
}

struct node
{
public:
	node(int s, int e):start(s), end(e)
	{

	}
	int start;
	int end;	
};

void quickSort(std::vector<int> &input)
{
	if(input.empty() || input.size() == 1)
	{
		return;
	}
	node n(0, input.size() - 1);
	std::stack<node> st;
	st.push(n);
	while(!st.empty())
	{
		n = st.top();
		st.pop();
		int q = partition(input, n.start, n.end);
		if(q > (n.start + 1))
			st.push(node(n.start, q - 1));
		if(q < (n.end - 1))
			st.push(node(q + 1, n.end));
	}
}


int main()
{
    std::vector<int> input, input1;
    while(!getIntArrayFromConsole(input));
    input1 = input;

    quickSortRecursively(input, 0, input.size() - 1);
    auto it = input.begin();
    while(it != input.end())
    {
    	std::cout<<*it<<" ";
    	it++;
    }
    std::cout<<std::endl;

    quickSort(input1);
    auto it2 = input1.begin();
    while(it2 != input1.end())
    {
    	std::cout<<*it2<<" ";
    	it2++;
    }
    std::cout<<std::endl;
}
