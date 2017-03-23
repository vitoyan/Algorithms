#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <sstream>
#include <stack>
#include <queue>

#include "./util/util.h"
#include "./util/buildDataStructure.h"


int main()
{
	std::vector<std::vector<int>> nodes(4, std::vector<int> (1, -1));
	std::vector<int> degree(4, 0);
	std::queue<int>  zeroNodes;
	std::queue<int> result;

	//  0 - 1, 1 - 2, 3 - 2
	nodes[0][0] = 1;
	nodes[1][0] = 2;
	nodes[3][0] = 2;

	for(int i = 0 ; i <= 3; i++)
	{
		int node = nodes[i][0];
		if(node >= 0)
			degree[node]++;
	}
	for(int i = 0 ; i < (int)degree.size(); i++)
	{
		if(degree[i] == 0)
			zeroNodes.push(i);
	}

	while(!zeroNodes.empty())
	{
		int node = zeroNodes.front();
		zeroNodes.pop();
		result.push(node);
		
		for(int i = 0; i < 1; i++)
		{
			node = nodes[node][0];
			if(node < 0)
				continue;
			degree[node]--;
			if(degree[node] == 0)
				zeroNodes.push(node);
		}
		
	}

	for(auto it : degree)
	{
		if(it != 0)
		{
			std::cout<<"there is a circle"<<std::endl;
			return 0;
		}
	}	

	while(!result.empty())
	{
		std::cout<<result.front()<<" ";
		result.pop();
	}
}