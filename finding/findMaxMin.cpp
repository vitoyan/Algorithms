#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <sstream>
#include <math.h>

#include "./util/util.h"

void findMaxMin(std::vector<int> input, int *max, int *min)
{
	if(input.empty()||!max||!min)
		return;

	if(input.size() == 1)
	{
		*max = *min = input[0];
		return;
	}

	int startIndex = 0;
	if(((int)input.size())%2 == 0)
	{
		if(input[0] >= input[1])
		{
			*max = input[0];
			*min = input[1];
		}
		else
		{
			*max = input[1];
			*min = input[0];
		}
		startIndex = 2;
	}
	else
	{
		*max = *min = input[0];
		startIndex = 1;
	}

	for(int i = startIndex; i < (int)input.size() - 1; i+=2)
	{
		if(input[i] < input[i+1])
		{
			if(input[i] < *min)
			{
				*min = input[i];
			}

			if(input[i+1] > *max)
			{
				*max = input[i+1];
			}
		}
		else
		{
			if(input[i] > *max)
			{
				*max = input[i];
			}

			if(input[i+1] < *min)
			{
				*min = input[i+1];
			}
		}
	}


}

int main()
{
    std::vector<int> input;
    while(!getIntArrayFromConsole(input));

    int max = 0, min = 0;
    findMaxMin(input, &max, &min);

    std::cout<<"max is "<<max<<std::endl;
    std::cout<<"min is "<<min<<std::endl;

    
}