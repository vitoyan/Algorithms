#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <sstream>

#include "./util/util.h"

void shellSort(std::vector<int> &input)
{
	for(int gap = input.size()/2; gap > 0; gap = gap/2)
	{
		for(int i = gap; i < (int)input.size(); i++)
		{
			for(int j = i; j >= gap; j -= gap)
			{
				if( input[j] < input[j - gap])
				{
					int temp = input[j];
					input[j] = input[j - gap];
					input[j - gap] = temp;
				}
			}					
		}
	}
}


int main()
{
    std::vector<int> input;
    while(!getIntArrayFromConsole(input));

    shellSort(input);

    for(auto it: input)
    {
    	std::cout<<it<<" ";
    }
    std::cout<<std::endl;
}