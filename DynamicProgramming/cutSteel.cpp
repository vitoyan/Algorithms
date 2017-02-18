#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <sstream>
#include <stack>
#include <limits>

#include "./util/util.h"

std::vector<int> cutSteel(std::vector<int> &p)
{
	std::vector<int> m(p.size() + 1, 0);
	std::vector<int> s(p.size() + 1, 0);
	for(int j = 1; j <= (int)p.size(); j++)
	{
		for(int i = 1; i <= j; i++)
		{
			if(m[j] < (p[i - 1] + m[j - i]))
			{
				s[j] = i;
				m[j] = p[i - 1] + m[j - i];
			}
		}		
	}
	return s;
}

void printCutSolution(std::vector<int> s, int n)
{
	if(s.empty() || n == 0)
		return;

	while(n > 0)
	{
		std::cout<<s[n]<<" ";
		n = n - s[n];
	}
	std::cout<<std::endl;
}

int main()
{
	std::vector<int> input;
    while(!getIntArrayFromConsole(input));
    printCutSolution(cutSteel(input), input.size());
}