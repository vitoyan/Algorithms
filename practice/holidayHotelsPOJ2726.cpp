#include <iostream>
#include <algorithm>

class hotel
{
public:
	int dis;
	int cost;	
};

bool compare(hotel &m, hotel &n)
{
	if(m.dis == n.dis)
		return m.cost < n.cost;
	return m.dis < n.dis;
}


int main()
{
	int size = 0;
	std::cin>>size;
	while(size != 0)
	{
		hotel *input =  new hotel[size];
		if(!input)
			return 0;
		for(int i = 0; i < size; i++)
		{
			std::cin>>input[i].dis>>input[i].cost;
		}

		std::sort(input, input + size, compare);

		int	minCost = input[0].cost;
		int count = 1;

		for(int i = 0; i < size; i++)
		{
			if(input[i].cost < minCost)
			{
				count++;
				minCost = input[i].cost;
			}
		}
		

		delete[] input;	
		std::cout<<count<<std::endl;	
		size = 0;
		std::cin>>size;		
	}
	return 0;
}