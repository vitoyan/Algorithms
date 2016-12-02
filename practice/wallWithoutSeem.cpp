#include <iostream>
#include <vector>
#include <queue>

void calculatingLayers(int w, std::vector<std::vector<std::queue<int> > > &layers)
{
	std::queue<int> s1, s2;
	std::vector<std::queue<int> > v1, v2;
	//for with = 0
	layers.push_back(v1);
	//for with = 1
	layers.push_back(v1);
	//for with = 2
	s1.push(2);
	v1.push_back(s1);
	layers.push_back(v1);
	//for with = 3
	s2.push(3);
	v2.push_back(s2);
	layers.push_back(v2);
	//for with = 4
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
}

void calculatingBricksPositions(int w, const std::vector<std::queue<int> > &layer, std::vector<std::vector<int> > &pos)
{
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
}

void calculatingLayersDisjointMatrix(const std::vector<std::vector<int> > &pos, std::vector<std::vector<int> > &matrix)
{
	int posSize = (int)pos.size();
	for(int i = 0; i < posSize; i++)
	{
		std::vector<int> tmp;
		for(int j = 0; j < posSize; j++)
		{
			if(i == j)
				continue;
			bool isDisjoint = true;
			for(int it1 = 0, it2 = 0; it1 < (int)pos[i].size() && it2 < (int)pos[j].size();)
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
				else
				{
					it1++;
				}
			}	
			if(isDisjoint)
				tmp.push_back(j);
		}
		matrix.push_back(tmp);		
	}	
}

template <class T1, class T2>
void calculatingWalls(int h, const std::vector<std::vector<T1> > &matrix, std::vector<T2> &walls)
{
	for(int i = 0; i < h - 1; i++)
	{
		std::vector<T2> tmp = walls;
		for(int j = 0; j < (int)matrix.size(); j++)
		{
			T2 sum = 0;
			for(auto it2 : matrix[j])
			{
				sum += walls[it2];
			}
			tmp[j] = sum;
		}
		walls = tmp;		
	}	
}

long long wall(int w, int h)
{
	if(w < 2 || h == 0)
		return 0;

	if( h == 1)
	{
		long long *p = NULL;
		p = new long long[w + 1];

		p[0] = 0;
		p[1] = 0;
		p[2] = 1;
		if(w > 2)
			p[3] = 1;
		for(int i = 4; i < w + 1; i++)
		{
			p[i] = p[i - 2] + p[i - 3];
		}
		long long ret = p[w];
		delete[] p;
		return ret;
	}

	std::vector<std::vector<std::queue<int> > > layers;
	calculatingLayers(w, layers);
			
	std::vector<std::queue<int> > layer = layers.back();
	std::vector<std::vector<int> > pos;
	calculatingBricksPositions(w, layer, pos);

	std::vector<std::vector<int> > matrix;
	calculatingLayersDisjointMatrix(pos, matrix);

	std::vector<long long> walls(pos.size(), 1);
	calculatingWalls<int, long long>(h, matrix, walls);
	
	long long ret = 0;
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