#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <sstream>
#include <stack>
#include <set>
#include <limits>
#include <algorithm>

#include "./util/util.h"

std::vector<std::vector<int> > maximumActivityOrder(std::vector<int> &input1, std::vector<int> &input2)
{
	int size = (int)input1.size();
	std::vector<std::vector<int> > m(size + 1, std::vector<int>(size + 1, 0));
	std::vector<std::vector<int> > s(size + 1, std::vector<int>(size + 1, 0));
	input1.push_back(std::numeric_limits<int>::max());
	
	if(input1.empty() || input2.empty())
		return std::vector<std::vector<int> > ();

	for(int step = 2; step <= size; step++)
	{
		for(int i = 0; i <= size - step; i++)
		{
			int j = i + step;
			if(input1[i] <= input2[j])
			{
			for(int k = i + 1; k < j; k++)
			{
				if(input1[k] < input2[i] || input2[k] > input1[j])
					continue;
				{
					if(m[i][j] < (m[i][k] + m[k][j] +1))
					{
						m[i][j] = m[i][k] + m[k][j] +1;
						s[i][j] = k;
					}
				}
			}
			}
		}
	}
	return s;	
}

void printActivityOrder(std::vector<std::vector<int> > &s, int a, int b)
{
	if(a < b)
	{
		printActivityOrder(s, a, s[a][b]);
		if(s[a][b] != 0)
		{
			std::cout<<"Activity"<<s[a][b]<<" ";
			printActivityOrder(s, s[a][b], b);
		}
	}
}

int main()
{
	//input 1: start time array
	//input 2: finish time arrary as ascending
	//for example
	//1 3 0 5 3 5
	//4 5 6 7 9 9
	std::vector<int> input1, tmp1(1, 0);
    while(!getIntArrayFromConsole(input1));
    std::vector<int> input2, tmp2(1, 0);
    while(!getIntArrayFromConsole(input2));
    std::sort(input2.begin(), input2.end());
    tmp1.insert(tmp1.begin()+1, input1.begin(), input1.end());
    tmp2.insert(tmp2.begin()+1, input2.begin(), input2.end());    

    auto s = maximumActivityOrder(tmp1, tmp2); 
    printActivityOrder(s, 0, input1.size() + 1); 
    
    std::cout<<std::endl;
}