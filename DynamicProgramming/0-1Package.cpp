#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <sstream>
#include <stack>
#include <limits>

#include "./util/util.h"

std::vector<std::vector<int> > package(const std::vector<int> &value, const std::vector<int> &weight)
{
	if(value.size() != weight.size() || value.empty())
		return std::vector<std::vector<int> > ();

	int size = (int)value.size();
	int totalWeight = 0;
	for(auto i : weight)
	{
		totalWeight += i;
	}
	std::vector<std::vector<int> > m(size, std::vector<int>(totalWeight + 1, 0));
	std::vector<std::vector<int> > s(size, std::vector<int>(totalWeight + 1, 0));

	for(int i = 1; i < size; i++)
		for(int j = 1; j < totalWeight + 1; j++)
		{
			if(weight[i] > j)
			{
				m[i][j] = m[i-1][j];
				s[i][j] = 0;
			}
			else
			{
				int tmp1 = m[i-1][j];
				int tmp2 = m[i-1][j - weight[i]] + value[i];
				if(tmp1 >= tmp2)
				{
					m[i][j] = tmp1;
					s[i][j] = 0;
				}
				else
				{
					m[i][j] = tmp2;
					s[i][j] = 1;
				}
			}
		}
	return s;
}

void printPackage(const std::vector<std::vector<int> > &s, const std::vector<int> &weight, int m, int n)
{
	if(n < 0 || m <0 || m >= (int)weight.size())
		return;

	if(s[m][n])
	{		
		printPackage(s, weight, m - 1, n - weight[m]);
		std::cout<<"P"<<m<<" ";
	}
	else
	{
		printPackage(s, weight, m - 1, n);
	}
}

int main()
{
	std::vector<int> input1, tmp1(1, 0);
    while(!getIntArrayFromConsole(input1));
    std::vector<int> input2, tmp2(1, 0);
    while(!getIntArrayFromConsole(input2));
    tmp1.insert(tmp1.begin()+1, input1.begin(), input1.end());
    tmp2.insert(tmp2.begin()+1, input2.begin(), input2.end()); 

    auto s = package(tmp1, tmp2);
    std::cout<<"pls input weight: ";
    int weight = 0;
    std::cin>>weight;
    int totalWeight = 0;
    for(auto i : input2)
    {
    	totalWeight += i;
    }
    if(totalWeight <= weight)
    {
    	for(int i = 1; i < (int)tmp1.size(); i++)
    		std::cout<<"P"<<i<<" ";
    }
    else
    {
    	std::cout<<tmp2.size() - 1<<std::endl;;
    	printPackage(s, tmp2, tmp2.size() - 1, weight);
    	std::cout<<std::endl;
    }
}