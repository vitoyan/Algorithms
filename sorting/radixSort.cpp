#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <sstream>
#include <math.h>

#include "./util/util.h"

void getMax(std::vector<int> input, int &max)
{
	if(input.empty())
		return;
	max = input[0];
	for(auto i : input)
	{
		if(i > max )
			max = i;
	}
}

std::vector<int> radixSort(std::vector<int> input)
{
	int max = 0;
	getMax(input, max);
		
	std::vector<int> output;
	output.resize(input.size());
	for(int m = 1; m <= max; m = m*10)
	{
		std::vector<int> count;
		count.resize(10);
		for(int i = 0; i < (int)input.size(); i++)
		{
			count[(input[i]/m)%10]++;
		}

		for(int i = 1; i < (int)count.size(); i++)
		{
			count[i] = count[i] + count[i-1];
		}

		for(int i = (int)input.size() - 1; i >= 0; i--)
		{
			output[count[(input[i]/m)%10] - 1] = input[i];
			count[(input[i]/m)%10]--;
		}
		input = output;		
	}

	return output;
}


int main()
{
    std::vector<int> input;
    while(!getIntArrayFromConsole(input));

    std::vector<int> output = radixSort(input);

    for(auto it : output)
    {
    	std::cout<<it<<" ";
    }
    std::cout<<std::endl;
}