#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <sstream>

#include "./util/util.h"

void merge(std::vector<int> &input, int p, int r)
{
	if(p >=r)
		return;

	int q = p + (r- p)/2;
	std::vector<int> temp;
	temp.resize(r - p + 1);
	auto it = temp.begin();
	int p1 = p;
	int p2 = q + 1;
	while(p1 <= q && p2 <= r)
	{
		if(input[p1] <= input[p2])
		{
			*it = input[p1];
			p1++;
		}
		else
		{
			*it = input[p2];
			p2++;
		}
		it++;
	}
	
	while(p1 <= q)
	{
		*it = input[p1];
		p1++;
		it++;
	}

	while(p2 <= r )
	{
		*it = input[p2];
		p2++;
		it++;
	}
	
	it = temp.begin();
	for(int i = p; i <= r; i++)
	{
		input[i] = *it;
		it++;
	}
}

void mergeSort(std::vector<int> &input, int p, int r)
{	
	if(p < r)
	{
		int q = p + (r - p)/2;
		mergeSort(input, p, q);
		mergeSort(input, q + 1, r);
		merge(input, p, r);
	}
}


int main()
{
    std::vector<int> input;
    while(!getIntArrayFromConsole(input));
    mergeSort(input, 0, input.size() - 1);

    auto it = input.begin();
    while(it != input.end())
    {
    	std::cout<<*it<<" ";
    	it++;
    }
    std::cout<<std::endl;
}