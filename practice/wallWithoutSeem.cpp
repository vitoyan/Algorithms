#include <iostream>
#include <vector>
#include <queue>
#include <chrono>


long long wall(long long w, long long h)
{
	auto t1 = std::chrono::high_resolution_clock::now();
	if(w < 2 || h == 0)
		return 0;
	
	long long *p = NULL;
	p = new long long[w + 1];

	p[0] = 0;
	p[1] = 0;
	p[2] = 1;
	p[3] = 1;
	p[4] = 1;
	p[5] = 2;
	for(long long i = 6; i < w + 1; i++)
	{
		p[i] = p[i - 2] + p[i - 3];
	}

	if( h == 1)
		return p[w];

	std::vector<std::vector<std::queue<long long> > > layers;
	std::queue<long long> s1, s2;
	std::vector<std::queue<long long> > v1, v2;
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
	for(long long i = 5; i < w + 1; i++)
	{
		std::vector<std::queue<long long> > tmp;
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
	auto t2 = std::chrono::high_resolution_clock::now();
	std::cout << "calculating layers took " << std::chrono::duration_cast<std::chrono::milliseconds>(t2-t1).count()
              << " milliseconds\n";
		

	//calculating bricks position
	std::vector<std::queue<long long> > layer = layers.back();
	std::vector<std::vector<long long> > pos;
	for(auto it : layer)
	{
		long long sum = 0;
		std::vector<long long> tmp;
		while(!it.empty())
		{
			sum += it.front();
			it.pop();
			if(sum != w)
				tmp.push_back(sum);
		}
		pos.push_back(tmp);
	}
	auto t3 = std::chrono::high_resolution_clock::now();
	std::cout << "calculating bricks position took " << std::chrono::duration_cast<std::chrono::milliseconds>(t3-t2).count()
              << " milliseconds\n";	

	//calculating two layers without seem
	std::vector<std::vector<long long> > matrix;
	long long posSize = (long long)pos.size();
	for(long long i = 0; i < posSize; i++)
	{
		std::vector<long long> tmp;
		for(long long j = 0; j < posSize; j++)
		{
			if(i == j)
				continue;
			bool isDisjoint = true;
			for(long long it1 = 0, it2 = 0; it1 < (long long)pos[i].size() && it2 < (long long)pos[j].size();)
			{
				if(pos[i][it1] == pos[j][it2])
				{
					isDisjoint = false;
					break;
				}
				if(pos[i][it1] > pos[j][it2])
				{
					it2++;
				}
				if(pos[i][it1] < pos[j][it2])
				{
					it1++;
				}
			}	
			if(isDisjoint)
				tmp.push_back(j);
		}
		matrix.push_back(tmp);		
	}
	auto t4 = std::chrono::high_resolution_clock::now();
	std::cout << "calculating disjolong long took " << std::chrono::duration_cast<std::chrono::milliseconds>(t4-t3).count()
              << " milliseconds\n";	

	std::vector<long long> walls(pos.size(), 1);
	for(long long i = 0; i < h - 1; i++)
	{
		std::vector<long long> tmp = walls;
		for(long long j = 0; j < (long long)matrix.size(); j++)
		{
			long long sum = 0;
			for(auto it2 : matrix[j])
			{
				sum += walls[it2];
			}
			tmp[j] = sum;
		}
		walls = tmp;
		
	}
	auto t5 = std::chrono::high_resolution_clock::now();
	std::cout << "calculating walls took " << std::chrono::duration_cast<std::chrono::milliseconds>(t5-t4).count()
              << " milliseconds\n";	
	
	long long ret = 0;
	for(auto it : walls)
	{		
		ret += it;
	}
	return ret;
}


int main()
{
	long long w = 0, q = 0;
	std::cin>>w>>q;
	std::cout<<wall(w, q)<<std::endl;
}