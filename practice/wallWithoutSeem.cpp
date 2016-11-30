#include <iostream>
#include <vector>
#include <queue>
#include <bitset>


int wall(int w, int h)
{
	if(w < 2 || h == 0)
		return 0;
	
	int *p = NULL;
	p = new int[w + 1];

	p[0] = 0;
	p[1] = 0;
	p[2] = 1;
	p[3] = 1;
	p[4] = 1;
	p[5] = 2;
	for(int i = 6; i < w + 1; i++)
	{
		p[i] = p[i - 2] + p[i - 3];
	}

	if( h == 1)
		return p[w];

	std::vector<std::vector<std::queue<int> > > layers;
	std::queue<int> s1, s2;
	std::vector<std::queue<int> > v1, v2;
	//for p[0]
	layers.push_back(v1);
	//for p[1]
	layers.push_back(v1);
	//for p[2]
	s1.push(2);
	v1.push_back(s1);
	layers.push_back(v1);
	//for p[3]
	s2.push(3);
	v2.push_back(s2);
	layers.push_back(v2);
	//for p[4]
	s1.push(2);
	v1.clear();
	v1.push_back(s1);
	layers.push_back(v1);

	//calculating layers 
	for(int i = 5; i < w + 1; i++)
	{
		std::vector<std::queue<int> > tmp;
		auto m = layers[i - 3];
		auto n = layers[i - 2];
		for(auto it : m)
		{
			it.push(3);
			tmp.push_back(it);
		}
		for(auto it : n)
		{
			it.push(2);
			tmp.push_back(it);
		}

		layers.push_back(tmp);
	}

		
	for(auto it : layers)
	{
		for(auto it1 : it)
		{
			auto tmp = it1;
			while(!tmp.empty())
			{
				tmp.pop();
			}
		}
	}	

	//calculating bricks position
	std::vector<std::queue<int> > layer = layers.back();
	std::vector<std::vector<int> > pos;
	for(auto it : layer)
	{
		int sum = 0;
		std::vector<int> tmp;
		while(!it.empty())
		{
			sum += it.front();
			it.pop();
			if(sum != w)
				tmp.push_back(sum);
		}
		pos.push_back(tmp);
	}	

	//calculating two layers withou seem
	std::vector<std::vector<int> > matrix;
	for(int i = 0; i < (int)pos.size(); i++)
	{
		std::vector<int> tmp;
		for(int j = 0; j < (int)pos.size(); j++)
		{
			bool isDisjoint = true;
			auto it1 = pos[i].begin();
			auto it2 = pos[j].begin();
			while(it1 != pos[i].end() && it2 != pos[j].end())
			{
				if(*it1 == *it2)
				{
					isDisjoint = false;
					break;
				}
				if(*it1 > *it2)
				{
					it2++;
				}
				if(*it1 < *it2)
				{
					it1++;
				}
			}
			if(isDisjoint)
				tmp.push_back(j);
		}
		matrix.push_back(tmp);
	}	

	std::vector<int> walls(pos.size(), 1);
	for(int i = 0; i < h - 1; i++)
	{
		std::vector<int> tmp = walls;
		for(int j = 0; j < (int)matrix.size(); j++)
		{
			int sum = 0;
			for(auto it2 : matrix[j])
			{
				sum += walls[it2];
			}
			tmp[j] = sum;
		}
		walls = tmp;
		
	}
	
	int ret = 0;
	for(auto it : walls)
	{		
		ret += it;
	}
	return ret;
}


int main()
{
	int w = 0, q = 0;
	std::cin>>w>>q;
	std::cout<<wall(w, q)<<std::endl;
}