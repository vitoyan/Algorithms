#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <sstream>
#include <math.h>
#include <cstdlib>

#include "./util/util.h"

int radomizedPartition(std::vector<int> &input, int p, int q)
{
	if(p == q)
		return p;

	int anchor = std::rand()%(q - p + 1) + p;

	int i = p -1, j = p;
	while(j <= q)
	{
		if(input[j] <= input[anchor])
		{
			i++;
			if(i != j)
			{
				int tmp = input[i];
				input[i] = input[j];
				input[j] = tmp;
				if(j == anchor)
					anchor = i;
			}			
		}

		j++;
	}

	if(i != anchor)
	{
		int tmp = input[i];
		input[i] = input[anchor];
		input[anchor] = tmp;
	}	

	return i;
}

int randomizedSelect(std::vector<int> &input, int p, int r, int i)
{
	if(p == r)
		return input[p];

	int q = radomizedPartition(input, p, r);
	if(i == (q + 1))
		return input[q];
	if(i < (q + 1))
		return randomizedSelect(input, p, q - 1, i);
	else
		return randomizedSelect(input, q + 1, r, i);
}



int main()
{
    std::vector<int> input;
    while(!getIntArrayFromConsole(input));

    int middle = randomizedSelect(input, 0, (int)input.size() - 1, input.size()/2);
    std::cout<<"the middle sequnce is "<<input.size()/2<<" the middle is "<<middle<<std::endl;
}