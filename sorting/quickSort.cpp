#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <sstream>

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

void quickSort(std::vector<int> &input, int p, int r)
{
	if(p < r)
	{
		int q = partition(input, p, r);		  	
		quickSort(input, p, q - 1 );
		quickSort(input, q + 1, r);
	}	
}



int main()
{
    std::vector<int> input;
    while(!getIntArrayFromConsole(input));
    quickSort(input, 0, input.size() - 1);

    auto it = input.begin();
    while(it != input.end())
    {
    	std::cout<<*it<<" ";
    	it++;
    }
    std::cout<<std::endl;
}
