#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <sstream>
#include <stack>
#include <limits>

#include "./util/util.h"

std::vector<std::vector<int> > matrixChainOrder(std::vector<int> &p)
{
	std::vector<std::vector<int> > s(p.size(), std::vector<int>(p.size(), 0));
	if(p.empty())
		return s;

	std::vector<std::vector<int> > m(p.size(), std::vector<int>(p.size(), 0));

	for(int length = 2; length <= (int)p.size() - 1; length++)
		for(int  i = 1; i <= (int)p.size() - length; i++)
		{
			int j = i + length - 1;
			m[i][j] = std::numeric_limits<int>::max();
			for(int k = i; k <= j - 1; k++)
			{
				int q = m[i][k] + m[k + 1][j] + p[i-1]*p[k]*p[j];
				if(q < m[i][j])
				{
					m[i][j] = q;
					s[i][j] = k;
				}
			}
		}	
	return s;
}

void printMartixChainOrder(std::vector<std::vector<int> > &s, int i, int j)
{
	if(s.empty())
		return;
	if(i == j)
	{
		std::cout<<"A"<<i;
		return;
	}
	std::cout<<"(";
	printMartixChainOrder(s, i, s[i][j]);
	printMartixChainOrder(s, s[i][j] + 1, j);
	std::cout<<")";
}

int main()
{
	std::vector<int> input;
    while(!getIntArrayFromConsole(input));
    std::vector<std::vector<int> > s = matrixChainOrder(input);
    printMartixChainOrder(s, 1, s.size()-1);    
}