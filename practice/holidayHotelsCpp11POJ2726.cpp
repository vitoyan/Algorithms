#include <iostream>
#include <map>


int main()
{
	int size = 0;
	std::cin>>size;
	std::map<int, int> input;
	std::map<int, int> order;
	
	while(size > 0)
	{
		int d = 0, c = 0;
		std::cin>>d>>c;
		input.insert({d, c});
		order.insert({d, 6-size});
		size--;
	}


	auto first = input.begin();
	int distance = first->first;
	int cost = first->second;

	for(auto elm : input)
	{
		if(elm.first == distance && elm.second < cost)
		{
			cost = elm.second;
		}
	}

	std::cout<<order[distance];


}