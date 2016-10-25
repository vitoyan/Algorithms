#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <sstream>

#include "./util/util.h"

void countSort(std::vector<int> &input, std::vector<int> &output)
{
	std::vector<int> count;

	int max = input[0];
	for(auto i : input)
	{
		if(i > max)
			max = i;
	}
	count.resize(max + 1);

	for(int i = 0; i < (int)input.size(); i++)
	{
		count[input[i]]++;
	}

	for(int i = 1; i < (int)count.size(); i++)
	{
		count[i] = count[i] + count[i - 1];
	}

	for(int i = 0; i < (int)input.size(); i++)
	{
		output[count[input[i]] - 1] = input[i];
		count[input[i]]--;
	}
}

int main()
{
    std::vector<int> input;
    while(!getIntArrayFromConsole(input));
    std::vector<int> output;
    output.resize(input.size());

    countSort(input, output);

    for(auto it : output)
    {
    	std::cout<<it<<" ";
    }
    std::cout<<std::endl;
}